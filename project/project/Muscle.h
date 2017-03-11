#pragma once
class Muscle
{
public:
	float target_length;
	float force;
	int connectionID1;
	int connectionID2;
	Muscle(int connectionID1, int connectionID2);
	~Muscle();
};

