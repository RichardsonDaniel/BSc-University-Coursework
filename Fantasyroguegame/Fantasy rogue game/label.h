#ifndef Label_H
#define Label_H

#include <SDL_ttf.h>
#include <glew.h>
#include <ctime>
#include <iostream>

class Label
{
	public:
		~Label() {return;};
		static void exitFatalError(char *message);
		void textToTexture(const char * str);
		void draw(float x, float y); 
		void draw(float x, float y, GLfloat scale);
	private:
		GLuint texID;
		GLuint height;
		GLuint width;
		TTF_Font* textFont;
};
#endif