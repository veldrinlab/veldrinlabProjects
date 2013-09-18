/**
 * Declaration of IMenuState class.
 * @file    IMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef IMENUSTATE_H
#define IMENUSTATE_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "TextCreationException.hpp"

namespace menu
{

/**
 * IMenuState is an abstract class which is used as an interface to the classes which 
 * represent states of menu.
 */
class IMenuState
{
	protected:
		SDL_Color backgroundColor;
		void displayOneText(TTF_Font* font, SDL_Surface* screen, const char* text, SDL_Color foreground, int x, int y) throw(TextCreationException);
	public:
		virtual IMenuState* changeStateUp() = 0;
		virtual IMenuState* changeStateDown() = 0;
		virtual IMenuState* performAction() = 0;
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen) = 0;
};

}
#endif
