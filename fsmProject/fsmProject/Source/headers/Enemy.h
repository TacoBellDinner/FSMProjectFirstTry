/*
Class for the enemies, that at the time of this writing, only attack
the player and ignore the companion AI.

Author: Gabriel Cabrera
*/

#ifndef ENEMY_H
#define ENEMY_H

#include "Game.h"
#include "Partner.h"
#include "Player.h"
#include "Fighter.h"



class Enemy : public Fighter
{
public:
	//member var declarations


	//member function prototypes
	Enemy(Player* target, int health);
	virtual void attackTarget();

};


#endif