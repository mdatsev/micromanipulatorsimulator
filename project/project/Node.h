#pragma once
#include "Vec2.h"
#include "Ground.h"
#include <vector>
class Node
{
public:
	float size;
	float friction;
	float airFriction = 0.99;
	float mass;
	float restitution;
	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	std::vector<Vec2> forces;
	Node(Vec2 pos, float size, float friction, float restitution, float mass = 1, bool gravity = true);
	~Node();
	void Step();
	int AddForce(Vec2 force);
	void ChangeForce(int id, Vec2 force);
	void CollisionDetector();
};

