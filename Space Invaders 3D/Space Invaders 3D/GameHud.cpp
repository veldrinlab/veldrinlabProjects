/**
 * File contains definition of GameHud class.
 * @file    GameHud.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-11-28
 * @version 1.0
 */

#include <math.h>

#include "GameHud.h"

/**
 * Class default constructor.
 */
GameHud::GameHud()
{
	lifeAmount = 3;
	points = 0;

	lifeTexture = new Texture("Data/life.png");
	pointsTexture = new Texture("Data/points.png");
}

/**
 * Destructor, free allocated memory.
 */
GameHud::~GameHud()
{
	delete lifeTexture;
	delete pointsTexture;
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

		renderLifes();
		renderPoints();

		glEnable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}

/**
 * Method is used to render player life number.
 */
void GameHud::renderLifes()
{
	for(int i = 0; i < lifeAmount; ++i)
	{
		glBindTexture(GL_TEXTURE_2D, *lifeTexture->getTexture());

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glBegin( GL_QUADS );
			glTexCoord2i( 0, 0 );
			glVertex3f( 20 + (GLfloat)i*40, 530, 0 );
			glTexCoord2i( 1, 0 );
			glVertex3f( 60  + (GLfloat)i*40, 530, 0 );
			glTexCoord2i( 1, 1 );
			glVertex3f( 60  + (GLfloat)i*40, 570, 0 );
			glTexCoord2i( 0, 1 );
			glVertex3f( 20  +(GLfloat) i*40, 570, 0 );
		glEnd();
		glDisable(GL_BLEND);
	}
}

/**
 * Method is used to render gained points.
 */
void GameHud::renderPoints()
{
	for(int i = 0; i <6; ++i)
	{
		float temp= powf(10.0f,static_cast<float>((5-i)));
		temp = points / temp;
		int value = static_cast<int>(temp);

		glBindTexture(GL_TEXTURE_2D, *pointsTexture->getTexture());

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glBegin( GL_QUADS );
			glTexCoord2f( 0 + (GLfloat)0.1*value, 0 );
			glVertex3f( 260 + (GLfloat)i*40 , 530, 0 );
			glTexCoord2f( 0.1f + (GLfloat)0.1 * value, 0 );
			glVertex3f( 300 + (GLfloat)i*40, 530, 0 );
			glTexCoord2f( 0.1f + (GLfloat)0.1 * value, 1.0f );
			glVertex3f( 300 + (GLfloat)i*40, 570, 0 );
			glTexCoord2f(0.0f + (GLfloat)0.1 * value, 1.0f );
			glVertex3f( 260 + (GLfloat)i*40, 570, 0 );
		glEnd();

		glDisable(GL_BLEND);
	}

}

/**
 * Method is used to set player life amount.
 */
void GameHud::setLifeAmount(const int lifeAmount)
{
	this->lifeAmount = lifeAmount;
}

/**
 * Method is used to increase points when player have destroyed enemy Invader.
 */
void GameHud::increasePoints()
{
	points += 20;
}
