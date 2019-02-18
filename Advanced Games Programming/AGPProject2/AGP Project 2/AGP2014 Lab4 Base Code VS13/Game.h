#pragma once
#include <stack>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include "rt3d.h"
#include "Screen.h"
#include "GameScreen.h"

class Game
{
public:
	Game();
	~Game();

	void init();
	void run();

private:
	SDL_Window * window;
	SDL_GLContext glContext;

	SDL_Window * setupRC(SDL_GLContext &context);

	void setCurrentScreen(Screen * newScreen);
	
	Screen * currentScreen;
	Screen * gameScreen;

};
