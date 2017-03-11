#pragma once
class Muscle
{
public:
	float target_length;
	float stiffness;
	int connectionID1;
	int connectionID2;
	Muscle(int connectionID1, int connectionID2, float force, float target_length);
	~Muscle();
};

