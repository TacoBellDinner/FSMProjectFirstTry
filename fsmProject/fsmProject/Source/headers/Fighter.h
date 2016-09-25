/*
Superclass for all the characters that can fight.
Author: Gabriel Cabrera
*/

#ifndef FIGHTER_H
#define FIGHTER_H

#include <string>
#include <vector>

using namespace std;

class Fighter
{
	/*
	Superclass for all characters in the game that can fight.
	*/
public:
	//member var declarations

	int maxHealth;
	int currHealth;

	Fighter* pTarget;
	int strength; //damage done when attacking

	vector<string>* pInventory;

	//member function prototypes
	Fighter();
	Fighter(int health);
	void takeDamage(int damage);


};

#endif