/**
 * File contains entry point of application.
 * @file    main.cpp
 * @author  Szymon Jab³oñski
 * @date    2011-02-27
 * @version 1.0
 */


#include "Game/Game.hpp"

using namespace Resource;

PResource createTexture(std::string name, std::string filepath)
{
	return PResource(new Texture(name, filepath));
}

PResource createMesh(std::string name, std::string filepath)
{
	return PResource(new Mesh(name, filepath));
}

int main(int argc, char **argv)
{
	//console for debugging - fajna sprawa przy okienkowych aplikacjach jak qDebug() w Qt
	//	AllocConsole();
	//	freopen("CONOUT$", "wb", stdout);

	ResourceManager* resManager = ResourceManager::getInstance();
	resManager->registerResource(TEXTURE, createTexture);
	resManager->registerResource(MESH, createMesh);
	
	Game::Game* game = new Game::Game();
	game->performAction();

	//	fclose(stdout);
	//	FreeConsole();
	delete game;
	return 0;
}
