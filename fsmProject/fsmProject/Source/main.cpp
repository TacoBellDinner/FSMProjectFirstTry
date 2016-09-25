/* fsmProgram.cpp : Defines the entry point for the console application.
//
Author: Gabriel Cabrera
Project based on Mat Buckland's West World example

Current Tasks:
	Code the AI state transitions with working rules
*/

#include "stdafx.h"
#include "Windows.h"
#include <iostream>
#include "headers/Player.h"
#include "headers/Partner.h"
#include "headers/PartnerStates.h"

using namespace std;


int main()
{
	/*cout << "GOOD BYE, CRUEL WORLD.";
	cin.get(); //testing! */ 

	//starting health for the player and their companion
	int playerHp = 160;
	int partnerHp = 160;

	//Set up that player and companion
	Player* player = 0;  
	Partner* partner = 0;
	//^these pointers need to start off pointing at nothing
	// so they can be passed into a function

	partner = new Partner(player, 160, Idle::instance());
	player = new Player(partner, 160);
	//now, these pointers are pointing to actual objects instead
	//of nothingness!

	//Let's take a look at their health.
	cout << "The player and their companion enter this world.";

	//have pauses between the message displays
	int milliseconds = 1600;
	Sleep(milliseconds);

	cout << "\nPlayer's current health: " << player->currHealth;
	Sleep(milliseconds);
	cout << "\nPartner's current health: " << partner->currHealth;
	Sleep(milliseconds);

	if (player->currHealth == player->maxHealth)
	{
		cout << "\n\nThe player is in top condition. ";
		cout << player->currHealth << "/" << player->maxHealth << " HP.";
	}

	Sleep(milliseconds);

	if (partner->currHealth == partner->maxHealth)
	{
		cout << "\n\nThe player's companion is in top condition. ";
		cout << partner->currHealth << "/" << partner->maxHealth << " HP.";
	}

	Sleep(milliseconds * 3);

	cout << "\n\nPress Enter to exit.";
	cin.get();

    return 0;
}

