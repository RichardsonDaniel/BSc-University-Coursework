#ifndef STATEMAP_H
#define STATEMAP_H

#include <SDL.h>
#include "StateGame.h"
#include "Label.h"
#include "Monster.h"
#include "AbstractItem.h"

class Game;

class StateMap: public StateGame {
public:
	~StateMap() { delete label; }
	void draw(SDL_Window * window, Game& context);
	void init(Game &context);
	void update(Game& context);
	void handleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void pause(Game& context) { }
	bool collisionCheck(float targetXPos, float targetYPos, float targetXSize, float targetYSize, Game &context);

private:
	int monsterCount;
};

#endif
