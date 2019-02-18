#include "StateIntro.h"
#include "Game.h"

void StateIntro::init(Game& context) {
	label = new Label();

	// set up the timer
	// delay lets the timer run for the set value

	delay = 3;
	current = clock();
	last = current + delay * CLOCKS_PER_SEC;
}

void StateIntro::handleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if (sdlEvent.type == SDL_KEYDOWN)
	{
		if (sdlEvent.key.keysym.sym == SDLK_RETURN || sdlEvent.key.keysym.sym == SDLK_KP_ENTER || sdlEvent.key.keysym.sym == SDLK_SPACE)
		{
			context.setState(context.getStateMainMenu());
		}
	}
}

void StateIntro::draw(SDL_Window* window, Game& context) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	label->textToTexture("COMPANY");
	label->draw(-0.55f, 0.5f, 0.010f);
	label->textToTexture("SPLASH SCREEN");
	label->draw(-0.20f, 0.2f);
	SDL_GL_SwapWindow(window); 

}

void StateIntro::pause(Game& context) {
	current = clock();

	if(last<=current)
		context.setState(context.getStateMainMenu());
}

void StateIntro::update(Game& context){
     pause(context);
}