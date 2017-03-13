#pragma once
class Vec2
{
public:
	float x;
	float y;
	Vec2(float x, float y);
	Vec2();
	~Vec2();
	float Magnitude();
	static Vec2 Normalize(Vec2);
	static float Distance(Vec2, Vec2);
	void operator+=(const Vec2 & v);
	void operator*=(const float & right);
	Vec2 operator+(const Vec2 & right);
	Vec2 operator-(const Vec2 & right);
	Vec2 operator*(const float & right);
	Vec2 operator/(const float & right);
};

