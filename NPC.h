#ifndef NPC_H
#define NPC_H

#include "Player.h"
#include <string>

class NPC{
protected:
	std::string name;
	std::string description;
	Player *player;
public:
	NPC();
	NPC(std::string name, std::string description, Player *player);
	void Description();//print the description
	std::string GetName(); // return the name
	void Annoy(); //currently only output not actual interaction with classes
	void Compliment(); // "" ""
	int GetInput(int max); // get the users input
	virtual void Talk(); // virtual talk for subclass overiding 
	
	~NPC();
};
#endif