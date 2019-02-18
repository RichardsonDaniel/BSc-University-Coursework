#pragma once
#include "game.h"
#include "Init.h"
#include "glaux.h"
#include <gl\gl.h>
#include <gl\glu.h>
#include <glut.h>
#include "freeglut.h"
#include "carInfo.h"
#include <iostream>
using namespace std;

// preload variables
#define HI 1																// height of the camera
#define WI 40.0																// width of the view
int keyPress[5]={0};														// key info
GLuint tileMap[MAP_H][MAP_W];												// store map
bool is_end=false;															// determine whether the game ends
bool fullscr=true;															// whether it's fullscreen or not
car *aCar;																	// pointer to the car class

// texture loading
void loadTexture()
{
	// prepare for texture loading
	whd_bitmap floor_tex,wall_tex,boarder_tex,car_tex,symbol_1_tex,symbol_2_tex,symbol_3_tex,start_tex,end_tex,congrats_tex;
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);
	glGenTextures(10,texName);
	
	// load floor
	glBindTexture(GL_TEXTURE_2D,texName[Floor]);
	setTexParameter();
	floor_tex.load(L"Resources/floor.bmp");
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,floor_tex.width,floor_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,floor_tex.data);
	
	//load wall
	glBindTexture(GL_TEXTURE_2D,texName[Wall]);
	setTexParameter();
	wall_tex.load(L"Resources/barrier.bmp");
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,wall_tex.width,wall_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,wall_tex.data);
	
	//load boarder
	glBindTexture(GL_TEXTURE_2D,texName[Boarder]);
	setTexParameter();
	boarder_tex.load(L"Resources/boarder.bmp");
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,boarder_tex.width,boarder_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,boarder_tex.data);
	
	//load car
	glBindTexture(GL_TEXTURE_2D,texName[Car]);
	setTexParameter();
	car_tex.load(L"Resources/car.bmp",0,0,0);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,car_tex.width,car_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,car_tex.data);
	
	//load end
	glBindTexture(GL_TEXTURE_2D,texName[End]);
	setTexParameter();
	end_tex.load(L"Resources/end.bmp");
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,end_tex.width,end_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,end_tex.data);
	
	//load symbol_1
	glBindTexture(GL_TEXTURE_2D,texName[Tar]);
	setTexParameter();
	symbol_1_tex.load(L"Resources/tar.bmp");
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,symbol_1_tex.width,symbol_1_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,symbol_1_tex.data);
	
	//load symbol_2
	glBindTexture(GL_TEXTURE_2D,texName[Grass]);
	setTexParameter();
	symbol_2_tex.load(L"Resources/Grass.bmp");
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,symbol_2_tex.width,symbol_2_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,symbol_2_tex.data);
	
	//load symbol_3
	glBindTexture(GL_TEXTURE_2D,texName[tester]);
	setTexParameter();
	symbol_3_tex.load(L"Resources/tester.bmp");
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,symbol_3_tex.width,symbol_3_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,symbol_3_tex.data);

	//load start
	glBindTexture(GL_TEXTURE_2D,texName[Start]);
	setTexParameter();
	start_tex.load(L"Resources/start.bmp");
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,start_tex.width,start_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,start_tex.data);

	//load congrats
	glBindTexture(GL_TEXTURE_2D,texName[Congrats]);
	setTexParameter();
	congrats_tex.load(L"Resources/win.bmp",0,0,0);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,congrats_tex.width,congrats_tex.height,0,GL_RGBA,GL_UNSIGNED_BYTE,congrats_tex.data);
}

void init()
{
	aCar=new car(CX,CY,HL,AN,SP,AC,DC,TS,HB);								// A new object is created labeled as aCar
	glClearColor(0.0,0.0,0.0,1.0);											// this will hold the defined statistics from carInfo.h
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_ALPHA_TEST);
	loadTexture();
}

