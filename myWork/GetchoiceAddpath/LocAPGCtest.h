#ifndef LOCATIONTEST_H
#define LOCATIONTEST_H

#include <string>

class Locations {
protected:
	int *possibleRoute;
	int NumNPC;
	int size = 1;
public:
	Locations(); //constructor
	Locations(int *apossible,int NumNPC); //constructor with input

	int GetChoice(int num); //get choice;
	void AddPath(int path);

	~Locations(); //deconstructor
};
#endif