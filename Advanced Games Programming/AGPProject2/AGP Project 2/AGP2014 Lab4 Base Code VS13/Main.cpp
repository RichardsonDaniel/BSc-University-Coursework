#include "Game.h"

#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

int main(int argc, char *argv[])
{
	Game gameAGP;

	gameAGP.init();
	gameAGP.run();
	gameAGP.~Game();
		

    return 0;
}