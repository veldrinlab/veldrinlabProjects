/**
 * Declaration of ColorDepthMenuState class.
 * @file    ColorDepthMenuState.h
 * @author  Adam Sznajder
 * @date    2010-12-21
 * @version 1.0
 */

#ifndef ColorDepthMenuState_H
#define ColorDepthMenuState_H

#include "Menu/IMenuState.hpp"

namespace menu
{

/**
 * ColorDepthMenuState is a IMenuState based class which is used in 
 * order to show when "ColorDepth" option is active.
 */
class ColorDepthMenuState : public IMenuState
{
	public:
		ColorDepthMenuState();
		ColorDepthMenuState(SDL_Color initColor);
    ~ColorDepthMenuState() {};
		virtual IMenuState* changeStateUp();
		virtual IMenuState* changeStateDown();
		virtual IMenuState* performAction();
		virtual void printMenuText(TTF_Font* font, SDL_Surface* screen);
};

}
#endif