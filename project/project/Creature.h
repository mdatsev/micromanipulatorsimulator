#pragma once
#include "Node.h"
#include <vector>

class Creature
{
public:
	std::vector<Node> nodes;
	Creature();
	Creature(Node n);
	~Creature();
	void Step();
};

