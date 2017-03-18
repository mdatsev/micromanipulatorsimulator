#pragma once
class Muscle
{
public:
	double target_length;
	double stiffness;
	int node1_ID;
	int node2_ID;
	int node1_ForceID;
	int node2_ForceID;
	Muscle(int connectionID1, int connectionID2, double stiffness, double target_length);
	~Muscle();
};

