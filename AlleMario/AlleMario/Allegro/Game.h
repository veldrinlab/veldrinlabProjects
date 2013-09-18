/**
 * Game.h
 *
 * Game class represents main obejct of game application. It store all data
 * needed by rendering obejct, start game timer etc.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef GAME_H
#define GAME_H

#include <allegro5/allegro5.h>
#include <allegro5/a5_font.h>
#include <allegro5/a5_ttf.h>
#include <allegro5/a5_iio.h>
#include <iostream>

#include "Timer.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "EntityManager.h"

class Game
{
private:
	Timer *gameTimer;
	Renderer *gameRenderer;
	ResourceManager* resourceManager;
	EntityManager* gameEntities;

public:
	Game();
	~Game();

	void startGame();

	void gameEngineInit();
	void windowInit();
	void releaseResources();

};

#endif