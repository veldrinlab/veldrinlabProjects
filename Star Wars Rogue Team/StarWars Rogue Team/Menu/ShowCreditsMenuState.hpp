/**
 * Declaration of ShowCreditsMenuState class.
 * @file    CreditsMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef SHOWCREDITSMENUSTATE_H
#define SHOWCREDITSMENUSTATE_H

#include "IMenuState.hpp"

namespace menu
{

/**
 * ShowCreditsMenuState is a IMenuState based class which is used in order to show credits.
 */
class ShowCreditsMenuState : public IMenuState
{
	public:
		ShowCreditsMenuState();
		ShowCreditsMenuState(SDL_Color initColor);
    ~ShowCreditsMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif
