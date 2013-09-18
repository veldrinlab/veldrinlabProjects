/**
 * Player.cpp
 * File contains definition of Player class.
 *
 *  Created on: 2010-07-13
 *      Author: Szymon "Veldrin" Jab³oñski
 */

#include <iostream>
#include "Player.h"

using namespace std;


Player::Player(ALLEGRO_BITMAP *spriteBitmap,int spriteWidth, int spriteHeight)
{
	this->entitySprite = new Sprite(spriteBitmap,spriteWidth,spriteHeight);
	coinNumber = 0;
	lifeNumber = 3;

	//TODO:  pozycja bohatera z pliku w entity manager
	xPosition = 304.0f;
	yPosition = 341.0f;

	velocity.setX(0.0f);
	velocity.setY(0.0f);
	acceleration.setX(0.0f);
	acceleration.setY(0.0f);

	entitySprite->setCurrentFrameDelay(0.1f);

	this->strategy = new IdleStrategy(this);
	this->state = new IdleState(this);
}

Player::~Player()
{
	delete strategy;
	delete state;

}

void Player::updateEntity(float dt)
{
	strategy->executeStrategy(this,dt);
}


void Player::drawEntity()
{
	al_draw_bitmap_region(entitySprite->getSpriteBitmap(), entitySprite->getSpritePositionX()*32,
		entitySprite->getSpritePositionY()*47, entitySprite->getSpritePositionX()+32,
			entitySprite->getSpritePositionX()+47, xPosition,yPosition, NULL);

}


void Player::setStrategy(PlayerStrategy *strategy)
{
	delete this->strategy;
	this->strategy = strategy;
}

PlayerStrategy* Player::getStrategy()
{
	return strategy;
}

void Player::setState(PlayerState *state)
{
	delete this->state;
	this->state = state;
}

PlayerState* Player::getState()
{
	return state;
}


Sprite* Player::getSprite()
{
	return entitySprite;

}

float Player::getXPosition()
{
	return xPosition;
}

float Player::getYPosition()
{
	return yPosition;
}

void Player::setXPosition(float xPosition)
{
	this->xPosition = xPosition;
}

void Player::setYPosition(float yPosition)
{
	this->yPosition = yPosition;
}

Vector2D Player::getVelocity()
{
	return velocity;
}

void Player::setVelocity(Vector2D newVelocity)
{
	this->velocity = newVelocity;
}

Vector2D Player::getAcceleration()
{
	return acceleration;
}

void Player::setAcceleration(Vector2D newAcceleration)
{
	this->acceleration = newAcceleration;
}
