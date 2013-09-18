/**
 * File contains definition of Player class.
 * @file    Player.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-26
 * @version 1.0
 */
	
#include "Player.hpp"

using namespace std;
using namespace Resource;
using namespace Engine;
using namespace Math;

namespace Game
{

/**
 * Default, private constructor.
 */
Player::Player()
{

}

/** 
 * Constructor with initialize parameters.
 * @param   textureFileName is Player mesh texture file name.
 * @param	position is origin position vector.
 */
Player::Player(const char* textureFileName,const Vector3D& position)
{
	this->position = position;
	isDead = false;
	isVisible = false;
	healthPoints = 100;
	mana = 25;
	angle = 0.0f;
	attacking = false;
	damageOccurred = false;
	rage = false;
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
Player::~Player()
{
	delete sword;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void Player::updateEntity(const float elapsedTime)
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

	//update miecza bohatera
	this->sword->position = position;

	if(playerAnimation.isRooling)
	{
		playerAnimation.frameTimeAccumulator += elapsedTime;
		if(playerAnimation.frameTimeAccumulator >= playerAnimation.frameTime[playerAnimation.currentFrameX])
		{
			playerAnimation.frameTimeAccumulator = 0.0f;
			playerAnimation.currentFrameX++;
			playerAnimation.currentFrameX %= playerAnimation.framesAmount;

			this->sword->setAngle(angle + playerAnimation.currentFrameX*22.5f);

			if(playerAnimation.currentFrameX == 0)
			{
				playerAnimation.isRooling = false;
				attacking = false;
			}
		}
	}
	else
		this->sword->setAngle(angle);
	
	//trzeba wprowadziæ enuma kierunku ruchu i odniego uzale¿niaæ obrót, pozycje miecza itp.
}

/**
 * Method is used to render entity.
 */
void Player::renderEntity()
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
void Player::moveLeft()
{
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
void Player::moveRight()
{
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
void Player::moveUp()
{
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
void Player::moveDown()
{
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
void Player::stopXAxisMove()
{
	moveDirection.x = 0.0f;
}

/**
 * Method is used to stop player YAxis movement.
 */
void Player::stopYAxisMove()
{
	moveDirection.y = 0.0f;
}

/**
 * Method is used to stop init right attack.
 */
void Player::rightAttack()
{
	//zmienic pare rzeczy
	playerAnimation.isRooling = true;
	attacking = true;
}

/**
 * Method is used to stop init left attack.
 */
void Player::leftAttack()
{
	//zmienic pare rzeczy
	playerAnimation.isRooling = true;
	attacking = true;
}

/**
 * Method is used to start rage using mana.
 */
void Player::rageStart()
{
	if(mana > 0)
		rage = true;

}
/**
 * Method is used decrease player hp amount and init damage occurred animation.
 */
void Player::damaged()
{
	damageOccurred = true;
	this->healthPoints--;

}

/**
 * Accessor to hp amount.
 * @return	player health points.
 */
int Player::getHealthPoints() const
{
	return healthPoints;
}

/**
 * Accessor to mp amount.
 * @return	player mana points.
 */
int Player::getMana() const
{
	return mana;
}

/**
 * Accesor to player state.
 * @return	true if player is swinging sword.
 */
bool Player::isAttacking() const
{
	return attacking;
}

/**
 * Accesor to player rage state.
 * @return	true if player is in rage.
 */
bool Player::isRage() const
{
	return rage;
}

/**
 * Accessor to private sword memebr.
 * @return	ponter to sword object.
 */
Sword* Player::getSword() const
{
	return sword;
}

/**
 * Setter of private sword member.
 * @param	sword is pointer to sword object.
 */
void Player::setSword(Sword* sword)
{
	this->sword = sword;
}

}