//determine which key is being pressed
void keyboardDown(unsigned char key,int w,int h)
{
	if (key==27)
	{
		if (fullscr)
			glutLeaveGameMode();
		delete aCar;
		exit(0);
	}
	if (key==' ')
		keyPress[4]=1;
}
void specialDown(int key,int w,int h)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		keyPress[0]=1;
		break;
	case GLUT_KEY_DOWN:
		keyPress[1]=1;
		break;
	case GLUT_KEY_LEFT:
		keyPress[2]=1;
		break;
	case GLUT_KEY_RIGHT:
		keyPress[3]=1;
		break;
	default:
		break;
	}
}

//determine which key is being released
void keyboardUp(unsigned char key,int w,int h)
{
	if (key==' ')
		keyPress[4]=0;
}
void specialUp(int key,int w,int h)
{
	switch(key)
	{
	case GLUT_KEY_UP:
		keyPress[0]=0;
		break;
	case GLUT_KEY_DOWN:
		keyPress[1]=0;
		break;
	case GLUT_KEY_LEFT:
		keyPress[2]=0;
		break;
	case GLUT_KEY_RIGHT:
		keyPress[3]=0;
		break;
	default:
		break;
	}
}

void showEnd()
{
	is_end=true;
	glutPostRedisplay();
}

// per vertex pixel collision test
bool collisionTest(int map_h,int map_w,int side)
{
	double x[4],y[4],v[2];
	double cosCONST=cos(aCar->angle+PI/2)*aCar->halfLong/4;
	double sinCONST=sin(aCar->angle+PI/2)*aCar->halfLong/4;
																			//
																			// four vertices' current coordinates
	x[0]=aCar->cX+cosCONST+aCar->halfLong*cos(aCar->angle);					//
	y[0]=aCar->cY+sinCONST+aCar->halfLong*sin(aCar->angle);					//
	x[1]=aCar->cX+cosCONST;													//
	y[1]=aCar->cY+sinCONST;													//
	x[2]=aCar->cX-cosCONST;													//
	y[2]=aCar->cY-sinCONST;													//
	x[3]=aCar->cX-cosCONST+aCar->halfLong*cos(aCar->angle);					//
	y[3]=aCar->cY-sinCONST+aCar->halfLong*sin(aCar->angle);					//
																			//
																			// coordinates offset
	v[0]=map_w*side/2;
	v[1]=-map_h*side/2;

	for (int i=0;i<4;i++)													// Initialise counter and loop
	{																		//
		x[i]=x[i]+v[0];														// Set up vertice's x coordinate for this iteration's check
		y[i]=y[i]+v[1];														// set up vertice's y coordinate for this iteration's check
																			//
		int m=int(-y[i]/side);												// 
		int n=int(x[i]/side);												//
																			//
		if (tileMap[m][n]!=0												// Test to see if the current vertice is colliding with a non passable tile
			&&tileMap[m][n]!=4												//
			&&tileMap[m][n]!=8												//
			&&tileMap[m][n]!=5)												// 
			return true;													// 
		else																// Otherwise
		{																	//
			if (tileMap[m][n]==4)											// Test to see if current vertice has collided with finish line
				showEnd();													//
		}																	//
	}																		//
	return false;															//
}																			//

