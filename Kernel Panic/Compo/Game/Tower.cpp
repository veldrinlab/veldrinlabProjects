#include "Tower.hpp"

using namespace std;
using namespace Resource;
using namespace Engine;
using namespace Math;

namespace Game
{

Tower::Tower(const char* textureFileName, const Math::Vector3D& position, const int hpAmount)
{
	framesCounter = 0;
	currentFrame = 9;
	moving = false;
	this->position = position;
	healthPoints = 200;
	
	isDead = false;
	isVisible = true;

	collisionSphere.position = Vector3D(position.x,position.y,0.0f);
	collisionSphere.radius = 100.0f;
	
	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string(textureFileName), string(textureFileName), TEXTURE);
	light = resManager->getResource(string("Data/light.png"), string("Data/light.png"), TEXTURE);
	

	for(int i=0; i<4; i++)
	{
	framesCoords[i].first.x = i*0.25f;
	framesCoords[i].first.y = 0.75f;
	framesCoords[i].second.x = (i+1)*0.25f;
	framesCoords[i].second.y = 0.75f;
	framesCoords[i].third.x = (i+1)*0.25f;
	framesCoords[i].third.y = 1.0f;
	framesCoords[i].quadruple.x = (i)*0.25f;
	framesCoords[i].quadruple.y = 1.0f;
	}

	for(int i=4; i<8; i++)
	{
	framesCoords[i].first.x = i*0.25f;
	framesCoords[i].first.y = 0.5f;
	framesCoords[i].second.x = (i+1)*0.25f;
	framesCoords[i].second.y = 0.5f;
	framesCoords[i].third.x = (i+1)*0.25f;
	framesCoords[i].third.y = 0.75f;
	framesCoords[i].quadruple.x = (i)*0.25f;
	framesCoords[i].quadruple.y = 0.75f;
	}

	for(int i=8; i<10; i++)
	{
	framesCoords[i].first.x = i*0.25f;
	framesCoords[i].first.y = 0.25f;
	framesCoords[i].second.x = (i+1)*0.25f;
	framesCoords[i].second.y = 0.25f;
	framesCoords[i].third.x = (i+1)*0.25f;
	framesCoords[i].third.y = 0.5f;
	framesCoords[i].quadruple.x = (i)*0.25f;
	framesCoords[i].quadruple.y = 0.5f;
	}
}

Tower::~Tower()
{


}


void Tower::renderEntity()
{
	framesCounter++;
	if(moving)
	{
		if(active)
		{
			if (framesCounter%30 == 0)currentFrame++;						
			if(currentFrame>= 9)	moving = false;
		}
		else
		{
			if (framesCounter%30 == 0)currentFrame--;						
			if(currentFrame<= 0)	moving = false;
		}
	}

	glPushMatrix();
	glTranslatef(position.x,position.y,position.z);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	if(active)
	{
		glColor4f(0.7f,0.0f,0.0f,0.4f);
		glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(light.get())->getTexture());
		glBegin( GL_QUADS );
			glTexCoord2f( 0, 0 );
			glVertex3f( 20,20, 0 );
			glTexCoord2f( 1,0 );
			glVertex3f( 120, 20, 0 );
			glTexCoord2f( 1, 1);
			glVertex3f( 120, 120, 0 );
			glTexCoord2f(0,1);
			glVertex3f( 20, 120, 0 );
		glEnd();
		glColor4f(1,1,1,1);
	}
	glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(texture.get())->getTexture());
	glBegin( GL_QUADS );
		glTexCoord2f( framesCoords[currentFrame].first.x, framesCoords[currentFrame].first.y );
		glVertex3f( 0,0, 0 );
		glTexCoord2f( framesCoords[currentFrame].second.x, framesCoords[currentFrame].second.y );
		glVertex3f( 150, 0, 0 );
		glTexCoord2f( framesCoords[currentFrame].third.x, framesCoords[currentFrame].third.y );
		glVertex3f( 150, 150, 0 );
		glTexCoord2f( framesCoords[currentFrame].quadruple.x, framesCoords[currentFrame].quadruple.y );
		glVertex3f( 0, 150, 0 );
	glEnd();
	glDisable(GL_BLEND);

	glPopMatrix();	

	//collisionSphere.drawBoudningSphere();

}

void Tower::updateEntity(const float elapsedTime)
{
	if(healthPoints <= 0)
		isDead = true;

	//odnawianie ¿ycia

}

}