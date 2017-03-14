#include "stdafx.h"
#include "Creature.h"
#include "Node.h"


Creature::Creature()
{
}


Creature::~Creature()
{
}

void Creature::Step()
{
	for (Node& n : nodes)
	{
		n.forces = Vec2(0, n.gravity ? n.mass * 0.1 : 0);
	}

	for (Muscle& m : muscles)
	{
		Vec2 force_direction1 = Vec2::Normalize(nodes[m.node2_ID].pos - nodes[m.node1_ID].pos);
		Vec2 force_direction2 = Vec2::Normalize(nodes[m.node1_ID].pos - nodes[m.node2_ID].pos);
		float length = Vec2::Distance(nodes[m.node1_ID].pos, nodes[m.node2_ID].pos);
		float displacement =  length - m.target_length;
		nodes[m.node1_ID].forces += force_direction1  *  m.stiffness * displacement;
		nodes[m.node2_ID].forces += force_direction2  * m.stiffness * displacement;
	}

	for (Node& n : nodes)
	{
		n.CollisionDetector();
		n.acc = n.forces / n.mass;
		n.vel += n.acc;
		n.vel *= n.airFriction;
		n.pos += n.vel;
	}
}

void Creature::AddNode(Node n)
{
	nodes.push_back(n);
}

void Creature::AddMuscle(Muscle m)
{
	muscles.push_back(m);
}
