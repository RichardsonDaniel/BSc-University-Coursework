#pragma once
#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>

// Abstract Screen class, for creation of concrete Screen objects used in ScreenManager

class Screen
{
public:

	Screen(void) { }

	virtual ~Screen(void) { return; }

	virtual void draw(SDL_Window * window) = 0;
	virtual void update() = 0;
	virtual void checkEvents() = 0;
};
#endif

