#include "Camera.h"

Camera::Camera()
{
	eye = glm::vec3(0.0f, 2.0f, 0.0f);
	at = glm::vec3(0.0f, 1.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
}


Camera::~Camera(void)
{
	focus->~Character();
}

void Camera::update() 
{
	Uint8 *keys = SDL_GetKeyboardState(NULL);

	tempY = eye.y;

	if ( keys[SDL_SCANCODE_R] && tempY < 3.0f) tempY += 0.1; // Move camera height up by amount to maximum value
	if ( keys[SDL_SCANCODE_F] && tempY > 0.6f) tempY -= 0.1; // Move camera height down by amount to minimum value

	// Keeping camera set on the currently focused character...
	eye = moveForward(focus->getPos(), focus->getRotate(), -4.0f);
	at = moveForward(focus->getPos(), focus->getRotate(), 1.0f);

	eye.y = tempY;
}


