#ifndef LOCATIONS_H
#define LOCATIONS_H

#include <string>
#include "NPC.h"
#include "Player.h"

class Locations {
protected:
	std::string name; //name of location
	std::string description; //description of it
	int size; //use to give options
	int *possibleRoute; //used in possible route function
	NPC **npc; //npc polymorphism
	int numNPC; //number of npc in location
	Player *player;
public:
	Locations(); //constructor
	Locations(std::string aName,std::string aDescriptions,int *apossible,int asize,NPC **npc,int NumNPC,Player *player); //constructor with input
	int GetChoice(int num); //get choice;
	void GetDescription(); //return discription
	std::string GetName(); //return the name of the location
	int * GetPossibleRoute(); //get possible route
	int GetSize(); //get the size
	void AddPath(int path);
	void NPCList(); //talk to any given NPC
	virtual void Choice(); //choice to interact with several options

	~Locations(); //deconstructor
};
#endif