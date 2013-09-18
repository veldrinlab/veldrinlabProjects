/*
 * TileList.cpp
 * File contains definition of TileList class.
 *
 *  Created on: 2010-08-23
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include <QtGui>
#include "TileList.h"

using namespace std;

TileList::TileList(QWidget *parent) : QListWidget(parent)
{
	setGeometry(5, 140, 150, 400);
    setViewMode(QListView::IconMode);
    setIconSize(QSize(32, 32));
    setSpacing(10);
	initTileList();

}

TileList::~TileList()
{

}

void TileList::addPiece(QPixmap pixmap, QPoint location, int type, QString text)
{
	QListWidgetItem *pieceItem = new QListWidgetItem(this,type);
    pieceItem->setIcon(QIcon(pixmap));
    pieceItem->setData(Qt::UserRole, QVariant(pixmap));
    pieceItem->setData(Qt::UserRole+1, location);
    pieceItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
	pieceItem->setText(text);
}

void TileList::loadTile(const QString &path)
{
	QString fileName = path;

	if (fileName.isNull())
         fileName = QFileDialog::getOpenFileName(this,
             tr("Open Image"), "", "Image Files (*.png *.jpg *.bmp)");

     if (!fileName.isEmpty())
	 {
         QPixmap newImage;
         if (!newImage.load(fileName)) 
		 {
             QMessageBox::warning(this, tr("Open Image"),
                                   tr("The image file could not be loaded."),
                                   QMessageBox::Cancel);
             return;
         }
		 this->tileImage = newImage;
     }
}

void TileList::initTileList()
{
	//TODO: make load tile info from file
	int i = 0;

	loadTile("gfx/0.png");
	this->addPiece(this->tileImage,QPoint(0,0),i++,"");
	loadTile("gfx/1.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/2.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/3.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/4.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/5.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/6.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/7.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/8.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/9.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/10.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/11.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/12.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/13.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/14.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/15.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/16.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/17.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/18.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/19.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/20.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/21.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/22.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/23.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/24.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/25.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/26.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/27.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/28.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/29.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/30.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/31.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/32.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/33.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/34.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/35.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/36.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/37.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/38.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/39.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/40.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
	loadTile("gfx/41.png");
	this->addPiece(this->tileImage,QPoint(0,i),i++,"");
}

void TileList::setTileMap(Map* tileMap)
{
	this->tileMap = tileMap;
	connect(this,SIGNAL(itemPressed(QListWidgetItem*)),tileMap,SLOT(tileSelected(QListWidgetItem*)));
}

QPixmap TileList::findTileByID(int tileID)
{
	QListWidgetItem* searchedItem = this->item(tileID);
	QPixmap pixmap = searchedItem->icon().pixmap(QSize(32, 32));
	return pixmap;
}