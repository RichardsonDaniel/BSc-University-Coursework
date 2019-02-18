/*

 Fantasy Rogue Game, Game Engine Design.
 B00239486.

 using code from lectures, lab exersices and notes

*/


#include "Game.h"

#if _DEBUG
#pragma comment(linker, "/subsystem:\"console\" /entry:\"WinMainCRTStartup\"")
#endif

int main(int argc, char *argv[])
{
    Game *newGame = new Game();
	newGame->run();
	delete newGame;
    return 0;
}
