/**
 * File contains declaration of GameState class.
 * @file    GameState.hpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2012-03-20
 */

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

namespace dse
{
	/**
	 * Class represntes abstract game state.
	 */
	class GameState
	{
	protected:
		bool isRunning;

	public:	
		virtual ~GameState() {};
		virtual void performAction() = 0;
		virtual void init() = 0;
		virtual void exit() = 0;
		virtual void input() = 0;
		virtual void logic() = 0;
		virtual void render() = 0;
	};
}
#endif
