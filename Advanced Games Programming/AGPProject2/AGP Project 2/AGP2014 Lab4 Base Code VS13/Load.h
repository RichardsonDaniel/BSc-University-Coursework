#include <GL/glew.h>
#include <SDL.h>
#include <iostream>
#include <fstream>
#include <string>
#include <glm\glm.hpp>


namespace Load {
	GLuint loadBitmap(char *fname);
	glm::vec3 moveForward(glm::vec3 pos, GLfloat d, GLfloat r);
	glm::vec3 moveRight(glm::vec3 pos, GLfloat d, GLfloat r);
}

