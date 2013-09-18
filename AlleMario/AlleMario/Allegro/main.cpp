#include "Game.h"

#undef main

using namespace std;

int main()
{
	Game *game = new Game();
	game->gameEngineInit();
	game->startGame();

	return 0;
}
