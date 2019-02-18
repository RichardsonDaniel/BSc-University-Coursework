#include<gl/glut.h>
#include<cmath>
#include"ship.h"
#include"random.h"
#include"ground.h"



Lander::Lander(float ix, float iy, int ifuel)
{
	x = ix; y = iy;
	radius = 10;
	dx=random(-2, 2);
	dy=random(1, 1);
	fuel = ifuel;
}

void Lander::show(){
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(22, 0, 0, 1);
	glTranslatef(-x, -y, 0);
	draw();
	glPopMatrix();
}

void Lander::draw()
{
	glBegin(GL_POLYGON);		// main body of lander
	const int NPOINTS=90;
	const float TWOPI=2*3.1415927;
	const float STEP=TWOPI/NPOINTS;
	glColor3f(1, 0.8, 0.2);
	for(float angle=0; angle<TWOPI; angle+=STEP)	
		glVertex2f(x+radius*cos(angle), y+radius*sin(angle));
	glEnd();

		glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	for(float angle=0; angle<TWOPI; angle+=STEP)	
		glVertex2f(x+radius*cos(angle), y+radius*sin(angle));
	glEnd();

			glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	int inerrad = 5;
	for(float angle=0; angle<TWOPI; angle+=STEP)	
		glVertex2f(x+inerrad*cos(angle), y+inerrad*sin(angle));
	glEnd();

			glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	for(float angle=0; angle<TWOPI; angle+=STEP)	
		glVertex2f(x+inerrad*cos(angle), y+inerrad*sin(angle));
	glEnd();



	glBegin(GL_LINE_LOOP);		// landing gear left
	glColor3f(1, 0.8, 0.2);
	glVertex2f(x-6, y-6);
	glColor3f(1, 0.8, 0.2);
	glVertex2f(x-12, y-12);
	glEnd();

	glBegin(GL_LINE_LOOP);		// landing gear right
	glColor3f(1, 0.8, 0.2);
	glVertex2f(x, y-8);
	glColor3f(1, 0.8, 0.2);
	glVertex2f(x, y-17);
	glEnd();
}


void Lander::gravity()
{
	x += dx;			// move horizontal
	y += -dy;			// gravity
	dy += GRAVITY;		// to vertical movement
}

void Lander::incrementVel(float ddx, float ddy)
{
	if(fuel > 0)	// if there is fuel, decrement it
		{
			fuel -= 1;
			if(fuel < 1)	// if fuel is below 0, do not change it
				fuel -= 0;
		}

	dx += ddx;	// increment horizontal velocity
	dy -= ddy;	// inrecrement vertical velocity
}

void Lander::stop()	// stop the landers movement
{
	dy = dx = 0;
}

void Lander::reset() // reset all properties of lander
{
	x = random(100,900);
	y = random(500,700);
	dx=random(-2, 2);
	dy=random(1, 1);
	fuel = 200;
}

void Lander::windowcollisions()	// check for lander hitting the sides of the window, move to the opposite side if hit, to keep in view
{
	if((x+radius)<0)			
		x = x+1000;
	else if((x-radius) > 1000)	
		x = x-1000;
}

float Lander::heightLeftAboveGround(Ground *g) // check height between ground and left landing gear
{
	return g->Ground::heightAt(x-12);
}

float Lander::heightRightAboveGround(Ground *g) // check height between ground and right landing gear 
{
	return g->heightAt(x);
}





