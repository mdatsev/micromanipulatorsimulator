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

void Vec2::operator+=(const Vec2 &v) {
	x += v.x;
	y += v.y;
}

void Vec2::operator*=(const float &right) {
	x *= right;
	y *= right;
}

Vec2 Vec2::operator+(const Vec2 &right) {
	Vec2 result;
	result.x = x + right.x;
	result.y = y + right.y;
	return result;
}

Vec2 Vec2::operator-(const Vec2 & right)
{
	Vec2 result;
	result.x = x - right.x;
	result.y = y - right.y;
	return result;
}

Vec2 Vec2::operator*(const float &right) {
	Vec2 result;
	result.x = x * right;
	result.y = y * right;
	return result;
}

Vec2 Vec2::operator/(const float &right) {
	Vec2 result;
	result.x = x / right;
	result.y = y / right;
	return result;
}
