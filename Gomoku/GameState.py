#!/usr/bin/python

# Projekt PSZT - Gomoku

# File contains definition of game possible states used for controlling game
# loop. We use State pattern.

# Szymon Jablonski & Michal Andrzejewski
# 10.11.2010
# GameState.py

import sys
from PyQt4 import QtGui, QtCore

import random
import time


#Abstract Game State class. All game states must extend GameState class
#and implement permonAction method.
class GameState:
    def __init__(self):
        pass
        
    def performAction(self):
        pass
    

# Default initial state, player can set game options, read about game rules
# and start new game -> this will change state to PlayerMove state or AIMove
# State. The game will be controlled by iteration of states not game loop.
class IdleState(GameState):
    def __init__(self,gameBoard):
        GameState.__init__(self)
        self.gameBoard = gameBoard

    # State standard method, block gameBoard mouse slots. Player can't make
    # move.
    def performAction(self):
        self.gameBoard.setEnabled(False)

# Player State - user can make move. This state is set after AIMoveState perform
# their action and didn't win or if game was started and Player have first move.
class PlayerMoveState(GameState):
    def __init__(self,gameBoard):
        GameState.__init__(self)
        self.gameBoard = gameBoard

    # State standard method, enable gameBoard mouse slots. Player can make
    # move.
    def performAction(self):
        self.gameBoard.setEnabled(True)

# AIState - computer will use   alpha-beta algorithm to find best move to win with Player.
# This state is set after PlayerMoveState perform their action and didn't win or if game
# was started and AI have first move.
class AIMoveState(GameState):
    INFINITY = 1000000

    def __init__(self, gameBoard):
        GameState.__init__(self)
        self.gameBoard = gameBoard

    # Alpha-beta algorithm or random move. Also disable gameBoard to avoid Player movement.
    # for test - random to test game loop.
    def performAction(self):
        self.gameBoard.setEnabled(False)
        useAB = True

        maxDepth = self.gameBoard.gameWindow.maxDepth
        maxTime = self.gameBoard.gameWindow.maxTime
        useTime = self.gameBoard.gameWindow.useTime
        useDepth = self.gameBoard.gameWindow.useDepth

        if useAB == False: # make random move
            print 'Using random move generator'
            x = random.randint(0, self.gameBoard.boardSize - 2)
            y = random.randint(0, self.gameBoard.boardSize - 2)
            
            while(self.gameBoard.isValidMove(x, y) == False):
                x = random.randint(0, self.gameBoard.boardSize - 2)
                y = random.randint(0, self.gameBoard.boardSize - 2)

            if(self.gameBoard.gameWindow.playerFigure == 1):
                self.gameBoard.board[x][y] = 2
            else:
                self.gameBoard.board[x][y] = 1
        else: # make move based on minimax AB algorithm
            if useTime is True:
                print 'Using time constraint: %f' % maxTime
                tmpDepth = 0
                move, val = None, None
                while maxTime > 0.0:
                    tmpDepth += 1
                    start = time.clock()
                    move, val = self.minimax(self.gameBoard, tmpDepth)
                    end = time.clock()
                    maxTime -= (end - start)
                    print ("Time elapsed: %f, time left: %f, depth: %d" % ((end-start), maxTime, tmpDepth))
                flag = self.gameBoard.addAIStone(move[0], move[1], self.gameBoard.gameWindow.aiFigure)

            elif useDepth is True:
                print 'Depth: %d' % maxDepth
                start = time.clock()
                move, val = self.minimax(self.gameBoard, maxDepth)
                end = time.clock()
                print end - start
                flag = self.gameBoard.addAIStone(move[0], move[1], self.gameBoard.gameWindow.aiFigure)

        winner = self.gameBoard.checkForGameOver()
        if winner is not None:
            self.gameBoard.AIGameOver(winner)
        self.gameBoard.setEnabled(True)

    def minimax(self, board, depth):
        (move, val) = self.alphabeta(board, depth, -1000000, 1000000, self.gameBoard.gameWindow.aiFigure)
        return (move, val)

    # Alpha-beta pruning algorithm
    def alphabeta(self, game, depth, alpha, beta, figure):
        if game.checkForGameOver() == self.gameBoard.gameWindow.aiFigure:
            return ((-1, -1), 100000)

        if game.checkForGameOver() == self.gameBoard.gameWindow.playerFigure:
            return ((-1, -1), -100000)

        if depth == 0:
            eval_ = heval(game.board, game.boardSize, self.gameBoard.gameWindow.aiFigure) - heval(game.board, game.boardSize, self.gameBoard.gameWindow.playerFigure)
            return ((-1, -1), eval_)

        if figure == self.gameBoard.gameWindow.aiFigure: # player MAX (AI)
            bestMove = None
            for move in game.getValidMoves():
                g = game.copy()
                g.addAIStone(move[0], move[1], figure)
                (move_, val_) = self.alphabeta(g, depth-1, alpha, beta, self.gameBoard.gameWindow.playerFigure)
                if val_ > alpha:
                    alpha = val_
                    bestMove = move
                if alpha >= beta:
                    return (bestMove, beta)
            if bestMove == None:
                bestMove = game.getValidMoves()[0]
            return (bestMove, alpha)
        else: # player MIN
            bestMove = None
            for move in game.getValidMoves():
                g = game.copy()
                g.addAIStone(move[0], move[1], figure)
                (move_, val_) = self.alphabeta(g, depth-1, alpha, beta, self.gameBoard.gameWindow.aiFigure)
                if val_ < beta:
                    beta = val_
                    bestMove = move
                if alpha >= beta:
                    return (bestMove, alpha)
            if bestMove == None:
                bestMove = game.getValidMoves()[0]
            return (bestMove, beta)

# Evaluate score for given figures and board
def heval(board, boardSize, figure):
    value = 0
    arange = [2, 3, 4, 5]

    for a in arange:
        krange = range(0, a)
        # Analyze columns     
        for i in range(0, boardSize):
            for j in range(0, boardSize - len(krange) + 1):
                flag = True
                for k in krange:
                    if(board[i][j+k] != figure):
                        flag = False
                        break
                if flag == True:
                    value += 10*a

        # Analyze rows
        for j in range(0, boardSize):
            for i in range(0, boardSize - len(krange) + 1):
                flag = True
                for k in krange:
                    if(board[i+k][j] != figure):
                        flag = False
                        break
                if flag == True:
                    value += 10*a

        # Analyze canonical diagonal
        for i in range(0, boardSize - len(krange) + 1):
            for j in range(0, boardSize - len(krange) + 1):
                flag = True
                for k in krange:
                    if(board[i+k][j+k] != figure):
                        flag = False
                        break
                if flag == True:
                    value += 10*a

        # Analyze non-canonical diagonal
        for i in range(len(krange)-1, boardSize):
            for j in range(0, boardSize - len(krange) + 1):
                flag = True
                for k in krange:
                    if(board[i-k][j+k] != figure):
                        flag = False
                        break
                if flag == True:
                    value += 10*a
    return value
