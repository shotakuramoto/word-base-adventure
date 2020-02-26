#ifndef NPC_H
#define NPC_H

#include <string>

class NPC{
protected:
	std::string name;
	std::string description;
public:
	NPC();
	NPC(std::string name, std::string description);
	std::string GetName();
	void Compliment(); //currently only output not actual interaction with classes
	void Talk(); // virtual talk for subclass overiding 
	
	~NPC();
};
#endif