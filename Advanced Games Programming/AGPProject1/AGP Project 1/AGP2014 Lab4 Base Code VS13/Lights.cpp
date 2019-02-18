#include "Lights.h"
#include "iostream"
#include "fstream"
#include <string>

Lights::Lights(void)
{
	hWindow = setupRC(glContext); // Create window and render context 

	// Required on Windows *only* init GLEW to access OpenGL beyond 1.1
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) { // glewInit failed, something is seriously wrong
		std::cout << "glewInit failed, aborting." << endl;
		exit(1);
	}
	cout << glGetString(GL_VERSION) << endl;

	r = 0.0f;

	meshIndexCount = 0;

	eye = glm::vec3(0.0f, 1.0f, 0.0f);
	at = glm::vec3(0.0f, 1.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	rt3d::lightStruct templight0 = {
			{ 0.3f, 0.0f, 0.0f, 1.0f }, // ambient
			{ 0.5f, 0.0f, 0.0f, 1.0f }, // diffuse
			{ 0.1f, 0.0f, 0.0f, 1.0f }, // specular
			{ -5.0f, 5.0f, -10.0f, 1.0f } // position
	};
	rt3d::lightStruct templight1 = {
			{ 0.0f, 0.3f, 0.0f, 1.0f }, // ambient
			{ 0.0f, 0.5f, 0.0f, 1.0f }, // diffuse
			{ 0.0f, 0.1f, 0.0f, 1.0f }, // specular
			{ 5.0f, 5.0f, -10.0f, 1.0f } // position
	};
	rt3d::lightStruct templight2 = {
			{ 0.0f, 0.0f, 0.3f, 1.0f }, // ambient
			{ 0.0f, 0.0f, 0.5f, 1.0f }, // diffuse
			{ 0.0f, 0.0f, 0.1f, 1.0f }, // specular
			{ 0.0f, 10.0f, -10.0f, 1.0f } // position
	};
	rt3d::lightStruct templight3 = {
			{ 0.0f, 0.3f, 0.0f, 1.0f }, // ambient
			{ 0.0f, 0.3f, 0.0f, 1.0f }, // diffuse
			{ 0.0f, 0.5f, 0.0f, 1.0f }, // specular
			{ -5.0f, 10.0f, -10.0f, 1.0f } // position
	};

	light0 = templight0;
	light1 = templight1;
	light2 = templight2;

	light3 = templight0;
	light4 = templight1;
	light5 = templight2;

	light3 = templight0;
	light4 = templight1;
	light5 = templight2;

	light6 = templight0;
	light7 = templight1;
	light8 = templight2;

	// Add lights to array list
	lightList = new rt3d::lightStruct[NUMLIGHTS];

	lightList[0] = light0;
	lightList[1] = light1;
	lightList[2] = light2;

	lightList[3] = light3;
	lightList[4] = light4;
	lightList[5] = light5;

	lightList[6] = light6;
	lightList[7] = light7;
	lightList[8] = light8;

	lightPos0 = glm::vec4(-5.0f, 5.0f, -10.0f, 1.0f);
	lightPos1 = glm::vec4(5.0f, 5.0f, -10.0f, 1.0f);
	lightPos2 = glm::vec4(0.0f, 10.0f, -10.0f, 1.0f);

	lightPos3 = glm::vec4(-5.0f, 10.0f, -10.0f, 1.0f);
	lightPos4 = glm::vec4(5.0f, 10.0f, -10.0f, 1.0f);
	lightPos5 = glm::vec4(0.0f, 5.0f, -10.0f, 1.0f);

	lightPos6 = glm::vec4(-5.0f, 15.0f, -10.0f, 1.0f);
	lightPos7 = glm::vec4(5.0f, 15.0f, -10.0f, 1.0f);
	lightPos8 = glm::vec4(0.0f, 15.0f, -10.0f, 1.0f);

	// Add light positions to array list
	lightPosList[0] = lightPos0;
	lightPosList[1] = lightPos1;
	lightPosList[2] = lightPos2;

	lightPosList[3] = lightPos3;
	lightPosList[4] = lightPos4;
	lightPosList[5] = lightPos5;

	lightPosList[6] = lightPos6;
	lightPosList[7] = lightPos7;
	lightPosList[8] = lightPos8;

	attenuation.x = 1.0f;
	attenuation.y = 0.01f;
	attenuation.z = 0.001f;

	rt3d::materialStruct tempmaterial0 = {
			{ 0.2f, 0.4f, 0.2f, 1.0f }, // ambient
			{ 0.5f, 1.0f, 0.5f, 1.0f }, // diffuse
			{ 0.0f, 0.1f, 0.0f, 1.0f }, // specular
			2.0f  // shininess
	};
	rt3d::materialStruct tempmaterial1 = {
			{ 0.4f, 0.4f, 1.0f, 1.0f }, // ambient
			{ 0.8f, 0.8f, 1.0f, 1.0f }, // diffuse
			{ 0.2f, 0.2f, 0.2f, 1.0f }, // specular
			1.0f  // shininess
	};

	material0 = tempmaterial0;
	material1 = tempmaterial1;

	modelview = glm::mat4(1.0);
}

