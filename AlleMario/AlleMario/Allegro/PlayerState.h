/**
 * PlayerState module contains Player state classes. Therze are two types of Player state:
 * Movement and Life state depends on gameplay time,player input and collision.
 *
 *  Created on: 2010-09-07
 *      Author: Szymon "Veldrin" Jabłoński
 */


#ifndef PLAYERSTATE_H
#define PLAYERSTATE_H

#include <allegro5/allegro5.h>
#include <allegro5/a5_iio.h>
#include <math.h>

#include "Vector2D.h"


class Player;


class PlayerState
{
public: 
	virtual ~PlayerState() {} ;

	virtual void updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state) = 0;

};

class IdleState : public PlayerState
{
public:
	IdleState(Player *player);

	void updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state);
};

class MoveRightState : public PlayerState
{
public:
	MoveRightState(Player *player);

	void updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state);
};

class MoveLeftState : public PlayerState
{
public:
	MoveLeftState(Player *player);

	void updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state);

};

class JumpState : public PlayerState
{
public:
	JumpState(Player *player);

	void updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state);

};

class FallState : public PlayerState
{
public:
	FallState(Player *player);

	void updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state);
};


// Life State classes 
#endif




