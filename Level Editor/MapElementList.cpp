/**
 * MapElementList.cpp file contains implementation of MapElementList class.
 * @file    MapElementList.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-09-13
 * @version 1.0
 */


#include "MapElementList.h"

using namespace std;

MapElementList::MapElementList(QWidget *parent, string fileName): QListWidget(parent)
{
	setIconSize(QSize(32, 32));
	setSpacing(10);
	initElementList(fileName);

}

MapElementList::~MapElementList()
{

}


void MapElementList::initElementList(string fileName)
{
	string resourceName;
	string resourcePath;
	ifstream fileStream;
	int tileID = 0;

	fileStream.open(fileName.c_str());

	if (fileStream.is_open())
	{
		while (!fileStream.eof())
		{
			getline(fileStream,resourceName);
			getline(fileStream,resourcePath);
			loadTile(QString(resourcePath.c_str()));
			addPiece(tileID++,resourceName.c_str());
		}
	}
	else
	{
		qDebug("Unable to open Resource file ");
		exit(1);
	}

	fileStream.close();

}


void MapElementList::loadTile(const QString &path)
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

void MapElementList::addPiece(int tileID, QString text)
{
	QListWidgetItem *pieceItem = new QListWidgetItem(QIcon(tileImage),text,this,tileID);

	pieceItem->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);;
	this->insertItem(tileID,pieceItem);
}


void MapElementList::setTileMap(Map* tileMap)
{
	this->tileMap = tileMap;
	connect(this,SIGNAL(itemPressed(QListWidgetItem*)),tileMap,SLOT(tileSelected(QListWidgetItem*)));
}

QPixmap MapElementList::findTileByID(int tileID)
{
	QListWidgetItem* searchedItem = this->item(tileID);
	QPixmap pixmap = searchedItem->icon().pixmap(QSize(32, 32));
	return pixmap;
}


