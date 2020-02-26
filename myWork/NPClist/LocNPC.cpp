#include <iostream>
#include <string>
#include "LocNPC.h"
#include "NPCtest.h"

Locations::Locations(){
	//constructor
	name = "?";
	description = "?";
	size = -1;
	possibleRoute = new int[1];
	NumNPC = 2;
	npc = new NPC*[1];
}

Locations::Locations(std::string aName,std::string aDescriptions,int *apossible,int asize,NPC **anpc,int aNumNPC){
	//constructor with inputs
	name = aName;
	description = aDescriptions;
	possibleRoute = apossible;
	size = asize;
	npc = anpc;
	NumNPC = aNumNPC;
}

void Locations::setNPC() {
	npc = new NPC* [1];
	npc[0] = new NPC("James","just some guy");
	npc[1] = new NPC("Tim","he's mocking you for playing this game");
}

int Locations::GetChoice(int num) {
	int input = -1;
	while(input<=0 || input > num){
		std::cout << "Input: ";
		std::cin >> input;
	}
	return input;
}

void Locations::NPCList() {
	std::cout << "start" << std::endl;
	for(int i=0;i<NumNPC;i++){
		std::cout << (i+1) << ": " << npc[i]->GetName() <<std::endl;
	}
	std::cout << (NumNPC+1) << ": back" << std::endl;
	int temp = (GetChoice(NumNPC+1)-1);
	if(temp == NumNPC){
		std::cout << "You go back to do somthing else" << std::endl;
	}
	else{
		npc[temp]->Talk();
	}
}

//deconstructor
Locations::~Locations(){
}