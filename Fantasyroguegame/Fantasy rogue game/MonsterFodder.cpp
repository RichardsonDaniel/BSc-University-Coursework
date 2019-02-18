#include "MonsterFodder.h"
#include "Game.h"
#include <sstream>

MonsterFodder::MonsterFodder() {
	xpos = (float)rand()/RAND_MAX - 0.75f;//random spawn location
	ypos = (float)rand()/RAND_MAX - 0.75f;
	
	//initial values for fodder
	xsize = 0.05f;
	ysize = 0.05f;
	health = 3; 
	strength = 3;
	speed = 7;
	dollars = 1;

	dead = false;

	glClearColor(0.0, 0.0, 0.0, 0.0);

	label = new Label();
	hasCollided = false;
}

void MonsterFodder::draw() {
	glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
		glVertex2f (xpos, ypos); // first corner
		glVertex2f (xpos+xsize, ypos); // second corner
		glVertex2f (xpos+xsize, ypos+ysize); // third corner
		glVertex2f (xpos, ypos+ysize); // fourth corner
	glEnd();

	label->textToTexture("Fodder");
	label->draw(xpos, ypos-ysize);
}

void MonsterFodder::update() { }

void MonsterFodder::setCombatPos() {
	xpos = 0.2f; ypos = 0; // mover monster centre right for combat
}