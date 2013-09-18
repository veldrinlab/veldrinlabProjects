/**
 * Declaration of BackMenuState class.
 * @file    BackMenuState.h
 * @author  Adam Sznajder
 * @date    2010-12-21
 * @version 1.0
 */

#ifndef BackMenuState_H
#define BackMenuState_H

#include "Menu/IMenuState.hpp"

namespace menu
{

/**
 * BackMenuState is a IMenuState based class which is used in order to show when "BACK" option is active.
 */
class BackMenuState : public IMenuState
{
	public:
		BackMenuState();
		BackMenuState(SDL_Color initColor);
    ~BackMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif
