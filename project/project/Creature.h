#pragma once
#include "Node.h"
#include "Muscle.h"
#include <vector>

class Creature
{
public:
	std::vector<Node> nodes;
	std::vector<Muscle> muscles;
	Creature();
	~Creature();
	void AddNode(Node);
	void AddMuscle(Muscle);
	void CreateRandom(int min_nodes, int max_nodes, double max_dimension, int min_muscles, int max_muscles);
};

