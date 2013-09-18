/*
 * MapEditor.cpp
 * File contains definition of MapEditor class.
 *
 *  Created on: 2010-08-23
 *      Author: Szymon Jab³oñski - Veldrin
 */

#include <QtGui>
#include <QTextStream>
#include <QFile>
#include <QSpinBox>
#include <iostream>
#include <QTabWidget>

#include "MapEditor.h"

using namespace std;


MapEditor::MapEditor(QWidget *parent, Qt::WFlags flags): QMainWindow(parent, flags)
{
	setMinimumSize(1200, 800);
    setMaximumSize(1200, 800);

	setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setWindowTitle(tr("Level Editor"));

	centerWidget();
	initializeWidgets();
	initializeComponets();
	createActions();
    createMenus();
    createToolBars();
    createStatusBar();
    setCurrentFile("");
    setUnifiedTitleAndToolBarOnMac(true);
}


MapEditor::~MapEditor()
{
	delete tileMap;
	delete tileList;
	delete collisionsList;
	delete entitiesList;
	delete tabWidget;
	delete gridCheckbox;
	delete widthLabel;
	delete heightLabel;
	delete widthBox;
	delete heightBox;
	delete layerOneCheckBox;
	delete layerTwoCheckBox;
	delete layerThreeCheckBox;
	delete layerFourCheckBox;
	delete layerFiveCheckBox;
	delete tileLayerOneButton;
	delete tileLayerTwoButton;
	delete tileLayerThreeButton;
}

void MapEditor::keyPressEvent(QKeyEvent *e)
{
	if (e->key() == Qt::Key_Escape)
		close();
	else
		QWidget::keyPressEvent(e);
}

void MapEditor::centerWidget()
{
	QDesktopWidget *desktop = QApplication::desktop();

	int width = frameGeometry().width();
	int height = frameGeometry().height();  

	int screenWidth = desktop->width();
	int screenHeight = desktop->height();

	int x = (screenWidth - width) / 2;
	int y = (screenHeight - height) / 2;

	move(x,y);
}


void MapEditor::initializeWidgets()
{
	tabWidget = new QTabWidget(this);
	tabWidget->setGeometry(5, 340, 173, 400);
	
	tileList = new MapElementList(tabWidget,"tiles.txt");
	collisionsList = new MapElementList(tabWidget,"collisions.txt");
	entitiesList = new MapElementList(tabWidget,"entities.txt");

	tileMap = new Map();

	tileList->setTileMap(tileMap);
	collisionsList->setTileMap(tileMap);
	entitiesList->setTileMap(tileMap);

	tabWidget->addTab(tileList, tr("Tiles"));
	tabWidget->addTab(collisionsList, tr("Collisions"));
	tabWidget->addTab(entitiesList, tr("Entities"));
	
	connect(tabWidget,SIGNAL(currentChanged(int)), tileMap, SLOT(changeCurrentLayer(int)));

	mapScroll = new QScrollArea(this);
	mapScroll->setGeometry(200,60,928,704);
	mapScroll->setFrameShape(QFrame::NoFrame);;
	mapScroll->setWidget(tileMap);

}

