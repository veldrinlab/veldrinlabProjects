/**
 * File contains declaration of main game class - Game.
 * @file    Game.h
 * @author  Szymon "Veldrin" Jab³oñski & Adam Sznajder
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef GAME_H
#define GAME_H

#include "WindowManager.h"
#include "InputManager.h"
#include "Timer.h"
#include "Renderer.h"
#include "CollisionDetector.h"
#include "GameState.h"

/**
 * Game main class.
 * @remarks
 */
class Game
{
private:
	WindowManager* gameWindow;
	InputManager* gameInput;
	SceneManager* gameScene;
	Timer* gameTimer;
	Renderer* gameRenderer;
	CollisionDetector* detector;
	CollisionHandler* handler;
	
	GameState* actualState;
	bool gameDone;

public:
	Game();
	~Game();

	void doSomeMagic();

	WindowManager* getGameWindow() const;
	InputManager* getGameInput() const;
	SceneManager* getGameScene() const;
	Timer* getGameTimer() const;
	Renderer* getGameRenderer() const;
	CollisionDetector* getDetector() const;
	CollisionHandler* getHandler() const;
	GameState* getActualState() const;
	bool isGameDone() const;
	void setGameDone(const bool done);
	void setGameState(GameState* gameState);
};
#endif
