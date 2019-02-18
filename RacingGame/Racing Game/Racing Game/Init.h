#pragma once
#include "game.h"
#include "car.h"

#define MAP_H 30
#define MAP_W 30
#define TILE_SIDE 10

// texture parameter macro
#define setTexParameter()\
{		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_REPEAT);\
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_REPEAT);\
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);\
		glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR);}

enum texObj {Floor=0,Wall=1,Boarder=2,Car=3,End=4,Tar=5,Grass=6,tester=7,Start=8,Congrats=9};

void readMap(GLuint map[MAP_H][MAP_W]);