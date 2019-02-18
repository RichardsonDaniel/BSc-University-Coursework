#pragma once
#define NUMLIGHTS 11
#include "rt3d.h"
#include "rt3dObjLoader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stack>
#include <SDL_ttf.h>
#include "Screen.h"
#include "Game.h"
#include "Shaders.h"
#include "Renderer.h"
#include "Particle.h"
#include "Light.h"

using namespace std;

class GameScreen: public Screen {
public:
	GameScreen();
	~GameScreen();
	void init();
	void draw(SDL_Window * window);
	bool update();
	glm::vec3 moveForward(glm::vec3 pos, GLfloat angle, GLfloat d);
	glm::vec3 moveRight(glm::vec3 pos, GLfloat angle, GLfloat d);

private:
	Renderer renderer;
	Shaders shaderManager;
	Light lightList[NUMLIGHTS];
	glm::vec4 lightPosList[NUMLIGHTS];
	glm::vec3 lightConeDirection[NUMLIGHTS];
	int selectLight;
	int tempParticlePosition;
	float particleSize = 0.1;
	bool choiceMade = false;
	bool moreLight = false;
	int choice = 1;
};


