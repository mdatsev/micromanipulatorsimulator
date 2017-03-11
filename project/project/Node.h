#pragma once
#include "Vec2.h"
class Node
{
public:
	float size;
	float friction;
	float mass;
	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	Node(Vec2 pos, float size, float friction, float mass = 1, Vec2 acc = Vec2(0, 0));
	~Node();
	void Step();
	void AddForce(Vec2 force);
};

