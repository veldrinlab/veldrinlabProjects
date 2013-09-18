/**
 * File contains definition of Player class.
 * @file    Player.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-26
 * @version 1.0
 */

#include "PlayerWii.hpp"
#include "World.hpp"

using namespace std;
using namespace Resource;
using namespace Engine;
using namespace Math;

namespace Game
{

/**
 * Default, private constructor.
 */
PlayerWii::PlayerWii()
{

}

/** 
 * Constructor with initialize parameters.
 * @param   textureFileName is Player mesh texture file name.
 * @param	position is origin position vector.
 */
PlayerWii::PlayerWii(const char* textureFileName,const Vector3D& position)
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

	stompTime = -1;
	stompButton = false;
	stompAttack = false;

	velocity = Vector3D(100.0f,100.0f,0.0f);
	moveDirection = Vector3D(0.0f,0.0f,0.0f);
	collisionSphere.position = position;
	collisionSphere.radius = 50.0f;
	
	//animation, prototypowo, no i jakis state jest potrzebny czy ma sie animowac czy nie
	playerAnimation[0].currentFrameX = 0;
	playerAnimation[0].currentFrameY = 0;
	playerAnimation[0].framesAmount = 5;
	playerAnimation[0].frameTimeAccumulator = 0.0f;
	playerAnimation[0].frameTime[0] = 0.01f;
	playerAnimation[0].frameTime[1] = 0.01f;
	playerAnimation[0].frameTime[2] = 0.01f;
	playerAnimation[0].frameTime[3] = 0.01f;
	playerAnimation[0].frameTime[4] = 0.20f;
	playerAnimation[0].isRooling = false;

	playerAnimation[1].currentFrameX = 0;
	playerAnimation[1].currentFrameY = 0;
	playerAnimation[1].framesAmount = 5;
	playerAnimation[1].frameTimeAccumulator = 0.0f;
	playerAnimation[1].isRooling = false;

		for(int i=0; i<4; i++)
	{
	jumpCoords[i].first.x = i*0.25f;
	jumpCoords[i].first.y = 0.75f;
	jumpCoords[i].second.x = (i+1)*0.25f;
	jumpCoords[i].second.y = 0.75f;
	jumpCoords[i].third.x = (i+1)*0.25f;
	jumpCoords[i].third.y = 1.0f;
	jumpCoords[i].quadruple.x = (i)*0.25f;
	jumpCoords[i].quadruple.y = 1.0f;
	}

	for(int i=4; i<8; i++)
	{
	jumpCoords[i].first.x = i*0.25f;
	jumpCoords[i].first.y = 0.5f;
	jumpCoords[i].second.x = (i+1)*0.25f;
	jumpCoords[i].second.y = 0.5f;
	jumpCoords[i].third.x = (i+1)*0.25f;
	jumpCoords[i].third.y = 0.75f;
	jumpCoords[i].quadruple.x = (i)*0.25f;
	jumpCoords[i].quadruple.y = 0.75f;
	}

	for(int i=8; i<12; i++)
	{
	jumpCoords[i].first.x = i*0.25f;
	jumpCoords[i].first.y = 0.25f;
	jumpCoords[i].second.x = (i+1)*0.25f;
	jumpCoords[i].second.y = 0.25f;
	jumpCoords[i].third.x = (i+1)*0.25f;
	jumpCoords[i].third.y = 0.5f;
	jumpCoords[i].quadruple.x = (i)*0.25f;
	jumpCoords[i].quadruple.y = 0.5f;
	}

	for(int i=12; i<16; i++)
	{
	jumpCoords[i].first.x = i*0.25f;
	jumpCoords[i].first.y = 0.0f;
	jumpCoords[i].second.x = (i+1)*0.25f;
	jumpCoords[i].second.y = 0.0f;
	jumpCoords[i].third.x = (i+1)*0.25f;
	jumpCoords[i].third.y = 0.25f;
	jumpCoords[i].quadruple.x = (i)*0.25f;
	jumpCoords[i].quadruple.y = 0.25f;
	}

	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string("PlayerTexture1"), string(textureFileName), TEXTURE);
	hpAccumulator = 0;
	mpAccumulator = 0;
}

/**
 * Class destructor, free allocated memory.
 */
PlayerWii::~PlayerWii()
{
	delete sword;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void PlayerWii::updateEntity(const float elapsedTime)
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


	if(playerAnimation[0].isRooling)
	{
		playerAnimation[0].frameTimeAccumulator += elapsedTime;
		if(playerAnimation[0].frameTimeAccumulator >= playerAnimation[0].frameTime[playerAnimation[0].currentFrameX])
		{
			playerAnimation[0].frameTimeAccumulator = 0.0f;
			playerAnimation[0].currentFrameX++;
			playerAnimation[0].currentFrameX %= playerAnimation[0].framesAmount;

			if(playerAnimation[0].currentFrameX == 4)
				this->sword->setAngle(angle+90.0f);
			else
				this->sword->setAngle(angle);

			if(playerAnimation[0].currentFrameX == 0)
			{
				playerAnimation[0].isRooling = false;
				attacking = false;
			}
		}
	}
	else
		this->sword->setAngle(angle);

	if (stompTime > -1) {
		
		if (stompTime == 1) stompAttack = true;
		else stompAttack = false;
		stompTime -= elapsedTime;
		if (stompTime <= 0) World::shake = false;
	}
	else {
		stompTime = -1;
	}
	//trzeba wprowadziæ enuma kierunku ruchu i odniego uzale¿niaæ obrót, pozycje miecza itp.
}

