//sets up the game and starts the main loop
#include "Game.h"

int Game::instances = 0;

void Game::run() {
	bool running = true; //set running to true
	SDL_Event sdlEvent;

	std::cout << "Progress: About to enter main loop" << std::endl;

	while (running)	
	{
		while (SDL_PollEvent(&sdlEvent))
		{
			if (sdlEvent.type == SDL_QUIT)
				running = false;
			else
				stateCurrent->handleSDLEvent(sdlEvent, *this);
		}
		stateCurrent->draw(window, *this); //draw current state
		stateCurrent->update(*this); //update the current state
	}
}

Game::Game() {
	window = setupRC(glContext);

	//create and initialise all states
	stateMap = new StateMap();
	stateMainMenu = new StateMainMenu();
	stateIntro = new StateIntro();
	stateCredits = new StateCredits();
	stateCombat = new StateCombat();
	stateCharSelect = new StateCharSelect();
	stateGameOver = new StateGameOver();

	stateMap->init(*this);
	stateMainMenu->init(*this);
	stateIntro->init(*this);
	stateCredits->init(*this);
	stateCombat->init(*this);
	stateCharSelect->init(*this);
	stateGameOver->init(*this);
	
	stateCurrent = stateIntro; //set starting state
	instances++;
	if (instances > 1)
		Label::exitFatalError("Attempt to create multiple game instances"); //stop multiplse instances


	//create and initalise all objects in the map
	player = new Player();
	monsterFactory = new MonsterFactory();

	monArr[0] = monsterFactory->orderMonster("fodder");
	monArr[1] = monsterFactory->orderMonster("fodder");
	monArr[2] = monsterFactory->orderMonster("fodder");
	monArr[3] = monsterFactory->orderMonster("fodder");
	monArr[4] = monsterFactory->orderMonster("fodder");
	monArr[5] = monsterFactory->orderMonster("brute");
	monArr[6] = monsterFactory->orderMonster("brute");
	monArr[7] = monsterFactory->orderMonster("brute");
	monArr[8] = monsterFactory->orderMonster("raider");

	itemArr[0]= new ItemStimulant(new Item("Stimulant", 0, 0, 1));
	itemArr[1]= new ItemHealthPack(new Item("Health Pack", 0, 1, 0));
	itemArr[2]= new ItemHealthPack(new Item("Health Pack", 0, 1, 0));
	itemArr[3]= new ItemCombatPack(new Item("Combat Pack", 2, 0, 0));
	itemArr[4]= new ItemCombatPack(new Item("Combat Pack", 2, 0, 0));
}

SDL_Window * Game::setupRC(SDL_GLContext &context) // setup SDL window
{
	TTF_Font* textFont;
	SDL_Window *window;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialize video
        Label::exitFatalError("Unable to initialize SDL"); 

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); 
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); 

	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
 
    window = SDL_CreateWindow("Fantasy Rogue Game",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
	if (!window) 
       Label::exitFatalError("Unable to create window");
 
    context = SDL_GL_CreateContext(window); 
    SDL_GL_SetSwapInterval(1); 

	if (TTF_Init()== -1)
		Label::exitFatalError("TTF failed to initialise.");
	
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);
	if (textFont == NULL)
		Label::exitFatalError("Failed to open font.");

	return window;
}

Game::~Game() {
	delete stateCurrent;
	delete stateMap;
	delete stateMainMenu;
	delete stateIntro;
	delete stateCredits;
	delete stateCombat;
	delete stateCharSelect;
	delete stateGameOver;

    SDL_DestroyWindow(window);
	SDL_Quit();
}
