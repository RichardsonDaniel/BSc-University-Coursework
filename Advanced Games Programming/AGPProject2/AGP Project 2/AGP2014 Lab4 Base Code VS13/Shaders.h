#pragma once
#include <GL/glew.h>
#include <unordered_map>
#include <string>
#include <iostream>
#include <glm/glm.hpp>
#include "rt3d.h"
using namespace std;

typedef unordered_map<std::string, GLuint> shadermap;

class Shaders
{
public:
	Shaders();
	~Shaders();

	void init();
	void useShader(string ID);

	GLuint getShader(string ID);
	
	
private:
	shadermap shaderMap;
	
};

