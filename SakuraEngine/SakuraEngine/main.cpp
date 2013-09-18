/**
 * File contains entry point of application.
 * @file    main.cpp
 * @author  Szymon Jab³oñski
 * @date    2011-02-27
 * @version 1.0
 */


#include "Game/Game.hpp"
#include "ResourceManager/ResourceManager.hpp"

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
	ResourceManager* resManager = ResourceManager::getInstance();
	resManager->registerResource(TEXTURE, createTexture);
	resManager->registerResource(MESH, createMesh);
	
	Game::Game* game = new Game::Game();
	game->performAction();

	delete game;
	return 0;
}
