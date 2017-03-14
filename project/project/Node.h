#pragma once
#include "Vec2.h"
#include "Ground.h"
#include <vector>
#include <map>
class Node
{
	float oldTime = 0;
	std::map<int, int> normal_forces;
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
	int AddForce();
	void ChangeForce(int id, Vec2 force);
	void CollisionDetector();
	static bool linePointCollision(Vec2 point, Vec2 point2, Vec2 closestPoint, float len);
};

