#!/usr/bin/python

# Projekt PSZT - Gomoku

# File contains definition of game main widnow class GameWindow,

# Szymon Jablonski
# 10.11.2010
# GameWindow.py 

import sys
from PyQt4 import QtGui, QtCore

from GameBoard import GameBoard
from GameState import IdleState
from GameState import PlayerMoveState
from GameState import AIMoveState


# Game main class used to iniailize main window with menu, status bar etc.
class GameWindow(QtGui.QMainWindow):
    def __init__(self):
        QtGui.QMainWindow.__init__(self)

        self.resize(500, 540)
        self.setMaximumSize(500,540)
        self.setMinimumSize(500,540)
        self.setWindowTitle('PSZT Gomoku Game')
        self.setWindowIcon(QtGui.QIcon('ico.png'))
        self.centerWindow()

        self.initializeGame()
        self.gameBoard = GameBoard(self)
        self.setCentralWidget(self.gameBoard)

        self.initializeState()
        self.initializeMenu()
        self.statusBar()    

    # Method is used to initialize Menu
    def initializeMenu(self):
        self.newGame = QtGui.QAction(QtGui.QIcon('newGame.png'),'New game',self)
        self.newGame.setShortcut('Ctrl+N')
        self.newGame.setStatusTip('Star new game')
        self.connect(self.newGame,QtCore.SIGNAL('triggered()'),self.slotNewGameAction)

        self.options = QtGui.QAction(QtGui.QIcon('options.png'),'Options',self)
        self.options.setShortcut('Ctrl+O')
        self.options.setStatusTip('Configure options')
        self.connect(self.options, QtCore.SIGNAL('triggered()'), self.slotOptionsAction)
                
        self.exit = QtGui.QAction(QtGui.QIcon('exit.png'), 'Exit', self)
        self.exit.setShortcut('Ctrl+Q')
        self.exit.setStatusTip('Exit application')
        self.connect(self.exit, QtCore.SIGNAL('triggered()'), QtCore.SLOT('close()'))

        self.about = QtGui.QAction(QtGui.QIcon('about.png'),'About',self)
        self.about.setShortcut('Ctrl+A')
        self.about.setStatusTip('Read about Game and autors')
        self.connect(self.about,QtCore.SIGNAL('triggered()'),self.slotAboutAction)

        self.aboutPyQt = QtGui.QAction(QtGui.QIcon('aboutPyQt.png'),'About PyQt',self)
        self.aboutPyQt.setShortcut('Ctrl+T')
        self.aboutPyQt.setStatusTip('Read about PyQt')
        self.connect(self.aboutPyQt,QtCore.SIGNAL('triggered()'),self.slotAboutPyQtAction)
        
        menubar = self.menuBar()
        file = menubar.addMenu('&Game')
        file.addAction(self.newGame)
        file.addAction(self.options)
        file.addAction(self.exit)
        help = menubar.addMenu('&Help')
        help.addAction(self.about)
        help.addAction(self.aboutPyQt)

        self.initializeOptions()

    # Method is used to initialize Game Options Widget
    def initializeOptions(self):
        self.options = QtGui.QWidget()
        self.options.resize(400, 200)
        self.options.setMaximumSize(400,200)
        self.options.setMinimumSize(400,200)
        self.options.setWindowTitle('PSZT Gomoku Game - Options')
        self.options.setWindowIcon(QtGui.QIcon('options.png'))                
        screen = QtGui.QDesktopWidget().screenGeometry()
        size = self.options.geometry()
        self.options.move((screen.width()-size.width())/2, (screen.height()-size.height())/2)

        # Init board size options
        self.options.setBoardSize = QtGui.QLabel("Set Board size:",self.options)
        self.options.setBoardSize.move(20,10)
        self.options.boardSizeBox = QtGui.QSpinBox(self.options)
        self.options.boardSizeBox.setGeometry(20,30,50,20)
        self.options.boardSizeBox.setMinimum(7)
        self.options.boardSizeBox.setMaximum(25)
        self.options.boardSizeBox.setValue(25)
        self.options.boardSizeBox.setSingleStep(2)
        self.options.sizeValue = 27

       # Init alpha-beta options
        self.options.setABDepth = QtGui.QLabel("Set A-B depth:",self.options)
        self.options.setABDepth.move(150,10)
        self.options.depthBox = QtGui.QSpinBox(self.options)
        self.options.depthBox.setGeometry(150,30,50,20)
        self.options.depthBox.setMinimum(1)
        self.options.depthBox.setMaximum(10)
        self.options.depthBox.setValue(2)

        self.options.setMaxSearchTime = QtGui.QLabel("Set max. search time:",self.options)
        self.options.setMaxSearchTime.move(230,10)
        self.options.timeBox = QtGui.QDoubleSpinBox(self.options)
        self.options.timeBox.setGeometry(230,30,50,20)
        self.options.timeBox.setMinimum(0.1)
        self.options.timeBox.setMaximum(10.0)
        self.options.timeBox.setValue(3.0)
        self.options.timeBox.setSingleStep(0.1)

        # backup values
        self.options.depthValue = 2
        self.options.timeValue = 3.0
        
        self.connect(self.options.boardSizeBox,QtCore.SIGNAL('valueChanged(int)'),self.slotBoardSize)
        self.connect(self.options.timeBox,QtCore.SIGNAL('valueChanged(double)'),self.slotMaxTime)
        self.connect(self.options.depthBox,QtCore.SIGNAL('valueChanged(int)'),self.slotMaxDepth)


        self.options.abButtonGroup = QtGui.QButtonGroup()

        self.options.chooseABValue = QtGui.QLabel("Choose A-B value:",self.options)
        self.options.chooseABValue.move(180,80)

        self.options.useDepth = QtGui.QRadioButton("Use depth",self.options)
        self.options.useDepth.move(180,100)
        self.connect(self.options.useDepth, QtCore.SIGNAL('pressed()'), self.slotUseDepth)
        
        self.options.useTime = QtGui.QRadioButton("Use time",self.options)
        self.options.useTime.move(180,120)
        self.options.useTime.toggle()
        self.connect(self.options.useTime, QtCore.SIGNAL('pressed()'), self.slotUseTime)

        self.options.abButtonGroup.addButton(self.options.useDepth)
        self.options.abButtonGroup.addButton(self.options.useTime)

        # backup values
        self.options.useDepthValue = False
        self.options.useTimeValue = True

        # Init figure options
        self.options.figureButtonGroup = QtGui.QButtonGroup()

        self.options.choosePlayerFigure = QtGui.QLabel("Choose Player figure:",self.options)
        self.options.choosePlayerFigure.move(20,80)

        self.options.useWhite = QtGui.QRadioButton("Use white",self.options)
        self.options.useWhite.move(20,100)
        self.connect(self.options.useWhite, QtCore.SIGNAL('pressed()'), self.slotUseWhite)

        self.options.useBlack = QtGui.QRadioButton("Use black",self.options)
        self.options.useBlack.move(20,120)
        self.options.useBlack.toggle()
        self.connect(self.options.useBlack, QtCore.SIGNAL('pressed()'), self.slotUseBlack)

        self.options.figureButtonGroup.addButton(self.options.useBlack)
        self.options.figureButtonGroup.addButton(self.options.useWhite)

        # backup values
        self.options.playerFigureValue = 2
        self.options.aiFigureValue = 1
        self.options.playerFirstMoveValue = True

        self.options.okButton = QtGui.QPushButton("OK",self.options)
        self.options.okButton.move(20,160)

        self.options.cancelButton = QtGui.QPushButton("Cancel",self.options)
        self.options.cancelButton.move(180,160)

        self.connect(self.options.okButton, QtCore.SIGNAL('pressed()'), self.okClose)                                                               
        self.connect(self.options.cancelButton, QtCore.SIGNAL('pressed()'), self.options.close)

    # Method is used to confirm option changes and close options window.
    def okClose(self):
        self.boardSize = self.options.sizeValue
        self.gameBoard.boardSize = self.boardSize
        self.gameBoard.update()
        self.maxDepth = self.options.depthValue
        self.maxTime = self.options.timeValue
        self.useTime = self.options.useTimeValue
        self.useDepth = self.options.useDepthValue
        self.playerFigure = self.options.playerFigureValue
        self.aiFigure = self.options.aiFigureValue
        self.playerFirstMove =self.options.playerFirstMoveValue
        
        self.options.close()

    # Method is used to set game board size.
    def slotBoardSize(self,value):
        self.options.sizeValue = value +2

    # Method is used to set max search depth of alpha-beta algorithm.
    def slotMaxDepth(self,value):
        self.options.depthValue = value

    # Method is used to set max search time of alpha-beta algorithm.
    def slotMaxTime(self,value):
        self.options.timeValue = value
    
    # Method is used to set that alpha-beta will use time bound.
    def slotUseTime(self):
        if(self.options.useTime.isDown):
            self.options.useTimeValue = True
            self.options.useDepthValue = False

    # Method is used to set that alpha-beta will use depth boudn.
    def slotUseDepth(self):
        if(self.options.useDepth.isDown):
            self.options.useTimeValue = False
            self.options.useDepthValue = True

    # Method is used to set that Player will use white figure and starts second.
    def slotUseWhite(self):
        if(self.options.useWhite.isDown):
            self.options.playerFigureValue = 1
            self.options.aiFigureValue = 2
            self.options.playerFirstMoveValue = False
            self.aiFigure = 2

    # Method is used to set that Player will use black figure and starts first.
    def slotUseBlack(self):
        if(self.options.useBlack.isDown):
            self.options.playerFigureValue = 2
            self.options.aiFigureValue = 1
            self.options.playerFirstMoveValue = True
            self.aiFigure = 1

    # Method is used to initialize game
    def initializeGame(self):
        self.boardSize = 27
        self.maxDepth = 2
        self.maxTime = 0.1
        self.useTime = True
        self.useDepth = False
        self.playerFigure = 2
        self.aiFigure = 1
        self.playerFirstMove = True

    # Method is used to initialize game state.
    def initializeState(self):
        # set initial game state - Idle
        self.gameState = IdleState(self.gameBoard)
        self.gameState.performAction()

    # Method is used to center widnow on screen.
    def centerWindow(self):
        screen = QtGui.QDesktopWidget().screenGeometry()
        size =  self.geometry()
        self.move((screen.width()-size.width())/2, (screen.height()-size.height())/2)

    # Method is used to catch key press event.
    def keyPressEvent(self, event):
        if event.key() == QtCore.Qt.Key_Escape:
            self.close()

    # Method is used to start game.
    def slotNewGameAction(self):
        self.disconnect(self.options.boardSizeBox,QtCore.SIGNAL('valueChanged(int)'),self.slotBoardSize)
        #self.options.boardSizeBox.disconnect()
        self.gameBoard = GameBoard(self)
        self.setCentralWidget(self.gameBoard)
        self.gameBoard.initializeGameBoard()
        self.gameBoard.update()

        if(self.playerFirstMove == True):
            self.gameState = PlayerMoveState(self.gameBoard)
        else:
            self.gameState = AIMoveState(self.gameBoard)
            
        self.gameState.performAction()

    # Method is used to show options.
    def slotOptionsAction(self):
        self.options.activateWindow()
        self.options.setVisible(True)
    
    # Method is used to execute about action. Show game rules and credits.
    def slotAboutAction(self):
        QtGui.QMessageBox.about(self,"Gomoku", "Game Gomoku with Alpha-beta AI algorithm "
                                "developed by Michal Andrzejewski and Szymon Jablonski, students "
                                "of Warsaw University of Technology for Basics of Artificial Intelligence course.")

    # Method is used to execute aboutPyQt action. Show information about Qt.
    def slotAboutPyQtAction(self):
        QtGui.QMessageBox.aboutQt(self)

    # Method is used to set game to gameOver state, show winner and close
    # application.
    def gameOver(self, winner):
        #enter idle state
        self.gameState = IdleState(self.gameBoard)
        self.gameState.performAction()
        self.over = QtGui.QWidget()
        self.over.resize(300, 200)
        self.over.setMaximumSize(300,200)
        self.over.setMinimumSize(300,200)
        self.over.setWindowTitle('PSZT Gomoku Game - Game Over!')
        self.over.setWindowIcon(QtGui.QIcon('options.png'))                
        screen = QtGui.QDesktopWidget().screenGeometry()
        size = self.over.geometry()
        self.over.move((screen.width()-size.width())/2, (screen.height()-size.height())/2)

        if winner == self.aiFigure:
            self.over.winnerLabel = QtGui.QLabel("AI won!",self.over)
        elif winner == self.playerFigure:
            self.over.winnerLabel = QtGui.QLabel("Player won!",self.over)
        elif winner == 0:
            self.over.winnerLabel = QtGui.QLabel("Draw!",self.over)

        self.over.winnerLabel.move(110,40)

        self.over.exitButton = QtGui.QPushButton("Exit",self.over)
        self.over.exitButton.move(100,75)
        
        self.over.activateWindow()
        self.over.setVisible(True)
        
        self.connect(self.over.exitButton, QtCore.SIGNAL('pressed()'), self.exitSlot)

    # Method is used to close application.
    def exitSlot(self):
        self.over.close()
        self.close()


                   

        

