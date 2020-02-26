#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <string>
#include "NPCtest.h"

class Locations {
protected:
	std::string name;
	std::string description;
	int size;
	int *possibleRoute;
	NPC **npc;
	int NumNPC;
public:
	void setNPC();
	Locations(); //constructor
	Locations(std::string aName,std::string aDescriptions,int *apossible,int asize,NPC **npc,int NumNPC); //constructor with input
	void NPCList(); //talk to any given NPC
	int GetChoice(int num);
	void setNPC();
	~Locations(); //deconstructor
};
#endif