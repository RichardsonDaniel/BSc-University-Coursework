#include "StateCombat.h"
#include "Game.h"

void StateCombat::init(Game &context) {
	label = new Label();
	fighting = false;
}

void StateCombat::handleSDLEvent(SDL_Event const &sdlEvent, Game &context) {
	//wait and check for keypresses of enter
	if (sdlEvent.type == SDL_KEYDOWN) {
		if (sdlEvent.key.keysym.sym == SDLK_RETURN) {
			if( fighting == false )
				combat();
			else if ( fighting == true ) {
				// if player defeats monster return to map
				if( currentMonster->getHealth() <= 0) {
					postCombatAlive();
					fighting = false;
					context.setState(context.getStateMap());
				} else if (player->getHealth() <= 0) {
					//if monster wins, gameover screen
					postCombatDead(context);
					fighting = false;
				}
			}
		}
	}
}

//first attack calculations
void StateCombat::preCombat() {
	if(player->getSpeed() == currentMonster->getSpeed())//if speeds are equal
		attackTurn = rand() % 2;//choose at random
	if(player->getSpeed() > currentMonster->getSpeed())//highest speed gets first hit
		attackTurn = 1;     
	else
		attackTurn = 0;
}
//damage dealt is calculated between 2 and strenght of attacker
void StateCombat::inCombat() {
	int playerHit = rand() % (player->getStrength()-1) + 2;
	int monsterHit = rand() % (currentMonster->getStrength()-1) + 2;

	std::cout << "player hit monster: " << playerHit << "    " << "   monster hit player: " << monsterHit << std::endl;

	//switch attacking roles
	if( attackTurn == 1 ) {
		currentMonster->setHealth(playerHit);
		attackTurn = 0;
	}
	if( attackTurn == 0 ) {
		player->damageTaken(monsterHit);
		attackTurn = 1;
	}
}

void StateCombat::postCombatAlive() {
	//if the player has won
	player->resetPos();//reset to original poistion
	int heal = (player->getMaxHealth() - player->getHealth())/2;// and heal for half dsmsge taken
	player->setHealth(heal + player->getHealth());
	//collect money dropped
	player->setDollars(currentMonster->getDollars());

	// set the monster to dead
	currentMonster->setDead(true);

	//if monster drops an item
	if(currentMonster->getDropRate() == true) {
		int itemDrop = rand() % 100 + 1; //create random number

		if( itemDrop >= 20 ) { //20% chance of stimulant
			monsterDrop = new ItemStimulant(new Item("Stimulant", 0, 0, 1));
			std::cout << "Monster dropped" << "(rate: " << itemDrop << ") " << "Item Stimulant" << std::endl; }
		else if( itemDrop > 20 && itemDrop <= 40) {//20% chance of combat pack
			monsterDrop = new ItemCombatPack(new Item("Combat Pack", 2, 0, 0));
			std::cout << "Monster dropped" << "(rate: " << itemDrop << ") " << "Item Combat Pack" << std::endl; }
		else {
			monsterDrop = new ItemHealthPack(new Item("Health Pack", 0, 1, 0));//60% chance of health pack
			std::cout << "Monster dropped" << "(rate: " << itemDrop << ") " << "Item Health Pack" << std::endl; }

		monsterDrop->itemEffect(player);
	}
}

//combat loop until victor is decided
void StateCombat::combat() {
	do {
	preCombat();
	inCombat();
	} while (player->getHealth() > 0 && currentMonster->getHealth() > 0);

	fighting = true;
}

void StateCombat::postCombatDead(Game& context) {
	//end game screen
	context.setState(context.getStateGameOver());
}

void StateCombat::draw(SDL_Window * window, Game& context) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	
	//player reference
	player = context.player;
	player->draw();

	//draw player stats
	std::stringstream playerStrStream1;
	playerStrStream1 << "Health:" << player->getHealth();
	label->textToTexture(playerStrStream1.str().c_str());
    label->draw(-0.2f, -0.1f, 0.0015f);

	std::stringstream playerStrStream2;
	playerStrStream2 << "Strength:" << player->getStrength();
	label->textToTexture(playerStrStream2.str().c_str());
    label->draw(-0.2f, -0.15f, 0.0015f);

	std::stringstream playerStrStream3;
	playerStrStream3 << "Speed:" << player->getSpeed();
	label->textToTexture(playerStrStream3.str().c_str());
    label->draw(-0.2f, -0.2f, 0.0015f);

	std::stringstream playerStrStream4;
    playerStrStream4 << "Dollars:" << player->getDollars();
	label->textToTexture(playerStrStream4.str().c_str());
    label->draw(-0.2f, -0.25f, 0.0015f);

	//monster reference
	for(int i=0; i<9; i++) {
		if(context.monArr[i] != NULL) {
			if(context.monArr[i]->getHasCollided() == true) {
				currentMonster = context.monArr[i];
			}
		}
	}

	//draw current monster stats
	currentMonster->setCombatPos();
	currentMonster->draw();
			
	std::stringstream monsterStrStream1;
	monsterStrStream1 << "Health:" << currentMonster->getHealth();
	label->textToTexture(monsterStrStream1.str().c_str());
	label->draw(0.2f, -0.1f, 0.0015f);

	std::stringstream monsterStrStream2;
	monsterStrStream2 << "Strength:" << currentMonster->getStrength();
	label->textToTexture(monsterStrStream2.str().c_str());
	label->draw(0.2f, -0.15f, 0.0015f);

	std::stringstream monsterStrStream3;
	monsterStrStream3 << "Speed:" << currentMonster->getSpeed();
	label->textToTexture(monsterStrStream3.str().c_str());
	label->draw(0.2f, -0.20f, 0.0015f);

	std::stringstream monsterStrStream4;
	monsterStrStream4 << "Dollars:" << currentMonster->getDollars();
	label->textToTexture(monsterStrStream4.str().c_str());
	label->draw(0.2f, -0.25f, 0.0015f);

	SDL_GL_SwapWindow(window); 
}

void StateCombat::update(Game& context) { }
