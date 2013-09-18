/**
 * MapElementList class represents three types of TileMap element object: tiles,collisons and entities.
 * Each MapElementList contains all tiles that can be used to create tile map. User can add own tiles 
 * to list, select tiles and set it to choosen place on map. MapElementList are stored in TabWidget. Tiles
 * image are stored in txt file.
 * @file    LayerWidget.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-09-13
 * @version 1.0
 */

#ifndef MAPELEMENTLIST_H
#define MAPELEMENTLIST_H

#include <QListWidget>
#include <QtGui>
#include <iostream>
#include <fstream>
#include <string>

#include "Map.h"

class MapElementList : public QListWidget
{
  Q_OBJECT

private:
	Map* tileMap; 
	QPixmap tileImage;

public:
	MapElementList(QWidget *parent = 0, std::string fileName = NULL);
   ~MapElementList();
   
	void initElementList(std::string fileName);
	void loadTile(const QString &path);
	void addPiece(int tileID, QString text);
	void setTileMap(Map* tileMap);
	QPixmap findTileByID(int tileID);

};
#endif
