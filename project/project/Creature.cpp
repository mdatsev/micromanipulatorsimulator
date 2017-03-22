#include "stdafx.h"
#include "Creature.h"


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

void Creature::CreateRandom(int min_nodes, int max_nodes, double max_dimension, int min_muscles, int max_muscles)
{
	nodes.clear();
	muscles.clear();
	//todo
}
