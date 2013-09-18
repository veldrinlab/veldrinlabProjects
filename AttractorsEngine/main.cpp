/**
 * File contains entry point of application - Attractor Engine by Szymon "Veldrin" Jab³oñski
 * @file    main.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-09-28
 * @version 1.0
 */

#include "AttractorEngine.h"

#undef main

int main(int argc, char *argv[])
{
	AttractorEngine* engine = new AttractorEngine();
	engine->runEngine();
}
