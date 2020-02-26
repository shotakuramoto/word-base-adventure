#include <iostream>
#include <string>
#include "Locations.h"
#include "Player.h"
#include "NPC.h"
#include "Trader.h"

Locations::Locations(){
	//constructor
	name = "?";
	description = "?";
	size = -1;
	possibleRoute = new int[1];
	NumNPC = -1;
	npc = new NPC*[1];
	player = new Player();
}

Locations::Locations(std::string aName,std::string aDescriptions,int *apossible,int asize,NPC **anpc,int aNumNPC,Player *aplayer){
	//constructor with inputs
	name = aName;
	description = aDescriptions;
	possibleRoute = apossible;
	size = asize;
	npc = anpc;
	NumNPC = aNumNPC;
	player = aplayer;
}

int Locations::GetChoice(int num) {
	int input = -1;
	while(input<=0 || input > num){
		std::cout << "Input: ";
		std::cin >> input;
	}
	return input;
}

void Locations::GetDescription(){
	//below is the actual program
	std::cout << "You are in " << name << ", " << description << std::endl;

	//below is test program
	//std::cout <<  Description <<std::endl;
}

std::string Locations::GetName(){
	//return the name
	return name;
}

int * Locations::GetPossibleRoute(){
	//return the route
	return possibleRoute;
}

int Locations::GetSize(){
	//return the size of possible route
	return size;
}

void Locations::AddPath(int path){
	int *temp = possibleRoute;
	possibleRoute = new int[size+1];
	for(int i=0;i<size;i++){
		possibleRoute[i] = temp[i];
	}
	possibleRoute[size] = path;
	size = size+1;
	delete[] temp;
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

void Locations::Choice() {
	/////output options/////////
	std::cout << "What would you like to do" << std::endl;
	std::cout << "1: Check Where you are" << std::endl;
	std::cout << "2: Check any people in your area" << std::endl;
	std::cout << "3: exit" << std::endl;

	int temp = GetChoice(3); //get the input from the player

	//go through the switch statement
	switch(temp){
		case 1:
			//get the area discription
			GetDescription();
			break;
		case 2:
			//trigger the npc
			NPCList();
			break;
		case 3:
			break;
		default:
			break;
	}
}

//deconstructor
Locations::~Locations(){
	delete[] possibleRoute,npc;
	delete player;
}