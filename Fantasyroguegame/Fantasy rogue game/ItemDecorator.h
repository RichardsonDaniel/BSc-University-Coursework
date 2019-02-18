#ifndef ITEMDECORATOR_H
#define ITEMDECORATOR_H

class ItemDecorator: public AbstractItem {
public:
	ItemDecorator(AbstractItem *i) { item = i; }
	void draw() { item->draw(); }
	int getHealth() { return item->getHealth();}
	int getStrength() { return item->getStrength();}
	int getSpeed() {return item->getSpeed();}
	float getXPos() {return xpos;}
	float getYPos() {return ypos;}
	float getXSize() {return xsize;}
	float getYSize() {return ysize;}
	void itemEffect(Player *player){item->itemEffect(player);} //stat effects to player
	~ItemDecorator() {delete item;}

private:
	AbstractItem * item;

protected: 
	int health;
	int strength;
	int speed;
};
#endif
