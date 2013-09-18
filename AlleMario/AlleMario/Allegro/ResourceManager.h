/**
 * ResourceManager.h
 *
 * ResourceManager class represents object used to load and store all game graphics.
 * Renderer object use ResourceManager to draw image on screen.
 *
 *  Created on: 2010-07-12
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <allegro5/allegro5.h>
#include <allegro5/a5_iio.h>
#include <vector>


class ResourceManager
{
private:

	std::vector<ALLEGRO_BITMAP*> mapTiles;

	//mapa wskaznikow ALLEGRO_BITMAP wraz z nazwami plikow
	ALLEGRO_BITMAP *playerSpriteSheet;

public:
	ResourceManager();
	~ResourceManager();


	void loadMapTiles();
	void loadPlayerSpriteSheet();

	ALLEGRO_BITMAP* getPlayerSpriteSheet();
	ALLEGRO_BITMAP* getTileByID(int tileID);
};
#endif