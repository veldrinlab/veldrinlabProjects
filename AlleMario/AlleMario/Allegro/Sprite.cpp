/**
 * Sprite.cpp
 * File contains definition of Sprite class.
 *
 *  Created on: 2010-08-28
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include "Sprite.h"

using namespace std;

Sprite::Sprite(ALLEGRO_BITMAP* spriteBitmap, int spriteWidth, int spriteHeight)
{
	this->spriteBitmap = spriteBitmap;
	this->spriteWidth = spriteWidth;
	this->spriteHeight = spriteHeight;

	spritePositionX = 0;
	spritePositionY = 0;
	
	rowNumber = al_get_bitmap_height(spriteBitmap)/spriteHeight;
	columnNumber = al_get_bitmap_width(spriteBitmap)/spriteWidth;

}

Sprite::~Sprite()
{

}

ALLEGRO_BITMAP* Sprite::getSpriteBitmap()
{
	return spriteBitmap;
}

int Sprite::getSpritePositionX()
{
	return spritePositionX;
}

int Sprite::getSpritePositionY()
{
	return spritePositionY;
}

void Sprite::setSpritePositionX(int spritePositionX)
{
	this->spritePositionX = spritePositionX;
}

void Sprite::setSpritePositionY(int spritePositionY)
{
	this->spritePositionY = spritePositionY;
}

void Sprite::updateCurrentFrameDelay(float dt)
{
	this->currentFrameDelay = this->currentFrameDelay - dt;
}

void Sprite::setCurrentFrameDelay(float frameDelay)
{
	this->currentFrameDelay = frameDelay;
}

float Sprite::getCurrentFrameDelay()
{
	return currentFrameDelay;
}

