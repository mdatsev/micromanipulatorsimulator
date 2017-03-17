#pragma once
#include "Vec2.h"
#include "Ground.h"
#include <vector>
#include <map>
class Node
{
	float oldTime = 0;
public:
	bool debug_collides = false;
	Vec2 gravityForce;
	float size;
	float friction;
	float airFriction = 1;
	float mass;
	float restitution;
	Vec2 pos;
	Vec2 vel;
	Vec2 acc;
	Vec2 forces;
	Node(Vec2 pos, float size, float friction, float restitution, float mass = 1, bool gravity = true);
	~Node();
	bool CollidesWithGround(Ground*, Vec2* collision_point_ptr);
	static bool linePointCollision(Vec2 point, Vec2 point2, Vec2 closestPoint, float len);
	static bool pointCircleCollision(Vec2 point, Vec2 circle, float size);
};

