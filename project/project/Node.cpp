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

void Node::CollisionDetector(Ground ground)
{

}