/*
This defines all the states that the partner AI can use.

Author: Gabriel Cabrera
*/

#ifndef PARTNER_STATES_H
#define PARTNER_STATES_H

//^header guard. Necessary to avoid rendundant copying of header file  
// contents, so the compiler doesnt crash.

#include "State.h"
#include "Partner.h"

class Passive : public State
{
public:

	//setup the singleton with a static function
	static Passive* instance();

	Passive() {};

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};

class Attack : public State
{
public:

	//setup the singleton with a static function
	static Attack* instance();

	Attack() {}; 

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};

class DefAgg : public State
{
public:

	//setup the singleton with a static function
	static DefAgg* instance();

	DefAgg() {};

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};

class Heal : public State
{
public:

	//setup the singleton with a static function
	static Heal* instance();

	Heal() {};

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};

class Stealth : public State
{
public:

	//setup the singleton with a static function
	static Stealth* instance();

	Stealth() {};

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};

class Exploratory : public State
{
public:

	//setup the singleton with a static function
	static Exploratory* instance();

	Exploratory() {};

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};

class Idle : public State
{
public:

	//setup the singleton with a static function
	static Idle* instance();

	Idle() {};

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};

class GoTo : public State
{
public:

	//setup the singleton with a static function
	static GoTo* instance();

	GoTo() {};

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};

class Open : public State
{
public:

	//setup the singleton with a static function
	static Open* instance();

	Open() {};

	virtual void enter(Game* game, Partner* partner);
	virtual void exit(Game* game, Partner* partner);
	virtual void execute(Game* game, Partner* partner);
	virtual void adapt(Game* game, Partner* partner);
};
#endif 
// ^needed at the end of header files when you use header guards.