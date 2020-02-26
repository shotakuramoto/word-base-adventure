#include <iostream>
#include <string>
#include "Player.h"
#include "NPC.h"
#include "Trader.h"

Trader::Trader():NPC(){
	item = "?";
	desire = "?";
}
Trader::Trader(std::string name, std::string description, Player *player, std::string items_,std::string desire_):NPC(name,description,player){
	item = items_;
	desire = desire_;
}

void Trader::Talk(){ // options for user
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1: Annoy " << name << std::endl;
	std::cout << "2: Compliment " << name << std::endl;
	std::cout << "3: Trade" << std::endl;
	std::cout << "4: leave " << name << " alone" << std::endl;
	int current = GetInput(4);
	switch(current){
		case 1:
			Annoy();
			break;
		case 2:
			Compliment();
			break;
		case 3:
			Trade();
			break;
		case 4:
			break;
		default:
			break;
	}
}

void Trader::Trade(){
	//give option for user to trade
	std::cout << "Would you like to trade a " << desire << " with a " << item << std::endl;
	std::cout << "1: Yes" << std::endl;
	std::cout << "2: No" << std::endl;
	int current = GetInput(2);
	switch(current){
		case 1:
			if(player->TakeItem(desire)){//check if user has item then remove it
				player->GiveItem(item); // give npc item
			}
			else{
				std::cout << "You do not have this item" << std::endl;
			}
			break;
		case 2:
			break;
		default:
			break;
	}
}
