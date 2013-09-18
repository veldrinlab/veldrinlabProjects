/**
 * AttractorEngine class represents class used to init SDL, choose attractor and render it.
 * @file    AttractorEngine.h
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-09-28
 * @version 1.0
 */

#ifndef ATTRACTORENGINE_H
#define ATTRACTORENGINE_H

#include <stdlib.h>
#include <SDL.h>

#include "Attractor.h"

class AttractorEngine
{
private:
	SDL_Surface* screen;

public:
	AttractorEngine();
	~AttractorEngine();

	void runEngine();

};


#endif 