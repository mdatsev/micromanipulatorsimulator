#include "stdafx.h"
#include "Vec2.h"
#include <math.h>


Vec2::Vec2(float x, float y) : x(x), y(y)
{
}

Vec2::Vec2() : x(0), y(0)
{
}

Vec2::~Vec2()
{
}

float Vec2::Magnitude()
{
	return sqrt(x * x + y * y);
}

Vec2 Vec2::Normalize(Vec2 v)
{
	Vec2 result;
	float length = v.Magnitude();
	if (length != 0) {
		result.x = v.x / length;
		result.y = v.y / length;
	}

	return result;
}

float Vec2::Distance(Vec2 v1, Vec2 v2)
{
	return sqrt(pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2));
}

float Vec2::Dot(Vec2 v1, Vec2 v2)
{
	return v1.x*v2.x + v1.y*v2.y;
}
