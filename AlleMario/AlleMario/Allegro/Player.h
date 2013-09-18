/**
 * Player.h
 *
 * Renderer class represents object of Player/Mario. It store all
 * data connected with player position, state, life number etc.
 *
 *  Created on: 2010-07-13
 *      Author: Szymon "Veldrin" Jab³oñski
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "PlayerState.h"
#include "PlayerStrategy.h"


class Player : public Entity
{
private:
    PlayerState *state;
	PlayerStrategy *strategy;
	int lifeNumber;
	int coinNumber;                                      

public:
	Player(ALLEGRO_BITMAP *spriteBitmap, int spriteWidth, int spriteHeight);
	~Player();

	void updateEntity(float dt);
	void drawEntity();

	void setStrategy(PlayerStrategy *strategy);
	PlayerStrategy* getStrategy();

	void setState(PlayerState *state);
	PlayerState* getState();

	Sprite* getSprite();

	float getXPosition();
	float getYPosition();
	void setXPosition(float xPosition);
	void setYPosition(float yPosition);

	Vector2D getVelocity();
	void setVelocity(Vector2D newVelocity);

	Vector2D getAcceleration();
	void setAcceleration(Vector2D newAcceleration);

};

#endif

