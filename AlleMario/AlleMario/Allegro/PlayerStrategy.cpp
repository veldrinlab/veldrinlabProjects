/**
 * PlayerStrategy.cpp
 * File contains definition of PlayerStrategy classes.
 *
 *  Created on: 2010-08-29
 *      Author: Szymon "Veldrin" Jab³oñski
 */

#include "Player.h"

using namespace std;

IdleStrategy::IdleStrategy(Player *player)
{
	player->getSprite()->setSpritePositionX(0);
	player->getSprite()->setCurrentFrameDelay(0.1f);
}


void IdleStrategy::executeStrategy(Player *player, float dt)
{
	//nothing to do in Mario case, for example Megaman has Idle Animation
}


MoveRightStrategy::MoveRightStrategy(Player *player)
{
	player->getSprite()->setSpritePositionX(0);
	player->getSprite()->setSpritePositionY(0);
	player->getSprite()->setCurrentFrameDelay(0.1f);

}

void MoveRightStrategy::executeStrategy(Player *player, float dt)
{
	player->getSprite()->updateCurrentFrameDelay(dt);

	if(player->getSprite()->getCurrentFrameDelay() < 0)
	{
		player->getSprite()->setSpritePositionX((player->getSprite()->getSpritePositionX()+1) % 2);
		player->getSprite()->setCurrentFrameDelay(0.1f);
	}

}

MoveLeftStrategy::MoveLeftStrategy(Player *player)
{
	player->getSprite()->setSpritePositionX(0);
	player->getSprite()->setSpritePositionY(1);
	player->getSprite()->setCurrentFrameDelay(0.1f);

}



void MoveLeftStrategy::executeStrategy(Player *player, float dt)
{
	player->getSprite()->updateCurrentFrameDelay(dt);

	if(player->getSprite()->getCurrentFrameDelay() < 0)
	{
		player->getSprite()->setSpritePositionX((player->getSprite()->getSpritePositionX()+1) % 2);
		player->getSprite()->setCurrentFrameDelay(0.1f);
	}

}


JumpStrategy::JumpStrategy(Player *player)
{
	player->getSprite()->setSpritePositionX(2);
	player->getSprite()->setCurrentFrameDelay(0.1f);
	player->setAcceleration(Vector2D(0.0f,-100.0f));
	player->setVelocity(Vector2D(0.0f,100.0f));
}



void JumpStrategy::executeStrategy(Player *player, float dt)
{
	float currentVelocity = player->getVelocity().getY() + (player->getAcceleration().getY() *dt); 
	
	player->setVelocity(Vector2D(0.0f,currentVelocity));

	float deltaY = player->getVelocity().getY() * dt;

	player->setYPosition(player->getYPosition() - deltaY);


}

FallStrategy::FallStrategy(Player *player)
{
	player->getSprite()->setSpritePositionX(3);
	player->getSprite()->setCurrentFrameDelay(0.1f);
	player->setAcceleration(Vector2D(0.0f,-100.0f));
	player->setVelocity(Vector2D(0.0f,0.0f));
}



void FallStrategy::executeStrategy(Player *player, float dt)
{
	float currentVelocity = player->getVelocity().getY() - (player->getAcceleration().getY() *dt); 
	
	player->setVelocity(Vector2D(0.0f,currentVelocity));

	float deltaY = player->getVelocity().getY() * dt;

	player->setYPosition(player->getYPosition() + deltaY);


}