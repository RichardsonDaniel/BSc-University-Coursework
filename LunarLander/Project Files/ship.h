#ifndef SHIP_H
#define SHIP_H
#include "ground.h"

const float GRAVITY = 0.003;

class Lander
{
	public:
		int fuel;
		Lander(float ix, float iy, int iradius);
		void show();	
		void draw();
		void gravity();
		void windowcollisions();
		void stop();
		void incrementVel(float ddx, float ddy);
		void reset();
		int getfuel(){return fuel;}
		void setfuel(int newfuel){fuel = newfuel;}
		float gety(){return y;}
		float getx(){return x;}
		float getDx(){return dx;}
		float getDy(){return dy;}
		float heightLeftAboveGround(Ground *g);
		float heightRightAboveGround(Ground *g);
	private:
		float x, y, radius, dy, dx;

};
#endif