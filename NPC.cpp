#include <iostream>
#include <string>
#include "NPC.h"
#include "Player.h"


NPC::NPC(){
	name = "?";
	description = "?";
}

NPC::NPC(std::string name_, std::string description_, Player *player_){
	name = name_;
	description = description_;
	player = player_;
}

void NPC::Description(){ // simple print out
	std::cout << name << ", " << description << std::endl;
}

std::string NPC::GetName(){ 
	return name;
}

void NPC::Annoy(){ // simple print out
	std::cout << "You annoy " << name << ", " << name << " doesn't like that." << std::endl;
}

void NPC::Compliment(){ // simple print out
	std::cout << "You Compliment " << name << ", " << name << " likes that" << std::endl;
}

int NPC::GetInput(int max){ //getting restricted input and returning
	int current = -1;
	while (current<=0 || current > max){
		std::cout << "input: ";
		std::cin >> current;
		if(current<=0 || current > max){
			std::cout << "Please Enter within the range 0 to "<< max << std::endl;
		}
	}
	return current;
}

void NPC::Talk(){ // giving users option
	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1: Annoy " << name << std::endl;
	std::cout << "2: Compliment " << name << std::endl;
	std::cout << "3: leave " << name << " alone" << std::endl;
	int current = GetInput(3);
	switch(current){
		case 1:
			Annoy();
			break;
		case 2:
			Compliment();
			break;
		case 3:
			break;
		default:
			break;
	}
}
	
NPC::~NPC(){
	delete player;
}

