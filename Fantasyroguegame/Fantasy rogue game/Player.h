#ifndef PLAYER_H
#define PLAYER_H

#include <SDL.h>
#include "Label.h"

class Player {
public:
	~Player() { delete label; }
	Player();
	void draw();
	void moveY(float val);
	void moveX(float val);
	void update();

	void setCombatPos();
	void resetPos();

	float getXPos() { return xpos; }
	float getYPos() { return ypos; }
	float getXSize() { return xsize; }
	float getYSize() { return ysize; }

	int getHealth() { return health;}
	int getMaxHealth() { return maxHealth;}
	int getStrength() { return strength;}
	int getSpeed() { return speed;}
	int getDollars() { return dollars; }

	void setHealth(int newHealth) { health = newHealth; }
	void damageTaken(int damage) { health = health - damage; }
	void setMaxHealth(int newHealth) { maxHealth = maxHealth + newHealth; }
	void setStrength(int newStrength) { strength = strength+newStrength; }
	void setSpeed(int newSpeed) { speed = speed+newSpeed; }
	void setDollars(int newDollars) { dollars = dollars+newDollars; }
private:
	float xpos, ypos, xsize, ysize;
	float tempXPos, tempYPos;
	Label *label;
	int health, strength, speed, dollars;
	int maxHealth;
};

#endif

