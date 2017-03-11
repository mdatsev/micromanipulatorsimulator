#include "stdafx.h"
#include "Creature.h"
#include "Node.h"


Creature::Creature()
{
}

Creature::Creature(Node n)
{
	nodes.push_back(n);
}


Creature::~Creature()
{
}

void Creature::Step()
{
	for (Node& n : nodes)
	{
		n.Step();
	}
}
