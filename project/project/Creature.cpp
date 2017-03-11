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
	for (Muscle& m : muscles)
	{
		Vec2 force_direction1 = Vec2::Normalize(nodes[m.connectionID2].pos - nodes[m.connectionID1].pos);
		Vec2 force_direction2 = Vec2::Normalize(nodes[m.connectionID1].pos - nodes[m.connectionID2].pos);
		float distance1 = Vec2::Distance(nodes[m.connectionID1].pos, nodes[m.connectionID2].pos);
		float distance2 = Vec2::Distance(nodes[m.connectionID1].pos, nodes[m.connectionID2].pos);
		nodes[m.connectionID1].AddForce(force_direction1 * m.stiffness * distance1);
		nodes[m.connectionID2].AddForce(force_direction2 * m.stiffness * distance2);
	}

	for (Node& n : nodes)
	{
		n.Step();
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
