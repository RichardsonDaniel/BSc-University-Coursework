#include<gl/glut.h>
#include"ground.h"
#include"random.h"

Ground::Ground()
{
	int flat1 = random(10, 50);// sets random variable for flat area 1 across the screen
	int flat2 = random(50, 80);// sets random variable for flat area 2 across the screen
	float h = random(80, 130);//random height variable for the flat areas

	for(int i=0; i<100; i++){ //sets random spiking heights for ground level
		heights[i] = random(50, 100); }
	for(int i=flat1; i<flat1+10; i++){ //inserts a flat area at the random height h
		heights[i] = h; }
	for(int i=flat2; i<flat2+10; i++){ //inserts second flat area at same height
		heights[i] = h; }
}

void Ground::show()
{
	glBegin(GL_TRIANGLE_FAN);//Triangle_fan had better land filling than polygon on tests
		glColor3f(0.4, 0.4, 0.4);
		glVertex2f(-02, -1);
		for(int i=0; i<100; i++){
			glVertex2f(i*10, heights[i]); }
		glVertex2f(1015, -1);	
	glEnd();
}


