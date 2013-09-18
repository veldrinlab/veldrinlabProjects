/**
 * Declaration of ResoulutionMenuState.
 * @file    ResolutionMenuState.h
 * @author  Adam Sznajder
 * @date    2010-12-21
 * @version 1.0
 */

#ifndef ResolutionMenuState_H
#define ResolutionMenuState_H

#include "Menu/IMenuState.hpp"

namespace menu
{

/**
 * ResolutionMenuState is a IMenuState based class which is used to show resulution option active.
 */
class ResolutionMenuState : public IMenuState
{
	public:
		ResolutionMenuState();
		ResolutionMenuState(SDL_Color initColor);
    ~ResolutionMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif
