#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Light
{
public:
	Light();
	Light(glm::vec4 iAmbient, glm::vec4 iDiffuse, glm::vec4 iSpecular, glm::vec4 iPosition, glm::vec3 iConeDirection, GLfloat iConeFallOff, glm::vec3 iAttenuation, int iActive, int iType);
	~Light(void);

	void setPositionX(GLfloat newPosition);
	void setPositionY(GLfloat newPosition);
	void setPositionZ(GLfloat newPosition);
	void setPositionW(GLfloat newPosition);

	void setConeDirectionX(GLfloat newDirection);
	void setConeDirectionY(GLfloat newDirection);
	void setConeDirectionZ(GLfloat newDirection);

	void setConeFallOff(GLfloat newConeFallOff);
	GLfloat * getAmbient();
	GLfloat * getDiffuse();
	GLfloat * getSpecular();
	GLfloat * getPosition();
	GLfloat * getConeDirection();
	GLfloat getPositionX();
	GLfloat getPositionY();
	GLfloat getPositionZ();
	GLfloat getPositionW();
	GLfloat getConeDirectionX();
	GLfloat getConeDirectionY();
	GLfloat getConeDirectionZ();
	GLfloat getConeFallOff();

	void setAttenuationLinear(GLfloat newAttenuation);
	void setAttenuationQuadratic(GLfloat newAttenuation);
	GLfloat * getAttenuation();
	GLfloat getAttenuationLinear();
	GLfloat getAttenuationQuadratic();

	int getStatus();
	void turnOff();
	void turnOn();

	void setType(int newType);
	int getType();

private:
	GLfloat ambient[4];
	GLfloat diffuse[4];
	GLfloat specular[4];
	GLfloat position[4];
	GLfloat coneDirection[3];
	GLfloat coneFallOff;
	GLfloat attenuation[3];
	int active;
	int type; // 0 for point, 1 for spot, 2 for directional

};

