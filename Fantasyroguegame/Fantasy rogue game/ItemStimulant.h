#ifndef ITEMSTIMULANT_H
#define ITEMSTIMULANT_H
#define ITEMSTIMULANT_H

class ItemStimulant: public ItemDecorator {
public:
	ItemStimulant(AbstractItem *n): ItemDecorator(n) { 
		xpos = (float)rand()/RAND_MAX - 0.75f;
		ypos = (float)rand()/RAND_MAX - 0.75f;
		xsize = 0.025f;
		ysize = 0.025f;
		label = new Label();
	}
	int getSpeed() { return ItemDecorator::getSpeed();}

	//add stimulant effect to players speed
	void itemEffect(Player *player) {
		player->setSpeed(this->getSpeed());
	}

	void draw() {
		ItemDecorator::draw();
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POLYGON);
			glVertex2f (xpos, ypos); // first corner
			glVertex2f (xpos+xsize, ypos); // second corner
			glVertex2f (xpos+xsize, ypos+ysize); // third corner
			glVertex2f (xpos, ypos+ysize); // fourth corner
		glEnd();

		label->textToTexture("Stimulant");
		label->draw(xpos, ypos+xsize, 0.0015f);
	}
	~ItemStimulant() { std::cout << "Deleting Decorator Stimulant " << std::endl; delete label; }
};
#endif