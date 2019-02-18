#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <glew.h>
#include <cstdlib>
#include <ctime>
#include <sstream>

#include "Player.h"
#include "Label.h"

#include "StateGame.h"
#include "StateMap.h"
#include "StateMainMenu.h"
#include "StateIntro.h"
#include "StateCredits.h"
#include "StateCombat.h"
#include "StateCharSelect.h"
#include "StateGameOver.h"

#include "Monster.h"
#include "MonsterSpawn.h"

#include "AbstractItem.h"
#include "Item.h"
#include "ItemDecorator.h"
#include "ItemHealth.h"
#include "ItemCombat.h"
#include "ItemStimulant.h"

class Game
{
	public:
		Game();
		~Game();
		void run();
		SDL_Window * setupRC(SDL_GLContext &context);
	private:
		SDL_Window *window;
		SDL_GLContext glContext;

		void setState(StateGame * newState){stateCurrent = newState;}

		StateGame *getStateCurrent(){return stateCurrent;}
		StateGame *getStateMap(){return stateMap;}
		StateGame *getStateMainMenu(){return stateMainMenu;}
		StateGame *getStateIntro(){return stateIntro;}
		StateGame *getStateCredits(){stateCredits->init(*this); return stateCredits;} // re-init to reset timer
		StateGame *getStateCombat(){return stateCombat;}
		StateGame *getStateCharSelect(){return stateCharSelect;}

		StateGame *getStateGameOver(){return stateGameOver;}

		friend class StateGame;
		friend class StateMap;
		friend class StateMainMenu;
		friend class StateIntro;
		friend class StateCredits;
		friend class StateCombat;
		friend class StateCharSelect;
		friend class StateGameOver;

		StateGame * stateCurrent;
		StateGame * stateMap;
		StateGame * stateMainMenu;
		StateGame * stateIntro;
		StateGame * stateCredits;
		StateGame * stateCombat;
		StateGame * stateCharSelect;
		StateGame * stateGameOver;

		static int instances;

		Player *player;

		MonsterFactory *monsterFactory;

		AbstractItem * itemArr[7];
		Monster * monArr[4];
};
#endif