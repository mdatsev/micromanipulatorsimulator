#include "stdafx.h"
#include "Creature.h"
#include "Node.h"


Creature::Creature()
{
}


Creature::~Creature()
{
}

void Creature::AddNode(Node n)
{
	nodes.push_back(n);
}

void Creature::AddMuscle(Muscle m)
{
	muscles.push_back(m);
}
