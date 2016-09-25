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

using namespace std;

class Game
{
public:

	//member var declarations
	Player* player;
	Partner* partner;

	bool enemiesNear;
	float healThresh; 
	//^when player health below this percentage, prompt healing
	//from the ai

	//member function prototypes
	Game();
	void play();


};

#endif