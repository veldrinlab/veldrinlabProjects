/**
 * Definition of Menu class.
 * @file    Menu.cpp
 * @author  Adam Sznajder
 * @date    2010-11-13
 * @version 1.0
 */

#include "Menu.hpp"
#include "GameMenuState.hpp"
//#include "windows.h"

namespace menu
{

/**
 * Constructor.
 */ 
Menu::Menu()
{
   /* Initialize defaults, Video and Audio */
   if( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)==(-1) ) { 
      system("pause");
	  exit(-1);
   }

   _putenv(_strdup("SDL_VIDEO_CENTERED=1")); 
   /* Set up the video */
   int WINWIDTH = 800, WINHEIGHT = 600, BPP = 32;
   screen = SDL_SetVideoMode( WINWIDTH,WINHEIGHT, BPP, SDL_SWSURFACE );
   if( screen == NULL ) {
        exit(1);
   }
   SDL_ShowCursor( SDL_DISABLE );
   stateContext = new MenuStateContext(new GameMenuState());
}

/**
 * Destructor.
 */
Menu::~Menu()
{
	TTF_CloseFont(font);
	TTF_Quit();
}

/**
 * Method used to configure the screen.
 * @param fontPath - path to the font file.
 * @param background - path to the background file.
 * @param fontSize - size of the font.
 * @throw TextCreationException - thrown when it's impossible to open TTF which allows to type a text on the screen.
 * @throw FontException - thrown when the game could not open font file.
 */
void Menu::configureMenu(const char* fontPath, const char* background, int fontSize) throw(TextCreationException, FontException)
{
   /* Set up the SDL_TTF */
   if (TTF_Init() == -1)
   {
	   TextCreationException exception;
	   throw exception;
   }

	font = TTF_OpenFont( fontPath, fontSize );
	if (font == NULL) 
	{
		FontException exception;
		throw exception;
	}
	backgroundPath = background;
}

/**
 * Method used to display menu.
 */
void Menu::showMenu()
{
	bool quit = false;
	try
	{
		configureMenu("fonts/arial.ttf", "Data/background.bmp", 20);
	} catch (FontException font)
	{
		//AllocConsole();
		//freopen("CONOUT$", "wb", stdout);
		std::cout << "Nieprawidlowa sciezka do czcionki. Zakonczenie aplikacji.\n";
		//system("pause");
		//fclose(stdout);
		//FreeConsole();
		exit(0);
	} catch (TextCreationException text)
	{
		///AllocConsole();
		//freopen("CONOUT$", "wb", stdout);
		std::cout << "Brak mozliwosci inicjalizacji czcionek. Zakonczenie aplikacji.\n";
		//system("pause");
		//fclose(stdout);
		//FreeConsole();
		exit(0);
	}
	displayMenuBackground();
	stateContext->printMenu(font, screen);
	while( !quit ) 
	{
		SDL_Event event;
		if( SDL_PollEvent( &event ) ) 
		{
			switch( event.type ) 
			{
				case SDL_KEYDOWN: 
				{
					int key = event.key.keysym.sym;
					if( key == SDLK_UP)
					{
						menuUp();
						displayMenuBackground();
						stateContext->printMenu(font, screen);
						continue;
					}
					if( key == SDLK_DOWN)
					{
						menuDown();
						displayMenuBackground();
						stateContext->printMenu(font, screen);
						continue;
					}
					if ( key == SDLK_RETURN )
					{
						quit = stateContext->performAction();
						if (!quit)
						{
							displayMenuBackground();
							stateContext->printMenu(font, screen);
							continue;
						}
					}
					if( key == SDLK_ESCAPE ) 
					{
						quit = stateContext->performQuitMenuAction();
					}
					break;
				}
			}
		}
	}
}

/**
 * Method used to display menu background on the screen.
 */
void Menu::displayMenuBackground()
{
	SDL_Rect dest = {0, 0, 0, 0};
	SDL_Surface* background = SDL_LoadBMP(backgroundPath);
	if (background == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		exit(0);
	}
	
	SDL_Surface* image = SDL_DisplayFormat(background);
	SDL_FreeSurface(background);
	SDL_BlitSurface( image, NULL, screen, &dest );
	SDL_FreeSurface(image);
}

/**
 * Method used to switch to other state when arrow down key was pressed.
 */
void Menu::menuDown()
{
	stateContext->changeStateDown();
}

/**
 * Method used to switch to other state when arrow up key was pressed.
 */
void Menu::menuUp()
{
	stateContext->changeStateUp();
};

}
