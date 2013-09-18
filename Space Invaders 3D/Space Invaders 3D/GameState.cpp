/**
 * File contains definition of GameState module classes.
 * @file    GameState.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#include "Game.h"

/**
 * Method is used to perform action of actual state.
 */
void IdleState::performAction()
{
	// nothing to do, Idle state
}

/**
 * Method is used to perform action of actual state.
 */
void PlayState::performAction()
{
	game->getGameTimer()->updateTimerData();

	if(game->getGameInput()->updateInput())
		game->setGameDone(true);

	game->getDetector()->detectCollision();
	game->getHandler()->handleCollision();

	game->getGameScene()->updateScene(game->getGameTimer()->getElapsedTime());
	game->getGameRenderer()->renderScene();

	game->getGameTimer()->updateFramesData();

	if(game->getGameTimer()->isSecondElapsed())
	{
		game->getGameTimer()->updateFpsData();
		game->getGameTimer()->resetFrameData();
	}
}

/**
 * Method is used to perform action of actual state.
 */
void PauseState::performAction()
{
	if(game->getGameInput()->updateInput())
		game->setGameDone(true);

	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, 800, 0,600);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glBindTexture(GL_TEXTURE_2D, *pause->getTexture());

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glBegin( GL_QUADS );
			glTexCoord2i( 0, 0 );
			glVertex3f( 280,300, 0 );
			glTexCoord2i( 1, 0 );
			glVertex3f(  550,300, 0 );
			glTexCoord2i( 1, 1 );
			glVertex3f( 550,350, 0 );
			glTexCoord2i( 0, 1 );
			glVertex3f( 280,350, 0 );
		glEnd();
		glDisable(GL_BLEND);

		glEnable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
    SDL_GL_SwapBuffers();

}

/**
 * Method is used to perform action of actual state.
 */
void GameOverState::performAction()
{ 
	if(game->getGameInput()->updateInput())
		game->setGameDone(true);

	glClearColor (0.0f,0.0f,0.0f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
		glLoadIdentity();
		gluOrtho2D(0, 800, 0,600);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glBindTexture(GL_TEXTURE_2D, *gameOver->getTexture());

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glBegin( GL_QUADS );
			glTexCoord2i( 0, 0 );
			glVertex3f( 280,300, 0 );
			glTexCoord2i( 1, 0 );
			glVertex3f(  550,300, 0 );
			glTexCoord2i( 1, 1 );
			glVertex3f( 550,350, 0 );
			glTexCoord2i( 0, 1 );
			glVertex3f( 280,350, 0 );
		glEnd();
		glDisable(GL_BLEND);

		glEnable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
    SDL_GL_SwapBuffers();
}
