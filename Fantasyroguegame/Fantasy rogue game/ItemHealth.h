#ifndef ITEMHEALTHPACK_H
#define ITEMHEALTHPACK_H

class ItemHealthPack: public ItemDecorator {
public:
	ItemHealthPack(AbstractItem *n): ItemDecorator(n) { 
		xpos = (float)rand()/RAND_MAX - 0.75f;
		ypos = (float)rand()/RAND_MAX - 0.75f;
		xsize = 0.025f;
		ysize = 0.025f;
		label = new Label();
	}
	int getHealth() { return ItemDecorator::getHealth();}


	
	void itemEffect(Player *player) {
		if(player->getHealth() == player->getMaxHealth()) //if health is not lost increase overall health by 1
			player->setMaxHealth(this->getHealth());

		player->setHealth(player->getMaxHealth()); 	//if health is lost set players health back to 10
	}

	void draw() {
		ItemDecorator::draw();
		glColor3f(1.0, 0.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex2f (xpos, ypos); // first corner
			glVertex2f (xpos+xsize, ypos); // second corner
			glVertex2f (xpos+xsize, ypos+ysize); // third corner
			glVertex2f (xpos, ypos+ysize); // fourth corner
		glEnd();

		label->textToTexture("Health Pack");
		label->draw(xpos, ypos+xsize, 0.0015f);
	}
	~ItemHealthPack() { std::cout << "Deleting Decorator Health Pack" << std::endl; delete label; }
};
#endif