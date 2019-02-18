#include "StateGameOver.h"
#include "Game.h"

void StateGameOver::init(Game& context) {
	label = new Label();
}


void StateGameOver::handleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if (sdlEvent.type == SDL_KEYDOWN)
	{
		if (sdlEvent.key.keysym.sym == SDLK_RETURN || sdlEvent.key.keysym.sym == SDLK_KP_ENTER)
		{
			context.setState(context.getStateIntro());
		}
	}
}

void StateGameOver::draw(SDL_Window* window, Game& context) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	
	//if the player has health remaining, win
	if(context.player->getHealth() > 0)
		label->textToTexture("You Won!");
	else
	// if not, loss
		label->textToTexture("GAME OVER");
	
	label->draw(-0.65f, 0.5f, 0.006f);
	label->textToTexture("<Enter> To Return To Main Menu");
	label->draw(-0.65f, 0.2f);
	SDL_GL_SwapWindow(window); 
}


void StateGameOver::update(Game& context){
	
}