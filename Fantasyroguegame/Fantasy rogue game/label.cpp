//used to draw all text ans objects to the screen
#include "Label.h"

void Label::exitFatalError(char *message) {
    std::cout << message << " " << SDL_GetError();
    SDL_Quit();
    exit(1);
}

void Label::textToTexture(const char * str) {
	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);
	SDL_Surface *stringImage;
	SDL_Color colour = { 100, 0, 225 };
	stringImage = TTF_RenderText_Blended(textFont,str,colour);

	if (stringImage == NULL)
		Label::exitFatalError("String surface not created.");

	GLuint colours = stringImage->format->BytesPerPixel;

	GLuint format, internalFormat;
	if (colours == 4) {   // alpha
		if (stringImage->format->Rmask == 0x000000ff)
			format = GL_RGBA;
	    else
		    format = GL_BGRA;
	} else {             // no alpha
		if (stringImage->format->Rmask == 0x000000ff)
			format = GL_RGB;
	    else
		    format = GL_BGR;
	}
	internalFormat = (colours == 4) ? GL_RGBA : GL_RGB;

	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID); 
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, stringImage->w, stringImage->h, 0, format, GL_UNSIGNED_BYTE, stringImage->pixels);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	width = stringImage->w;
	height = stringImage->h;
	SDL_FreeSurface(stringImage);
	TTF_CloseFont(textFont);
}

// draw label via custom scale
void Label::draw(float x, float y, GLfloat scale) {
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glBegin(GL_QUADS);
	  glTexCoord2d(0,1); // Texture has origin at top not bottom
      glVertex3f (x,y, 0.0); // first corner
	  glTexCoord2d(1,1);
      glVertex3f (x+scale*width, y, 0.0); // second corner
	  glTexCoord2d(1,0);
      glVertex3f (x+scale*width, y+scale*height, 0.0); // third corner
	  glTexCoord2d(0,0);
      glVertex3f (x, y+scale*height, 0.0); // fourth corner
    glEnd();
	glDisable(GL_TEXTURE_2D);
	glDeleteTextures(1, &texID);
}

void Label::draw(GLfloat x, GLfloat y)
{
	draw(x,y, 0.002f);
}