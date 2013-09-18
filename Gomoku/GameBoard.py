#!/usr/bin/python

# File contains definition of GameBoard class.

# Szymon Jablonski & Michal Andrzejewski
# 10.11.2010
# GameBoard.py

import sys
from PyQt4 import QtGui, QtCore
from GameState import AIMoveState
from GameState import IdleState

#Game board widget class
class GameBoard(QtGui.QWidget):

    # Class default constructor
    def __init__(self, gameWindow, oldgame = None, parent=None):
        if oldgame == None:
            QtGui.QWidget.__init__(self, parent)
            self.gameWindow = gameWindow
            self.boardSize = gameWindow.boardSize
            self.stonesOnBoard = 0
            self.initializeGameBoard()
            self.initializeResources()
            self.setEnabled(False)
        else:
            self.gameWindow = oldgame.gameWindow
            self.boardSize = oldgame.boardSize
            self.stonesOnBoard = oldgame.stonesOnBoard
            self.board = [[oldgame.board[i][j] for j in range(self.boardSize)] for i in range(self.boardSize)]

    # Copy constructor
    def copy(self):
        return GameBoard(self.gameWindow, self)
        
    # Method used to initialize boardSize x boardSize game board
    def initializeGameBoard(self):
        self.board = [[0 for col in range(self.boardSize)] for row in range(self.boardSize)]

    # Method used to load and initialize graphic resources for game
    def initializeResources(self):
        self.white = QtGui.QPixmap("white.png")
        self.black = QtGui.QPixmap("black.png")

    # Method used to catch mouse press event to set White or Black figure to game board by user.
    def mousePressEvent(self,event):
        x = event.pos().x() / (500/self.boardSize)
        y = event.pos().y() / (500/self.boardSize)
        self.addStone(x, y, self.gameWindow.playerFigure)

    # Add stone method used for generating next state during A-B
    def addAIStone(self, x, y, figure):
        if(self.isValidMove(x, y)):
            self.stonesOnBoard += 1
            self.board[x][y] = figure
            return True
        else:
            return False

    def AIGameOver(self, winner):
        if winner is not None:
            self.gameWindow.gameOver(winner)


    # Add stone of given player to the board
    def addStone(self, x, y, figure):
        if(self.isValidMove(x, y)):
            self.stonesOnBoard += 1
            self.board[x][y] = figure
            self.update()
            winner = self.checkForGameOver()
            if winner is not None:
                self.gameWindow.gameOver(winner)
            else:
                self.gameWindow.gameState = AIMoveState(self)
                self.gameWindow.gameState.performAction()
            return True
        else:
            return False

    # Method used to paint game board widget with actual game state.
    def paintEvent(self, event):
        paint = QtGui.QPainter()
        paint.begin(self)
        paint.setPen(QtCore.Qt.black)
        size = self.size()

        paint.setBrush(QtGui.QColor(211, 163, 65, 255))
        paint.drawRect(0,0,500,500)

        for i in range(1, self.boardSize-1):
            paint.drawLine(500/(self.boardSize-1),i*500/(self.boardSize-1),(500-(500/(self.boardSize-1))-1),i*500/(self.boardSize-1))
            paint.drawLine(i*500/(self.boardSize-1),500/(self.boardSize-1),i*500/(self.boardSize-1),(500-(500/(self.boardSize-1))-1))

        for i in range(1, self.boardSize-1):
            for j in range(1, self.boardSize-1):
                if(self.board[i][j] == 1):
                    paint.drawPixmap(((i)*(500/(self.boardSize-1)))-((500/(self.boardSize-1))/2),(j)*(500/(self.boardSize-1))-((500/(self.boardSize-1))/2),(500/(self.boardSize-1)),(500/(self.boardSize-1)),self.white)
                if (self.board[i][j] == 2):
                    paint.drawPixmap(((i)*(500/(self.boardSize-1)))-((500/(self.boardSize-1))/2),(j)*(500/(self.boardSize-1))-((500/(self.boardSize-1))/2),(500/(self.boardSize-1)),(500/(self.boardSize-1)),self.black)

        paint.end()

    # Check if move satisfies Gomoku rules
    def isValidMove(self, x, y):
        if x < 0 or x >= self.boardSize or y < 0 or y >= self.boardSize:
            return False

        if self.stonesOnBoard == 0:
            if x == self.boardSize/2 and y == self.boardSize/2:
                return True
            else:
                return False

        if self.board[x][y] != 0:
            return False

        if x > 0 and x < self.boardSize-1 and y > 0 and y < self.boardSize-1:
            if self.board[x-1][y] == 0 and self.board[x+1][y] == 0 and self.board[x][y-1] == 0 and self.board[x][y+1] == 0 and self.board[x-1][y-1] == 0 and self.board[x-1][y+1] == 0 and self.board[x+1][y-1] == 0 and self.board[x+1][y+1] == 0:
                return False
            else:
                return True
        return False

    # Get list of tuples of valid moves in current board configuration
    def getValidMoves(self):
        returnList = list()
        for i in range(0, self.boardSize):
            for j in range(0, self.boardSize):
                if self.isValidMove(i, j):
                    returnList.append((i, j))
        return returnList


        
    # Method is used to check if Player or AI win the game -> Game Over
    def checkForGameOver(self):
        # draw
        if self.stonesOnBoard == self.boardSize * self.boardSize:
            return 0

        krange = [0, 1, 2, 3, 4]

        # Analyze columns     
        for i in range(0, self.boardSize):
            for j in range(0, self.boardSize - 4):
                playerFlag = True
                aiFlag = True
                for k in krange:
                    if(self.board[i][j+k] != self.gameWindow.playerFigure):
                        playerFlag = False
                    if(self.board[i][j+k] != self.gameWindow.aiFigure):
                        aiFlag = False
                    if aiFlag == False and playerFlag == False:
                        break
                if playerFlag == True:
                    return self.gameWindow.playerFigure
                if aiFlag == True:
                    return self.gameWindow.aiFigure

        # Analyze rows
        for j in range(0, self.boardSize):
            for i in range(0, self.boardSize - 4):
                playerFlag = True
                aiFlag = True
                for k in krange:
                    if(self.board[i+k][j] != self.gameWindow.playerFigure):
                        playerFlag = False
                    if(self.board[i+k][j] != self.gameWindow.aiFigure):
                        aiFlag = False
                    if aiFlag == False and playerFlag == False:
                        break
                if playerFlag == True:
                    return self.gameWindow.playerFigure
                if aiFlag == True:
                    return self.gameWindow.aiFigure

        # Analyze canonical diagonal
        for i in range(0, self.boardSize - 4):
            for j in range(0, self.boardSize - 4):
                playerFlag = True
                aiFlag = True
                for k in krange:
                    if(self.board[i+k][j+k] != self.gameWindow.playerFigure):
                        playerFlag = False
                    if(self.board[i+k][j+k] != self.gameWindow.aiFigure):
                        aiFlag = False
                    if aiFlag == False and playerFlag == False:
                        break
                if playerFlag == True:
                    return self.gameWindow.playerFigure
                if aiFlag == True:
                    return self.gameWindow.aiFigure

        # Analyze non-canonical diagonal
        for i in range(4, self.boardSize):
            for j in range(0, self.boardSize - 4):
                playerFlag = True
                aiFlag = True
                for k in krange:
                    if(self.board[i-k][j+k] != self.gameWindow.playerFigure):
                        playerFlag = False
                    if(self.board[i-k][j+k] != self.gameWindow.aiFigure):
                        aiFlag = False
                    if aiFlag == False and playerFlag == False:
                        break
                if playerFlag == True:
                    return self.gameWindow.playerFigure
                if aiFlag == True:
                    return self.gameWindow.aiFigure
        return None

