#include "MonsterBrute.h"
#include "Game.h"
#include <sstream>

MonsterBrute::MonsterBrute() {
	xpos = (float)rand()/RAND_MAX - 0.75f;//random spawn location
	ypos = (float)rand()/RAND_MAX - 0.75f;
	
	//initial values for brute 
	xsize = 0.05f;
	ysize = 0.05f;
	health = 12; 
	strength = 8;
	speed = 6;
	dollars = 10;

	dead = false;

	glClearColor(0.0, 0.0, 0.0, 0.0);

	label = new Label();
	hasCollided = false;
}

void MonsterBrute::draw() {
	glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
		glVertex2f (xpos, ypos); // first corner
		glVertex2f (xpos+xsize, ypos); // second corner
		glVertex2f (xpos+xsize, ypos+ysize); // third corner
		glVertex2f (xpos, ypos+ysize); // fourth corner
	glEnd();

	label->textToTexture("Brute");
	label->draw(xpos, ypos-ysize);
}

void MonsterBrute::update() { }

void MonsterBrute::setCombatPos() {
	xpos = 0.2f; ypos = 0; // mover monster centre right for combat
}