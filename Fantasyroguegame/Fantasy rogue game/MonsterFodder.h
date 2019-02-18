#ifndef MONSTERFODDER_H
#define MONSTERFODDER_H

#include "Monster.h"

class MonsterFodder: public Monster {
public:
	~MonsterFodder() { std::cout << "Deleted MonsterFodder" << std::endl; delete label; }
	MonsterFodder();
	void draw();
	float getXPos(){return xpos;}
	float getYPos(){return ypos;}
	float getXSize(){return xsize;}
	float getYSize(){return ysize;}
	void update();
	bool getHasCollided() {return hasCollided;}
	void sethasCollided(bool value) {hasCollided = value;}
	void setCombatPos();
	int getHealth() {return health;}
	int getStrength() {return strength;}
	int getSpeed() {return speed;}
	int getDollars() {return dollars;}
	void setHealth(int newHealth) {health = health - newHealth;}

	bool getDropRate() {
		dropRate = rand() % 100+1; //random value between 1 and 100
		std::cout << "monster drop rate: " << dropRate << std::endl;
		if(dropRate <= 5) //if <=5 then item is dropped
			return true;
		else //otherwise no drop
			return false;
	}    

	void setDead(bool value) { 
		dead = value;
	}

	bool getDead() { 
		return dead;
	}
};

#endif
