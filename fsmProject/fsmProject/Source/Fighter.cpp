/*
Superclass for all characters in the game that can fight.
*/

#include "headers/Fighter.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

Fighter::Fighter()
{
	maxHealth = 100;
	currHealth = maxHealth;

	inventory = new vector<string>;
}

Fighter::Fighter(int health)
{
	//set the fighter's health, and start them with an empty
	// inventory
	maxHealth = health;
	currHealth = maxHealth;
	pInventory = new vector<string>;
}

void Fighter::takeDamage(int damage)
{
	currHealth -= damage;
}