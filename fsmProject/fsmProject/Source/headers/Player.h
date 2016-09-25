#ifndef PLAYER_H
#define PLAYER_H

#include "Fighter.h"
#include "Partner.h"
#include "Game.h"
#include <string>
#include <vector>

class Player : public Fighter
{
public:

	//member var declarations
	Partner* pPartner; //pointer to companion
	Game* pGame; //pointer to game object

	bool isFighting;
	bool healthyEnough;

	//member function prototypes
	Player();
	Player(Game* game, Partner* partner, int health = 100);
	
	virtual void update();
	
};

#endif