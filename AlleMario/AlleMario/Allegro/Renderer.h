/**
 * Renderer.h
 *
 * Renderer class represents main object of game responsible for rendering
 * game scene. It hold pointers for actual Level map and player object.

 *  Created on: 2010-07-12
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef RENDERER_H
#define RENDERER_H

#include <allegro5/allegro5.h>
#include <allegro5/a5_iio.h>
#include <allegro5/a5_font.h>
#include <allegro5/a5_ttf.h>
#include <string>
#include <sstream>

#include "TileMap.h"
#include "Viewport.h"
#include "ResourceManager.h"
#include "EntityManager.h"

class Renderer
{
private:
	TileMap* actualLevelMap;
	Viewport* mapViewport;
	ResourceManager* resourceManager;
	EntityManager* gameEntities;

	ALLEGRO_BITMAP *mapBuffer;
	
	//GAME HUD
	ALLEGRO_FONT* textFont;
	std::string fpsData;

public:
	Renderer(EntityManager* gameEntities,ResourceManager* resourceManager);
	~Renderer();

	void renderScene();
	void drawViewportEntities();
	void drawLevelMap();
	void drawGameHud();
	void fontInit();

	void setActualLevelMap(TileMap* actualLevelMap);
	TileMap* getActualLevelMap();
	void setMapViewport(Viewport* mapViewport);
	Viewport* getMapViewport();
	void setFpsData(float fpsData);
	void releaseResources();

};
#endif