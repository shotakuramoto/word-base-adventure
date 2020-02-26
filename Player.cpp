#include <iostream>
#include "Player.h"
#include <string>


Player::Player(){
	axe = false;
	mushroom = false;
	chainsaw = false;
	location = 0;
}

void Player::ChangeLocation(int num){
	location = num;
}

int Player::GetLocation(){
	return location;
}

bool Player::TakeItem(std::string item){
	if(item == "axe"){
		if(axe){
			axe = false;
			return true;
		}
	}
	else if(item == "mushroom"){
		if(mushroom){
			mushroom = false;
			return true;
		}
	}
	else if(item == "chainsaw"){
		if(chainsaw){
			chainsaw = false;
			return true;
		}
	}
	return false;
}

void Player::GiveItem(std::string item){
	if(item == "axe"){
		axe = true;
	}
	else if(item == "mushroom"){
		mushroom = true;
	}
	else if(item == "chainsaw"){
		chainsaw = true;
	}	
}

void Player::PrintInventory()
{
	if(axe)
	{
		std::cout<< "You have a might axe"<<std::endl;
	}
	if(mushroom)
	{
		std::cout<< "You have a mushroom"<<std::endl;
	}
	if(chainsaw)
	{
		std::cout<< "You have a chainsaw"<<std::endl;
	}

	if((!axe) && (!mushroom) && (!chainsaw))
	{
		std::cout<< "There is nothing interest here" <<std::endl;
	}
}