#include "Kernel.hpp"

using namespace std;
using namespace Resource;
using namespace Engine;
using namespace Math;

namespace Game
{

Kernel::Kernel(const char* textureFileName, const Math::Vector3D& position, const int hpAmount)
{
	this->position = position;
	healthPoints = hpAmount;
	
	isDead = false;
	isVisible = true;
	hpAccumulator = 0;

	collisionSphere.position = position;
	collisionSphere.radius = 100.0f;
	
	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string(textureFileName), string(textureFileName), TEXTURE);

}

Kernel::~Kernel()
{


}


void Kernel::renderEntity()
{
	glPushMatrix();
	glTranslatef(0.0f,0.0f,position.z);

	glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(texture.get())->getTexture());
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin( GL_QUADS );
		glTexCoord2f( 0, 0 );
		glVertex3f( 0,0, 0 );
		glTexCoord2f( 1.0f, 0.0f );
		glVertex3f( 150, 0, 0 );
		glTexCoord2f( 1.0f, 1.0f );
		glVertex3f( 150, 150, 0 );
		glTexCoord2f( 0, 1 );
		glVertex3f( 0, 150, 0 );
	glEnd();
	glDisable(GL_BLEND);

	glPopMatrix();	

}

void Kernel::updateEntity(const float elapsedTime)
{
	if(healthPoints <= 0)
		isDead = true;

	hpAccumulator++;

	if(hpAccumulator == 20)
	{
		if(healthPoints < 100)
			healthPoints++;
		hpAccumulator = 0;
	}

	//odnawianie ¿ycia

}

}