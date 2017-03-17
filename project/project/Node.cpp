#include "stdafx.h"
#include "Node.h"
#include "World.h"
#include "globals.h"
#include <ctime>

Node::Node(Vec2 pos, float size, float friction, float restitution, float mass, bool gravity) : 
	pos(pos), size(size), friction(friction), restitution(restitution), mass(mass), gravityForce(gravity ? Vec2(0, gravity_constant) : Vec2(0,0))
{
}

Node::~Node()
{
}

bool Node::CollidesWithGround(Ground* ground, Vec2* collision_point_ptr)
{
	for (int i = 0; i < ground->points.size() - 1; i++)
	{
		Vec2 p1 = ground->points[i];
		Vec2 p2 = ground->points[i + 1];

		//check if in bounding box
		float left = p1.x < p2.x ? p1.x : p2.x;
		float right = p1.x > p2.x ? p1.x : p2.x;
		float top = p1.y < p2.y ? p1.y : p2.y;
		float bottom = p1.y > p2.y ? p1.y : p2.y;
		if (left > pos.x + size
			|| right < pos.x - size
			|| top > pos.y + size
			|| bottom < pos.y - size)
		{
			continue;
		}

		//part to projection point [0-1]
		float part = std::fmax(0, std::fmin(1, Vec2::Dot(pos - p1, p2 - p1) / Vec2::DistanceSq(p1, p2)));

		Vec2 projection = p1 + (p2 - p1) * part;

		float d = Vec2::DistanceSq(pos, projection);
		if ( d <= size * size)
		{
			*collision_point_ptr = projection;
			return true;
		}
	}
	return false;
}

bool Node::linePointCollision(Vec2 point, Vec2 point2, Vec2 closestPoint, float len)
{
	float dist1 = Vec2::Distance(point, closestPoint);
	float dist2 = Vec2::Distance(point2, closestPoint);


	if (dist1 * dist1 + dist2 * dist2 >= len - 2 * dist2 * dist1 && 
		dist1 * dist1 + dist2 * dist2 <= len - 2 * dist2 * dist1) {
		return true;
	}
	return false;
}

bool Node::pointCircleCollision(Vec2 point, Vec2 circle, float size)
{
	float distance = Vec2::Distance(point, circle);
	if (distance <= size) {
		return true;
	}
	return false;
}