#pragma once
#include "game.h"

class car
{
public:
	//constructor
	car()
	{
		cX=0;
		cY=0;
		halfLong=0;
		angle=0;
		speed=0;
		acceleration=0;
		deceleration=0;
		topspeed=0;
		handbreak=0;
	}
	
	car(GLdouble x,GLdouble y,double l,double a,double s,double ac,double dc,double ts,double hb)
	{
		cX=x;
		cY=y;
		halfLong=l;
		angle=a;
		speed=s;
		acceleration=ac;
		deceleration=dc;
		topspeed=ts;
		handbreak=hb;
	}
	
	GLdouble cX,cY; //the middle point
	double halfLong;
	double angle; //the pointing direction
	double speed;
	double acceleration;
	double deceleration;
	double topspeed;
	double handbreak;

	car& operator = (const car& infoCar)
	{
		cX=infoCar.cX;
		cY=infoCar.cY;
		halfLong=infoCar.halfLong;
		angle=infoCar.angle;
		speed=infoCar.speed;
		acceleration=infoCar.acceleration;
		deceleration=infoCar.deceleration;
		topspeed=infoCar.topspeed;
		handbreak=infoCar.handbreak;
	}
};
