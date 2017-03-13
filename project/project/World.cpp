#include "stdafx.h"
#include "World.h"


World::World()
{
}


World::~World()
{
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
			float x1 = c.nodes[n.node1_ID].pos.x;
			float y1 = c.nodes[n.node1_ID].pos.y;
			float x2 = c.nodes[n.node2_ID].pos.x;
			float y2 = c.nodes[n.node2_ID].pos.y;
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

				HPEN hOldPen = (HPEN)SelectObject(hMemDc, greenPen);

				MoveToEx(hMemDc, n.pos.x, n.pos.y, NULL);
				LineTo(hMemDc, n.pos.x + n.vel.x * 60, n.pos.y + n.vel.y * 60);

				SelectObject(hMemDc, redPen);
				MoveToEx(hMemDc, n.pos.x, n.pos.y, NULL);
				LineTo(hMemDc, n.pos.x + n.acc.x * 3600, n.pos.y + n.acc.y * 3600);

				SelectObject(hMemDc, hOldPen);
				DeleteObject(greenPen);
				DeleteObject(redPen);
				DeleteObject(bluePen);
			}
		}
	}

	BitBlt(hdc, rect.left, rect.top, rect.right, rect.bottom, hMemDc, 0, 0, SRCCOPY);

	DeleteObject(hBrush);
	DeleteObject(hBmp);
	DeleteDC(hMemDc);
}

void World::Step()
{
	for(Creature& c : creatures)
	{
		c.Step();
	}
}
