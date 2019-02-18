#include "ScreenManager.h"

ScreenManager::ScreenManager(void)
{
	// Create screenGame and set it as the currentScreen
	screenGame = new ScreenGame();
	currentScreen = screenGame;
}

ScreenManager::~ScreenManager(void)
{
	// Destruct screens
	screenGame->~ScreenGame();
	currentScreen->~Screen();
}

void ScreenManager::draw(SDL_Window * window) 
{
	// Draw the currently selected screen
	currentScreen->draw(window);
}

void ScreenManager::update() 
{
	// Update currently selected screen
	currentScreen->update();
}

void ScreenManager::checkEvents() 
{
	// Check events for current screen
	currentScreen->checkEvents();
}