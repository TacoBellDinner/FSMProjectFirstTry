/*
------------------------------------------------------------------------
//
//  Name:   State.h
//
//  Desc:   abstract base class to define an interface for a state
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)

Gabriel's note: changed the function names to camelCaps. Though they each
// have only one word.
------------------------------------------------------------------------
*/
#ifndef STATE_H
#define STATE_H
#include "Partner.h"
#include "Game.h"



class State
{
public:

  virtual ~State(){}

  //this will execute when the state is entered
  virtual void enter(Game* game, Partner*) = 0;

  //this is the state's normal update function
  virtual void execute(Game* game, Partner*) = 0;
  
  //this will execute when the state is exited. (My word, isn't
  //life full of surprises... ;o))
  virtual void exit(Game* game, Partner*) = 0;

  virtual void adapt(Game* game, Partner*) = 0;
  //^ the States can have the ai switch to another state based on some
  //criteria. Like Passive going to Heal when the player's too hurt.

};

#endif