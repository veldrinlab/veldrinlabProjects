/**
 * File contains definition of Sword class.
 * @file    Sword.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2011-02-28
 * @version 1.0
 */
#include "World.hpp"

using namespace std;
using namespace Resource;
using namespace Engine;

namespace Game
{

bool World::shake = false;

/** 
 * Constructor with initialize parameters.
 * @param   textureFileName is World mesh texture file name.
 */
World::World(const char* textureFileName)
{
	isDead = false;
	isVisible = false;

	rand = new Utils::Random();
	
	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string("BackgroundTexture"), string(textureFileName), TEXTURE);

	dangerKurwa = false;
	blendAccumulator = -3.0f;
	time = 0.0f;
}

/**
 * Class destructor, free allocated memory.
 */
World::~World()
{
	delete rand;
}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void World::updateEntity(const float elapsedTime)
{
	//nothing to be done
	time += elapsedTime;
	if(dangerKurwa)
	{
		blendAccumulator += elapsedTime;

	if(time >= 0.3f)
	{
		time = 0.0f;
		dangerKurwa = !dangerKurwa;
	}

	if(blendAccumulator >= 1.2f)
		blendAccumulator = 0.0f;
	}
}

/**
 * Method is used to render entity. Use Vertext Buffer Objects.
 */
void World::renderEntity()
{
	if(dangerKurwa)
		glColor4f(1.0f,0.0f,0.0f,1.0f);

	if (shake) {
		glPushMatrix();
		glTranslatef(rand->getFloat(-10.0f,10.0f),rand->getFloat(-10.0f,10.0f),0.0f);
	}
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(texture.get())->getTexture());
		glBegin( GL_QUADS );
			glTexCoord2i( 0, 0 );
			glVertex3f( 0, 0, 0 );
			glTexCoord2i( 1, 0 );
			glVertex3f( 1024, 0, 0 );
			glTexCoord2i( 1, 1 );
			glVertex3f( 1024, 768, 0 );
			glTexCoord2i( 0, 1 );
			glVertex3f( 0, 768, 0 );
		glEnd();
	glPopMatrix();

	if (shake) {
		glPopMatrix();
	}
		//glDisable(GL_BLEND);
	glColor4f(1.0f,1.0f,1.0f,1.0f);
}

}