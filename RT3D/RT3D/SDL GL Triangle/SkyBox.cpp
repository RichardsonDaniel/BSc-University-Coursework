#include "SkyBox.h"

SkyBox::SkyBox(void)
{
	rotateAngle = 90;
}


SkyBox::~SkyBox(void)
{
}

void SkyBox::init(GLuint newShaderProgram)
{
	skyBoxShader = newShaderProgram; // Set skybox shader

	// Load in skybox textures
	skyBoxTexture[0] = rt3d::loadBitmap("Resources/SkyBoxBack.bmp");
	skyBoxTexture[1] = rt3d::loadBitmap("Resources/SkyBoxLeft.bmp");
	skyBoxTexture[2] = rt3d::loadBitmap("Resources/SkyBoxRight.bmp");
	skyBoxTexture[3] = rt3d::loadBitmap("Resources/SkyBoxUp.bmp");
	skyBoxTexture[4] = rt3d::loadBitmap("Resources/SkyBoxFront.bmp");
	skyBoxTexture[5] = rt3d::loadBitmap("Resources/SkyBoxDown.bmp");

	// Initialise vertex, index and texture data...
	skyBoxVertCount = 12;

	GLfloat skyBoxVerts[] = {
		2, -2, -2,
		2, 2, -2,
		-2, 2, -2,
		-2, -2, -2
	};

	skyBoxIndexCount = 6;

	GLuint skyBoxIndices[] = { 0, 1, 2, 0, 2, 3 };

	GLfloat skyBoxTexCoords[] = {
		1, 1,
		1, 0,
		0, 0,
		0, 1
	};

	// Create mesh object for skybox
	skyBox = rt3d::createMesh(skyBoxVertCount, skyBoxVerts, nullptr, skyBoxVerts, skyBoxTexCoords, skyBoxIndexCount, skyBoxIndices);
}

void SkyBox::draw(std::stack<glm::mat4> &mvStack)
{
	// front
	mvStack.push( mvStack.top() );
	glBindTexture(GL_TEXTURE_2D, skyBoxTexture[4]);
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(2.0f, 2.0f, 2.0f));
	rt3d::setUniformMatrix4fv(skyBoxShader, "modelview", glm::value_ptr(mvStack.top()));
	rt3d::drawIndexedMesh(skyBox,skyBoxIndexCount,GL_TRIANGLES);

	// left
	glBindTexture(GL_TEXTURE_2D, skyBoxTexture[2]);
	mvStack.top() = glm::rotate(mvStack.top(), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(2.0f, 2.0f, 2.0f));
	rt3d::setUniformMatrix4fv(skyBoxShader, "modelview" , glm::value_ptr(mvStack.top()));
	rt3d::drawIndexedMesh(skyBox,skyBoxIndexCount,GL_TRIANGLES);

	// back
	glBindTexture(GL_TEXTURE_2D, skyBoxTexture[0]);
	mvStack.top() = glm::rotate(mvStack.top(), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(2.0f, 2.0f, 2.0f));
	rt3d::setUniformMatrix4fv(skyBoxShader, "modelview" , glm::value_ptr(mvStack.top()));
	rt3d::drawIndexedMesh(skyBox,skyBoxIndexCount,GL_TRIANGLES);
	
	// right
	glBindTexture(GL_TEXTURE_2D, skyBoxTexture[1]);
	mvStack.top() = glm::rotate(mvStack.top(), 90.0f, glm::vec3(0.0f, 1.0f, 0.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(2.0f, 2.0f, 2.0f));
	rt3d::setUniformMatrix4fv(skyBoxShader, "modelview" , glm::value_ptr(mvStack.top()));
	rt3d::drawIndexedMesh(skyBox,skyBoxIndexCount,GL_TRIANGLES); 

	// top
	glBindTexture(GL_TEXTURE_2D, skyBoxTexture[3]);
	mvStack.top() = glm::rotate(mvStack.top(), 90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
	mvStack.top() = glm::rotate(mvStack.top(), 90.0f, glm::vec3(0.0f, 0.0f, -1.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(2.0f, 2.0f, 2.0f));
	rt3d::setUniformMatrix4fv(skyBoxShader, "modelview" , glm::value_ptr(mvStack.top()));
	rt3d::drawIndexedMesh(skyBox,skyBoxIndexCount,GL_TRIANGLES); 
}
