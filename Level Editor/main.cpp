/**
 * Entry point of MapEditor application
 * @file    main.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-08-23
 * @version 1.0
 */

#include <QtGui/QApplication>
#include "MapEditor.h"


int main(int argc, char *argv[])
{
	QApplication levelEditor(argc, argv);
	MapEditor window;
	window.setWindowIcon(QIcon("images/Mushroom.png"));
	window.show();
	return levelEditor.exec();
}
