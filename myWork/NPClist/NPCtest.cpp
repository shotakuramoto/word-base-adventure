#include <iostream>
#include <string>
#include "NPCtest.h"

NPC::NPC(){
	name = "?";
	description = "?";
}

NPC::NPC(std::string name_, std::string description_){
	name = name_;
	description = description_;
}

std::string NPC::GetName(){ 
	return name;
}

void NPC::Compliment(){ // simple print out
	std::cout << "You Compliment " << name << ", " << name << " likes that" << std::endl;
}

void NPC::Talk(){ // giving users option
	Compliment();
}
	
NPC::~NPC(){
}