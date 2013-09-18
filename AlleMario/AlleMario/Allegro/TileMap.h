/**
 * TileMap.h
 *
 * TileMap class represents game Map structure.

 *  Created on: 2010-07-09
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include <vector>
#include "Tile.h"

class TileMap
{
private:
	std::vector<std::vector<Tile*>> tileMap;
	int mapWidth;
	int mapHeight;

public:
	TileMap(std::string mapStructureFile);
	~TileMap();

	Tile* getMapTile(int x, int y);

	void setTileMap(std::vector<std::vector<Tile*>> tileMap);
	std::vector<std::vector<Tile*>> getTileMap();

	void setMapWidth(int mapWidth);
	int getMapWidth();

	void setMapHeight(int mapHeight);
	int getMapHeight();

};

#endif