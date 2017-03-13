#include "stdafx.h"
#include "Node.h"


Node::Node(Vec2 pos, float size, float friction, float restitution, float mass, Vec2 acc) : pos(pos), size(size),friction(friction), restitution(restitution), mass(mass), acc(acc)
{
}

Node::~Node()
{
}

void Node::Step()
{
	pos += vel;
	vel += acc;
}

void Node::AddForce(Vec2 force)
{
	acc += force / mass;
}

void Node::CollisionDetector()
{
	Ground* ground;
	for (int i = 0; i < ground->points.size() - 1; i++)
	{
		float len = Vec2::Distance(ground->points[i], ground->points[i + 1]);
		float dot = (((pos.x - ground->points[i].x)*(ground->points[i + 1].x - ground->points[i].x)) + ((pos.y - ground->points[i].y)*(ground->points[i + 1].y - ground->points[i].y))) / pow(len, 2);
		float closestX = ground->points[i].x + (dot * (ground->points[i + 1].x - ground->points[i].x));
		float closestY = ground->points[i].y + (dot * (ground->points[i + 1].y - ground->points[i].y));
		Vec2 closestPoint = Vec2(closestX, closestY);
		if (!linePointCollision(ground->points[i], ground->points[i + 1], closestPoint, len))
		{
			return;
		}
		float closestDist = Vec2::Distance(closestPoint, pos);
		if (closestDist <= size)
		{
			//Here goes stuff after they collide
		}
	}
}

bool linePointCollision(Vec2 point, Vec2 point2, Vec2 closestPoint, float len)
{
	float dist1 = Vec2::Distance(point, closestPoint);
	float dist2 = Vec2::Distance(point2, closestPoint);

	float epsilon = 0.1f;

	if (dist1 + dist2 >= len - epsilon && dist1 + dist2 <= len + epsilon) {
		return true;
	}
	return false;
}