#ifndef STATEGAME_H
#define STATEGAME_H

#include <SDL.h>
#include "Label.h"

class Game;

class StateGame {
public:
	virtual ~StateGame() { return; }
	virtual void draw(SDL_Window * window, Game& context) = 0;
	virtual void init(Game &context) = 0;
	virtual void update(Game &context) = 0;
	virtual void handleSDLEvent(SDL_Event const &sdlEvent, Game &context) = 0;
	virtual void pause(Game &context) = 0;
protected:
	Label* label;
	int delay;
};

#endif
