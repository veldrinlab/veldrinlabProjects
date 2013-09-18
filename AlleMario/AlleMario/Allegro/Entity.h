/**
 * Entity.h
 *
 * Abstract class represents main parent class of all in-game objects, like
 * Player, Enemy, PowerUp, Coin, etc.
 *
 *  Created on: 2010-08-28
 *      Author: Szymon Jab³oñski - Veldrin
 */


#ifndef ENTITY_H
#define ENTITY_H

#include <allegro5/allegro5.h>
#include <allegro5/a5_iio.h>
#include <string>

#include "Sprite.h"
#include "Vector2D.h"

class Entity
{
protected:
	float xPosition;
	float yPosition;
	Sprite *entitySprite;
	Vector2D velocity;
	Vector2D acceleration;


public:
	virtual void updateEntity(float dt) = 0;
	virtual void drawEntity() = 0;
	
};
#endif
