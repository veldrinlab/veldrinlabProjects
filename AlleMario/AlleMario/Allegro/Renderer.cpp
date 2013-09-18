/**
 * Renderer.cpp
 *
 * File contains definition of Renderer class.
 *
 *  Created on: 2010-07-12
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include "Renderer.h"

#include <iostream>

using namespace std;

Renderer::Renderer(EntityManager* gameEntities, ResourceManager* resourceManager)
{
	this->gameEntities = gameEntities;
	this->resourceManager = resourceManager;
	actualLevelMap = new TileMap("mapStructure.txt");
	mapViewport = new Viewport();

	resourceManager = new ResourceManager();
	
	mapBuffer = al_create_bitmap(640,480);

	fpsData = "FPS: ?";
	fontInit();
}

Renderer::~Renderer()
{
	releaseResources();
}


void Renderer::renderScene()
{
	al_set_target_bitmap(mapBuffer);
	al_clear_to_color( al_map_rgb(0,0,0));

	drawLevelMap();
	
	drawViewportEntities();
	
	drawGameHud();



	al_set_target_bitmap(al_get_backbuffer());
	al_draw_bitmap(mapBuffer,0,0,NULL);
	al_flip_display();
}

void Renderer::drawLevelMap()
{
	int tileWidth = 32;
	int tileHeight = 32;

	int left = mapViewport->getWorldX() / tileWidth;
	int right = left + (mapViewport->getViewportWidth() / tileWidth) +1 ;
	int top = mapViewport->getWorldY() / tileHeight;
	int bottom = top + (mapViewport->getViewportHeight() / tileHeight);

	for( int v = top; v < bottom; v++ )
	{
		for( int u = left; u < right; u++ )
		{
			int x = u * tileWidth - mapViewport->getWorldX() + mapViewport->getScreenX();
			int y = v * tileHeight - mapViewport->getWorldY() + mapViewport->getScreenY();

			Tile* tile = actualLevelMap->getMapTile(u,v);

			al_draw_bitmap(resourceManager->getTileByID(tile->getTileID()),x,y,NULL);
			
		}
	}
	
}

void Renderer::drawViewportEntities()
{
	//sprawdzenie ktore Entity znajduja sie w polu widzenia
	//i narysowanie ich
	for(unsigned int i = 0; i < gameEntities->getEntityMap().size(); i++)
		gameEntities->getEntityMap()[i]->drawEntity();
}


void Renderer::drawGameHud()
{
	al_set_blender( ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA, al_map_rgb(0,0,0) );
	const char *cFPS = fpsData.c_str();
	al_draw_text( textFont, 10, 0, 0, cFPS);
	al_set_blender( ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA, al_map_rgb(255,255,255) );

}

void Renderer::fontInit()
{
	textFont = al_load_ttf_font( "times.ttf", 20, 0 );
	if ( !textFont )
	{
		cerr << "Font loading error occurred!" << std::endl;
		getchar();
		exit(1);
	}

}

void Renderer::setActualLevelMap(TileMap* actualLevelMap)
{
	this->actualLevelMap = actualLevelMap;
}

TileMap* Renderer::getActualLevelMap()
{
	return actualLevelMap;
}

void Renderer::setMapViewport(Viewport* mapViewport)
{
	this->mapViewport = mapViewport;
}

Viewport* Renderer::getMapViewport()
{
	return mapViewport;
}

void Renderer::setFpsData(float fpsData)
{
	stringstream out;
	string fps = "FPS: ";
	out << fpsData;
	fps += out.str();
	this->fpsData = fps;
}

void Renderer::releaseResources()
{
	delete actualLevelMap;
	delete mapViewport;
	delete resourceManager;
	delete textFont;
	al_destroy_bitmap(mapBuffer);
}