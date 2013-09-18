/**
 * Declaration of ShowOptionsMenuState class.
 * @file    ShowOptionsMenuState.h
 * @author  Adam Sznajder
 * @date    2010-12-21
 * @version 1.0
 */

#ifndef SHOWOPTIONSMENUSTATE_H
#define SHOWOPTIONSMENUSTATE_H

#include "Menu/IMenuState.hpp"

namespace menu
{

/**
 * ShowOptionsMenuState is a IMenuState based class which is used in order to show options.
 */
class ShowOptionsMenuState : public IMenuState
{
	public:
		ShowOptionsMenuState();
		ShowOptionsMenuState(SDL_Color initColor);
    ~ShowOptionsMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif
