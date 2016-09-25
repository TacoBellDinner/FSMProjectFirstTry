#include "headers/Enemy.h"
#include "headers/Player.h"

Enemy::Enemy(Player* target, int health)
{
	/*
	Initializes the enemy object.
	*/

	pTarget = target;
	maxHealth = health;
	currHealth = maxHealth;

	pInventory = 0; //no inventory needed for this enemy

	strength = 30;
}

void Enemy::attackTarget()
{
	pTarget->takeDamage(strength);
}
