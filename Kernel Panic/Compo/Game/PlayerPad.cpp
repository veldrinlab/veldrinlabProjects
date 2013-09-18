/**
 * File contains definition of Player class.
 * @file    Player.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-26
 * @version 1.0
 */

#include "PlayerPad.hpp"
#include "Tower.hpp"

using namespace std;
using namespace Resource;
using namespace Engine;
using namespace Math;

namespace Game
{

/**
 * Default, private constructor.
 */
PlayerPad::PlayerPad()
{

}

/** 
 * Constructor with initialize parameters.
 * @param   textureFileName is Player mesh texture file name.
 * @param	position is origin position vector.
 */
PlayerPad::PlayerPad(const char* textureFileName,const Vector3D& position)
{
	this->isSpeededUp = false;
	this->position = position;
	isDead = false;
	isVisible = false;
	healthPoints = 100;
	mana = 25;
	angle = 0.0f;
	attacking = false;
	damageOccurred = false;
	rage = false;
	buildTower = false;
	manaAccum = 0;

	velocity = Vector3D(100.0f,100.0f,0.0f);
	moveDirection = Vector3D(0.0f,0.0f,0.0f);
	collisionSphere.position = position;
	collisionSphere.radius = 50.0f;
	
	//animation, prototypowo, no i jakis state jest potrzebny czy ma sie animowac czy nie
	playerAnimation.currentFrameX = 0;
	playerAnimation.currentFrameY = 0;
	playerAnimation.framesAmount = 5;
	playerAnimation.frameTimeAccumulator = 0.0f;
	playerAnimation.frameTime[0] = 0.01f;
	playerAnimation.frameTime[1] = 0.01f;
	playerAnimation.frameTime[2] = 0.01f;
	playerAnimation.frameTime[3] = 0.01f;
	playerAnimation.frameTime[4] = 0.20f;
	playerAnimation.isRooling = false;

	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string("PlayerTexture"), string(textureFileName), TEXTURE);
	hpAccumulator = 0;
	mpAccumulator = 0;
}

/**
 * Class destructor, free allocated memory.
 */
PlayerPad::~PlayerPad()
{

}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void PlayerPad::updateEntity(const float elapsedTime)
{
	hpAccumulator++;
	mpAccumulator++;
	manaAccum++;

	if(healthPoints <= 0)
		isDead = true;

	if(rage)
	{
		velocity = Vector3D(200.0f,200.0f,0.0f);
		if(manaAccum >= 5)
		{
			mana--;
			manaAccum = 0;
		}
	}
	else
		velocity = Vector3D(100.0f,100.0f,0.0f);

	if(mana <=0)
		rage = false;


	if(hpAccumulator == 20)
	{
		if(healthPoints < 100)
			healthPoints++;
		hpAccumulator = 0;
	}

	if(mpAccumulator == 30)
	{
		if(mana < 25)
			mana++;
		mpAccumulator = 0;
	}

	position.x += velocity.x * elapsedTime * moveDirection.x;
	position.y += velocity.y * elapsedTime * moveDirection.y;
	collisionSphere.position = position;

	if(playerAnimation.isRooling)
	{
		playerAnimation.frameTimeAccumulator += elapsedTime;
		if(playerAnimation.frameTimeAccumulator >= playerAnimation.frameTime[playerAnimation.currentFrameX])
		{
			playerAnimation.frameTimeAccumulator = 0.0f;
			playerAnimation.currentFrameX++;
			playerAnimation.currentFrameX %= playerAnimation.framesAmount;


			if(playerAnimation.currentFrameX == 0)
			{
				playerAnimation.isRooling = false;
				attacking = false;
			}
		}
	}
	
	
	//trzeba wprowadziæ enuma kierunku ruchu i odniego uzale¿niaæ obrót, pozycje miecza itp.
}

/**
 * Method is used to render entity.
 */
