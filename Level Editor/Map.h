/**
 * Map class contains level map structure data, map width/height, tile, colisions, entity layet
 * It is one of LevelEditor widget. User can set map grid, increase map width and height, change layer view. 
 * Map class store model data and also print map view..
 * @file    Map.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-08-23
 * @version 1.0
 */


#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QListWidgetItem>
#include <QIcon>
#include <QLabel>
#include <vector>

#include "MapLayer.h"

class Map : public QWidget
{
	Q_OBJECT

private:
	int mapWidth;
	int mapHeight;

	MapLayer mapLayers[5];
	int currentLayer;

	QListWidgetItem* selectedTile;

	bool gridChecked;
	bool tileLayerOneChecked;
	bool tileLayerTwoChecked;
	bool tileLayerThreeChecked;
	bool collisionLayerChecked;
	bool entityLayerChecked;

	void createEmptyMap();
	void increaseMapWidth();
	void increaseMapHeight();
	void decreaseMapWidth();
	void decreaseMapHeight();

private slots:
	void changeMapWidth(int value);
	void changeMapHeight(int value);
	void tileSelected(QListWidgetItem* tile);
	void showTileGrid(int state);
	void changeCurrentLayer(int index);
	void showTileLayerOne(int state);
	void showTileLayerTwo(int state);
	void showTileLayerThree(int state);
	void showCollisionLayer(int state);
	void showEntityLayer(int state);
	void setTileLayerOne(bool checked);
	void setTileLayerTwo(bool checked);
	void setTileLayerThree(bool checked);

protected:
	void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

public:
    Map(QWidget *parent = 0,int mapWidth = 20, int mapHeight = 15);
	~Map();

	void clearMap();
	void fillMap();

	void setMapWidth(int mapWidth);
	void setMapHeight(int mapHeight);
	int getMapWidth();
	int getMapHeight();
	
	MapLayer* getMapLayers();
	void setMapStructureCell(int x, int y, int tileID, int mapLayer);
	void addTilePosition(QPoint tilePosition, int mapLayer);
	void addTilePixmap(QPixmap tilePixmap, int mapLayer);

};

#endif