#ifndef MONSTER_H
#define MONSTER_H

#include <SDL.h>
#include "Label.h"

class Monster {
public:
	virtual ~Monster() { return; }
	virtual void draw() = 0;
	virtual float getXPos() = 0;
	virtual float getYPos() = 0;
	virtual float getXSize() = 0;
	virtual float getYSize() = 0;

	virtual void sethasCollided(bool value) = 0;
	virtual void setDead(bool value) = 0;
	virtual void setCombatPos() = 0;
	virtual void setHealth(int newHealth) = 0;

	virtual bool getHasCollided() = 0;
	virtual int getHealth() = 0;
	virtual int getStrength() = 0;
	virtual int getSpeed() = 0;
	virtual int getDollars() = 0;
	virtual bool getDropRate() = 0;
	virtual bool getDead() = 0;

	virtual void update() = 0;

protected:
	float xpos, ypos, xsize, ysize;
	int health, strength, speed, dollars, dropRate;
	Label *label;
	bool hasCollided;
	bool dead;
};
#endif