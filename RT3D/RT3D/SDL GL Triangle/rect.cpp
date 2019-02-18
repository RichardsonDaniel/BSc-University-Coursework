#include "rect.h"

rect::rect()
{
	left=right=top=bottom=0;
}

void rect::setRect(GLfloat x, GLfloat z, GLfloat w, GLfloat h)
{
	left = x;
	right = x+w;
	top = z;
	bottom = z+h;
}

bool rect::intersects(rect &r){
	return ! (left > r.right ||
				right < r.left ||
				top > r.bottom ||
				bottom < r.top);
	return true;
} 

