#pragma once
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <SDL.h>
#include "Screen.h"
#include "ScreenGame.h"

// ScreenManager, used for maintaing screens to be drawn to the window.

class ScreenManager
{
public:
	ScreenManager(void);
	~ScreenManager(void);

	void draw(SDL_Window * window);
	void update();
	void checkEvents();
private:
	// Current screen will be the only screen to be drawn, this only needs to point to another screen to actually inception the shown screen
	Screen * currentScreen;

	// Only a game screen is needed for this project
	ScreenGame * screenGame;
};
#endif
