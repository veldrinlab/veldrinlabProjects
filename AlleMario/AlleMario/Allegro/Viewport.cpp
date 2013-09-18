/**
 * Viewport.cpp
 * File contains definition of Viewport class.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon "Veldrin" Jab³oñski
 */

#include <iostream>

#include "Viewport.h"

using namespace std;

Viewport::Viewport()
{
	setViewportWidth(640.0f);
	setViewportHeight(480.0f);
	setWorldX(0.0f);
	setWorldY(0.0f);
	setScreenX(0.0f);
	setScreenY(0.0f);

	viewportBlocked = false;
}

Viewport::~Viewport()
{

}

void Viewport::updateViewport(float dt,ALLEGRO_KEYBOARD_STATE key_state)
{
	velocity.setX(0.0f);
	//w naszym przypadku niepotrzebne
	velocity.setY(0.0f);
	
	if(al_key_down(&key_state,ALLEGRO_KEY_RIGHT) && !viewportBlocked)
		velocity.setX(96.0f);
	else if(al_key_down(&key_state,ALLEGRO_KEY_LEFT) && !viewportBlocked)
		velocity.setX(-96.0f);

	float deltaX = velocity.getX() * dt;
	float deltaY = velocity.getY() * dt;

	//w naszym przypadku nie potrzebne
	this->worldX = this->worldX + deltaX;
	this->worldY = this->worldY + deltaY;

}

void Viewport::setViewportWidth(float viewportWidth)
{
	this->viewportWidth = viewportWidth;
}

void Viewport::setViewportHeight(float viewportHeight)
{
	this->viewportHeight = viewportHeight;
}

void Viewport::setWorldX(float worldX)
{
	this->worldX = worldX;
}

void Viewport::setWorldY(float worldY)
{
	this->worldY = worldY;
}

void Viewport::setScreenX(float screenX)
{
	this->screenX = screenX;
}

void Viewport::setScreenY(float screenY)
{
	this->screenY = screenY;
}

float Viewport::getViewportWidth()
{
	return viewportWidth;
}

float Viewport::getViewportHeight()
{
	return viewportHeight;
}

float Viewport::getWorldX()
{
	return worldX;
}

float Viewport::getWorldY()
{
	return worldY;
}

float Viewport::getScreenX()
{
	return screenX;
}

float Viewport::getScreenY()
{
	return screenY;
}

void Viewport::setViewportVelocity(Vector2D newVelocity)
{
	this->velocity = newVelocity;
}
