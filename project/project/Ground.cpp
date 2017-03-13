#include "stdafx.h"
#include "Ground.h"


Ground::Ground(float height, float friction) : height(height), friction(friction)
{
}


Ground::~Ground()
{
}

void Ground::AddPoint(Vec2 point)
{
	points.push_back(point);
}