SDL_Window * Lights::setupRC(SDL_GLContext &context)
{
	SDL_Window * window;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialize video
		rt3d::exitFatalError("Unable to initialize SDL");

	// Request an OpenGL 3.0 context.

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // double buffering on
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); // 8 bit alpha buffering
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4); // Turn on x4 multisampling anti-aliasing (MSAA)

	// Create 800x600 window
	window = SDL_CreateWindow("SDL/GLM/OpenGL Demo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	if (!window) // Check window was created OK
		rt3d::exitFatalError("Unable to create window");

	context = SDL_GL_CreateContext(window); // Create opengl context and attach to window
	SDL_GL_SetSwapInterval(1); // set swap buffers to sync with monitor's vertical refresh rate
	return window;
}

Lights::~Lights(void)
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(hWindow);
	SDL_Quit();
}

void Lights::init()
{
	shaderProgram = rt3d::initShaders("multiplelight.vert", "multiplelight.frag");

	vector<GLfloat> verts;
	vector<GLfloat> norms;
	vector<GLfloat> tex_coords;
	vector<GLuint> indices;
	rt3d::loadObj("cube.obj", verts, norms, tex_coords, indices);
	meshIndexCount = indices.size();
	meshObject = rt3d::createMesh(verts.size() / 3, verts.data(), nullptr, norms.data(), tex_coords.data(), meshIndexCount, indices.data());

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	// Used to print the controls to the console for testing
	string x;
	ifstream inFile;
	inFile.open("controls.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}
	while (getline(inFile, x)) {
		cout << x << endl;
	}
	inFile.close(); 
}

// Used for sending attenuation values to shader
void Lights::setUniform(GLuint shader, const char * uniform, glm::vec3 val)
{
	GLuint uniformIndex = glGetUniformLocation(shader, uniform);
	glUniform3f(uniformIndex, val.x, val.y, val.z);
}

// Used for sending light array to shader
void Lights::setUniform(GLuint shader, rt3d::lightStruct iLightList[])
{
	// Spawns in the first three lights whilst waiting for input for the rest
	for (int i = 0; i<currLights; i++) {
		std::stringstream ss;
		ss << (i);
		std::string s = ss.str();
		std::string temp = "lights[" + s + "]" + ".ambient";
		int uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform4fv(uniformIndex, 1, iLightList[i].ambient);
		temp = "lights[" + s + "]" + ".diffuse";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform4fv(uniformIndex, 1, iLightList[i].diffuse);
		temp = "lights[" + s + "]" + ".specular";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform4fv(uniformIndex, 1, iLightList[i].specular);
		temp = "lights[" + s + "]" + ".position";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform4fv(uniformIndex, 1, iLightList[i].position);
	}
}

void Lights::setUniformMatrix3fv(const GLuint program, const char* uniformName, const GLfloat *data)
{
	int uniformIndex = glGetUniformLocation(program, uniformName);
	glUniformMatrix3fv(uniformIndex, 1, GL_FALSE, data);
}

glm::vec3 Lights::moveForward(glm::vec3 pos, GLfloat angle, GLfloat d) {
	return glm::vec3(pos.x + d*std::sin(r*DEG_TO_RADIAN), pos.y, pos.z - d*std::cos(r*DEG_TO_RADIAN));
}

glm::vec3 Lights::moveRight(glm::vec3 pos, GLfloat angle, GLfloat d) {
	return glm::vec3(pos.x + d*std::cos(r*DEG_TO_RADIAN), pos.y, pos.z + d*std::sin(r*DEG_TO_RADIAN));
}

void Lights::run()
{
	bool running = true; // set running to true
	SDL_Event sdlEvent;  // variable to detect SDL events
	while (running)	{	// the event loop
		while (SDL_PollEvent(&sdlEvent)) {
			if (sdlEvent.type == SDL_QUIT)
				running = false;
		}
		update();
		draw(hWindow); // call the draw function
	}
}

void Lights::update()
{
	const Uint8 *keys = SDL_GetKeyboardState(NULL);

	// Moving the camera
	if (keys[SDL_SCANCODE_W]) eye = moveForward(eye, r, 0.2f);
	if (keys[SDL_SCANCODE_S]) eye = moveForward(eye, r, -0.2f);
	if (keys[SDL_SCANCODE_A]) eye = moveRight(eye, r, -0.2f);
	if (keys[SDL_SCANCODE_D]) eye = moveRight(eye, r, 0.2f);
	if (keys[SDL_SCANCODE_E]) eye.y += 0.2;
	if (keys[SDL_SCANCODE_Q]) eye.y -= 0.2;
	if (keys[SDL_SCANCODE_COMMA]) r -= 1.0f;
	if (keys[SDL_SCANCODE_PERIOD]) r += 1.0f;

	// Wirefram on/off
	if (keys[SDL_SCANCODE_1]) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_CULL_FACE);
	}

	if (keys[SDL_SCANCODE_2]) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		glEnable(GL_CULL_FACE);
	}

	// Move Light 0
	if (keys[SDL_SCANCODE_L]) {
		lightPosList[0].x += 0.1;
	}
	if (keys[SDL_SCANCODE_J]) {
		lightPosList[0].x -= 0.1;
	}

	if (keys[SDL_SCANCODE_K]) {
		lightPosList[0].z += 0.1;
	}
	if (keys[SDL_SCANCODE_I]) {
		lightPosList[0].z -= 0.1;
	}

	// Move Light 1
	if (keys[SDL_SCANCODE_RIGHT]) {
		lightPosList[1].x += 0.1;
	}
	if (keys[SDL_SCANCODE_LEFT]) {
		lightPosList[1].x -= 0.1;
	}

	if (keys[SDL_SCANCODE_DOWN]) {
		lightPosList[1].z += 0.1;
	}
	if (keys[SDL_SCANCODE_UP]) {
		lightPosList[1].z -= 0.1;
	}

	// Move Light 1 and Light 0 in the y axis
	if (keys[SDL_SCANCODE_N]) {
		lightPosList[0].y += 0.1;
		lightPosList[1].y += 0.1;
	}
	if (keys[SDL_SCANCODE_M]) {
		lightPosList[0].y -= 0.1;
		lightPosList[1].y -= 0.1;
	}

	// Attenuatrion controls
	if (keys[SDL_SCANCODE_8]) {
		attenuation.x += 0.01f;
	}
	if (keys[SDL_SCANCODE_9]) {
		attenuation.y -= 0.01f;
	}
	if (keys[SDL_SCANCODE_0]) {
		attenuation.z -= 0.01f;
	}

	if (keys[SDL_SCANCODE_7]) {
		attenuation.x = 1.0f;
		attenuation.y = 0.01f;
		attenuation.z = 0.001f;
	}

	// Create 3 extra lights
	if (keys[SDL_SCANCODE_3]) {
		if (set1limiter < 3) {
			if (currLights < 9) {
				currLights++;
				set1limiter++;
				std::cout << "Extra light from set 1 added" << endl;
			}
		}
	}

	// Create 3 more extra lights
	if (keys[SDL_SCANCODE_4]) {
		if (set2limiter < 3) {
			if (currLights < 9) {
				currLights++;
				set2limiter++;
				std::cout << "Extra light from set 2 added" << endl;
			}
		}
	}

	// Move extra spawned lights togeather
	if (keys[SDL_SCANCODE_H]) {
		if (currLights > 3) {
			lightPosList[3].x += 0.1;
			lightPosList[4].x += 0.1;
			lightPosList[5].x += 0.1;
		}
		if (currLights == 9) {
			lightPosList[6].x += 0.1;
			lightPosList[7].x += 0.1;
			lightPosList[8].x += 0.1;
		}
	}
	if (keys[SDL_SCANCODE_F]) {
		if (currLights > 3) {
			lightPosList[3].x -= 0.1;
			lightPosList[4].x -= 0.1;
			lightPosList[5].x -= 0.1;
		}
		if (currLights == 9) {
			lightPosList[6].x -= 0.1;
			lightPosList[7].x -= 0.1;
			lightPosList[8].x -= 0.1;
		}
	}

	if (keys[SDL_SCANCODE_G]) {
		if (currLights > 3) {
			lightPosList[3].z += 0.1;
			lightPosList[4].z += 0.1;
			lightPosList[5].z += 0.1;
		}
		if (currLights == 9) {
			lightPosList[6].z += 0.1;
			lightPosList[7].z += 0.1;
			lightPosList[8].z += 0.1;
		}
	}
	if (keys[SDL_SCANCODE_T]) {
		if (currLights > 3) {
			lightPosList[3].z -= 0.1;
			lightPosList[4].z -= 0.1;
			lightPosList[5].z -= 0.1;
		}
		if (currLights == 9) {
			lightPosList[6].z -= 0.1;
			lightPosList[7].z -= 0.1;
			lightPosList[8].z -= 0.1;
		}
	}

	// Make the first three lights into directional lights
	if (keys[SDL_SCANCODE_5]) {

		if (lightPos0 == glm::vec4(-5.0f, 5.0f, -10.0f, 1.0f)) {
			// Reset first three lights to be Directional
			lightPos0 = glm::vec4(-5.0f, 5.0f, -10.0f, 0.0f);
			lightPos1 = glm::vec4(5.0f, 5.0f, -10.0f, 0.0f);
			lightPos2 = glm::vec4(0.0f, 10.0f, -10.0f, 0.0f);

			// Reregister them in the array
			lightPosList[0] = lightPos0;
			lightPosList[1] = lightPos1;
			lightPosList[2] = lightPos2;
			std::cout << "First three lights now directional." << endl;
		}
	}

	// Make the first three lights into point lights
	if (keys[SDL_SCANCODE_6]) {

		if (lightPos0 == glm::vec4(-5.0f, 5.0f, -10.0f, 0.0f)) {
			// Reset first three lights to be point
			lightPos0 = glm::vec4(-5.0f, 5.0f, -10.0f, 1.0f);
			lightPos1 = glm::vec4(5.0f, 5.0f, -10.0f, 1.0f);
			lightPos2 = glm::vec4(0.0f, 10.0f, -10.0f, 1.0f);

			// Reregister them in the array
			lightPosList[0] = lightPos0;
			lightPosList[1] = lightPos1;
			lightPosList[2] = lightPos2;
			std::cout << "First three lights now Point." << endl;
		}
	}

	// Make just Light 1 directional
	if (keys[SDL_SCANCODE_KP_1]) {
		if (lightPos0 == glm::vec4(-5.0f, 5.0f, -10.0f, 1.0f)) {
			lightPos0 = glm::vec4(-5.0f, 5.0f, -10.0f, 0.0f);
			lightPosList[0] = lightPos0;
			std::cout << "Light 1 is now a directional light." << endl;
		}
	}

	// Make just Light 1 point
	if (keys[SDL_SCANCODE_KP_4]) {
		if (lightPos0 == glm::vec4(-5.0f, 5.0f, -10.0f, 0.0f)) {
			lightPos0 = glm::vec4(-5.0f, 5.0f, -10.0f, 1.0f);
			lightPosList[0] = lightPos0;
			std::cout << "Light 1 is now a point light." << endl;
		}
	}

	// Make just Light 2 directional
	if (keys[SDL_SCANCODE_KP_2]) {
		if (lightPos1 == glm::vec4(5.0f, 5.0f, -10.0f, 1.0f)) {
			lightPos1 = glm::vec4(5.0f, 5.0f, -10.0f, 0.0f);
			lightPosList[1] = lightPos1;
			std::cout << "Light 2 is now a directional light." << endl;
		}
	}

	// Make just Light 2 point
	if (keys[SDL_SCANCODE_KP_5]) {
		if (lightPos1 == glm::vec4(5.0f, 5.0f, -10.0f, 0.0f)) {
			lightPos1 = glm::vec4(5.0f, 5.0f, -10.0f, 1.0f);
			lightPosList[1] = lightPos1;
			std::cout << "Light 2 is now a point light." << endl;
		}
	}

	// Make just Light 3 directional
	if (keys[SDL_SCANCODE_KP_3]) {
		if (lightPos2 == glm::vec4(0.0f, 10.0f, -10.0f, 1.0f)) {
			lightPos2 = glm::vec4(0.0f, 10.0f, -10.0f, 0.0f);
			lightPosList[2] = lightPos2;
			std::cout << "Light 3 is now a directional light." << endl;
		}
	}

	// Make just Light 3 point
	if (keys[SDL_SCANCODE_KP_6]) {
		if (lightPos2 == glm::vec4(0.0f, 10.0f, -10.0f, 0.0f)) {
			lightPos2 = glm::vec4(0.0f, 10.0f, -10.0f, 1.0f);
			lightPosList[2] = lightPos2;
			std::cout << "Light 3 is now a point light." << endl;
		}
	}
}

