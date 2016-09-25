/*
Sets up the properties of the AI partner.

Author: Gabriel Cabrera, Mat Buckland
*/
#ifndef PARTNER_H
#define PARTNER_H
//^header guards

//includes
#include <string>
#include <vector>
#include "Fighter.h"
#include "State.h"
#include "Game.h"
#include "Player.h"

using namespace std;

class Partner : public Fighter
{
public:
	//member var declarations

	//pointers to the current and previous states the AI was in
	State*					pCurrState;
	State*					pPrevState;
	State*					pBeforeFight;

	//also need a pointer to the player object, so the partner
	//can do stuff like heal the player
	Player*					pPlayer; 
	
	Game*					pGame;
	
	//^ percentage threshold health can drop before prompting heals

	bool					onCommand; 
	/* ^
	When this is true, the ai cant change to other states automatically.
	This makes sure the AI carries out its current player command until
	it is either done or the player sends another command.
	
	When this is false, it changes state automatically based on certain
	parameters.
	*/

	bool canHeal; //makes sure not to get to the heal state when unable to heal
	bool onSpotPass; //whether or not to be passive when an enemy is spotted

	//member function prototypes
	//constructors
	Partner();
	Partner(Game* game,
			Player* partneredTo, 
			int health = 100, 
			State* start = 0 );

	//functions
	virtual void update();
	virtual void changeState(State* newState);
	virtual void takeCommand(State* newState);
	virtual bool needHealPlayer();
	virtual void heal();
	virtual void attackEnemy();
	virtual void update();

	
};

#endif