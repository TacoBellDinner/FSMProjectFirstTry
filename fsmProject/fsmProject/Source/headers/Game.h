/*
Serves as a sort of game controller class, while also encompassing the game
itself.

Author: Gabriel Cabrera
*/
#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "Player.h"
#include "Partner.h"
#include "Enemy.h"

using namespace std;

class Game
{
public:

	//member var declarations
	Player* pPlayer;
	Partner* pPartner;
	Enemy* pEnemy;
	
	bool enemiesNear;
	float healThresh; 
	//^when player health below this percentage, prompt healing
	//from the ai

	//member function prototypes
	Game();
	void setupCharacters();
	void play();


};

#endif
