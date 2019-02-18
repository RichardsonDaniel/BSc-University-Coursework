/*
 LunarlanderMission Game, 2D Graphics Programming.
 B00239486.
 
 Random class created by Alistair McMonnies:
 (alistair.mcmonnies@uws.ac.uk)
 Bitmap class created by Alistair McMonnies, Daniel Livingstone and Chris Backhouse:
 (alistair.mcmonnies@uws.ac.uk, daniel.livingstone@uws.ac.uk and cjbackhouse@hotmail.com - www.backhouse.tk)

 Backdrop image taken from deviant art and converted to Bitmap:
 http://th01.deviantart.net/fs6/PRE/i/2005/024/f/7/Blue_Starfield_by_oblisk87.jpg

 Int to string convertor taken from multiple posts at:
 http://stackoverflow.com/questions/5590381/easiest-way-to-convert-int-to-string-in-c
 (link doesn't seem to always work but should be in top results of google search for "int to string C++" which has it cached)
 
 Special Key presses used from Adv Lab 2, created by Alistair McMonnies.
 drawString used from Chapter 9 of Module Notes, created by Alistair McMonnies.

 Created by Daniel Richardson.
 Created with Xcode/Visual studio.
 Copyright (c) 2013 Daniel Richardson. All rights reserved.
 */

#include<iostream>
#include<gl/glut.h>
#include<sstream> //used for int to string convertor
#include"random.h"
#include"ship.h"
#include"ground.h"
#include"Bitmap.h"
using namespace std;

//Beginning Setup Variables

float startx = random(100,900);//Random x starting position of lander
float starty = random(500,700);//Random y starting position of lander
int startfuel = 200;//initial fuel setup
Lander lander(startx, starty, startfuel);//Lander Setup
float gametime = 0;//set gametime to 0	

string thefuel(" "); //fuel counter
string altitude(" ");//height counter

Ground *theground = NULL;
Bitmap *background = NULL;

void init()
{
	theground = new Ground;
	background = new Bitmap("background.bmp", false);
}

std::string IntToStr(int n)	 //Int convertor
{									
  std::ostringstream result;
  result << n;			
  return result.str();		
}

void drawString(void *font, float x, float y, const char *str)
{																	
	char *ch;														
	glRasterPos3f(x, y, 0.0);										
	for(ch=(char*)str; *ch ; ch++)									
		glutBitmapCharacter(font, (int)*ch);						
}																									

void gamemessages()	// function for notifications
{

	thefuel = IntToStr(lander.getfuel());
	altitude = IntToStr((int)lander.gety());

	glColor3f(0.4, 1, 0.4);
	drawString(GLUT_BITMAP_HELVETICA_18, 405, 30, "Fuel: ");			
	drawString(GLUT_BITMAP_HELVETICA_18, 445, 30, thefuel.c_str());		//Write fuel values onto screen
	drawString(GLUT_BITMAP_HELVETICA_18, 550, 30, "Altitude: ");		
	drawString(GLUT_BITMAP_HELVETICA_18, 620, 30, altitude.c_str());	//Write altitude values onto screen

	if(lander.gety() > 900)	{
			drawString(GLUT_BITMAP_HELVETICA_18, 100, 350, "You have ventured too far into space, press R to start again.");
			lander.stop(); } //if lander passes end of screen and a bit more the game is ended

	if(lander.getfuel() < 1)
		drawString(GLUT_BITMAP_HELVETICA_18, 100, 250, "You have no more fuel!"); //if fuel runs out display message

		if(lander.getDy() != 0)
		gametime += 0.002f;
}


void collisions()
{
	if(lander.gety() - lander.heightLeftAboveGround(theground) == lander.gety() - lander.heightRightAboveGround(theground)) // check if lander is above flat area
		{
			if(((lander.gety() - lander.heightLeftAboveGround(theground)) < 16) && lander.gety() - lander.heightRightAboveGround(theground) < 16)	// tests if lander is touching the ground
				{
					lander.stop();
					drawString(GLUT_BITMAP_HELVETICA_18, 100, 150, "You have landed successfully! Press R to reset the game");
				}	
		}
	else	
		{
			if(((lander.gety() - lander.heightLeftAboveGround(theground)) < 16) && lander.gety() - lander.heightRightAboveGround(theground) < 16)	// tests if lander is touching the ground NOT above a flat area
				{
					lander.stop();
					drawString(GLUT_BITMAP_HELVETICA_18, 100, 220, "You have crashed! Press R to reset the game!");
				}
		}
}



void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	background->draw(0, 0, 1000, 800);
	theground->show();
	lander.show();
	collisions();
	gamemessages();
	glutSwapBuffers();
}

void keysdown(unsigned char key, int x, int y)		// NORMAL KEYS
{
	switch(key)
	{
		case 'a':								// LEFT
			if(lander.getfuel() > 0)
				lander.incrementVel(-0.02, 0);
			else
				lander.incrementVel(0,0);
			break;
		case 'd':								// RIGHT
			if(lander.getfuel() > 0)
				lander.incrementVel(0.02, 0);
			else
				lander.incrementVel(0,0);
			break;
		case 'w':								// UP
			if(lander.getfuel() > 0)
				lander.incrementVel(0, 0.03);
			else
				lander.incrementVel(0,0);
			break;
		case 'r':								// Reset game
			lander.reset();
			gametime = 0;
			break;
	}
}

void special_keys(int key, int x, int y)	// ARROW KEYS
{
	switch(key) 
	{
		case GLUT_KEY_UP:					// ARROW UP
			if(lander.getfuel() > 0)
				lander.incrementVel(0, 0.03);
			else
				lander.incrementVel(0,0);
			break;
		case GLUT_KEY_RIGHT:				// ARROW RIGHT
			if(lander.getfuel() > 0)
				lander.incrementVel(0.02, 0);
			else
				lander.incrementVel(0,0);
			break;
		case GLUT_KEY_LEFT:					// ARROW LEFT
			if(lander.getfuel() > 0)
				lander.incrementVel(-0.02, 0);
			else
				lander.incrementVel(0,0);
			break;
	}
}

void timer(int value)
{
	display();
	lander.gravity();			//keep gravity
	lander.windowcollisions();	//move lander to opposite side if leaves window
	glutTimerFunc(10, timer, 0);
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1000,800);
	glutCreateWindow("Lunar Lander Mission");
	gluOrtho2D(0, 1000, 0, 800);
	init();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(display);
	glutTimerFunc(10, timer, 0);
	glutIdleFunc(display);
	glutKeyboardFunc(keysdown);
	glutSpecialFunc(special_keys); //For us of arrow keys aswell as wasd
	glutMainLoop(); 
}