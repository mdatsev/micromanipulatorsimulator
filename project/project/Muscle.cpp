#include "stdafx.h"
#include "Muscle.h"


Muscle::Muscle(int connectionID1, int connectionID2, float stiffness, float target_length) :
	connectionID1(connectionID1), connectionID2(connectionID2), stiffness(stiffness), target_length(target_length)
{
}


Muscle::~Muscle()
{
}