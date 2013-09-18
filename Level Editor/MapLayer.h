/**
 * MapLayer class represents one layer of Level Map structure object. Each Level Map has three tile
 * layers, one colllision map layer and one entity map layer 
 * @file    MapLayer.h 
 * @author	Szymon "Veldrin" Jab³oñski  
 * @date    2010-09-17
 * @version 1.0
 */


#ifndef MAPLAYER_H
#define MAPLAYER_H

#include <QPoint>
#include <QPixmap>
#include <vector>


class MapLayer
{
public:
	std::vector<std::vector<int>> mapStructure;
	std::vector<QPoint> tilePosition;
	std::vector<QPixmap> tilePixmap;
};

#endif


