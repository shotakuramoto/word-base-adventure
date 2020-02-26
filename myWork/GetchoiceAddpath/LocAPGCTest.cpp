#include <iostream>
#include <string>
#include "LocAPGCtest.h"

Locations::Locations(){
	//constructor
	possibleRoute = new int[1];
	NumNPC = -1;
}

Locations::Locations(int *apossible,int aNumNPC){
	//constructor with inputs
	possibleRoute = apossible;
	NumNPC = aNumNPC;
}

int Locations::GetChoice(int num) {
	int input = -1;
	while(input<=0 || input > num){
		std::cout << "Input: ";
		std::cin >> input;
	}
	return input;
}

void Locations::AddPath(int path){
	int *temp = possibleRoute;
	possibleRoute= new int[1];
	for(int i=0;i<size;i++){
		possibleRoute[i] = temp[i];
	}
	possibleRoute[size] = path;
	std::cout << possibleRoute[size] << std::endl;
	size = size+1;
	delete[] temp;
}

//deconstructor
Locations::~Locations(){
	delete[] possibleRoute;
}