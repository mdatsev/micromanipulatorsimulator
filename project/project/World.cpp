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

void World::Draw(HDC hdc, RECT rect)
{
	HDC hMemDc = CreateCompatibleDC(hdc);
	HBITMAP hBmp = CreateCompatibleBitmap(hdc, rect.right, rect.bottom);
	SelectObject(hMemDc, hBmp);
	SelectObject(hMemDc, GetStockObject(NULL_BRUSH));
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	FillRect(hMemDc, &rect, hBrush);

	for(Creature& c : creatures)
	{
		for (Node& n : c.nodes)
		{
			Ellipse(hMemDc, n.pos.x - n.size, n.pos.y - n.size, n.pos.x + n.size, n.pos.y + n.size);
		}

		for (Muscle& n : c.muscles)
		{
			float x1 = c.nodes[n.connectionID1].pos.x;
			float y1 = c.nodes[n.connectionID1].pos.y;
			float x2 = c.nodes[n.connectionID2].pos.x;
			float y2 = c.nodes[n.connectionID2].pos.y;
			MoveToEx(hMemDc, x1, y1, NULL);
			LineTo(hMemDc, x2, y2);
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
