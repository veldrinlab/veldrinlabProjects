/**
 * File contains definition of GameHud class.
 * @file    GameHud.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-28
 * @version 1.0
 */

#include "GameHud.hpp"

namespace game
{

/**
 * Class default constructor.
 */
GameHud::GameHud()
{
	shieldStatus = 100;
	ResourceManager* resManager = ResourceManager::getInstance();
	shieldTexture = resManager->getResource(std::string("HUD"), std::string("Data/hud.png"), TEXTURE);
	crosshairTexture=resManager->getResource(std::string("Cross"), std::string("Data/crosshair.png"), TEXTURE);
}

/**
 * Destructor, free allocated memory.
 */
GameHud::~GameHud()
{

}

/**
 * Method is used to render Game Hud.
 */
void GameHud::renderGameHud()
{
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, 800, 0,600);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		renderShieldStatus();
		renderCrosshair();

		glEnable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

}

/**
 * Method is used to render player x-wing shield status.
 */
void GameHud::renderShieldStatus()
{
	Texture* tempTexture = static_cast<Texture*>(shieldTexture.get());
	glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(0.0f,1.0f,0.0f,0.8f);
	glBegin( GL_QUADS );
		glTexCoord2i( 0, 0 );
		glVertex3f( 10, 10, 0 );
		glTexCoord2i( 1, 0 );
		glVertex3f( 110, 10, 0 );
		glTexCoord2i( 1, 1 );
		glVertex3f( 110, 110, 0 );
		glTexCoord2i( 0, 1 );
		glVertex3f( 10, 110, 0 );
	glEnd();
	glDisable(GL_BLEND);
	glColor4f(1.0f,1.0f,1.0f,1.0f);
}

/**
 * Method is used to render player x-wing crosshair.
 */
void GameHud::renderCrosshair()
{
	Texture* tempTexture = static_cast<Texture*>(crosshairTexture.get());
	glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glColor4f(0.0f,1.0f,0.0f,0.8f);
	glBegin( GL_QUADS );
		glTexCoord2i( 0, 0 );
		glVertex3f( 370, 280, 0 );
		glTexCoord2i( 1, 0 );
		glVertex3f( 430, 280, 0 );
		glTexCoord2i( 1, 1 );
		glVertex3f( 430, 320, 0 );
		glTexCoord2i( 0, 1 );
		glVertex3f( 370, 320, 0 );
	glEnd();
	glDisable(GL_BLEND);
	glColor4f(1.0f,1.0f,1.0f,1.0f);
}

}
