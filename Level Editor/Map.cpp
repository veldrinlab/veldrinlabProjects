/*
 * Map.cpp
 * File contains definition of Map class.
 *
 *  Created on: 2010-08-23
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include <QtGui>
#include <QPainter>
#include <vector>
#include <fstream>

#include "Map.h"

using namespace std;


Map::Map(QWidget *parent,int mapWidth, int mapHeight) : QWidget(parent)
{
	setMapWidth(mapWidth);
	setMapHeight(mapHeight);
	setGeometry(200,60,this->mapWidth*32,this->mapHeight*32);

	createEmptyMap();

	currentLayer = 0;
	gridChecked = true;
	tileLayerOneChecked = true;
	tileLayerTwoChecked = false;
	tileLayerThreeChecked = false;
	collisionLayerChecked = false;
	entityLayerChecked = false;

	selectedTile = NULL;
}

Map::~Map()
{

}

void Map::changeMapWidth(int value)
{
	if(value > mapWidth)
	{
		setMapWidth(value);
		increaseMapWidth();
	}
	else
	{
		setMapWidth(value);
		decreaseMapWidth();
	}

	setGeometry(200,60,this->mapWidth*32,this->mapHeight*32);
	update();
}

void Map::changeMapHeight(int value)
{
	if(value > mapHeight)
	{
		setMapHeight(value);
		increaseMapHeight();
	}
	else
	{
		setMapHeight(value);
		decreaseMapHeight();
	}

	setGeometry(200,60,this->mapWidth*32,this->mapHeight*32);
	update();
}

void Map::tileSelected(QListWidgetItem* tile)
{
	this->selectedTile = tile;
}

void Map::showTileGrid(int state)
{
	gridChecked = !gridChecked;
	update();
}

void Map::changeCurrentLayer(int index)
{
	switch(index)
	{
	case 0:
		currentLayer = 0;
		break;
	case 1:
		currentLayer = 3;
		break;
	case 2:
		currentLayer = 4;
		break;
	default:
		break;
	}

	update();          
}

void Map::showTileLayerOne(int state)
{
	tileLayerOneChecked = !tileLayerOneChecked;
	update();
}

void Map::showTileLayerTwo(int state)
{
	tileLayerTwoChecked = !tileLayerTwoChecked;
	update();
}

void Map::showTileLayerThree(int state)
{
	tileLayerThreeChecked = !tileLayerThreeChecked;
	update();
}

void Map::showCollisionLayer(int state)
{
	collisionLayerChecked = !collisionLayerChecked;
	update();
}

void Map::showEntityLayer(int state)
{
	entityLayerChecked = !entityLayerChecked;;
	update();
}

void Map::setTileLayerOne(bool checked)
{
	if(checked)
		currentLayer = 0;
}

void Map::setTileLayerTwo(bool checked)
{
	if(checked)
		currentLayer = 1;
}

void Map::setTileLayerThree(bool checked)
{
	if(checked)
		currentLayer = 2;
}

void Map::mousePressEvent(QMouseEvent *event)
{
	if(selectedTile == NULL)
		return;

	QPoint position = event->pos();
	int x = position.x()/32;
	int y = position.y()/32;

	QPixmap pixmap = selectedTile->icon().pixmap(QSize(32, 32));
	int tileID = selectedTile->type();

	this->mapLayers[currentLayer].tilePosition.push_back(QPoint(x*32,y*32));
	this->mapLayers[currentLayer].tilePixmap.push_back(pixmap);
	this->mapLayers[currentLayer].mapStructure[y][y] = tileID;

	update();
}

void Map::paintEvent(QPaintEvent *event)
{
	QPainter painter;

	QPen pen(Qt::black, 1, Qt::SolidLine);

    painter.begin(this);
    painter.fillRect(event->rect(), Qt::white);
	painter.setPen(pen);

	if(tileLayerOneChecked)
	{
		for (int i = 0; i < mapLayers[0].tilePixmap.size(); i++)
			painter.drawPixmap(mapLayers[0].tilePosition[i], mapLayers[0].tilePixmap[i]);
	}


	if(tileLayerTwoChecked)
	{
		for (int i = 0; i < mapLayers[1].tilePixmap.size(); i++)
			painter.drawPixmap(mapLayers[1].tilePosition[i], mapLayers[1].tilePixmap[i]);
	}

	if(tileLayerThreeChecked)
			{
		for (int i = 0; i < mapLayers[2].tilePixmap.size(); i++)
			painter.drawPixmap(mapLayers[2].tilePosition[i], mapLayers[2].tilePixmap[i]);
	}
	if(collisionLayerChecked)
			{
		for (int i = 0; i < mapLayers[3].tilePixmap.size(); i++)
			painter.drawPixmap(mapLayers[3].tilePosition[i], mapLayers[3].tilePixmap[i]);
	}
	if(entityLayerChecked)
	{
		for (int i = 0; i < mapLayers[4].tilePixmap.size(); i++)
			painter.drawPixmap(mapLayers[4].tilePosition[i], mapLayers[4].tilePixmap[i]);
	}

	if(gridChecked)
	{
		for(int i = 0; i<this->mapHeight; i++)
			painter.drawLine(0,32*i,this->mapWidth*32,32*i);
		
		for(int i = 0; i<this->mapWidth; i++)
			painter.drawLine(32*i,0,32*i,this->mapHeight*32);
	}

    painter.end();
}


void Map::clearMap()
{
	mapLayers[currentLayer].tilePixmap.clear();
	mapLayers[currentLayer].tilePosition.clear();

	for(int i = 0; i < mapHeight; i++)
		for(int j = 0; j < mapWidth; j++)
			mapLayers[currentLayer].mapStructure[i][j] = -1;
	update();

}

void Map::fillMap()
{
	if(selectedTile == NULL)
		return;

	QPixmap pixmap = selectedTile->icon().pixmap(QSize(32, 32));
	int tileID = selectedTile->type();


	for(int i = 0; i < mapHeight; i++)
	{
		for(int j = 0; j < mapWidth; j++)
		{
			mapLayers[currentLayer].tilePosition.push_back(QPoint(j*32,i*32));
			mapLayers[currentLayer].tilePixmap.push_back(pixmap);
			mapLayers[currentLayer].mapStructure[i][j] = tileID;
		}
	}
	update();
}

void Map::createEmptyMap()
{
	vector<int> temp;

	for(int i = 0; i < mapWidth; i++)
		temp.push_back(-1);

	for(int i = 0; i < 5; i++)
		for(int j = 0; j < mapHeight; j++)
			this->mapLayers[i].mapStructure.push_back(temp);
	
}

void Map::increaseMapWidth()
{
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < mapHeight; j++)
			this->mapLayers[i].mapStructure[j].push_back(-1);
}

void Map::increaseMapHeight()
{
	vector<int> temp;

	for(int i = 0; i < mapWidth; i++)
		temp.push_back(-1);

	for(int i = 0; i < 5; i++)
		this->mapLayers[i].mapStructure.push_back(temp);
}

void Map::decreaseMapWidth()
{
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < mapHeight; j++)
			this->mapLayers[i].mapStructure[j].pop_back();
}

void Map::decreaseMapHeight()
{
	for(int i = 0; i < 5; i++)
		this->mapLayers[i].mapStructure.pop_back();
}

void Map::setMapHeight(int mapHeight)
{
	this->mapHeight = mapHeight;
}

void Map::setMapWidth(int mapWidth)
{
	this->mapWidth = mapWidth;
}


int Map::getMapWidth()
{
	return mapWidth;
}


int Map::getMapHeight()
{
	return mapHeight;
}


MapLayer* Map::getMapLayers()
{
	return mapLayers;
}

void Map::setMapStructureCell(int x, int y, int tileID, int mapLayer)
{
	mapLayers[mapLayer].mapStructure[x][y] = tileID;
}


void Map::addTilePosition(QPoint tilePosition, int mapLayer)
{
	mapLayers[mapLayer].tilePosition.push_back(tilePosition);
}

void Map::addTilePixmap(QPixmap tilePixmap, int mapLayer)
{
	mapLayers[mapLayer].tilePixmap.push_back(tilePixmap);
}

