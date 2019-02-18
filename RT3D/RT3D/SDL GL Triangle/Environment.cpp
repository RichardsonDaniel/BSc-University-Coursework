#include "Environment.h"


Environment::Environment(std::string typeName, char *fnameTexture, char *fobj, GLfloat idx, GLfloat idy, GLfloat idz, GLfloat iScaleX, GLfloat iScaleY, GLfloat iScaleZ, GLfloat iRotate, GLuint newShaderProgram)
{
	// Set name of object
	type = typeName;

	// Initialise position data
	pos.x = idx;
	pos.y = idy;
	pos.z = idz;

	// Initialise scale data
	scale.x = iScaleX;
	scale.y = iScaleY;
	scale.z = iScaleZ;


	rotateAngle = iRotate; // Set rotation

	shaderProgram = newShaderProgram; // Set shader program

	// Load object data including texture and create mesh
	std::vector<GLfloat> verts;
	std::vector<GLfloat> norms;
	std::vector<GLfloat> tex_coords;
	std::vector<GLuint> indices;
	rt3d::loadObj(fobj, verts, norms, tex_coords, indices);
	GLuint size = indices.size();
	meshIndexCount = size;
	texture = rt3d::loadBitmap(fnameTexture);
	meshObject = rt3d::createMesh(verts.size()/3, verts.data(), nullptr, norms.data(), tex_coords.data(), size, indices.data());

	r.setRect(pos.x, pos.y, scale.x, scale.y); // Set up collision rectangle
}


Environment::~Environment(void)
{
}

void Environment::draw(std::stack<glm::mat4> &mvStack) 
{
	glBindTexture(GL_TEXTURE_2D, texture);
	mvStack.push(mvStack.top());
	mvStack.top() = glm::rotate(mvStack.top(), rotateAngle, glm::vec3(1.0f, 0.0f, 0.0f));
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(pos.x, pos.y, pos.z));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(scale.x, scale.y, scale.z));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	rt3d::drawIndexedMesh(meshObject,meshIndexCount,GL_TRIANGLES);
	mvStack.pop();
}

rect Environment::getRect(){ // Return collision rectangle
	return r;
}