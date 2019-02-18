#ifndef SCREEN_H
#define SCREEN_H
#include <SDL.h>

// Abstract class for game screens
// other screens will inherit from this

class Screen {
public:
	virtual ~Screen() {} 
	virtual void init() = 0;
	virtual void draw(SDL_Window * window) = 0;
	virtual bool update() = 0;
};
#endif