bool tarTest(int map_h,int map_w,int side)
{
	double x[4],y[4],v[2];
	double cosCONST=cos(aCar->angle+PI/2)*aCar->halfLong/4;
	double sinCONST=sin(aCar->angle+PI/2)*aCar->halfLong/4;
																			//
																			// four vertices' current coordinates
	x[0]=aCar->cX+cosCONST+aCar->halfLong*cos(aCar->angle);					//
	y[0]=aCar->cY+sinCONST+aCar->halfLong*sin(aCar->angle);					//
	x[1]=aCar->cX+cosCONST;													//
	y[1]=aCar->cY+sinCONST;													//
	x[2]=aCar->cX-cosCONST;													//
	y[2]=aCar->cY-sinCONST;													//
	x[3]=aCar->cX-cosCONST+aCar->halfLong*cos(aCar->angle);					//
	y[3]=aCar->cY-sinCONST+aCar->halfLong*sin(aCar->angle);					//
																			//
																			// coordinates offset
	v[0]=map_w*side/2;
	v[1]=-map_h*side/2;

	for (int i=0;i<4;i++)													// Initialise counter and loop
	{																		//
		x[i]=x[i]+v[0];														// Set up vertice's x coordinate for this iteration's check
		y[i]=y[i]+v[1];														// set up vertice's y coordinate for this iteration's check
																			//
		int m=int(-y[i]/side);												// 
		int n=int(x[i]/side);												//
																			//
		if (tileMap[m][n]==5)												// Test to see if the current vertice is colliding with a Sticky tile
			return true;													// 
		else																// Otherwise
		{																	//
			return false;													// It it not
		}																	//
	}																		//															
}																		    //
// update the car state
void updateState()
{
																		// collision reaction
	if (collisionTest(MAP_H,MAP_W,TILE_SIDE))
		aCar->speed=-aCar->speed*0.3;
	if (tarTest(MAP_H,MAP_W,TILE_SIDE))
		aCar->speed-=(aCar->speed*0.1);
	

																		// key reaction
	if (!is_end)														// if (is_end) does not equal true
	{
		if (keyPress[0]==1)											// Force applies
		{
			if (aCar->speed<aCar->topspeed)								// if car is less than (top speed)
				aCar->speed+=aCar->acceleration;						// speed = previous speed + acceleration
			aCar->cY+=aCar->speed*sin(aCar->angle);						// y = y + (speed) x sin(angle)
			aCar->cX+=aCar->speed*cos(aCar->angle);						// x = x + (speed) x cos(angle)
		}
		else														// there is no forward Force
		{
			if (keyPress[1]==1)										//if press back
			{
				if (aCar->speed>(-aCar->topspeed/3))					// if car speed is greater than the negative of (top speed)
					aCar->speed-=aCar->deceleration;					// speed = previous speed - deceleration
				aCar->cY+=aCar->speed*sin(aCar->angle);					// y = y + (speed) x sin(angle)
				aCar->cX+=aCar->speed*cos(aCar->angle);					// x = x + (speed) x cos(angle)
			}
			else													// no thrust, no back
			{
				if (aCar->speed!=0.0)									// if current speed does not = 0
				{														//
					double decele=0.0;									// Single variable for deceleration declared
					if (keyPress[4]==1)									// If the handbrake has been pressed
						decele=aCar->handbreak;							// The deceleration is equal to the handbreak value(handbreak force + ground deceleration)
					if (keyPress[4]==0)									// If the handbrake has not been pressed
						decele=deceleration_ground;						// The deceleration is equal to the 
					if (aCar->speed>0)									// 
					{													// If the car moving positively greater than 0
						aCar->speed+=decele;							// speed = previous speed + deceleration
						aCar->cY+=aCar->speed*sin(aCar->angle);			// y = y + (speed) x sin(angle)
						aCar->cX+=aCar->speed*cos(aCar->angle);			// x = x + (speed) x cos(angle)
					}													//
					else												//
					{													//
						if (aCar->speed<0)								// If the car moving positively greater than 0
						{												//
							aCar->speed-=decele;						// speed = previous speed - deceleration
							aCar->cY+=aCar->speed*sin(aCar->angle);		// y = y + (speed) x sin(angle)
							aCar->cX+=aCar->speed*cos(aCar->angle);		// x = x + (speed) x cos(angle)
						}
					}
				}
			}
		}
		if (keyPress[2]==1) 											// turn left	
		{																//
			if (aCar->speed!=0)											// if car is not at rest
			{															// decide whether the steering is in reverse
				if (aCar->speed>0)										// if current speed is positive
					aCar->angle+=STEERING;								// Angle of direction = current angle + steering value
				else													// otherwise
					aCar->angle-=STEERING;								// Angle of direction = current angle - steering value
																		//
			}															// 
		}																// 
		if (keyPress[3]==1) 											// turn right
		{																// 
			if (aCar->speed!=0)											// if car is not at rest
			{															// decide whether the steering is in reverse
				if (aCar->speed>0)										// if current speed is positive
					aCar->angle-=STEERING;								// Angle of direction = current angle - steering value
				else													// otherwise
					aCar->angle+=STEERING;								// Angle of direction = current angle + steering value
			}
		}
	}
}


