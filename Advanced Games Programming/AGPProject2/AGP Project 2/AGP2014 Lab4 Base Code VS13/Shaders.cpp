#include "Shaders.h"

Shaders::Shaders()
{
}

Shaders::~Shaders()
{
}

void Shaders::init()	
{
	//initialise all shaders at start of program
	shaderMap["multiplelights"] = rt3d::initShaders("multiplelight.vert", "multiplelight.frag");
	shaderMap["depth"] = rt3d::initShaders("depth.vert","depth.frag");
	shaderMap["shadow"] = rt3d::initShaders("shadow.vert","shadow.frag");
	shaderMap["particles"] = rt3d::initShaders("particles.vert","particles.frag");
	shaderMap["shader"] = rt3d::initShaders("phong-tex.vert","phong-tex.frag");
	
}

GLuint Shaders::getShader(string ID)
{
	//returns currently used shader
	return shaderMap[ID];
}

void Shaders::useShader(std::string ID)
{
	glUseProgram(shaderMap[ID]);
}
