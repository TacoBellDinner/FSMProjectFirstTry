#include "headers/Enemy.h"
#include <iostream>

using namespace std;

Enemy::Enemy(Player* target, int health)
{
	/*
	Initializes the enemy object.
	*/

	pTarget = target;
	maxHealth = health;
	currHealth = maxHealth;

	inventory = 0; //no inventory needed for this enemy

	strength = 30;
}

void Enemy::attackTarget()
{
	pTarget->takeDamage(strength);
}