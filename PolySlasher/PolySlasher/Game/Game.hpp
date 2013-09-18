/**
 * File contains declaration of main game class - Game.
 * @file    Game.hpp
 * @author  Szymon "Veldrin" Jab³oñski & Adam Sznajder
 * @date    2010-11-09
 * @version 1.0
 */

#ifndef GAME_HPP
#define GAME_HPP

#include "../Engine/Engine.hpp"
#include "Configuration.hpp"
#include "GameState.hpp"

namespace Game
{

/**
 * Game main class.
 * @remarks
 */
class Game
{
private:
	Engine::Engine* gameEngine;
	GameState* actualState;
	bool gameDone;

public:
	Game();
	~Game();
	virtual void performAction();

	Engine::Engine* getGameEngine() const;
	GameState* getActualState() const;
	bool isGameDone() const;
	void setGameDone(const bool done);
	void setGameState(GameState* gameState);
};

}
#endif
