//intialising the player, movement and combat coordinant points.
#include "Player.h"
#include "Game.h"

Player::Player() {
	std::cout << "Initializing Player" << std::endl;

	xpos = (float)rand()/RAND_MAX - 0.75f;//setting player at random position
	ypos = (float)rand()/RAND_MAX - 0.75f;
	
	xsize = 0.1f;//initial settings for player
	ysize = 0.1f;
	health = 10;
	maxHealth = 10;
	strength = 10;
	speed = 10;
	dollars = 0;

	glClearColor(0.0, 0.0, 0.0, 0.0);

	label = new Label();
}

void Player::draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear window
	// draw player
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f (xpos, ypos); // first corner
	glVertex2f (xpos+xsize, ypos); // second corner
    glVertex2f (xpos+xsize, ypos+ysize); // third corner
    glVertex2f (xpos, ypos+ysize); // fourth corner
	glEnd();
	
	label->textToTexture("Player");
	label->draw(xpos, ypos-(ysize/2)); 
}

// move player in Y direction
void Player::moveY(float val) {
	ypos += val;
}

// move player in X direction
void Player::moveX(float val) {
	xpos += val;
}

void Player::update() { }

void Player::setCombatPos() {
	tempXPos = xpos; tempYPos = ypos;
	xpos = -0.2f; ypos = 0;
	//save players last location to tempxpos, tempypos and move to
	//of centre left for combat screen
}

void Player::resetPos() {
	xpos = tempXPos;
	ypos = tempYPos;
	//returning player to saved position
}