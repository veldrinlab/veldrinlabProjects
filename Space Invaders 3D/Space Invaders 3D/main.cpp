/**
 * File contains entry point of application. 
 * @file    main.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-11-21
 * @version 1.0
 */

#include "Game.h"

int main( int argc, char* args[] )
{
	Game* game = new Game();
	game->doSomeMagic();

	delete game;
    return 0;
}
