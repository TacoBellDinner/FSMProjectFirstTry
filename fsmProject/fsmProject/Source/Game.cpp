#include "headers/Game.h"
#include "headers/PartnerStates.h"
#include <iostream>
#include <string>
#include <vector>
#include "Windows.h"

using namespace std;

Game::Game()
{
	/*
	Initializes the game.
	*/

	//First, the player and partner.
	//they'll both start with this much HP
	const int startingHp = 160;

	//set the pointers to zero so they can be passed into functions
	player = 0;
	partner = 0;

	//now have those pointers point to actual objects!
	player = new Player(this, partner, startingHp);
	partner = new Partner(this, player, startingHp, Idle::instance());

	//now, initialize the other values
	enemiesNear = false;
	healThresh = 0.50;

}

void Game::play()
{
	/*Executes the main game loop.*/

	//go through a lot of cycles
	const int cycles = 30;

	//set up how much of their max hp in damage the player 
	//will take each cycle
	const float hurt = 0.2;
	const int damageTaken = player->maxHealth * hurt;

	const int pause = 800; 
	//how long the pause between messages will be (in milliseconds)

	for (int i = 0; i < cycles; i++)
	{
		//have enemy attack the player
		cout << "\nPlayer got bit by a goblin! Player takes " << damageTaken << " HP of damage.";
		player->takeDamage(damageTaken);
		Sleep(pause);

		//have the AI act based on their current state

		partner->update();
		Sleep(pause);
	}

}