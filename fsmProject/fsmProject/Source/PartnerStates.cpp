/*
Defines things like how the states can switch.

Author: Gabriel Cabrera

*/
#include "headers/PartnerStates.h"
#include "headers/Partner.h"
#include "headers/Player.h"
#include <iostream>

using namespace std;

// for now, just have transition messages be sent for the 
// enter, exit, and execute functions.

Passive* Passive::instance()
{
	static Passive stateInst;
	return &stateInst;
}

void Passive::enter(Game* game, Partner* partner)
{
	cout << "\nEntering Passive State.";
}

void Passive::exit(Game* game, Partner* partner)
{
	cout << "\nExiting Passive State.";
}

void Passive::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in Passive state.";

	// All the AI does in Passive mode is be around the player until prompted
	// to switch states, so...
	adapt(game, partner);
	
}

void Passive::adapt(Game* game, Partner* partner)
{
	/*
	Makes the partner AI switch to a different state based on
	what's going on at the moment.

	*/

	//no conditions of whether the partner is on command; they do the same
	//thing, regardless

	//heal the player when they need it
	if (partner->needHealPlayer)
		partner->changeState(Heal::instance());

	///////////////////

	// if player is attacking, join him
	if (partner->pPlayer->isFighting)
	{
		partner->changeState(Attack::instance());
		return;
	}
		
	
}


// // // // // // // // // // // // // // // // // // // // /

Attack* Attack::instance()
{
	static Attack stateInst;
	return &stateInst;
}

void Attack::enter(Game* game, Partner* partner)
{
	cout << "\nEntering Attack State.";
}

void Attack::exit(Game* game, Partner* partner)
{
	cout << "\nExiting Attack State.";
}

void Attack::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in Attack state.";
}

void Attack::adapt(Game* game, Partner* partner)
{
	// when not on command, follow the rules for automatic switching
	if (!partner->onCommand)
	{
		//heal the player when they need it
		if (partner->needHealPlayer())
			partner->changeState(Heal::instance());

		//switch to DefAgg when there are no enemies left in range
		else if (!game->enemiesNear)
			partner->changeState(DefAgg::instance());

		else //just attack enemies
			partner->attackEnemy();

	}
	else //when on command, simply attack enemies
		partner->attackEnemy();
	

}
// // // // // // // // // // // // // // // // /

DefAgg* DefAgg::instance()
{
	static DefAgg stateInst;
	return &stateInst;
}

void DefAgg::enter(Game* game, Partner* partner)
{
	cout << "\nEntering DefAgg State.";
}

void DefAgg::exit(Game* game, Partner* partner)
{
	cout << "\nExiting DefAgg State.";
}

void DefAgg::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in DefAgg state.";
}

void DefAgg::adapt(Game* game, Partner* partner)
{
	if (!partner->onCommand) //following automatic rules
	{ 
		//when enemies are in range, attack
		if (game->enemiesNear)
		{
			partner->changeState(Attack::instance());
			return; //do nothing else
		}

		//when enemies are out of range and was passive before combat,
		//switch back to passive
		bool switchPassive = ((game->enemiesNear == false) && 
							(partner->pPrevState == Passive::instance()));

		if (switchPassive)
			partner->changeState(Passive::instance());

	}
}

// // // // // // // // // // // // // // // // // /

Heal* Heal::instance()
{
	static Heal stateInst;
	return &stateInst;
}

void Heal::enter(Game* game, Partner* partner)
{
	cout << "\nEntering Heal State.";
}

void Heal::exit(Game* game, Partner* partner)
{
	cout << "\nExiting Heal State.";
}

void Heal::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in Heal state.";
}

