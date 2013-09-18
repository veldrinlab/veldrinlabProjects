/**
 * MapEditor.h
 *
 *  Created on: 2010-08-23
 *      Author: Szymon Jab³oñski - Veldrin
 */

#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <QtGui>
#include <QCheckBox>
#include <QLabel>
#include <QSpinBox>
#include <QTabWidget>

#include "Map.h"
#include "MapElementList.h" 

class MapEditor : public QMainWindow
{
	Q_OBJECT
		
private:
	Map* tileMap;
	MapElementList *tileList;
	MapElementList *collisionsList;
	MapElementList *entitiesList;
	QTabWidget *tabWidget;
	QScrollArea* mapScroll;
		
	QSpinBox* widthBox;
	QSpinBox* heightBox;
	QLabel* widthLabel;
	QLabel* heightLabel;

	QCheckBox* gridCheckbox;
	QCheckBox* layerOneCheckBox;
	QCheckBox* layerTwoCheckBox;
	QCheckBox* layerThreeCheckBox;
	QCheckBox* layerFourCheckBox;
	QCheckBox* layerFiveCheckBox;
	QRadioButton* tileLayerOneButton;
	QRadioButton* tileLayerTwoButton;
	QRadioButton* tileLayerThreeButton;

	QString currentFile;
    QMenu *fileMenu;
	QMenu *helpMenu;
    QToolBar *fileToolBar;
    QAction *newMapAction;
    QAction *openMapAction;
    QAction *saveMapAction;
    QAction *saveAsAction;
    QAction *exitAction;
	QAction *aboutAction;
    QAction *aboutQtAction;
	QAction *clearMapAction;
	QAction *fillMapAction;

	void centerWidget();

	void initializeWidgets();
	void initializeComponets();
	void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();

    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);

private slots:
	void newFile();
    void open();
    bool save();
    bool saveAs();
	void clear();
	void fill();
    void about();

protected:
	void keyPressEvent(QKeyEvent *event);	

public:
	MapEditor(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MapEditor();

};
#endif
