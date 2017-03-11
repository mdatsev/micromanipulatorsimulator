#include "stdafx.h"
#include "Vec2.h"


Vec2::Vec2(float x, float y) : x(x), y(y)
{
}

Vec2::Vec2() : x(0), y(0)
{
}

Vec2::~Vec2()
{
}

void Vec2::operator+=(const Vec2 &v) {
	x += v.x;
	y += v.y;
}

Vec2 Vec2::operator+(const Vec2 &right) {
	Vec2 result;
	result.x = x + right.x;
	result.y = y + right.y;
	return result;
}

Vec2 Vec2::operator/(const float &right) {
	Vec2 result;
	result.x = x / right;
	result.y = y / right;
	return result;
}
