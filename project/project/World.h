#pragma once
#include <list>
#include "Node.h"
class World
{
	std::list<Node> nodes;
public:
	World();
	~World();
	void AddNode(Node);
	void Draw(HDC, RECT);
	void Step();
};