void display()
{
	//preparation
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glAlphaFunc(GL_NOTEQUAL,0);
	
	// display congrats
	if (is_end)
	{
		glBindTexture(GL_TEXTURE_2D,texName[Congrats]);
		glBegin(GL_QUADS);
			glTexCoord2d(0,0);
			glVertex2d(aCar->cX-30.0,aCar->cY-30.0);
			glTexCoord2d(1,0);
			glVertex2d(aCar->cX+30.0,aCar->cY-30.0);
			glTexCoord2d(1,1);
			glVertex2d(aCar->cX+30.0,aCar->cY+30.0);
			glTexCoord2d(0,1);
			glVertex2d(aCar->cX-30.0,aCar->cY+30.0);
		glEnd();
	}
	
	// draw car
	glBindTexture(GL_TEXTURE_2D,texName[Car]);
	double cosCONST=cos(aCar->angle+PI/2)*aCar->halfLong/4;
	double sinCONST=sin(aCar->angle+PI/2)*aCar->halfLong/4;
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,1.0);
		glVertex2d(aCar->cX+cosCONST+aCar->halfLong*cos(aCar->angle),aCar->cY+sinCONST+aCar->halfLong*sin(aCar->angle));
		glTexCoord2f(0.0,0.0);
		glVertex2d(aCar->cX+cosCONST,aCar->cY+sinCONST);
		glTexCoord2f(1.0,0.0);
		glVertex2d(aCar->cX-cosCONST,aCar->cY-sinCONST);
		glTexCoord2f(1.0,1.0);
		glVertex2d(aCar->cX-cosCONST+aCar->halfLong*cos(aCar->angle),aCar->cY-sinCONST+aCar->halfLong*sin(aCar->angle));
	glEnd();
		
	// draw textured backdrop	
	glPushMatrix();
	glTranslatef(-MAP_W*TILE_SIDE/2,MAP_H*TILE_SIDE/2,0.0); //make it in the center
	for (int i=0;i<MAP_H;i++)
	{
		for (int j=0;j<MAP_W;j++)
		{
			GLuint tileNo;
			tileNo=tileMap[i][j];
			glBindTexture(GL_TEXTURE_2D,texName[tileNo]);
			glBegin(GL_QUADS);
				glTexCoord2i(0,1); glVertex2i(j*TILE_SIDE,-i*TILE_SIDE);
				glTexCoord2i(0,0); glVertex2i(j*TILE_SIDE,-(i+1)*TILE_SIDE);
				glTexCoord2i(1,0); glVertex2i((j+1)*TILE_SIDE,-(i+1)*TILE_SIDE);
				glTexCoord2i(1,1); glVertex2i((j+1)*TILE_SIDE,-i*TILE_SIDE);
			glEnd();
		}
	}
	glPopMatrix();
	glDisable(GL_TEXTURE_2D);

	updateState();

	// follow the car
	glLoadIdentity();
	gluLookAt(aCar->cX,aCar->cY,HI,aCar->cX,aCar->cY,0.0,0.0,0.1,0.0);
	glutSwapBuffers();
}


void reshape(GLsizei w,GLsizei h)
{
	glViewport(0,0,w,h);	
	glMatrixMode(GL_PROJECTION);	
	glLoadIdentity();
	glOrtho(-WI*4/3,WI*4/3,-WI,WI,HI-0.1,HI+10.0); //create a flat frustum	
	glMatrixMode(GL_MODELVIEW);
}


void main(int argc,char** argv)
{
	// read map
	readMap(tileMap);
	
	// decide whether go to fullscreen or not
	cout<<" "<<endl;
	cout<<"enter fullscreen? (y/n):";
	char ans;
	cin>>ans;
	if (ans=='y')
		fullscr=true;
	else
	{
		if (ans=='n')
			fullscr=false;
		else
			exit(0);
	}

	// initialize glut
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	if (!fullscr)
	{
		glutInitWindowSize(1024,768);
		glutInitWindowPosition(0,0);
		glutCreateWindow("Racing Game");
	}
	else
	{
		glutGameModeString("1024x768:16");
		glutEnterGameMode();
	}

	// glut main functions
	init();
	glutDisplayFunc(display);
	glutSpecialFunc(specialDown);
	glutSpecialUpFunc(specialUp);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	
	glutMainLoop();
}