#ifndef STATEINTRO_H
#define STATEINTRO_H

#include <SDL.h>
#include "StateGame.h"

class Game;

class StateIntro: public StateGame {
public:
	~StateIntro() { delete label; }
	void draw(SDL_Window * window, Game& context);
	void init(Game &context);
	void update(Game& context);
	void handleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void pause(Game& context);

private:
	clock_t current;
	clock_t last;
};
#endif
