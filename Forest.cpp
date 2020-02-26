#include <string>
#include <iostream>
#include "Locations.h"
#include "Forest.h"
#include "NPC.h"
#include "Player.h"

//constructor
Forest::Forest():Locations(){
	
}

Forest::Forest(std::string aName,std::string aDescriptions,int *apossible,int asize,NPC **anpc,int aNumNPC,
Player *aplayer):Locations(aName, aDescriptions,apossible,asize,anpc,aNumNPC,aplayer) {

}

void Forest::Choice() {
	/////output options/////////
	std::cout << "What would you like to do" << std::endl;
	std::cout << "1: Check Where you are" << std::endl;
	std::cout << "2: Check any people in your area" << std::endl;
	std::cout << "3: Collect mushroom" << std::endl;
	std::cout << "4: Chop Tree" << std::endl;
	std::cout << "5: exit" << std::endl;

	int temp = GetChoice(5); //get the input from the player

	//go through the switch statement
	switch(temp){
		case 1:
			//get the area discription
			GetDescription();
			break;
		case 2:
			//trigger the npc
			std::cout << "start" << std::endl;
			NPCList();
			break;
		case 3:
			//change the location
			Mushroom();
			break;
		case 4:
			//change the location
			Tree();
			break;
		case 5:
			break;
		default:
			break;
	}
}

//give user to pick up the mushroom or not
void Forest::Mushroom() {
	//output the choice
	std::cout << "You see a mushroom on the ground, do you pick it up?" << std::endl;
	std::cout << "1: Yes" << std::endl;
	std::cout << "2: No" << std::endl;
	
	//get choice from the player
	int temp = GetChoice(2);

	//triger funtion depend on input
	switch(temp){
		case 1: 
			player->GiveItem("mushroom");
			break;
		case 2:
			break;
		default:
			break;
	}

}

//to unlock new area
void Forest::Tree(){
	//give options
	std::cout << "Would you like to chop down the tree, you will destroy your axe" << std::endl;
	std::cout << "1: Yes" << std::endl;
	std::cout << "2: No" << std::endl;
	int temp = GetChoice(2);
	switch(temp){
		case 1:
			//if player chose this, unlock the city area
			if(player->TakeItem("axe")){
				std::cout << "you chop the tree, you mighty axe is no more" << std::endl;
				AddPath(2);
			}
			else{
				//if player don't have axe, return this
				std::cout << "You do not have this item, for some reason you need an axe" << std::endl;
			}
			break;
		case 2:
			break;
		default:
			break;
	}
}

//deconstructor
Forest::~Forest() {
}