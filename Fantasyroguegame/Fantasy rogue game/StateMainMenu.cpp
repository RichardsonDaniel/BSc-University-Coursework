#include "StateMainMenu.h"
#include "Game.h"

void StateMainMenu::init(Game& context) {
	label = new Label();
}

void StateMainMenu::handleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	if (sdlEvent.type == SDL_KEYDOWN) {
		if (sdlEvent.key.keysym.sym == SDLK_n) {
			context.setState(context.getStateCharSelect());
		}
		if (sdlEvent.key.keysym.sym == SDLK_c) {
			std::cout << "Not yet implemented" << std::endl;
		}
		if (sdlEvent.key.keysym.sym == SDLK_r) {
			context.setState(context.getStateCredits());
		}
		if (sdlEvent.key.keysym.sym == SDLK_ESCAPE || sdlEvent.key.keysym.sym == SDLK_q)
		{
			SDL_DestroyWindow(context.window);
			SDL_Quit();
		}
	}
}

void StateMainMenu::draw(SDL_Window* window, Game& context) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	label->textToTexture("Main Menu");
	label->draw(-0.65f, 0.5f, 0.005f);
	label->textToTexture("<N>         New Game");
	label->draw(-0.65f, 0.2f);
	label->textToTexture("<C>         Continue Game");
	label->draw(-0.65f, 0);
	label->textToTexture("<R>         Credits");
	label->draw(-0.65f, -0.2f);
	label->textToTexture("<Q/Esc>   Quit");
	label->draw(-0.65f, -0.4f);
	SDL_GL_SwapWindow(window); 
}

void StateMainMenu::pause(Game& context) { }

void StateMainMenu::update(Game& context) { }