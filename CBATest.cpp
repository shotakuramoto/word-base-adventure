#include <iostream>
#include <string>
#include "CBA.h"

int main(){
	CBA test;
	
	int size;
	
	std::cin >> size;
	
	test.GetChoice(size);
	std::cout << test.GetCurrentChoice() << std::endl;
	
	
	return 1;
}