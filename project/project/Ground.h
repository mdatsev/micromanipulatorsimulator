#pragma once
#include "Vec2.h"
#include <vector>
class Ground
{
public:
	float height;
	float friction;
	std::vector<Vec2> points;
	Ground(float height, float friction);
	void AddPoint(Vec2);
	~Ground();
};

