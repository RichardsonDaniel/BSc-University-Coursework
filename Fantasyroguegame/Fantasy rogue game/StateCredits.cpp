#include "StateCredits.h"
#include "Game.h"

void StateCredits::init(Game& context) {
	label = new Label();
	//delay for 30 seconds
	delay = 30;
	current = clock();
	last = current + delay * CLOCKS_PER_SEC;
}

void StateCredits::handleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if (sdlEvent.type == SDL_KEYDOWN)
	{
		//unless key is pressed
		context.setState(context.getStateMainMenu());
	}
}

void StateCredits::draw(SDL_Window* window, Game& context) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	label->textToTexture("Credits");
	label->draw(-0.65f, 0.5f, 0.006f);
	label->textToTexture("Any Key to Return to Main Menu");
	label->draw(-0.65f, 0.2f); 
	SDL_GL_SwapWindow(window); 
}

void StateCredits::pause(Game& context) {
	current = clock();
	
	if(last<=current)
		context.setState(context.getStateMainMenu());
}

void StateCredits::update(Game& context){
     pause(context);
}
