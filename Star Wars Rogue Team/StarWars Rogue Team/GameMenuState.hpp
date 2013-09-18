/**
 * Declaration of GameMenuState class.
 * @file    GameMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef GAMEMENUSTATE_H
#define GAMEMENUSTATE_H

#include "Menu/IMenuState.hpp"
#include "GameMenuState.hpp"

namespace menu
{

/**
 * GameMenuState is a IMenuState based class which is used in order to represent the state when "Start Game" option is active in a menu.
 */
class GameMenuState : public IMenuState
{
	public:
		GameMenuState();
		GameMenuState(SDL_Color backgroundClr);
    ~GameMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}

#endif