void MapEditor::initializeComponets()
{
	widthBox = new QSpinBox(this);
	widthBox->setGeometry(5,65,50,20);
	widthBox->setMinimum(0);
	widthBox->setMaximum(10000);
	widthBox->setValue(20);

	heightBox = new QSpinBox(this);
	heightBox->setGeometry(5,95,50,20);
	heightBox->setMinimum(0);
	heightBox->setMaximum(10000);
	heightBox->setValue(15);

	widthLabel = new QLabel("map width",this);
	heightLabel = new QLabel("map height",this);
	widthLabel->move(60,65);
	heightLabel->move(60,95);

	gridCheckbox = new QCheckBox("Show TileGrid", this);
	gridCheckbox->setCheckState(Qt::Checked);
	gridCheckbox->move(5,125);

	layerOneCheckBox = new QCheckBox("Show Tiles 1", this);
	layerOneCheckBox->s	etCheckState(Qt::Checked);
	layerOneCheckBox->move(5, 145);

	layerTwoCheckBox = new QCheckBox("Show Tiles 2", this);
	layerTwoCheckBox->setCheckState(Qt::Unchecked);
	layerTwoCheckBox->move(5, 165);

	layerThreeCheckBox = new QCheckBox("Show Tiles 3", this);
	layerThreeCheckBox->setCheckState(Qt::Unchecked);
	layerThreeCheckBox->move(5, 185);

	layerFourCheckBox = new QCheckBox("Show Collisions", this);
	layerFourCheckBox->setCheckState(Qt::Unchecked);
	layerFourCheckBox->move(5, 205);

	layerFiveCheckBox = new QCheckBox("Show Entities", this);
	layerFiveCheckBox->setCheckState(Qt::Unchecked);
	layerFiveCheckBox->move(5, 225);

	tileLayerOneButton = new QRadioButton("Tile Layer 1", this);
	tileLayerOneButton->toggle();
	tileLayerOneButton->move(5, 265);

	tileLayerTwoButton = new QRadioButton("Tile Layer 2", this);
	tileLayerTwoButton->move(5, 285);

	tileLayerThreeButton = new QRadioButton("Tile Layer 3", this);
	tileLayerThreeButton->move(5, 305);

	connect(widthBox, SIGNAL(valueChanged(int)), tileMap, SLOT(changeMapWidth(int)));
	connect(heightBox, SIGNAL(valueChanged(int)), tileMap, SLOT(changeMapHeight(int)));
	connect(gridCheckbox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileGrid(int)));
	connect(layerOneCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerOne(int)));
	connect(layerTwoCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerTwo(int)));
	connect(layerThreeCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerThree(int)));
	connect(layerFourCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showCollisionLayer(int)));
	connect(layerFiveCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showEntityLayer(int)));

	connect(tileLayerOneButton, SIGNAL(toggled(bool)), tileMap, SLOT(setTileLayerOne(bool)));
	connect(tileLayerTwoButton, SIGNAL(toggled(bool)), tileMap, SLOT(setTileLayerTwo(bool)));
	connect(tileLayerThreeButton, SIGNAL(toggled(bool)), tileMap, SLOT(setTileLayerThree(bool)));
}

 void MapEditor::createActions()
 {
	 newMapAction = new QAction(QIcon("images/new-icon.png"), tr("&New"), this);
     newMapAction->setShortcuts(QKeySequence::New);
     newMapAction->setStatusTip(tr("Create a new file"));

     openMapAction = new QAction(QIcon("images/open-icon.png"), tr("&Open..."), this);
     openMapAction->setShortcuts(QKeySequence::Open);
     openMapAction->setStatusTip(tr("Open an existing file"));

     saveMapAction = new QAction(QIcon("images/save-icon.png"), tr("&Save"), this);
     saveMapAction->setShortcuts(QKeySequence::Save);
     saveMapAction->setStatusTip(tr("Save the document to disk"));

     saveAsAction = new QAction(tr("Save &As..."), this);
     saveAsAction->setShortcuts(QKeySequence::SaveAs);
     saveAsAction->setStatusTip(tr("Save the document under a new name"));

     exitAction = new QAction(tr("E&xit"), this);
     exitAction->setShortcuts(QKeySequence::Quit);
     exitAction->setStatusTip(tr("Exit the application"));
     
     aboutAction = new QAction(tr("&About"), this);
     aboutAction->setStatusTip(tr("Show the application's About box"));

     aboutQtAction = new QAction(tr("About &Qt"), this);
     aboutQtAction->setStatusTip(tr("Show the Qt library's About box"));

	 clearMapAction = new QAction(QIcon("images/delete-icon.png"),tr("&Clear"),this);
	 clearMapAction->setStatusTip(tr("Clear map layer"));

	 fillMapAction = new QAction(QIcon("images/fill-icon.png"),tr("&Fill"),this);
	 fillMapAction->setStatusTip(tr("Fill map layer with selected Tile"));
	 
	 connect(newMapAction, SIGNAL(triggered()), this, SLOT(newFile()));
	 connect(openMapAction, SIGNAL(triggered()), this, SLOT(open()));
	 connect(saveMapAction, SIGNAL(triggered()), this, SLOT(save()));
	 connect(saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));
	 connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
	 connect(aboutAction, SIGNAL(triggered()), this, SLOT(about()));
	 connect(aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
	 connect(clearMapAction, SIGNAL(triggered()), this, SLOT(clear()));
	 connect(fillMapAction, SIGNAL(triggered()), this, SLOT(fill()));

 }

void MapEditor::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newMapAction);
    fileMenu->addAction(openMapAction);
    fileMenu->addAction(saveMapAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAction);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAction);
    helpMenu->addAction(aboutQtAction);
}

void MapEditor::createToolBars()
{
	fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newMapAction);
    fileToolBar->addAction(openMapAction);
    fileToolBar->addAction(saveMapAction);
	fileToolBar->addAction(clearMapAction);
	fileToolBar->addAction(fillMapAction);
}

void MapEditor::createStatusBar()
{
	statusBar()->showMessage(tr("Ready"));
}

void MapEditor::newFile()
{
	delete tileMap;
	widthBox->setValue(20);
	heightBox->setValue(15);

	tileMap = new Map();
	tileList->setTileMap(tileMap);
	mapScroll->setWidget(tileMap);
	connect(gridCheckbox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileGrid(int)));
	connect(widthBox, SIGNAL(valueChanged(int)), tileMap, SLOT(changeMapWidth(int)));
	connect(heightBox, SIGNAL(valueChanged(int)), tileMap, SLOT(changeMapHeight(int)));
	connect(layerOneCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerOne(int)));
	connect(layerTwoCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerTwo(int)));
	connect(layerThreeCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerThree(int)));
	connect(layerFourCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showCollisionLayer(int)));
	connect(layerFiveCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showEntityLayer(int)));

    setCurrentFile("");
	update();
}

void MapEditor::open()
{
	QString fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty())
		loadFile(fileName);
}

bool MapEditor::save()
{
	if (currentFile.isEmpty())
		return saveAs();
	else
		return saveFile(currentFile);
}

