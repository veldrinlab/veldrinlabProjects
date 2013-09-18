/**
 * File contains definition of AttractorsEngine class.
 * @file    AttractorEngine.cpp
 * @author  Szymon "Veldrin" Jab³oñski
 * @date    2010-09-28
 * @version 1.0
 */


#include "AttractorEngine.h"

AttractorEngine::AttractorEngine()
{
	screen = SDL_SetVideoMode(1024,768,0,SDL_HWSURFACE);
	SDL_WM_SetCaption("Attractor Engine", NULL);
	SDL_ShowCursor(SDL_ENABLE); 
	SDL_LockSurface(screen);
}

AttractorEngine::~AttractorEngine()
{
	delete screen;
}

void AttractorEngine::runEngine()
{
	Attractor* attractor = NULL;
	SDL_Event event;
	int id = 0;

	printf("Attractor Engine 1.0\n Szymon 'Veldrin' Jablonski\n\n");
	printf("Menu\n\n");

	printf("0.PickOver \n");
	printf("1.PickOverModified \n");
	printf("2.PolyNomialTypeA \n");
	printf("3.Trigonometric \n");
	printf("4.Trigonometric2 ver.1 \n");
	printf("5.Trigonometric2 ver.2 \n");
	printf("6.Trigonometric2 ver.3\n");
	printf("7.Trigonometric3  \n");
	printf("8.Clifford ver.1 \n");
	printf("9.Clifford ver.2  \n");
	printf("10.Lorenz \n");
	printf("11.Lorenz84 \n");
	printf("Choose Attractor to generate: ");

	scanf_s("%d",&id);

	printf("Wait few seconds, attractor is generating....\n\n");

	switch(id)
	{
	case 0:
		attractor = new PickOver(20000000,1.0f,1.8f,0.71f,1.51f,1.0f);
		break;
	case 1:
		attractor = new PickOverModified(20000000,-2.17f,2.040f,2.76f,0.254f,1.0f);
		break;
	case 2:
		attractor = new PolyNomialTypeA(20000000,1.586f,1.124f,0.281f);
		break;
	case 3:
		attractor = new Trigonometric(20000000,0.98f, 1.01f, 1.97f, 1.76f, 1.01f, 0.99f);
		break;
	case 4:
		 attractor = new Trigonometric2(20000000,1.19f,1.13f,1.05f,1.46f,1.19f,1.0f);
		 break;
	case 5:
		attractor = new Trigonometric2(20000000,1.5f,1.1f,-0.73f,1.8f,1.3f,1.2f);
		break;
	case 6:
		attractor = new Trigonometric2(20000000,1.410f,0.97f,1.18f,1.74f,1.15f,1.02f);
		break;
	case 7:
		attractor = new Trigonometric3(20000000,1.1f,1.75f,2.44f,1.0f,4.0f,1.0f);
		break;
	case 8:
		attractor = new Clifford(20000000,1.22f,1.54f,0.95f,1.95f,1.0f);
		break;
	case 9:
		attractor = new Clifford(20000000,1.17f,1.49f,1.82f,1.2f,2.13f);
		break;
	case 10:
		attractor = new Lorenz(20000000, 16.29f, 11.426f ,4.669f, 0.058f);
		break;
	case 11:
		attractor = new Lorenz84(20000000, 1.111f,1.479f,4.494f,0.44f,0.135f);
		break;
	default:
		exit(1);
	}

	attractor->generateAttractor();
	attractor->scaleImageBuffer(screen);
	

	SDL_UnlockSurface(screen);
	SDL_UpdateRect(screen, 0, 0, 1024, 768);

	do
	{
		SDL_PollEvent(&event);
	} while (event.type!=SDL_QUIT);
	SDL_Quit();

}