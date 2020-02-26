#ifndef TRADER_H
#define TRADER_H

#include <string>
#include "Player.h"
#include "NPC.h"

class Trader: public NPC{
private:
	std::string item; // item they have
	std::string desire; // item they will give
public:
	Trader();
	Trader(std::string name, std::string description, Player *player, std::string item,std::string desire);
	void Talk(); //options for user
	void Trade(); // ability to trade
};
#endif