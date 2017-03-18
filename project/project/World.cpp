#include "stdafx.h"
#include "World.h"
#include <process.h>
#include "constants.h"

World::World()
{
}


World::~World()
{
}

void Simulate(void* param)
{
	World* world = (World*)param;
	world->simulation_running = true;
	while (world->simulation_running)
	{
		world->Integrate(0.001);
	}
}

void World::StartSimulation()
{
	_beginthread(Simulate, 0, this);
}

void World::StopSimulation()
{
	simulation_running = false;
}

void World::AddCreature(Creature n)
{
	creatures.push_back(n);
}

void World::Draw(HDC hdc, RECT rect, bool debug)
{
	HDC hMemDc = CreateCompatibleDC(hdc);
	HBITMAP hBmp = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
	SelectObject(hMemDc, hBmp);
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(hMemDc, &rect, hBrush);

	for(Creature& c : creatures)
	{
		MoveToEx(hMemDc, World::ground->points[0].x, World::ground->points[0].y, NULL); //fixme drawing the same point twice
		for (Vec2& point : World::ground->points)
		{
			LineTo(hMemDc, point.x, point.y);
		}

		for (Node& n : c.nodes)
		{
			int mass = n.mass;
			if (mass > 255)
				mass = 255;
			int color = 255 - mass;
			SelectObject(hMemDc, CreateSolidBrush(RGB(color, color, color)));
			Ellipse(hMemDc, n.pos.x - n.size, n.pos.y - n.size, n.pos.x + n.size, n.pos.y + n.size);
		}

		for (Muscle& n : c.muscles)
		{
			double x1 = c.nodes[n.node1_ID].pos.x;
			double y1 = c.nodes[n.node1_ID].pos.y;
			double x2 = c.nodes[n.node2_ID].pos.x;
			double y2 = c.nodes[n.node2_ID].pos.y;
			MoveToEx(hMemDc, x1, y1, NULL);
			LineTo(hMemDc, x2, y2);
		}
	}

	if (debug)
	{
		for (Creature& c : creatures)
		{
			for (Node& n : c.nodes)
			{
				HPEN redPen = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
				HPEN greenPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
				HPEN bluePen = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
				HPEN yellowPen = CreatePen(PS_SOLID, 1, RGB(0, 255, 255));

				HPEN hOldPen = (HPEN)SelectObject(hMemDc, greenPen);
				//draw velocity			
				MoveToEx(hMemDc, n.pos.x, n.pos.y, NULL);
				LineTo(hMemDc, n.pos.x + n.vel.x * 60, n.pos.y + n.vel.y * 60);

				//draw acceleration
				SelectObject(hMemDc, redPen);
				MoveToEx(hMemDc, n.pos.x, n.pos.y, NULL);
				LineTo(hMemDc, n.pos.x + n.acc.x * 3600, n.pos.y + n.acc.y * 3600);

				//draw forces
				SelectObject(hMemDc, bluePen);
				TCHAR buffer[80];
								SetTextColor(hMemDc, RGB(0, 0, 255));
				SetBkMode(hMemDc, TRANSPARENT);
				_stprintf_s(buffer, _T("c:%d"), n.debug_collides);
				TextOut(hMemDc, n.pos.x, n.pos.y, buffer, _tcslen(buffer));
					MoveToEx(hMemDc, n.pos.x, n.pos.y, NULL);
					LineTo(hMemDc, n.pos.x + n.forces.x * 60, n.pos.y + n.forces.y * 60);
					SelectObject(hMemDc, yellowPen);
					_stprintf_s(buffer, _T("mag:%f"), n.debug_vec2.Magnitude());
					TextOut(hMemDc, 0, 0, buffer, _tcslen(buffer));
					MoveToEx(hMemDc, n.pos.x, n.pos.y, NULL);
					LineTo(hMemDc, n.pos.x + n.debug_vec2.x, n.pos.y + n.debug_vec2.y);
					
					MoveToEx(hMemDc, 0, 100, NULL);
					LineTo(hMemDc, 1999, 100);
				SelectObject(hMemDc, hOldPen);
				DeleteObject(greenPen);
				DeleteObject(redPen);
				DeleteObject(bluePen);
				DeleteObject(yellowPen);
			}
		}
	}

	BitBlt(hdc, rect.left, rect.top, rect.right, rect.bottom, hMemDc, 0, 0, SRCCOPY);

	DeleteObject(hBrush);
	DeleteObject(hBmp);
	DeleteDC(hMemDc);
}

void World::Integrate(double dt)
{
	for(Creature& c : creatures)
	{
		for (Node& n : c.nodes) 
		{
			n.forces = n.gravityForce;
		}

		for (Muscle& m : c.muscles)
		{
			Vec2 force_direction1 = c.nodes[m.node2_ID].pos - c.nodes[m.node1_ID].pos;
			force_direction1.Normalize();
			Vec2 force_direction2 = c.nodes[m.node1_ID].pos - c.nodes[m.node2_ID].pos;
			force_direction2.Normalize();
			double length = c.nodes[m.node1_ID].pos.Distance(c.nodes[m.node2_ID].pos);
			double displacement = length - m.target_length;
			c.nodes[m.node1_ID].forces += force_direction1  *  m.stiffness * displacement;
			c.nodes[m.node2_ID].forces += force_direction2  * m.stiffness * displacement;
		}

		for (Node& n : c.nodes)
		{
			n.CollideWithGround(ground, dt);

			//n.CollideFlat(500);
			n.acc = n.forces / n.mass;
			n.vel += n.acc * dt;
			n.vel *= n.airFriction;
			n.pos += n.vel * dt;
		}
	}
}
