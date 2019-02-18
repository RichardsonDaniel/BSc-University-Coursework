#ifndef ABSTRACITEM_H
#define ABSTRACITEM_H

#include "Player.h"

class AbstractItem {
public:
	virtual void draw() = 0;
	virtual int getHealth() = 0;
	virtual int getStrength() = 0;
	virtual int getSpeed() = 0;
	virtual float getXPos() = 0;
	virtual float getYPos() = 0;
	virtual float getXSize() = 0;
	virtual float getYSize() = 0;
	virtual void itemEffect(Player *player) = 0;
	virtual ~AbstractItem(){}

protected:
	float xpos, ypos, xsize, ysize;
	Label* label;
};
#endif
