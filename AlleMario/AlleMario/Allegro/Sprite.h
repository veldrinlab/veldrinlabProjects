/**
 * Sprite.h
 *
 * Class represents Entity Sprite class. Store sprite sheet image pointer,
 * actual frame delay, frame number, sprite position.
 *
 *  Created on: 2010-08-28
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef SPRITE_H
#define SPRITE_H

#include <allegro5/allegro5.h>
#include <allegro5/a5_iio.h>
#include <string>

class Sprite
{
private:
	ALLEGRO_BITMAP* spriteBitmap;
	int spriteWidth;
	int spriteHeight;
	int spritePositionX;
	int spritePositionY;
	int rowNumber;
	int columnNumber;
	float currentFrameDelay;

public:
	Sprite(ALLEGRO_BITMAP* spriteBitmap, int spriteWidth, int spriteHeight);
	~Sprite();

	ALLEGRO_BITMAP* getSpriteBitmap();
	int getSpritePositionX();
	int getSpritePositionY();

	void setSpritePositionX(int spritePositionX);
	void setSpritePositionY(int spritePositionY);

	void updateCurrentFrameDelay(float dt);
	void setCurrentFrameDelay(float frameDelay);
	float getCurrentFrameDelay();

};
#endif