/**
 * Method is used to render entity.
 */
void PlayerWii::renderEntity()
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
		glTexCoord2f(playerAnimation[0].currentFrameX*0.2f, 0.8f-playerAnimation[0].currentFrameY);
		glVertex3f( 0,0, 0 );
		glTexCoord2f(playerAnimation[0].currentFrameX*0.2f+0.20f, 0.8f-playerAnimation[0].currentFrameY);
		glVertex3f( 100, 0, 0 );
		glTexCoord2f(playerAnimation[0].currentFrameX*0.2f+0.2f,1);
		glVertex3f( 100, 100, 0 );
		glTexCoord2f(playerAnimation[0].currentFrameX*0.2f,1);
		glVertex3f( 0, 100, 0 );
	glEnd();

	glColor3f(1.0f,1.0f,1.0f);
	damageOccurred = false;

	glDisable(GL_BLEND);
	glPopMatrix();	

	//collisionSphere.drawBoudningSphere();
}

void PlayerWii::stomp()
{
	if (!stompButton && stompTime<=-1) {
		World::shake = true;
		stompTime = 1;
		stompButton = true;
		stompAttack = true;
		playerAnimation[1].isRooling = true;
	}
}

void PlayerWii::stompStop() {
	stompButton = false;
}

/**
 * Method is used to set move direction to left.
 */
void PlayerWii::moveLeft()
{
	moveDirection.x = -2.0f;
	
	if(moveDirection.y == 2.0f)
		angle = -135.0f;
	else if(moveDirection.y == -2.0f)
		angle = -45.0f;
	else
		angle = -90.0f;
}

/**
 * Method is used to set move direction to right.
 */
void PlayerWii::moveRight()
{
	moveDirection.x = 2.0f;

	if(moveDirection.y == 2.0f)
		angle = 135.0f;
	else if(moveDirection.y == -2.0f)
		angle = 45.0f;
	else
		angle = 90.0f;
}

/**
 * Method is used to set move direction to up.
 */
void PlayerWii::moveUp()
{
	moveDirection.y = 2.0f;

	if(moveDirection.x == -2.0f)
		angle = -135.0f;
	else if(moveDirection.x == 2.0f)
		angle = 135.0f;
	else
		angle = 180.0f;
}

/**
 * Method is used to set move direction to down.
 */
void PlayerWii::moveDown()
{
	moveDirection.y = -2.0f;
	
	if(moveDirection.x == -2.0f)
		angle = -45.0f;
	else if(moveDirection.x == 2.0f)
		angle = 45.0f;
	else
		angle = 0.0f;
}

/**
 * Method is used to stop player XAxis movement.
 */
void PlayerWii::stopXAxisMove()
{
	moveDirection.x = 0.0f;
}

/**
 * Method is used to stop player YAxis movement.
 */
void PlayerWii::stopYAxisMove()
{
	moveDirection.y = 0.0f;
}

/**
 * Method is used to stop init right attack.
 */
void PlayerWii::rightAttack()
{
	//zmienic pare rzeczy
	playerAnimation[0].isRooling = true;
	attacking = true;
}

/**
 * Method is used to stop init left attack.
 */
void PlayerWii::leftAttack()
{
	//zmienic pare rzeczy
	playerAnimation[0].isRooling = true;
	attacking = true;
}

/**
 * Method is used to start rage using mana.
 */
void PlayerWii::rageStart()
{
	if(mana > 0)
		rage = true;

}
/**
 * Method is used decrease player hp amount and init damage occurred animation.
 */
void PlayerWii::damaged()
{
	damageOccurred = true;
	this->healthPoints--;

}

/**
 * Accessor to hp amount.
 * @return	player health points.
 */
int PlayerWii::getHealthPoints() const
{
	return healthPoints;
}

/**
 * Accessor to mp amount.
 * @return	player mana points.
 */
int PlayerWii::getMana() const
{
	return mana;
}

/**
 * Accesor to player state.
 * @return	true if player is swinging sword.
 */
bool PlayerWii::isAttacking() const
{
	return attacking;
}

/**
 * Accesor to player rage state.
 * @return	true if player is in rage.
 */
bool PlayerWii::isRage() const
{
	return rage;
}

/**
 * Accessor to private sword memebr.
 * @return	ponter to sword object.
 */
Sword* PlayerWii::getSword() const
{
	return sword;
}

/**
 * Setter of private sword member.
 * @param	sword is pointer to sword object.
 */
void PlayerWii::setSword(Sword* sword)
{
	this->sword = sword;
}

}