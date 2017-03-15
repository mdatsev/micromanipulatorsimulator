#pragma once
#include <vector>
#include "Creature.h"

class World
{
	std::vector<Creature> creatures;
public:
	static Ground* ground;
	World();
	~World();
	void AddCreature(Creature);
	void Draw(HDC, RECT, bool = false);
	void Step(float dt);
};

