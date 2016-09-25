#include "headers/Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//constructors
Player::Player()
{}

Player::Player(Game* game, Partner* partner, int health)
{
	/* 
	Initializes the Player object.
	
	game - pointer to the game object
	partner - pointer to the AI companion assigned to this player
	health - how much health the player starts off having
	*/

	//setup pointers to the game and partner
	pGame = game;
	pPartner = partner;

	//setup the health
	maxHealth = health;
	currHealth = maxHealth;

	//player starts out healthy enough and not fighting
	healthyEnough = true;
	isFighting = false;

	inventory = new vector<string>;
	
}

void Player::update()
{
	/*Updates player status depending on what's going on*/

	//when current health is above a threshold, the player is healthy enough
	healthyEnough = ((1.0 * currHealth / maxHealth) > pGame->healThresh);

	//is considered to be fighting when enemies are near, even though in this build,
	// the player is just a punching bag
	isFighting = pGame->enemiesNear;

	//make sure current health isnt above max health
	if (currHealth > maxHealth)
		currHealth = maxHealth;

}