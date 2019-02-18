#pragma once
#ifndef RECT_H
#define RECT_H

#include <GL/glew.h>

class rect{
public:
	rect();
	void setRect(GLfloat x, GLfloat y, GLfloat w, GLfloat h);
	bool intersects(rect &r);
private:
	float left, top, right, bottom;
};
#endif