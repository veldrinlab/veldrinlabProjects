/**
 * Declaration of ChooseLevelMenuState class.
 * @file    ChooseLevelMenuState.h
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#ifndef ChooseLevelMenuState_H
#define ChooseLevelMenuState_H

#include "Menu/IMenuState.hpp"

namespace menu
{

/**
 * ChooseLevelMenuState is a IMenuState based class which is used in order to
 * show when "Play Intro" option is active.
 */
class ChooseLevelMenuState : public IMenuState
{
	public:
		ChooseLevelMenuState();
		ChooseLevelMenuState(SDL_Color backgroundClr);
    ~ChooseLevelMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif