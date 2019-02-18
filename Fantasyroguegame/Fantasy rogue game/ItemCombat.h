#ifndef ITEMCOMBATPACK_H
#define ITEMCOMBATPACK_H

class ItemCombatPack: public ItemDecorator {
public:
	ItemCombatPack(AbstractItem *n): ItemDecorator(n) { 
		xpos = (float)rand()/RAND_MAX - 0.75f;
		ypos = (float)rand()/RAND_MAX - 0.75f;
		xsize = 0.025f;
		ysize = 0.025f;
		label = new Label();
	}

	int getStrength() { return ItemDecorator::getStrength();}

	//add combat effect to player
	void itemEffect(Player *player) {
		player->setStrength(this->getStrength());
	}

	void draw() {
		ItemDecorator::draw();
		glColor3f(0.0, 0.0, 1.0);
		glBegin(GL_POLYGON);
			glVertex2f (xpos, ypos); // first corner
			glVertex2f (xpos+xsize, ypos); // second corner
			glVertex2f (xpos+xsize, ypos+ysize); // third corner
			glVertex2f (xpos, ypos+ysize); // fourth corner
		glEnd();

		label->textToTexture("Combat Pack");
		label->draw(xpos, ypos+xsize, 0.0015f);
	}
	~ItemCombatPack() { std::cout << "Deleting Decorator Combat Pack" << std::endl; delete label; }
};
#endif