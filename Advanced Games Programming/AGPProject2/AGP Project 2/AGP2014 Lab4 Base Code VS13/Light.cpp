#include "Light.h"

Light::Light()
{
}

// Light constructor
Light::Light(glm::vec4 iAmbient, glm::vec4 iDiffuse, glm::vec4 iSpecular, glm::vec4 iPosition, glm::vec3 iConeDirection, GLfloat iConeFallOff, glm::vec3 iAttenuation, int iActive, int iType)
{
	ambient[0] = iAmbient.x; ambient[1] = iAmbient.y; ambient[2] = iAmbient.z; ambient[3] = iAmbient.w;
	diffuse[0] = iDiffuse.x; diffuse[1] = iDiffuse.y; diffuse[2] = iDiffuse.z; diffuse[3] = iDiffuse.w;
	specular[0] = iSpecular.x; specular[1] = iSpecular.y; specular[2] = iSpecular.z; specular[3] = iSpecular.w;
	position[0] = iPosition.x; position[1] = iPosition.y; position[2] = iPosition.z; position[3] = iPosition.w;
	coneDirection[0] = iConeDirection.x; coneDirection[1] = iConeDirection.y; coneDirection[2] = iConeDirection.z;
	coneFallOff = iConeFallOff;
	attenuation[0] = iAttenuation.x; attenuation[1] = iAttenuation.y; attenuation[2] = iAttenuation.z;
	active = iActive;
	type = iType;
}

Light::~Light(void)
{
}

// set positions
void Light::setPositionX(GLfloat newPosition)
{
	position[0] = newPosition;
}

void Light::setPositionY(GLfloat newPosition)
{
	position[1] = newPosition;
}

void Light::setPositionZ(GLfloat newPosition)
{
	position[2] = newPosition;
}

void Light::setPositionW(GLfloat newPosition)
{
	position[3] = newPosition;
}

// Set Cone Directions
void Light::setConeDirectionX(GLfloat newDirection)
{
	coneDirection[0] = newDirection;
}

void Light::setConeDirectionY(GLfloat newDirection)
{
	coneDirection[1] = newDirection;
}

void Light::setConeDirectionZ(GLfloat newDirection)
{
	coneDirection[2] = newDirection;
}

// return ambient

GLfloat * Light::getAmbient()
{
	return ambient;
}

// return diffuse
GLfloat * Light::getDiffuse()
{
	return diffuse;
}

// return specular
GLfloat * Light::getSpecular()
{
	return specular;
}

// return position
GLfloat * Light::getPosition()
{
	return position;
}

// return positionX
GLfloat Light::getPositionX()
{
	return position[0];
}

// return positionY
GLfloat Light::getPositionY()
{
	return position[1];
}

// return positionZ
GLfloat Light::getPositionZ()
{
	return position[2];
}

// return positionW
GLfloat Light::getPositionW()
{
	return position[3];
}

GLfloat * Light::getConeDirection()
{
	return coneDirection;
}

// return coneDirectionX
GLfloat Light::getConeDirectionX()
{
	return coneDirection[0];
}

// return coneDirectionY
GLfloat Light::getConeDirectionY()
{
	return coneDirection[1];
}

// return coneDirectionZ
GLfloat Light::getConeDirectionZ()
{
	return coneDirection[2];
}


void Light::setConeFallOff(GLfloat newConeFallOff)
{
	coneFallOff=newConeFallOff;
}


GLfloat Light::getConeFallOff()
{
	return coneFallOff;
}

GLfloat * Light::getAttenuation()
{
	return attenuation;
}

void Light::setAttenuationLinear(GLfloat newAttenuation)
{
	attenuation[1] = newAttenuation;
}

void Light::setAttenuationQuadratic(GLfloat newAttenuation)
{
	attenuation[2] = newAttenuation;
}

GLfloat Light::getAttenuationLinear()
{
	return attenuation[1];
}

GLfloat Light::getAttenuationQuadratic()
{
	return attenuation[2];
}

int Light::getStatus()
{
	return active;
}

void Light::setType(int newType)
{
	type = newType;
}

int Light::getType()
{
	return type;
}

void Light::turnOff()
{
	active = 0;
}

void Light::turnOn()
{
	active = 1;
}