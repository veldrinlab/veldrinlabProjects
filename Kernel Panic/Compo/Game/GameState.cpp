/**
 * File contains definition of GameState module classes.
 * @file    GameState.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-12-01
 * @version 1.0
 */

#include "Game.hpp"

using namespace Resource;

namespace Game
{

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
	game->getGameEngine()->getEngineTimer()->updateTimerData();

	if(game->getGameEngine()->getEngineInput()->updateInput())
		game->setGameDone(true);

	//game->getGameEngine()->getDetector()->detectCollision();
	//game->getGameEngine()->getHandler()->handleCollision();


	game->getGameEngine()->getEngineScene()->updateScene(game->getGameEngine()->getEngineTimer()->getElapsedTime());
	game->getGameEngine()->getEngineRenderer()->renderScene();

	game->getGameEngine()->getEngineTimer()->updateFramesData();

	if(game->getGameEngine()->getEngineTimer()->isSecondElapsed())
	{
		game->getGameEngine()->getEngineTimer()->updateFpsData();
		game->getGameEngine()->getEngineTimer()->resetFrameData();
	}
}


void IntroState::performAction()
{
	if(game->getGameEngine()->getEngineInput()->updateInput())
		game->setGameDone(true);

	game->getGameEngine()->getEngineTimer()->updateTimerData();
	timeAccumulator += game->getGameEngine()->getEngineTimer()->getElapsedTime();

	if(timeAccumulator <= 5.0f)
	{
		blendAccumulator += game->getGameEngine()->getEngineTimer()->getElapsedTime();
		glClearColor (0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDisable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			Configuration* config = Configuration::getInstance();
			gluOrtho2D(0, config->getWidth(), 0, config->getHeight());
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			Texture* tempTexture = static_cast<Texture*>(logo.get());
			glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
			glColor4f(1.0f,1.0f,1.0f,blendAccumulator);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBegin( GL_QUADS );
				glTexCoord2i( 0, 0 );
				glVertex3f( 0, 0, 0 );
				glTexCoord2i( 1, 0 );
				glVertex3f(  1024,0, 0 );
				glTexCoord2i( 1, 1 );
				glVertex3f( 1024,768, 0 );
				glTexCoord2i( 0, 1 );
				glVertex3f( 0,768, 0 );
			glEnd();
			glDisable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();
		SDL_GL_SwapBuffers();
	}
	if(timeAccumulator >=5.0f && timeAccumulator <= 10.0f)
	{
		blendAccumulator -= game->getGameEngine()->getEngineTimer()->getElapsedTime();
		glClearColor (0.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glDisable(GL_DEPTH_TEST);
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
			glLoadIdentity();
			Configuration* config = Configuration::getInstance();
			gluOrtho2D(0, config->getWidth(), 0, config->getHeight());
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			Texture* tempTexture = static_cast<Texture*>(logo.get());
			glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());
			glColor4f(1.0f,1.0f,1.0f,blendAccumulator);
			glEnable(GL_BLEND);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glBegin( GL_QUADS );
				glTexCoord2i( 0, 0 );
				glVertex3f( 0, 0, 0 );
				glTexCoord2i( 1, 0 );
				glVertex3f(  1024,0, 0 );
				glTexCoord2i( 1, 1 );
				glVertex3f( 1024,768, 0 );
				glTexCoord2i( 0, 1 );
				glVertex3f( 0,768, 0 );
			glEnd();
			glDisable(GL_BLEND);
			glEnable(GL_DEPTH_TEST);
			glMatrixMode(GL_PROJECTION);
		glPopMatrix();
		glMatrixMode(GL_MODELVIEW);

		glLoadIdentity();
		SDL_GL_SwapBuffers();
	}

	if(timeAccumulator >= 10.0f)
		this->game->setGameState(new PlayState(this->game));



}


/**
 * Method is used to perform action of actual state.
 */
void PauseState::performAction()
{
	//if(game->getGameEngine()->getEngineInput()->updateInput())
	//	game->setGameDone(true);

	//glDisable(GL_DEPTH_TEST);
	//glMatrixMode(GL_PROJECTION);
	//glPushMatrix();
	//	glLoadIdentity();
	//	Configuration* config = Configuration::getInstance();
	//	gluOrtho2D(0, config->getWidth(), 0, config->getHeight());
	//	glMatrixMode(GL_MODELVIEW);
	//	glLoadIdentity();

	//	Texture* tempTexture = static_cast<Texture*>(pause.get());
	//	glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());


	//	glEnable(GL_BLEND);
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//	glBegin( GL_QUADS );
	//		glTexCoord2i( 0, 0 );
	//		glVertex3f( 280,300, 0 );
	//		glTexCoord2i( 1, 0 );
	//		glVertex3f(  550,300, 0 );
	//		glTexCoord2i( 1, 1 );
	//		glVertex3f( 550,350, 0 );
	//		glTexCoord2i( 0, 1 );
	//		glVertex3f( 280,350, 0 );
	//	glEnd();
	//	glDisable(GL_BLEND);

	//	glEnable(GL_DEPTH_TEST);
	//	glMatrixMode(GL_PROJECTION);
	//glPopMatrix();
	//glMatrixMode(GL_MODELVIEW);

	//glLoadIdentity();
 //   SDL_GL_SwapBuffers();

}

/**
 * Method is used to perform action of actual state.
 */
void GameOverState::performAction()
{ 
	//if(game->getGameEngine()->getEngineInput()->updateInput())
	//	game->setGameDone(true);

	//glClearColor (0.0f,0.0f,0.0f,1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glDisable(GL_DEPTH_TEST);
	//glMatrixMode(GL_PROJECTION);
	//glPushMatrix();
	//	glLoadIdentity();
	//	Configuration* config = Configuration::getInstance();
	//	gluOrtho2D(0, config->getWidth(), 0, config->getHeight());
	//	glMatrixMode(GL_MODELVIEW);
	//	glLoadIdentity();

	//	Texture* tempTexture = static_cast<Texture*>(gameOver.get());
	//	glBindTexture(GL_TEXTURE_2D, *tempTexture->getTexture());

	//	glEnable(GL_BLEND);
	//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//	glBegin( GL_QUADS );
	//		glTexCoord2i( 0, 0 );
	//		glVertex3f( 280,300, 0 );
	//		glTexCoord2i( 1, 0 );
	//		glVertex3f(  550,300, 0 );
	//		glTexCoord2i( 1, 1 );
	//		glVertex3f( 550,350, 0 );
	//		glTexCoord2i( 0, 1 );
	//		glVertex3f( 280,350, 0 );
	//	glEnd();
	//	glDisable(GL_BLEND);

	//	glEnable(GL_DEPTH_TEST);
	//	glMatrixMode(GL_PROJECTION);
	//glPopMatrix();
	//glMatrixMode(GL_MODELVIEW);

	//glLoadIdentity();
 //   SDL_GL_SwapBuffers();
}

}
