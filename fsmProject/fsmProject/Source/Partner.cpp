#include "headers/Partner.h"
#include "headers/PartnerStates.h"
#include "headers/Game.h"
#include "assert.h"
#include <algorithm>

using namespace std;

//constructors
Partner::Partner() {};

Partner::Partner(
				Game* game,
				Player* partneredTo, 
				int health, 
				State* start)
{
	/*
	Initializes the Partner object.
	
	game - pointer to the game object
	partneredTo - pointer to the Player object this AI is partnered to.
	health - how much health the AI starts with.
	start - state that this AI will start in. Will be set to a default
	state if nothing is passed to it.

	*/

	//initialize pointers to the game object, player, and current state
	pGame = game;
	pPlayer = partneredTo;

	//set to default if necessary
	if (start == 0)
	{
		pCurrState = Passive::instance();
		pBeforeFight = pCurrState;
		//^record that this AI was passive before any combat
	}
	else
		pCurrState = start;

	//our partner starts in top condition
	maxHealth = health;
	currHealth = maxHealth;

	//and with an inventory full of potions!
	pInventory = new vector<string>;

	for (int i = 0; i < 10; i++)
		pInventory->push_back("potion");

	canHeal = true;
	onCommand = false;
	onSpotPass = false; //no orders to be passive on enemy-spotting, yet
	atDest = true;
	openedEntity = false;

	strength = 20;
	
}

void Partner::changeState(State* newState)
{
	/*
	Alters the AI's behavior by changing its state.
	*/

	//make sure both states are valid
	assert (pCurrState && newState);

	//exit the current state, record it as the previous state
	pCurrState->exit(this); 
	pPrevState = pCurrState;

	//change state to new state, call its entry method
	pCurrState = newState;
	pCurrState->enter(this);
}

void Partner::takeCommand(State* newState)
{
	/*
	When player sends a command, process it. This covers all parts of the flowchart
	that have state-changing done on player command.
	*/

	onCommand = true; 
	//make sure the ai sticks to the command 
	//until the player decides otherwise

	changeState(newState);
}

void Partner::heal()
{
	//makes the ai heal the player, if the AI has any potions left to use
	bool hasPotions = ( find(pInventory->begin(), 
						pInventory->end(), 
						"potion") 
						!= pInventory->end());

	if (hasPotions)
	{
		pPlayer->currHealth += 20;
	}
	else //if the ai cant heal, then return to whatever was the previous state
	{
		canHeal = false;
		changeState(pPrevState);
	}
}

void Partner::update()
{
	/*
	AI's normal behavior
	*/

	//Automatically switch states when necessary, provided
	//this AI isnt busy with something the Player commanded
	if (!onCommand)
	{

	}

	pCurrState->execute(pGame, this);

}

bool Partner::needHealPlayer()
{
	// if the player's hp is too low, switch to the Heal state
	int playerHp = pPlayer->currHealth;
	int playerMax = pPlayer->maxHealth;

	// check the current-to-max ratio of the HP to determine if healing is
	// neeeded
	float hpPercent = 1.0 * (playerHp / playerMax);
	bool tooLow = (hpPercent < pGame->healThresh);

	if (tooLow)
		return true;
	else
		return false;
}

void Partner::attackEnemy()
{
	/*
	Inflicts damage to current target.
	*/

	pTarget->takeDamage(strength);
}
