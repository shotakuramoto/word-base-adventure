#include <iostream>
#include <string>
#include "NPC.h"
#include "Player.h"


int main(){
	NPC test;

	int size;
	
	std::cin >> size;
	
	std::cout << test.GetInput(size);
	
	
	
	return 1;
}