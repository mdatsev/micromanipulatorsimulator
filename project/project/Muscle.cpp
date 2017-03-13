#include "stdafx.h"
#include "Muscle.h"


Muscle::Muscle(int connectionID1, int connectionID2, float stiffness, float target_length) :
	node1_ID(connectionID1), node2_ID(connectionID2), stiffness(stiffness), target_length(target_length)
{
}


Muscle::~Muscle()
{
}