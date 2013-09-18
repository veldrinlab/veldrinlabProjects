#!/usr/bin/python

# Projekt PSZT - Gomoku

# File contains entry point of the application.

# Szymon Jablonski
# 10.11.2010
# main.py 

import sys
from PyQt4 import QtGui
from PyQt4 import QtCore

from GameWindow import GameWindow

# Entry point of application.
app = QtGui.QApplication(sys.argv)
main = GameWindow()
main.show()
app.exec_()
