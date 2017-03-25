#include "stdafx.h"
#include "Creature.h"
#include <random>
#include "Config.h"



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

void Creature::CreateRandom()
{
	int overlapDistance = 5;
	nodes.clear();
	muscles.clear();
	std::mt19937 gen(seed);
	std::uniform_int_distribution<int> distI(min_nodes, max_nodes);
	std::uniform_real_distribution<double> distD(0, 1);

	//todo
	int number_of_nodes = distI(gen);

	distI = std::uniform_int_distribution<int>(min_muscles, max_muscles);
	int number_of_muscles = distI(gen);
	int nodeX, nodeY;
	float size, friction, restitution, mass;
	float target_length, stiffness;

	int nodeId1, nodeId2;

	for (int i = 0; i < number_of_nodes; i++)
	{
		distI = std::uniform_int_distribution<int>(0, max_dimension);
		nodeX = distI(gen);
		nodeY = distI(gen);
		distD = std::uniform_real_distribution<double>(min_size, max_size);
		size = distD(gen);
		distD = std::uniform_real_distribution<double>(min_friction, max_friction);
		friction = distD(gen);
		distD = std::uniform_real_distribution<double>(min_restitution, max_friction);
		restitution = distD(gen);
		distD = std::uniform_real_distribution<double>(min_mass, max_mass);
		mass = distD(gen);
		AddNode(Node(Vec2(nodeX, nodeY), size, friction, restitution, mass, true));
		for (int j = 0; j < number_of_muscles; j++)
		{
			distI = std::uniform_int_distribution<int>(0, number_of_muscles);
			nodeId1 = distI(gen);
			nodeId2 = distI(gen);
			if (nodeId1 == nodeId2)
			{
				continue;
			}
			for (Muscle& m : muscles)
			{
				if ((nodeId1 == m.node1_ID && nodeId2 == m.node2_ID)
					|| (nodeId1 == m.node2_ID && nodeId2 == m.node1_ID))
				{
					break;
					//todo na tam po kusno da triq node
				}
			}
			distD = std::uniform_real_distribution<double>(min_stiffnes, max_stiffness);
			stiffness = distD(gen);
			distD = std::uniform_real_distribution<double>(min_targetL, max_targetL);
			target_length = distD(gen);
			Muscle m = Muscle(nodeId1, nodeId2, stiffness, target_length);
		}
	}

	
}

void Creature::CheckOverlap(Node& node, int overlapDistance)
{
	for (Node& n : nodes)
	{
		#define left (n.pos.x - overlapDistance)
		#define right (n.pos.x + overlapDistance)
		#define top (n.pos.y - overlapDistance)
		#define bottom (n.pos.y + overlapDistance)
		if (left > node.pos.x + overlapDistance
			|| right < node.pos.x - overlapDistance
			|| top > node.pos.y + overlapDistance
			|| bottom < node.pos.y - overlapDistance)
		{
			
		}
	}
}
