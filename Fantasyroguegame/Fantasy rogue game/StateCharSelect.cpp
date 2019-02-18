#include "StateCharSelect.h"
#include "Game.h"

void StateCharSelect::init(Game& context) {
	label = new Label();
}

void StateCharSelect::handleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if (sdlEvent.type == SDL_KEYDOWN) {
		if (sdlEvent.key.keysym.sym == SDLK_RETURN || sdlEvent.key.keysym.sym == SDLK_KP_ENTER) {
			context.setState(context.getStateMap());
		}
	}
}

void StateCharSelect::draw(SDL_Window* window, Game& context) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	label->textToTexture("Character Selection");
	label->draw(-0.65f, 0.5f, 0.006f); 
	label->textToTexture("<Return> to Continue");
	label->draw(-0.65f, 0.2f); 
	SDL_GL_SwapWindow(window); 
}

void StateCharSelect::update(Game& context) { }