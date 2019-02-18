#ifndef STATECOMBAT_H
#define STATECOMBAT_H

#include <SDL.h>
#include "StateGame.h"
#include "Monster.h"
#include "Player.h"
#include "AbstractItem.h"

class Game;

class StateCombat: public StateGame {
public:
	~StateCombat() { delete label; delete currentMonster; delete player; delete monsterDrop; }
	void draw(SDL_Window * window, Game& context);
	void init(Game &context);
	void update(Game& context);
	void handleSDLEvent(SDL_Event const &sdlEvent, Game &context);
	void pause(Game& context) {}
	void preCombat();
	void inCombat();
	void postCombatDead(Game& context);
	void postCombatAlive();
	void combat();

private:
	Monster *currentMonster;
	Player *player;
	int attackTurn;
	AbstractItem *monsterDrop;
	bool fighting;
};

#endif