void Heal::adapt(Game* game, Partner* partner)
{
	//when player health is above a threshold and there are still enemies,
	//go back to attacking
	bool toAttack = (game->enemiesNear && partner->pPlayer->healthyEnough);

	//when player's health is above a threshold and there are no enemies left,
	//switch back to Passive or DefAgg, whichever was the previous state before 
	//combat
	bool switchBack = ((game->enemiesNear == false) && (partner->pPlayer->healthyEnough);

	//otherwise, just keep healing

	//act on which of the condiitons are true
	if (toAttack)
	{
		partner->changeState(Attack::instance());
	}
	else if (switchBack)
	{
		partner->changeState(partner->pBeforeFight);
	}
	else
	{
		partner->heal();
	}




}


// // // // // // // // // // // // // // // 

Stealth* Stealth::instance()
{
	static Stealth stateInst;
	return &stateInst;
}

void Stealth::enter(Game* game, Partner* partner)
{
	cout << "\nEntering Stealth State.";
}

void Stealth::exit(Game* game, Partner* partner)
{
	cout << "\nExiting Stealth State.";
}

void Stealth::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in Stealth state.";
}

void Stealth::adapt(Game* game, Partner* partner)
{
	//stealth can only switch to another state through command
	//(at the timne of this writing), so this function
	//does nothing.
}

// // // // // // // // // // // // // // // // // // 

Exploratory* Exploratory::instance()
{
	static Exploratory stateInst;
	return &stateInst;
}

void Exploratory::enter(Game* game, Partner* partner)
{
	cout << "\nEntering Exploratory State.";
}

void Exploratory::exit(Game* game, Partner* partner)
{
	cout << "\nExiting Exploratory State.";
}

void Exploratory::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in Exploratory state.";
}

void Exploratory::adapt(Game* game, Partner* partner)
{
	//exploratory can only switch to another state through command
	//(at the timne of this writing), so this function
	//does nothing.
}

// // // // // // // // // // // // // // // // // /

Idle* Idle::instance()
{
	static Idle stateInst;
	return &stateInst;
}

void Idle::enter(Game* game, Partner* partner)
{
	cout << "\nEntering Idle State.";
}

void Idle::exit(Game* game, Partner* partner)
{
	cout << "\nExiting Idle State.";
}

void Idle::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in Idle state.";
}

void Idle::adapt(Game* game, Partner* partner)
{
	//Treating "On Detect enemy" the same as enemies just being near, in this 
	// build.

	//when an enemy is detected and was ordered to be Passive when it happens,
	//switch to Passive
	//otherwise, switch to DeffAgg

	bool enemySpotted = (game->enemiesNear);
	bool toPassive = (enemySpotted && partner->onSpotPass);
	bool toDefAgg = (enemySpotted && (!partner->onSpotPass));

	if (toPassive)
	{
		partner->changeState(Passive::instance());
	}
	else if (toDefAgg)
	{
		partner->changeState(DefAgg::instance());
	}
}

// // // // // // // // // // // // // // /

GoTo* GoTo::instance()
{
	static GoTo stateInst;
	return &stateInst;
}

void GoTo::enter(Game* game, Partner* partner)
{
	cout << "\nEntering GoTo State.";
}

void GoTo::exit(Game* game, Partner* partner)
{
	cout << "\nExiting GoTo State.";
}

void GoTo::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in GoTo state.";
}

void GoTo::adapt(Game* game, Partner* partner)
{
	//when the ai is at its destination, switch it to Idle
	if (partner->atDest)
	{
		partner->changeState(Idle::instance());
	}

	//pretend there is code here for otherwise traveling :p
}
// // // // // // // // // // // // // // // // 

Open* Open::instance()
{
	static Open stateInst;
	return &stateInst;
}

void Open::enter(Game* game, Partner* partner)
{
	cout << "\nEntering Open State.";
}

void Open::exit(Game* game, Partner* partner)
{
	cout << "\nExiting Open State.";
}

void Open::execute(Game* game, Partner* partner)
{
	cout << "\nCurrently in Open state.";
}

void Open::adapt(Game* game, Partner* partner)
{
	//if the entity is opened, return to the previous state
	if (partner->openedEntity)
	{
		partner->changeState(partner->pPrevState);
	}

	//pretend there is code here for otherwise opening something
}