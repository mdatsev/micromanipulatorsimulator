#pragma once
#include <vector>
#include "Creature.h"

class World
{
	std::vector<Creature> creatures;
public:
	bool simulation_running;
	static Ground* ground;
	World();
	~World();
	void StartSimulation();
	void StopSimulation();
	void AddCreature(Creature);
	void Draw(HDC, RECT, bool = false);
	void Integrate(float dt);
};