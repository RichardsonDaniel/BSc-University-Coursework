#include "MonsterRaider.h"
#include "Game.h"
#include <sstream>

MonsterRaider::MonsterRaider() {
	xpos = (float)rand()/RAND_MAX - 0.75f;//random spawn location
	ypos = (float)rand()/RAND_MAX - 0.75f;

	//initial values for raider 
	xsize = 0.05f;
	ysize = 0.05f;
	health = 12; 
	strength = 7;
	speed = 12;
	dollars = 100;

	dead = false;

	glClearColor(0.0, 0.0, 0.0, 0.0);

	label = new Label();
	hasCollided = false;
}

void MonsterRaider::draw() {
	glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
		glVertex2f (xpos, ypos); // first corner
		glVertex2f (xpos+xsize, ypos); // second corner
		glVertex2f (xpos+xsize, ypos+ysize); // third corner
		glVertex2f (xpos, ypos+ysize); // fourth corner
	glEnd();

	label->textToTexture("Raider");
	label->draw(xpos, ypos-ysize);
}

void MonsterRaider::update() { }

void MonsterRaider::setCombatPos() {
	xpos = 0.2f; ypos = 0; // mover monster centre right for combat
}