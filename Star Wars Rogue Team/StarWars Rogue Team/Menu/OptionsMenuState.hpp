/**
 * Declaration of OptionsMenuState class.
 * @file    OptionsMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef OPTIONSMENUSTATE_H
#define OPTIONSMENUSTATE_H

#include "IMenuState.hpp"

namespace menu
{

/**
 * OptionsMenuState is a IMenuState based class which is used in order to represent the state when "Options" option is active in a menu.
 */
class OptionsMenuState : public IMenuState
{
	public:
		OptionsMenuState();
		OptionsMenuState(SDL_Color initColor);
    ~OptionsMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif
