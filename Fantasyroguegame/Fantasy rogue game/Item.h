#ifndef ITEM_H
#define ITEM_H

class Item: public AbstractItem {
public:
	Item(std::string basename, int str, int hp, int spd) { name.assign(basename); strength = str; health = hp; speed = spd;} // assign is a string function
	Item(char * basename, int str, int hp, int spd) { name.assign(basename); strength = str; health = hp; speed = spd;} // to set string contents
	void draw() {}

	int getHealth() {return health;}
	int getStrength() {return strength;}
	int getSpeed() {return speed;}

	float getXPos() {return xpos;}
	float getYPos() {return ypos;}
	float getXSize() {return xsize;}
	float getYSize() {return ysize;}

	void itemEffect(Player *player) {}
	~Item() { std::cout << "Deleting Object Item " << name << std::endl; }

private:
	std::string name;

protected: 
	int health;
	int strength;
	int speed;
};

#endif
