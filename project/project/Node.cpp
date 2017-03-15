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

void Node::CollideFlat(float height)
{
	if (pos.y > height - size)
	{
		pos.y = height - size;
		vel = vel - Vec2(0, -1) * (Vec2::Dot(vel, Vec2(0, -1))) * 2 * restitution; // reflection vector http://math.stackexchange.com/questions/13261/how-to-get-a-reflection-vector
		forces += Vec2(0, -1) * mass * gravity_constant;
	}
}

void Node::CollisionDetector()
{
	Ground* ground = World::ground;
	for (int i = 0; i < World::ground->points.size() - 1; i++)
	{
		Vec2 p1 = World::ground->points[i];
		Vec2 p2 = World::ground->points[i + 1];
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

		bool inside1 = pointCircleCollision(ground->points[i], pos, size);
		bool inside2 = pointCircleCollision(ground->points[i + 1], pos, size);
		if (inside1 || inside2)
		{
			Vec2 direction = Vec2::Normalize(pos - ground->points[i]);
			vel = vel - direction * (Vec2::Dot(vel, direction)) * 2 * restitution; // reflection vector http://math.stackexchange.com/questions/13261/how-to-get-a-reflection-vector
			forces += direction * mass * 0.1;
			continue;
		}

		float len = Vec2::Distance(ground->points[i], ground->points[i + 1]);
		float dot = (((pos.x - ground->points[i].x)*(ground->points[i + 1].x - ground->points[i].x)) + ((pos.y - ground->points[i].y)*(ground->points[i + 1].y - ground->points[i].y))) / pow(len, 2);
		float closestX = ground->points[i].x + (dot * (ground->points[i + 1].x - ground->points[i].x));
		float closestY = ground->points[i].y + (dot * (ground->points[i + 1].y - ground->points[i].y));
		Vec2 closestPoint = Vec2(closestX, closestY);
		if (!linePointCollision(ground->points[i], ground->points[i + 1], closestPoint, len))
		{
			continue;
		}
		float closestDist = Vec2::Distance(closestPoint, pos);
		if (closestDist <= size)
		{
			Vec2 direction = Vec2::Normalize(pos - closestPoint);
			vel = vel - direction * (Vec2::Dot(vel, direction)) * 2 * restitution; // reflection vector http://math.stackexchange.com/questions/13261/how-to-get-a-reflection-vector
			forces += direction * mass * gravity_constant;
		}
	}
} 

bool Node::linePointCollision(Vec2 point, Vec2 point2, Vec2 closestPoint, float len)
{
	float dist1 = Vec2::Distance(point, closestPoint);
	float dist2 = Vec2::Distance(point2, closestPoint);

	float epsilon = 0.1f;

	if (dist1 + dist2 >= len - epsilon && dist1 + dist2 <= len + epsilon) {
		return true;
	}
	return false;
}

bool Node::pointCircleCollision(Vec2 point, Vec2 circle, float size)
{
	float distance = Vec2::Distance(point, circle);
	if (distance <= size
	) {
		return true;
	}
	return false;
}