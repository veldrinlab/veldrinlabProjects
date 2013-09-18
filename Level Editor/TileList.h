/**
 * TileList.h
 * TileList class store all tiles that can be used to create tile map. User can add own tiles to List, select
 * tiles and set it to choosen place on map.
 *
 *  Created on: 2010-08-23
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef TILELIST_H
#define TILESLIST_H

#include <QListWidget>
#include "Map.h"

class TileList : public QListWidget
{
	Q_OBJECT

private:
	QPixmap tileImage;
	Map* tileMap;

public:
	TileList(QWidget *parent = 0);
	~TileList();
    void addPiece(QPixmap pixmap, QPoint location, int type, QString text);
	void loadTile(const QString &path);
	void initTileList();
	void setTileMap(Map* tileMap);
	QPixmap findTileByID(int tileID);

};

#endif