void PlayerPad::renderEntity()
{
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	glRotatef(angle,0,0,1);
	glTranslatef(-50,-50,0);
	glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(texture.get())->getTexture());
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if(damageOccurred)
		glColor3f(1.0f,0.0f,0.0f);

	glBegin( GL_QUADS );
		glTexCoord2f(playerAnimation.currentFrameX*0.2f, 0.8f-playerAnimation.currentFrameY);
		glVertex3f( 0,0, 0 );
		glTexCoord2f(playerAnimation.currentFrameX*0.2f+0.20f, 0.8f-playerAnimation.currentFrameY);
		glVertex3f( 100, 0, 0 );
		glTexCoord2f(playerAnimation.currentFrameX*0.2f+0.2f,1);
		glVertex3f( 100, 100, 0 );
		glTexCoord2f(playerAnimation.currentFrameX*0.2f,1);
		glVertex3f( 0, 100, 0 );
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);
	damageOccurred = false;

	glDisable(GL_BLEND);
	glPopMatrix();	

	//collisionSphere.drawBoudningSphere();
}

/**
 * Method is used to set move direction to left.
 */
void PlayerPad::moveLeft()
{
	//printf("ide w lewo\n");
	moveDirection.x = -1.0f;
	
	if(moveDirection.y == 1.0f)
		angle = -135.0f;
	else if(moveDirection.y == -1.0f)
		angle = -45.0f;
	else
		angle = -90.0f;
}

/**
 * Method is used to set move direction to right.
 */
void PlayerPad::moveRight()
{
	//	printf("ide w prawo\n");
	moveDirection.x = 1.0f;

	if(moveDirection.y == 1.0f)
		angle = 135.0f;
	else if(moveDirection.y == -1.0f)
		angle = 45.0f;
	else
		angle = 90.0f;
}

/**
 * Method is used to set move direction to up.
 */
void PlayerPad::moveUp()
{
	//	printf("ide w gore\n");
	moveDirection.y = 1.0f;

	if(moveDirection.x == -1.0f)
		angle = -135.0f;
	else if(moveDirection.x == 1.0f)
		angle = 135.0f;
	else
		angle = 180.0f;
}

/**
 * Method is used to set move direction to down.
 */
void PlayerPad::moveDown()
{
	//printf("ide w dol\n");
	moveDirection.y = -1.0f;
	
	if(moveDirection.x == -1.0f)
		angle = -45.0f;
	else if(moveDirection.x == 1.0f)
		angle = 45.0f;
	else
		angle = 0.0f;
}

/**
 * Method is used to stop player XAxis movement.
 */
void PlayerPad::stopXAxisMove()
{
	moveDirection.x = 0.0f;
	//printf("nie ide w x\n");
}

/**
 * Method is used to stop player YAxis movement.
 */
void PlayerPad::stopYAxisMove()
{
	moveDirection.y = 0.0f;
	//printf("nie ide w y\n");
}

void PlayerPad::Probieren()
{
	this->probieren_active = true;
}

void PlayerPad::Verhogen()
{
	this->verhogen_active = true;
}

void PlayerPad::SpeedUp()
{
	this->speedUp_active = true;
}

void PlayerPad::SetTower()
{
	this->buildTower = true;
}



/**
 * Method is used decrease player hp amount and init damage occurred animation.
 */
void PlayerPad::damaged()
{
	damageOccurred = true;
	this->healthPoints--;

}

/**
 * Accessor to hp amount.
 * @return	player health points.
 */
int PlayerPad::getHealthPoints() const
{
	return healthPoints;
}

/**
 * Accessor to mp amount.
 * @return	player mana points.
 */
int PlayerPad::getMana() const
{
	return mana;
}

/**
 * Accesor to player state.
 * @return	true if player is swinging sword.
 */
bool PlayerPad::isAttacking() const
{
	return attacking;
}

/**
 * Accesor to player rage state.
 * @return	true if player is in rage.
 */
bool PlayerPad::isRage() const
{
	return rage;
}


}