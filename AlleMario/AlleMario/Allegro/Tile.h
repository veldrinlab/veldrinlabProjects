/**
 * Tile.h
 *
 * Tile class represents basic part of game map structure. Each tile store
 * data about image, collision with Player and life modifer.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef TILE_H
#define TILE_H

#include <string>

class Tile
{
private:
	std::string tileImageFileName;
	char lifeModifier;
	bool solid;
	int tileWidth;
	int tileHeight;
	int tileID;

public:
	Tile(std::string tileImageFileName, char lifeModifier, bool solid,int tileID);
	Tile();
	~Tile();

	std::string getTileImageFileName();
	void setTileImageFileName(std::string tileImageFileName);

	char getLifeModifier();
	void setLifeModifier(char lifeModifier);

	bool isSolid();
	void setSolid(bool solid);

	void setTileWidth(int tileWidth);
	int getTileWidth();

	void setTileHeight(int tileHeight);
	int getTileHeight();

	void setTileID(int tileID);
	int getTileID();

};
#endif