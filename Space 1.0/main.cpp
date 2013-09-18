#include <oslib/oslib.h>
#include <unistd.h>

#include "space.h"

//Necessary to create eboot
PSP_MODULE_INFO("Space", 0, 1, 1);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_USER | THREAD_ATTR_VFPU);


int main()
{
	oslInit(0);
	oslInitGfx(OSL_PF_8888, 1);
	oslSetTransparentColor(RGB(255,0,255));

	Intro intro("intro1.png","intro2.png");
	intro.init();

	Game game("background.png",10);
	game.init();
	
    oslInitConsole();
	oslPrintf("Game over! Your score: %d", game.getScore());
    oslWaitKey();

	oslEndGfx();
	oslQuit();
	return 0;
}
