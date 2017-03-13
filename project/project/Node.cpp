#include "stdafx.h"
#include "Node.h"

Node::Node(Vec2 pos, float size, float friction, float restitution, float mass, bool gravity) : pos(pos), size(size), friction(friction), restitution(restitution), mass(mass)
{
	if (gravity)
	{
		forces.push_back(Vec2(0, mass * 0.1));
	}
}

Node::~Node()
{
}

void Node::Step()
{
	acc = Vec2(0, 0);
	for(Vec2& f : forces)
	{
		acc += f / mass;
	}
	acc = acc;
	pos += vel;
	vel += acc;
	vel *= airFriction;
}

int Node::AddForce(Vec2 force)
{
	forces.push_back(force);
	return forces.size() - 1;;
}

void Node::ChangeForce(int id, Vec2 force)
{
	forces[id] = force;
}

void Node::CollisionDetector(Ground ground)
{

}