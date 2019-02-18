#include "StateMap.h"
#include "Game.h"
#include <sstream>

void StateMap::init(Game &context) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	label = new Label();
	srand ( time(NULL) );
}

void StateMap::draw(SDL_Window * window, Game& context) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window

	context.player->draw();

	//draw all objects to the map
	for(int i=0; i<9; i++) {
		if(context.monArr[i] != NULL)
			context.monArr[i]->draw();
	} 
	for(int i=0; i<5; i++) {
		if(context.itemArr[i] != NULL)
			context.itemArr[i]->draw();
	} 
	
	// display player stats on-screen
	std::stringstream strStream;
	strStream << "Health:" << context.player->getHealth() << "         ";
	strStream << "Strength:" << context.player->getStrength() << "         ";
	strStream << "Speed:" << context.player->getSpeed() << "         ";
    strStream << "Dollars:" << context.player->getDollars();
    label->textToTexture(strStream.str().c_str());
    label->draw(-0.9f, -0.98f);

	SDL_GL_SwapWindow(window); // swap buffers
}

void StateMap::handleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if (sdlEvent.type == SDL_KEYDOWN) {
		switch( sdlEvent.key.keysym.sym ) {
			case SDLK_UP:
			case 'w': case 'W': 
				context.player->moveY(0.05f);
				break;
			case SDLK_DOWN:
			case 's': case 'S':
				context.player->moveY(-0.05f);
				break;
			case SDLK_LEFT:
			case 'a': case 'A': 
				context.player->moveX(-0.05f);
				break;
			case SDLK_RIGHT:
			case 'd': case 'D':
				context.player->moveX(0.05f);
				break;
			case SDLK_ESCAPE:
				context.setState(context.getStateMainMenu());
			break;
			default:
				break;
		}
	}
}

//check player collisions
bool StateMap::collisionCheck(float targetXPos, float targetYPos, float targetXSize, float targetYSize, Game &context) {
	if ( (targetXPos >= context.player->getXPos()) && (targetXPos+targetXSize <= context.player->getXPos()+context.player->getXSize())      // cursor surrounds target in x
         && (targetYPos >= context.player->getYPos()) && (targetYPos+targetYSize <= context.player->getYPos()+context.player->getYSize()) ) // cursor surrounds target in y
    {
           return true;
    }
	else return false;
}

void StateMap::update(Game& context) {
	// set dead monster count to 0
	monsterCount = 0;

	// if monster object in array exists, check if it is colliding with player
	// if so, set that monster has collided, set to combat state and move player to combat position
	for(int i=0; i<9; i++) {
		if(context.monArr[i] != NULL)
			if(collisionCheck(context.monArr[i]->getXPos(), context.monArr[i]->getYPos(), context.monArr[i]->getXSize(), context.monArr[i]->getYSize(), context) == true) {
				context.monArr[i]->sethasCollided(true);
				context.setState(context.getStateCombat());
				context.player->setCombatPos();
			}
	} 

	// if item object in array exists, check if the monster is dead
	// if it is dead then monster can be deleted and count incremented
	for(int i=0; i<9; i++) {
		if(context.monArr[i] != NULL) {
			if(context.monArr[i]->getDead() == true) {
				context.monArr[i]->sethasCollided(false);
				delete context.monArr[i];
				context.monArr[i] = NULL;
				monsterCount++;
			}
		}
	}


	// if item object in array exists, check if it colliding with the player
	// if so then apply the item effect to the player and delete the item
	for(int i=0; i<5; i++) {
		if(context.itemArr[i] != NULL)
			if(collisionCheck(context.itemArr[i]->getXPos(), context.itemArr[i]->getYPos(), context.itemArr[i]->getXSize(), context.itemArr[i]->getYSize(), context) == true) {
				context.itemArr[i]->itemEffect(context.player);
				delete context.itemArr[i];
				context.itemArr[i] = NULL;
			}
	} 

	// if all monsters are dead, game is over
	if(monsterCount==9)
		context.setState(context.getStateGameOver());
}