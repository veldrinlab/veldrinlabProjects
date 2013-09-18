/**
 * Declaration of CreditsMenuState class.
 * @file    CreditsMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef CREDITSMENUSTATE_H
#define CREDITSMENUSTATE_H

#include "IMenuState.hpp"

namespace menu
{

/**
 * CreditsMenuState is a IMenuState based class which is used in order to represent the state when "Credits" option is active in a menu.
 */
class CreditsMenuState : public IMenuState
{
	public:
		CreditsMenuState();
		CreditsMenuState(SDL_Color initColor);
    ~CreditsMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif
