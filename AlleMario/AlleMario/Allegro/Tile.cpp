/**
 * Tile.cpp
 * File contains definition of Tile class.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include <string>
#include "Tile.h"

using namespace std;

Tile::Tile(string tileImageFileName, char lifeModifier, bool solid, int tileID)
{
	setTileImageFileName(tileImageFileName);
	setTileID(tileID);
	setLifeModifier(lifeModifier);
	setSolid(solid);
	setTileWidth(32);
	setTileHeight(32);
}

Tile::Tile()
{
	tileImageFileName = "0.bmp";
	tileID = 0;
	solid = false;
	lifeModifier = 0;
	setTileWidth(32);
	setTileHeight(32);
}

Tile::~Tile()
{

}

string Tile::getTileImageFileName()
{
	return tileImageFileName;
}

void Tile::setTileImageFileName(string tileImageFileName)
{
	this->tileImageFileName = tileImageFileName;
}

char Tile::getLifeModifier()
{
	return lifeModifier;
}

void Tile::setLifeModifier(char lifeModifier)
{
	this->lifeModifier = lifeModifier;
}

bool Tile::isSolid()
{
	return solid;
}

void Tile::setSolid(bool solid)
{
	this->solid = solid;
}

void Tile::setTileWidth(int tileWidth)
{
	this->tileWidth = tileWidth;
}

int Tile::getTileWidth()
{
	return tileWidth;
}

void Tile::setTileHeight(int tileHeight)
{
	this->tileHeight = tileHeight;
}

int Tile::getTileHeight()
{
	return tileHeight;
}

void Tile::setTileID(int tileID)
{
	this->tileID = tileID;
}
int Tile::getTileID()
{
	return tileID;
}

