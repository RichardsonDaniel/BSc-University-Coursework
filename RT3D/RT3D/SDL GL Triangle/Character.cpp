#include "Character.h"

Character::Character(char *fnameTexture, char *fnameMesh, GLfloat idx, GLfloat idy, GLfloat idz, GLfloat iScaleX, GLfloat iScaleY, GLfloat iScaleZ, GLuint newShaderProgram)
{
	// Load texture and model data for character
	texture = rt3d::loadBitmap(fnameTexture);
	meshObject = tmpModel.ReadMD2Model(fnameMesh);
	vertCount = tmpModel.getVertDataSize();

	// Initialise position data
	pos.x = idx;
	pos.y = idy;
	pos.z = idz;

	// Initialise scale data
	scale.x = iScaleX;
	scale.y = iScaleY;
	scale.z = iScaleZ;

	// Default animation
	currentAnim = 0;

	// Initialise shader
	shaderProgram = newShaderProgram;

	// Starting angle
	rotateAngle = 0.0f;

	// Value to move by
	moveValue = 0.1f;
}


Character::~Character(void)
{
}

void Character::init() 
{
}

void Character::update() 
{
	Uint8 *keys = SDL_GetKeyboardState(NULL);

	// Move character forward, play run animation
	if ( keys[SDL_SCANCODE_W] ) {
		pos = moveForward(pos, rotateAngle, moveValue);
		currentAnim = 1;
		moveValue = 0.1;
	} else {
		currentAnim = 0; // Stand animation if not moving
	}

	// Move character backwards, play run animation
	if ( keys[SDL_SCANCODE_S] ) {
		pos = moveForward(pos, rotateAngle, -moveValue);
		currentAnim = 1;
		moveValue = 0.05;
	}

	if ( keys[SDL_SCANCODE_A] ) rotateAngle -= 1.0f; // Rotate character to the left
	if ( keys[SDL_SCANCODE_D] ) rotateAngle += 1.0f; // Rotate character to the right
	if ( keys[SDL_SCANCODE_SPACE] ) currentAnim = 6; // Play character's jump animation
	if ( keys[SDL_SCANCODE_LCTRL] ) currentAnim = 12; // Play character's crouch animation
	 
	// Play character's running crouch animation if moving actually moving 
	if ( keys[SDL_SCANCODE_LCTRL] && (keys[SDL_SCANCODE_W] || (keys[SDL_SCANCODE_S]) )) {
		currentAnim = 13;
		moveValue = 0.05;
	}

	// Set and keep collision rectangle on character
	r.setRect(pos.x, pos.z, scale.x, scale.z);
}

void Character::draw(std::stack<glm::mat4> &mvStack)
{
	rt3d::materialStruct material1 = {
		{0.4f, 0.4f, 1.0f, 1.0f}, // ambient
		{0.8f, 0.8f, 1.0f, 1.0f}, // diffuse
		{0.8f, 0.8f, 0.8f, 1.0f}, // specular
		1.0f  // shininess
	};

	// Animate the md2 model, and update the mesh with new vertex data
	tmpModel.Animate(currentAnim,0.1);
	rt3d::updateMesh(meshObject,RT3D_VERTEX,tmpModel.getAnimVerts(),tmpModel.getVertDataSize());

	// Drawing the model
	glCullFace(GL_FRONT);
	glBindTexture(GL_TEXTURE_2D, texture);
	rt3d::materialStruct tmpMaterial = material1;
	rt3d::setMaterial(shaderProgram, tmpMaterial);
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(pos.x, pos.y, pos.z));
	mvStack.top() = glm::rotate(mvStack.top(), 90.0f, glm::vec3(-1.0f, 0.0f, 0.0f));
	mvStack.top() = glm::rotate(mvStack.top(), 90.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	mvStack.top() = glm::rotate(mvStack.top(), rotateAngle, glm::vec3(0.0f, 0.0f, -1.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(scale.x, scale.y, scale.z));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	rt3d::drawMesh(meshObject, vertCount/3, GL_TRIANGLES);
	mvStack.pop();
	glCullFace(GL_BACK);
}

bool Character::collidingWith(rect &r) // Checking if collision has taken place
{ 
	if(this->r.intersects(r))
		return true;
	else
		return false;
}

rect Character::getRect() // gets collision box from function and returns it 
{ 
	return r;
}