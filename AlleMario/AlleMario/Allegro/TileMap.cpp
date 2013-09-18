/**
 * TileMap.cpp
 * File contains definition of TileMap class.
 *
 *  Created on: 2010-07-09
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include "TileMap.h"

using namespace std;

TileMap::TileMap(string mapStructureFile)
{
	int mapData;
	char dimensionData[4096];
	ifstream fileStream;

	fileStream.open(mapStructureFile.c_str());

	if (!fileStream)
	{
        cout << "Unable to open file";
        exit(1);
	}
	
	fileStream.getline(dimensionData,4096);
	setMapWidth(atoi(dimensionData));
	fileStream.getline(dimensionData,4096);
	setMapHeight(atoi(dimensionData));


	for( int i = 0; i < mapWidth; i++ )
		tileMap.push_back( vector< Tile* >() );

	for(int j = 0; j < mapHeight; j++)
	{
		for(int i = 0; i < mapWidth; i++)
		{
			tileMap[i].push_back(new Tile());
			fileStream >> mapData;

			tileMap[i][j]->setTileImageFileName("0.bmp");
			tileMap[i][j]->setTileID(mapData);
			tileMap[i][j]->setLifeModifier(0);
			tileMap[i][j]->setSolid(false);
		}
	}
	fileStream.close();
}

TileMap::~TileMap()
{

}


Tile* TileMap::getMapTile(int x, int y)
{
	return tileMap[x][y];
}


void TileMap::setTileMap(vector<vector<Tile*>> tileMap)
{
	this->tileMap = tileMap;
}

vector<vector<Tile*>> TileMap::getTileMap()
{
	return tileMap;
}

void TileMap::setMapWidth(int mapWidth)
{
	this->mapWidth = mapWidth;
}

int TileMap::getMapWidth()
{
	return mapWidth;
}

void TileMap::setMapHeight(int mapHeight)
{
	this->mapHeight = mapHeight;
}

int TileMap::getMapHeight()
{
	return mapHeight;
}