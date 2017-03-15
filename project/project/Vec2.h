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
	static float Dot(Vec2, Vec2);
	inline void operator+=(const Vec2 & v);
	inline void operator*=(const float & right);
	inline Vec2 operator+(const Vec2 & right);
	inline Vec2 operator-(const Vec2 & right);
	inline Vec2 operator*(const float & right);
	inline Vec2 operator/(const float & right);
};

inline void Vec2::operator+=(const Vec2 &v) {
	x += v.x;
	y += v.y;
}

inline void Vec2::operator*=(const float &right) {
	x *= right;
	y *= right;
}

inline Vec2 Vec2::operator+(const Vec2 &right) {
	Vec2 result;
	result.x = x + right.x;
	result.y = y + right.y;
	return result;
}

inline Vec2 Vec2::operator-(const Vec2 & right)
{
	Vec2 result;
	result.x = x - right.x;
	result.y = y - right.y;
	return result;
}

inline Vec2 Vec2::operator*(const float &right) {
	Vec2 result;
	result.x = x * right;
	result.y = y * right;
	return result;
}

inline Vec2 Vec2::operator/(const float &right) {
	Vec2 result;
	result.x = x / right;
	result.y = y / right;
	return result;
}
