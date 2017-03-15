#pragma once
class Muscle
{
public:
	float target_length;
	float stiffness;
	int node1_ID;
	int node2_ID;
	int node1_ForceID;
	int node2_ForceID;
	Muscle(int connectionID1, int connectionID2, float stiffness, float target_length);
	~Muscle();
};

