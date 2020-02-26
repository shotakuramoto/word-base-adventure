#ifndef PLAYER_H
#define PLAYER_H

#include <string>


class Player{
private:
	bool axe;
	bool mushroom; // “mushroom”
	bool chainsaw; // “chainsaw”
	int location;
public:
	Player();
	void ChangeLocation(int num);
	int GetLocation();
	bool TakeItem(std::string item);
	void GiveItem(std::string item);
	void PrintInventory();
};
#endif