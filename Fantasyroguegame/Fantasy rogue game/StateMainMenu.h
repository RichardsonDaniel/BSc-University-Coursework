#ifndef STATEMAINMENU_H
#define STATEMAINMENU_H

#include <SDL.h>
#include "StateGame.h"

class Game;

class StateMainMenu: public StateGame {
public:
	~StateMainMenu() { delete label; }
	void draw(SDL_Window * window, Game& context);
	void init(Game &context);
	void update(Game& context);
	void handleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void pause(Game& context);
};

#endif