/**
 * File contains definition of Enemy class.
 * @file    Enemy.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-28
 * @version 1.0
 */
	
#include "Enemy.hpp"

using namespace std;
using namespace Resource;
using namespace Engine;
using namespace Math;

namespace Game
{

/**
 * Default, private constructor.
 */
Enemy::Enemy()
{

}

/** 
 * Constructor with initialize parameters.
 * @param   textureFileName is Player mesh texture file name.
 * @param	position is origin position vector.
 */
Enemy::Enemy(const char* textureFileName,const Vector3D& position, Player* player)
{
	this->position = position;
	this->player = player;
	isDead = false;
	isVisible = true;
	healthPoints = 1;

	velocity = Vector3D(20.0f,20.0f,0.0f);
	moveDirection = Vector3D(0.0f,0.0f,0.0f);

	collisionSphere.position = position;
	collisionSphere.radius = 20.0f;
	
	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string(textureFileName), string(textureFileName), TEXTURE);
}

/**
 * Class destructor, free allocated memory.
 */
Enemy::~Enemy()
{

}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void Enemy::updateEntity(const float elapsedTime)
{
	if(healthPoints <= 0)
		isDead = true;

	moveDirection = player->position - position;
	moveDirection.normalize();

	position.x += velocity.x * elapsedTime * moveDirection.x;
	position.y += velocity.y * elapsedTime * moveDirection.y;
	collisionSphere.position = position;
}

/**
 * Method is used to render entity.
 */
void Enemy::renderEntity()
{
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	glTranslatef(-25,-25,0);

	glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(texture.get())->getTexture());
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin( GL_QUADS );
		glTexCoord2f( 0, 0 );
		glVertex3f( 0,0, 0 );
		glTexCoord2f( 1.0f, 0.0f );
		glVertex3f( 50, 0, 0 );
		glTexCoord2f( 1.0f, 1.0f );
		glVertex3f( 50, 50, 0 );
		glTexCoord2f( 0, 1 );
		glVertex3f( 0, 50, 0 );
	glEnd();
	glDisable(GL_BLEND);

	glPopMatrix();	

	//collisionSphere.drawBoudningSphere();
}

}