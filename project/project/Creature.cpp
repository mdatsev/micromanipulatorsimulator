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
		Vec2 force_direction1 = Vec2::Normalize(nodes[m.node2_ID].pos - nodes[m.node1_ID].pos);
		Vec2 force_direction2 = Vec2::Normalize(nodes[m.node1_ID].pos - nodes[m.node2_ID].pos);
		float length = Vec2::Distance(nodes[m.node1_ID].pos, nodes[m.node2_ID].pos);
		float displacement = (length - m.target_length);
		nodes[m.node1_ID].ChangeForce(m.node1_ForceID, force_direction1  *  m.stiffness * displacement);
		nodes[m.node2_ID].ChangeForce(m.node2_ForceID, force_direction2  * m.stiffness * displacement);
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
	m.node1_ForceID = nodes[m.node1_ID].AddForce(Vec2());
	m.node2_ForceID = nodes[m.node2_ID].AddForce(Vec2());
	muscles.push_back(m);
}
