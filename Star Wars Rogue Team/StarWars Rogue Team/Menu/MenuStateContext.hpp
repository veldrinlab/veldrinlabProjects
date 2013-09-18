/**
 * Declaration of MenuStateContext class.
 * @file    GameMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "IMenuState.hpp"
#include "CreditsMenuState.hpp"

namespace menu
{

/**
 * MenuStateContext is a class used to manage states of the menu in order
 * to remember which state is active.
 */
class MenuStateContext
{
	private:
		IMenuState* activeState;
	public:
		MenuStateContext(IMenuState* initState);
		~MenuStateContext();
		void changeStateUp();
		void changeStateDown();
		bool performAction();
		bool performQuitMenuAction();
		void printMenu(TTF_Font* font, SDL_Surface* screen);
};

}
#endif
