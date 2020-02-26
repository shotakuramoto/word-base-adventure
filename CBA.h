#ifndef CBA_H
#define CBA_H

#include "Player.h"
#include "Locations.h"

class CBA
{
private:
	int currentChoice;
	Locations **locations;
	Player *player;	
public:
	CBA();
	void Start(); // used to run the game
	int GetCurrentChoice();
	void GetChoice(int options); // used to get users input
	void ChangeLocation(); //used to update players location based on users input
	~CBA();

};
#endif