bool MapEditor::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this);
	setCurrentFile(fileName);
    if (fileName.isEmpty())
		return false;

    return saveFile(fileName);
}

void MapEditor::clear()
{
	tileMap->clearMap();
}

void MapEditor::fill()
{
	tileMap->fillMap();
}

void MapEditor::about()
{
	QMessageBox::about(this, tr("MapEditor"),
             tr("The <b>MapEditor</b> is tool made by <b> Szymon ""Veldrin"" Jablonski  </b>, "
			 "memebr of Polygon, Warsaw University of Technology Game Development team "
			 "for platformer game AlleMario, clone of popular Super Mario Bros game "
			 "made by Nintendo. Editor also can be used for any kind of tile-based game."
			 "It is Open-source project, for non-commercial use."));
}


void MapEditor::loadFile(const QString &fileName)
{
	QFile mapFile(fileName);
	int loadMapWidth = 0;
	int loadMapHeight = 0;
	int tileID = 0;

	if (mapFile.open(QFile::ReadOnly))
	{
		QTextStream in(&mapFile);
		QPixmap pixmap = NULL;
  
		in >> loadMapWidth;
		in >> loadMapHeight;

		delete tileMap;
		widthBox->setValue(loadMapWidth);
		heightBox->setValue(loadMapHeight);
		tileMap = new Map(this,loadMapWidth,loadMapHeight);
		tileList->setTileMap(tileMap);
		mapScroll->setWidget(tileMap);
		connect(gridCheckbox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileGrid(int)));
		connect(widthBox, SIGNAL(valueChanged(int)), tileMap, SLOT(changeMapWidth(int)));
		connect(heightBox, SIGNAL(valueChanged(int)), tileMap, SLOT(changeMapHeight(int)));
		connect(tabWidget,SIGNAL(currentChanged(int)), tileMap, SLOT(changeCurrentLayer(int)));
		connect(layerOneCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerOne(int)));
		connect(layerTwoCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerTwo(int)));
		connect(layerThreeCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showTileLayerThree(int)));
		connect(layerFourCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showCollisionLayer(int)));
		connect(layerFiveCheckBox, SIGNAL(stateChanged(int)), tileMap, SLOT(showEntityLayer(int)));

		for(int i = 0; i < tileMap->getMapHeight(); i++)
		{
			for(int j = 0; j < tileMap->getMapWidth(); j++)
			{

				in >> tileID;
				if(tileID != -1)
				{
					pixmap = tileList->findTileByID(tileID);
					tileMap->addTilePosition(QPoint(j*32,i*32),0);
					tileMap->addTilePixmap(pixmap,0);
				}
				tileMap->setMapStructureCell(i,j,tileID,0);

				in >> tileID;
				if(tileID != -1)
				{
					pixmap = tileList->findTileByID(tileID);
					tileMap->addTilePosition(QPoint(j*32,i*32),1);
					tileMap->addTilePixmap(pixmap,1);
				}
				tileMap->setMapStructureCell(i,j,tileID,1);

				in >> tileID;
				if(tileID != -1)
				{
					pixmap = tileList->findTileByID(tileID);
					tileMap->addTilePosition(QPoint(j*32,i*32),2);
					tileMap->addTilePixmap(pixmap,2);
				}
				tileMap->setMapStructureCell(i,j,tileID,2);

				in >> tileID;
				if(tileID != -1)
				{
					pixmap = collisionsList->findTileByID(tileID);
					tileMap->addTilePosition(QPoint(j*32,i*32),3);
					tileMap->addTilePixmap(pixmap,3);
				}
				tileMap->setMapStructureCell(i,j,tileID,3);

				in >> tileID;
				if(tileID != -1)
				{
					pixmap = entitiesList->findTileByID(tileID);
					tileMap->addTilePosition(QPoint(j*32,i*32),4);
					tileMap->addTilePixmap(pixmap,4);
				}
				tileMap->setMapStructureCell(i,j,tileID,4);
			}
		}
		
		update();
	}
	else
		qDebug("Unable to open file");

}

bool MapEditor::saveFile(const QString &fileName)
{
	QFile mapFile(fileName);

	if (mapFile.open(QFile::WriteOnly | QIODevice::Text))
	{
		QTextStream outStream(&mapFile);

		outStream << tileMap->getMapWidth() << endl;
		outStream << tileMap->getMapHeight() << endl;

		for(int i = 0; i < tileMap->getMapHeight(); i++)
		{
			for(int j = 0; j < tileMap->getMapWidth(); j++)
			{
				for(int k = 0; k < 5; k++)
				{
					outStream << tileMap->getMapLayers()[k].mapStructure[i][j];
					outStream << " ";
				}

				outStream << endl;
			}

		}
		return true;
	}
	else
		qDebug("Unable to open file");

	return false;
}

void MapEditor::setCurrentFile(const QString &fileName)
{
	currentFile = fileName;
    QString shownName = currentFile;
    if (currentFile.isEmpty())
        shownName = "untitled.txt";
    setWindowFilePath(shownName);
}


