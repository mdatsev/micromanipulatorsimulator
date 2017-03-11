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
