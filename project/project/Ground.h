#pragma once
class Ground
{
public:
	float height;
	float friction;
	float x;
	Ground(float height, float friction, float x);
	~Ground();
};

