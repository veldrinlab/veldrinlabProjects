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


/** 
 * Constructor with initialize parameters.
 * @param   textureFileName is World mesh texture file name.
 */
World::World(const char* textureFileName)
{
	isDead = false;
	isVisible = false;
	
	ResourceManager* resManager = ResourceManager::getInstance();
	texture = resManager->getResource(string("BackgroundTexture"), string(textureFileName), TEXTURE);
}

/**
 * Class destructor, free allocated memory.
 */
World::~World()
{

}

/**
 * Method used to update entities.
 * @param	elapsedTime is time between frames in seconds.
 */
void World::updateEntity(const float elapsedTime)
{
	//nothing to be done
}

/**
 * Method is used to render entity. Use Vertext Buffer Objects.
 */
void World::renderEntity()
{
	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, *static_cast<Texture*>(texture.get())->getTexture());
		glBegin( GL_QUADS );
			glTexCoord2i( 0, 0 );
			glVertex3f( 0, 0, 0 );
			glTexCoord2i( 1, 0 );
			glVertex3f( 800, 0, 0 );
			glTexCoord2i( 1, 1 );
			glVertex3f( 800, 600, 0 );
			glTexCoord2i( 0, 1 );
			glVertex3f( 0, 600, 0 );
		glEnd();
	glPopMatrix();
}

}