#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <string>
#include "Locations.h"

class Forest : public Locations
//the subclass of the location
{
public:
	//constructor
	Forest();
	Forest(std::string aName,std::string aDescriptions,int *apossible,int asize,NPC **anpc,int aNumNPC,
Player *aplayer);
	void Choice(); //get choice
	void Mushroom(); //pick up mushroom
	void Tree(); //allow new area to access

	~Forest(); //deconstuctor
};

#endif //FOREST_H