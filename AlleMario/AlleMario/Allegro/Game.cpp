/**
 * Game.cpp
 * File contains definition of Game class.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include "Game.h"

using namespace std;


Game::Game()
{

}

Game::~Game()
{
	releaseResources();
}

void Game::gameEngineInit()
{
	windowInit();
	resourceManager = new ResourceManager();
	gameEntities = new EntityManager("entity.txt", resourceManager);
	gameRenderer = new Renderer(gameEntities,resourceManager);
}

void Game::windowInit()
{
	al_init();
	al_init_font_addon();
	al_install_keyboard();
	al_init_iio_addon();
//	al_set_new_display_flags(ALLEGRO_FULLSCREEN);

	if (!al_create_display(640,480))
	{
		cerr << "Window init error occurred!" << std::endl;
		getchar();
		exit(1);
	}

	al_set_window_title("AlleMario 0.1");

}

void Game::startGame()
{

	ALLEGRO_KEYBOARD_STATE key_state;
	al_get_keyboard_state(&key_state);

	gameTimer = new Timer();


	while (!al_key_down(&key_state, ALLEGRO_KEY_ESCAPE))
	{
		gameTimer->updateTimerData();

		// Logic // 

		// get current keyboard state
		al_get_keyboard_state(&key_state);

		// update game camera
		gameRenderer->getMapViewport()->updateViewport(gameTimer->getTimeDifference(),key_state);


		// update visible entities
		Player* tempPlayer = static_cast<Player*>(gameEntities->getPlayerEntity());
		
		tempPlayer->getState()->updateState(tempPlayer, gameTimer->getTimeDifference(), key_state);

		gameEntities->updateEntities(gameTimer->getTimeDifference());


		// Render //

		// render scene
		gameRenderer->renderScene();
	




		/* Timer event */
		gameTimer->updateFramesData();

		if(gameTimer->isSecondEnded())
		{
			gameTimer->updateFpsData();
			gameRenderer->setFpsData(gameTimer->getFps());
			gameTimer->resetFpsCounter();
		}
   }

}

void Game::releaseResources()
{
	delete gameTimer;
	delete gameRenderer;
	delete gameEntities;
	delete resourceManager;
}
