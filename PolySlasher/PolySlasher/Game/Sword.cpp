/**
 * File contains definition of Sword class.
 * @file    Sword.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-28
 * @version 1.0
 */
	
#include "Sword.hpp"

using namespace std;
using namespace Resource;
using namespace Engine;
using namespace Math;

namespace Game
{

/**
 * Default, private constructor.
 */
Sword::Sword()
{

}

/** 
 * Constructor with initialize parameters.
 * @param   textureFileName is Player mesh texture file name.
 * @param	position is origin position vector.
 */
Sword::Sword(const char* textureFileName,const Vector3D& position)
{
	this->position = position;
	this->isDead = false;
	isVisible = false;
	angle = 0.0f;

	collisionSphere.position = position;
	collisionSphere.radius = 50.0f;
	
	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string("SwordTexture"), string(textureFileName), TEXTURE);
}

/**
 * Class destructor, free allocated memory.
 */
Sword::~Sword()
{

}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void Sword::updateEntity(const float elapsedTime)
{
	// switch po enumie, albo jakiœ sygna³

		if(angle == 0.0f)
			position.x -= 60.0f;
		else if(angle == 180.0f)
			position.x +=60.0f;
		else if(angle == -90.0f)
			position.y += 60.0f;
		else if(angle == 90.0f)
			position.y -= 60.0f;
		else if(angle == -45.0f)
		{
			position.x -= 45.0f;
			position.y += 45.0f;
		}
		else if(angle == 45.0f)
		{
			position.x -= 45.0f;
			position.y -= 45.0f;
		}
		else if(angle == -135.0f)
		{
			position.x += 45.0f;
			position.y += 45.0f;
		}
		else if(angle == 135.0f)
		{
			position.x += 45.0f;
			position.y -= 45.0f;
		}
		else if(angle == 270.0f)
			position.y += 60.0f;
		else if(angle == 225.0f)
		{
			position.x +=45.0f;
			position.y +=45.0f;
		}

		collisionSphere.position = position;
}

/**
 * Method is used to render entity. Use Vertext Buffer Objects.
 */
void Sword::renderEntity()
{
	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	glRotatef(angle,0,0,1);
	glTranslatef(-50,-50,0);

	glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(texture.get())->getTexture());
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin( GL_QUADS );
		glTexCoord2f( 0, 0.0f );
		glVertex3f( 0.0f, 0.0f, 0 );
		glTexCoord2f( 1.0f, 0.0f );
		glVertex3f( 100.0f, 0.0f, 0 );
		glTexCoord2f( 1.0f, 1.0f );
		glVertex3f( 100.0f, 100.0f, 0 );
		glTexCoord2f( 0, 1 );
		glVertex3f( 0.0f, 100.0f, 0 );
	glEnd();

	glDisable(GL_BLEND);

	glPopMatrix();	

	//collisionSphere.drawBoudningSphere();
}

/**
 * Setter to private movement angle memeber.
 * @param	angle is new angle.
 */
void Sword::setAngle(const float angle)
{
	this->angle = angle;
}

/**
 * Accessor to private angle memeber.
 * @return	angle
 */
float Sword::getAngle() const
{
	return angle;
}

}
