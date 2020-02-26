#include <iostream>
#include <string>
#include "Player.h"

using namespace std;

int main(){
	Player test;
	
	string item1;
	string item2;
	string item3;
	
	cin >> item1;
	cin >> item2;
	cin >> item3;
	
	
	test.GiveItem(item1);
	test.GiveItem(item2);
	test.GiveItem(item2);
	
	if(test.TakeItem(item1)){
		cout << "took item " << item1 << endl; 
	}
	else{
		cout << "either it did not work or " << item1 << " is not an item" << endl;
	}
	
	if(test.TakeItem(item2)){
		cout << "took item " << item2 << endl; 
	}
	else{
		cout << "either it did not work or " << item2 << " is not an item" << endl;
	}
	
	if(test.TakeItem(item3)){
		cout << "took item " << item3 << endl; 
	}
	else{
		cout << "either it did not work or " << item3 << " is not an item" << endl;
	}
	

	return 1;
}