void Lights::draw(SDL_Window * window)
{
	// clear the screen
	glEnable(GL_CULL_FACE);
	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set up projection matrix 
	glm::mat4 projection(1.0);
	projection = glm::perspective(60.0f, 800.0f / 600.0f, 1.0f, 150.0f);
	rt3d::setUniformMatrix4fv(shaderProgram, "projection", glm::value_ptr(projection));

	mvStack.push(modelview);

	// Set camera position
	at = moveForward(eye, r, 1.0f);
	mvStack.top() = glm::lookAt(eye, at, up);

	glDepthMask(GL_TRUE); // make sure depth test is on

	glUseProgram(shaderProgram);

	//Multiply light positions by modelview
	glm::vec4 tmp;
	for (int i = 0; i<NUMLIGHTS; i++)
	{
			tmp = mvStack.top()*lightPosList[i];
			lightList[i].position[0] = tmp.x;
			lightList[i].position[1] = tmp.y;
			lightList[i].position[2] = tmp.z;
	}

	// Set uniforms for shader (attenuation values, array of lights)
	setUniform(shaderProgram, "attenuation", attenuation);
	setUniform(shaderProgram, lightList);
	rt3d::setUniformMatrix4fv(shaderProgram, "projection", glm::value_ptr(projection));


	// draw cubes at light positions, accepts input
	glCullFace(GL_FALSE);
	for (int i = 0; i<currLights; i++) {
		mvStack.push(mvStack.top());
		mvStack.top() = glm::translate(mvStack.top(), glm::vec3(lightPosList[i].x, lightPosList[i].y, lightPosList[i].z));
		mvStack.top() = glm::scale(mvStack.top(), glm::vec3(1.5f, 1.5f, 1.5f));
		rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
		normalmatrix = glm::transpose(glm::inverse(glm::mat3(modelview)));
		setUniformMatrix3fv(shaderProgram, "normalmatrix", glm::value_ptr(normalmatrix));
		rt3d::setMaterial(shaderProgram, material1);
		rt3d::drawIndexedMesh(meshObject, meshIndexCount, GL_TRIANGLES);
		mvStack.pop();
	}

	// draw scene back
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(-10.0f, 20.0f, -30.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(20.0f, 20.0f, 0.1f));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	normalmatrix = glm::transpose(glm::inverse(glm::mat3(modelview)));
	setUniformMatrix3fv(shaderProgram, "normalmatrix", glm::value_ptr(normalmatrix));
	rt3d::setMaterial(shaderProgram, material1);
	rt3d::drawIndexedMesh(meshObject, meshIndexCount, GL_TRIANGLES);
	mvStack.pop();

	// scene front
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(-10.0f, 20.0f, 10.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(20.0f, 20.0f, 0.1f));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	normalmatrix = glm::transpose(glm::inverse(glm::mat3(modelview)));
	setUniformMatrix3fv(shaderProgram, "normalmatrix", glm::value_ptr(normalmatrix));
	rt3d::drawIndexedMesh(meshObject, meshIndexCount, GL_TRIANGLES);
	mvStack.pop();

	// sceneleft
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(-30.0f, 20.0f, -10.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(0.1f, 20.0f, 20.0f));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	normalmatrix = glm::transpose(glm::inverse(glm::mat3(modelview)));
	setUniformMatrix3fv(shaderProgram, "normalmatrix", glm::value_ptr(normalmatrix));
	rt3d::drawIndexedMesh(meshObject, meshIndexCount, GL_TRIANGLES);
	mvStack.pop();

	// scene right
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(10.0f, 20.0f, -10.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(0.1f, 20.0f, 20.0f));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	normalmatrix = glm::transpose(glm::inverse(glm::mat3(modelview)));
	setUniformMatrix3fv(shaderProgram, "normalmatrix", glm::value_ptr(normalmatrix));
	rt3d::drawIndexedMesh(meshObject, meshIndexCount, GL_TRIANGLES);
	mvStack.pop();

	// scene top
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(-10.0f, 40.0f, -10.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(20.0f, 0.1f, 20.0f));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	normalmatrix = glm::transpose(glm::inverse(glm::mat3(modelview)));
	setUniformMatrix3fv(shaderProgram, "normalmatrix", glm::value_ptr(normalmatrix));
	rt3d::drawIndexedMesh(meshObject, meshIndexCount, GL_TRIANGLES);
	mvStack.pop();

	// scene bottom
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(-10.0f, -0.1f, -10.0f));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(20.0f, 0.1f, 20.0f));
	rt3d::setUniformMatrix4fv(shaderProgram, "modelview", glm::value_ptr(mvStack.top()));
	normalmatrix = glm::transpose(glm::inverse(glm::mat3(modelview)));
	setUniformMatrix3fv(shaderProgram, "normalmatrix", glm::value_ptr(normalmatrix));
	rt3d::drawIndexedMesh(meshObject, meshIndexCount, GL_TRIANGLES);
	mvStack.pop();

	mvStack.pop(); // last pop
	glDepthMask(GL_TRUE);

	SDL_GL_SwapWindow(window); // swap buffers
}

