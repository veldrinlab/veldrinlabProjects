/**
 * PlayerState.cpp
 * File contains definition of PlayerState classes.
 *
 *  Created on: 2010-09-08
 *      Author: Szymon "Veldrin" Jab³oñski
 */

#include <iostream>

#include "Player.h"

using namespace std;

IdleState::IdleState(Player *player)
{
	player->setStrategy(new IdleStrategy(player));
}

void IdleState::updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state)
{
	//cout << " Current state: Idle " << endl;

	if(al_key_down(&key_state,ALLEGRO_KEY_RIGHT))
		player->setState(new MoveRightState(player));
	else if(al_key_down(&key_state,ALLEGRO_KEY_LEFT))
		player->setState(new MoveLeftState(player));
	else if(al_key_down(&key_state,ALLEGRO_KEY_UP))
		player->setState(new JumpState(player));

}

MoveRightState::MoveRightState(Player *player)
{
	player->setStrategy(new MoveRightStrategy(player));
}

void MoveRightState::updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state)
{
	//cout << " Current state: MoveRight " << endl;

	if(!al_key_down(&key_state,ALLEGRO_KEY_RIGHT))
		player->setState(new IdleState(player));

}

MoveLeftState::MoveLeftState(Player *player)
{
	player->setStrategy(new MoveLeftStrategy(player));
}

void MoveLeftState::updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state)
{
	//cout << " Current state: MoveLeft " << endl;
	
	if(!al_key_down(&key_state,ALLEGRO_KEY_LEFT))
		player->setState(new IdleState(player));
}


JumpState::JumpState(Player *player)
{
	player->setStrategy(new JumpStrategy(player));
}

void JumpState::updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state)
{
	//cout << " Current state: Jump " << endl;

	if(player->getVelocity().getY() < 0)
		player->setState(new FallState(player));


}




FallState::FallState(Player *player)
{
	player->setStrategy(new FallStrategy(player));
}

void FallState::updateState(Player *player, float dt, ALLEGRO_KEYBOARD_STATE key_state)
{
	//cout << " Current state: Fall " << endl;

}
