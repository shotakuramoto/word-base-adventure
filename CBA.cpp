#include <iostream>
#include <string>
#include "CBA.h"
#include "Locations.h"
#include "Player.h"
#include "NPC.h"
#include "Trader.h"
#include "Forest.h"

CBA::CBA(){ // used to create all game variables could be done by using text document and reading
	currentChoice = -1;
	player = new Player();
	locations = new Locations*[3];
	int *loc = new int[1];
	//TOWN CREATION
	loc[0] = 1;
	NPC **npc = new NPC*[2];
	npc[0] = new NPC("Jeff","just some guy",player);
	npc[1] = new Trader("Jim","wants a mushroom for some reason",player,"chainsaw","mushroom");
	locations[0] = new Locations("Town","a peacefull place",loc,1,npc,2,player);
	//FOREST CREATION
	loc = new int[1];
	npc = new NPC*[1];
	loc[0] = 0;
	npc[0] = new Trader("Jefferson","bored of attemping to cut down a tree with an axe",player,"axe","chainsaw");
	locations[1] = new Forest("Forest","a little scary",loc,1,npc,1,player);
	//CITY CREATION
	loc = new int[1];
	npc = new NPC*[1];
	loc[0] = 1;
	npc[0] = new NPC("Jeffston","he's mocking you for playing this game",player);
	locations[2] = new Locations("City","a place to be bullied",loc,1,npc,1,player);
}

void CBA::Start(){ // main game
	std::string State = "";
	std::cout << "Welcome" << std::endl;
	while(!(State == "end")){//will end if user selects exit

		/////output options/////////
		std::cout << "What would you like to do" << std::endl;
		std::cout << "1: See what I can do here" << std::endl;
		std::cout << "2: Go somewhere else" << std::endl;
		std::cout << "3: Check Inventory" << std::endl;
		std::cout << "4: exit" << std::endl;


		GetChoice(4);//get users input
		switch(currentChoice){
			case 1://go to locations options
				locations[player->GetLocation()]->Choice();
				break;
			case 2://change location 
				ChangeLocation();
				break;
			case 3://print what the player has in their inventory
				player->PrintInventory();
				break;
			case 4://end game
				State = "end";
				break;
			default: //end game
				State = "end";
				break;
		}

	}
	std::cout << "Finished" << std::endl;
}

int CBA::GetCurrentChoice(){
	return currentChoice;
}

void CBA::GetChoice(int options){
	int input = -1;//set to -1 to get into while loop
	while(input<=0 || input > options){//ristric users input from 0 to the number of options
		std::cout << "Input: "; 
		std::cin >> input;
		if((input<=0 || input > options)){
			std::cout << "Please Enter within the range 0 to "<< options << std::endl;
		}
	}
	currentChoice = input; //used so dont need to declare new variable each time
}

void CBA::ChangeLocation(){ 
	int current = player->GetLocation();//get the current location index
	int *pos = locations[current]->GetPossibleRoute(); // get the possible location index
	int size = locations[current]->GetSize(); // get the size of the possible location index
	Locations *temp; 
	for(int i=0;i<size;i++){
		std::cout << (i+1) << ": ";
		temp = locations[pos[i]];
		std::cout << temp->GetName() << std::endl;//print the name of each location and give each a number for the user to select
	}
	std::cout << size+1 << ": Exit" << std::endl;// add extra option for to leave
	GetChoice(size+1);//get the users input
	if((currentChoice-1)<size){
		player->ChangeLocation(pos[currentChoice-1]);//check if the user didnt want to exit
	}
}

CBA::~CBA(){//delete any memeory in heap 
	delete player;
	delete[] locations;
}
