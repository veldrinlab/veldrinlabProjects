/**
 * File contains entry point of application.
 * @file    main.cpp
 * @author  Szymon Jab³oñski & Adam Sznajder
 * @date    2010-10-16
 * @version 1.0
 */
#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include "Menu.hpp"
//#include "windows.h"
#include "ResourceManager/ResourceManager.hpp"
#include "ResourceManager/ResourceType.hpp"
#include "ResourceManager/Mesh.hpp"

using namespace resMan;

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
	AllocConsole();
	freopen("CONOUT$", "wb", stdout);

	ResourceManager* resManager = ResourceManager::getInstance();
	resManager->registerResource(TEXTURE, createTexture);
	resManager->registerResource(MESH, createMesh);

	menu::Menu* menu = new menu::Menu();
	menu->showMenu();

	fclose(stdout);
	FreeConsole();
	return 0;
}
