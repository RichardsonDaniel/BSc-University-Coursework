#include "Renderer.h"
#include "Load.h"	

Renderer::Renderer()
{
}

Renderer::~Renderer()
{
}

void Renderer::init()
{
	rt3d::lightStruct tempLight0 = {
		{0.3f, 0.3f, 0.3f, 1.0f}, // ambient
		{1.0f, 1.0f, 1.0f, 1.0f}, // diffuse
		{1.0f, 1.0f, 1.0f, 1.0f}, // specular
		{-10.0f, 10.0f, 10.0f, 1.0f}  // position
	};

	light0 = tempLight0;

	rt3d::materialStruct tempMaterial0 = {
		{0.8f, 0.8f, 0.8f, 1.0f}, // ambient
		{0.8f, 0.8f, 0.8f, 1.0f}, // diffuse
		{0.0f, 0.1f, 0.0f, 1.0f}, // specular
		2.0f  // shininess
	};

	material0 = tempMaterial0;

	rt3d::materialStruct tempMaterial1 = {
		{0.4f, 0.4f, 1.0f, 1.0f}, // ambient
		{0.8f, 0.8f, 1.0f, 1.0f}, // diffuse
		{0.8f, 0.8f, 0.8f, 1.0f}, // specular
		5.0f  // shininess
	};

	material1 = tempMaterial1;

	particleLight = new ParticlesList(0, glm::vec3(particleCubePosition), col1, col2, col3); // creates particle light pointer
	particleLight1 = new ParticlesList(0, glm::vec3(-3.25f, 3.25f, -39.0f), 0.0, 0.0, 3.0); // creates particle light pointer
	particleLight2 = new ParticlesList(0, glm::vec3(-37.50f, 3.25f, -4.75f), 0.0, 3.0, 0.0); // creates particle light pointer
	particleLight3 = new ParticlesList(0, glm::vec3(31.0f, 3.25f, -4.75f), 3.0, 0.0, 0.0); // creates particle light pointer

	biasMatrix = glm::mat4 (
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
	);

	meshIndexCount = 0;
	rotate = 0.0f;

	//camera set up
	eye = glm::vec3(-4.0f, 16.0f, 50.0f);
	at = glm::vec3(0.0f, 1.0f, -1.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	
	//depth buffer
	setDepthFBO();


	shaderManager.init();
	glUseProgram(shaderManager.getShader("shader"));
	rt3d::setLight(shaderManager.getShader("shader"), light0);
	rt3d::setMaterial(shaderManager.getShader("shader"), material0);

	glUseProgram(shaderManager.getShader("shadow"));
	setUniform(shaderManager.getShader("shadow"), "depthTexture", 1); //depth
	setUniform(shaderManager.getShader("shadow"), "textureUnit0", 0); //texture

	rt3d::setLight(shaderManager.getShader("shadow"), light0);
	rt3d::setMaterial(shaderManager.getShader("shadow"),material0);

	// assortment of props
	rt3d::loadObj("cube.obj", cubeVerts, cubeNorms, cubeTex_coords, cubeIndices);
	GLuint cubeSize = cubeIndices.size();
	meshIndexCount = cubeSize;
	meshObjects[0] = rt3d::createMesh(cubeVerts.size()/3, cubeVerts.data(), nullptr, cubeNorms.data(), cubeTex_coords.data(), cubeSize, cubeIndices.data());

	// lights
	rt3d::loadObj("cube.obj", lightVerts, lightNorms, lightTex_coords, lightIndices);
	GLuint lightSize = lightIndices.size();
	meshIndexCount = lightSize;
	meshObjects[1] = rt3d::createMesh(lightVerts.size()/3, lightVerts.data(), nullptr, lightNorms.data(), lightTex_coords.data(), lightSize, lightIndices.data());

	// load bitmaps from texture map
	textureMap["prop"] = Load::loadBitmap("prop.bmp");
	textureMap["colour"] = Load::loadBitmap("colour.bmp");
	textureMap["smoke"] = Load::loadBitmap("smoke.bmp");
	textureMap["box"] = Load::loadBitmap("box.bmp");
	textureMap["leaf"] = Load::loadBitmap("leaf.bmp");
	textureMap["smokecloud"] = Load::loadBitmap("smokecloud.bmp");
	textureMap["fabric"] = Load::loadBitmap("fabric.bmp");
	textureMap["goblin"] = Load::loadBitmap("hobgoblin2.bmp");
	textureMap["metal"] = Load::loadBitmap("studdedmetal.bmp");

	projection = glm::perspective(60.0f,800.0f/600.0f,1.0f,150.0f);

	// attenuates light props
	attenuation.x = 1.0f;
	attenuation.y = 0.01f;
	attenuation.z = 0.001f;

	// set up TrueType / SDL_ttf
	if (TTF_Init()== -1)
		cout << "TTF failed to initialise." << endl;

	textFont = TTF_OpenFont("MavenPro-Regular.ttf", 24);
	if (textFont == NULL)
		cout << "Failed to open font." << endl;

	// fog initialises
	fogMaxDist = 190.0f;
	fogMinDist = 1.0f;
	fogColour = glm::vec3(0.5f, 0.5f, 0.5f);
}

void Renderer::update()
{

	const Uint8 *keys = SDL_GetKeyboardState(NULL);

	//// Particle Controls

	// reset particles1 to white
	if (keys[SDL_SCANCODE_T]) { col1 += 0.5; particleLight = new ParticlesList(500, particleCubePosition, 1.0, 1.5, 1.0); particleLight->particleTimer(9999999); }
	// change particles1 to red
	if (keys[SDL_SCANCODE_F]) { col1 += 0.5; particleLight = new ParticlesList(500, particleCubePosition, col1, 0.5, 0.5); particleLight->particleTimer(9999999); }
	// change particles1 to green
	if (keys[SDL_SCANCODE_G]) { col2 += 0.5; particleLight = new ParticlesList(500, particleCubePosition, 0.5, col2, 0.5); particleLight->particleTimer(9999999); }
	// chnage particles1 to blue
	if (keys[SDL_SCANCODE_H]) { col3 += 0.5; particleLight = new ParticlesList(500, particleCubePosition, 0.5, 0.5, col3); particleLight->particleTimer(9999999); }

	// particle emmiter on
	if (keys[SDL_SCANCODE_EQUALS])
	{
		// creates new pointer, creating particles
		particleLight = new ParticlesList(500, particleCubePosition, col1, col2, col3);
		particleLight->particleTimer(9999999);
	}

	// particle emmiter off
	if (keys[SDL_SCANCODE_MINUS])
	{
		// creates new pointer, disabling particles
		particleLight = new ParticlesList(0, particleCubePosition, col1, col2, col3);
		particleLight->particleTimer(0);
	}

	if (keys[SDL_SCANCODE_KP_MULTIPLY])
	{
		particleLight1 = new ParticlesList(500, glm::vec3(-3.25f, 3.25f, -39.0f), 0.0, 0.0, 1.0);
		particleLight1->particleTimer(9999999);

		particleLight2 = new ParticlesList(500, glm::vec3(-37.50f, 3.25f, -4.75f), 0.0, 1.0, 0.0);
		particleLight2->particleTimer(9999999);

		particleLight3 = new ParticlesList(500, glm::vec3(31.0f, 3.25f, -4.75f), 1.0, 0.0, 0.0);
		particleLight3->particleTimer(9999999);
	}

	if (keys[SDL_SCANCODE_KP_DIVIDE])
	{
		particleLight1 = new ParticlesList(0, glm::vec3(-3.25f, 3.25f, -39.0f), 0.0, 0.0, 1.0);
		particleLight1->particleTimer(0);

		particleLight2 = new ParticlesList(0, glm::vec3(-37.50f, 3.25f, -4.75f), 0.0, 1.0, 0.0);
		particleLight2->particleTimer(0);

		particleLight3 = new ParticlesList(0, glm::vec3(31.0f, 3.25f, -4.75f), 1.0, 0.0, 0.0);
		particleLight3->particleTimer(0);
	}

	//// Fog Controls:

	// change fog max distance
	if ( keys[SDL_SCANCODE_UP] ) fogMaxDist += 1.0f;
	if ( keys[SDL_SCANCODE_DOWN] ) fogMaxDist -= 1.0f;

	// set fog to white
	if (keys[SDL_SCANCODE_KP_0]) { fogColour = glm::vec3(1.0f, 1.0f, 1.0f); fog1 = 1.0; fog2 = 1.0; fog3 = 1.0; }
	// add red value to fog
	if (keys[SDL_SCANCODE_KP_1]) { fog1 += 0.1; fogColour = glm::vec3(fog1, fog2, fog3); }
	// add green value to fog
	if (keys[SDL_SCANCODE_KP_2]) { fog2 += 0.1; fogColour = glm::vec3(fog1, fog2, fog3); }
	// add blue value to fog
	if (keys[SDL_SCANCODE_KP_3]) { fog3 += 0.1; fogColour = glm::vec3(fog1, fog2, fog3); }
	
	// rainbow effect
	if (keys[SDL_SCANCODE_KP_PLUS])
	{
		if (fog1 < 3.0){ fog1 += 0.1; fogColour = glm::vec3(fog1, 0.5, 0.5); }

		if (fog2 < 3.0){
			if (fog1 > 3.0){ fog2 += 0.1; fogColour = glm::vec3(0.5, fog2, 0.5); }
		}

		if (fog3 < 3.0){
			if (fog1 > 3.0){
				if (fog2 > 3.0){ fog3 += 0.1; fogColour = glm::vec3(0.5, 0.5, fog3);
					if (fog3 > 3.0){ fog1 = 1.0; fog2 = 1.0; fog3 = 1.0;}
				}
			}
		}
	}
}

void Renderer::renderDepth(glm::vec3 coords, glm::vec3 size, glm::vec4 iLightPos, glm::vec3 iLightConeDirection)
{
	shaderManager.useShader("depth");
	rt3d::setUniformMatrix4fv(shaderManager.getShader("depth"), "projection", glm::value_ptr(projection));

	glm::mat4 modelview(1.0); // set base position for scene
	mvStack.push(modelview);

	at = Load::moveForward(eye, rotate, 1.0f);
	mvStack.top() = glm::lookAt(eye,at,up);

	// offsets shadows to improve visual effect
	glEnable(GL_POLYGON_OFFSET_FILL);
	glPolygonOffset(1.0f,2.0f);

	// pushing light view (light at is the conedirection)
	mvStack.push(glm::lookAt(glm::vec3(iLightPos.x, iLightPos.y, iLightPos.z), iLightConeDirection, up));
	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(coords.x, coords.y, coords.z));
	mvStack.top() = glm::scale(mvStack.top(),glm::vec3(size.x, size.y, size.z));
	glCullFace(GL_FRONT); // culling improves shadows
	rt3d::setUniformMatrix4fv(shaderManager.getShader("depth"), "modelview", glm::value_ptr(mvStack.top()));
	rt3d::drawIndexedMesh(meshObjects[0],meshIndexCount,GL_TRIANGLES);
	mvStack.pop();
	glDisable(GL_POLYGON_OFFSET_FILL);
	glCullFace(GL_BACK);
	mvStack.pop();
	mvStack.pop(); // initial matrix
}
	
void Renderer::renderProp(string textureID, glm::vec3 coords, glm::vec3 size,glm::vec3 iLightConeDirection[], Light iLightList[], glm::vec4 iLightPosList[])
{
	shaderManager.useShader("shadow");

	rt3d::setUniformMatrix4fv(shaderManager.getShader("shadow"), "projection", glm::value_ptr(projection));

	glm::mat4 modelview(1.0); // set base position for scene
	mvStack.push(modelview);

	at = Load::moveForward(eye,rotate,1.0f);
	mvStack.top() = glm::lookAt(eye,at,up);

	glDepthMask(GL_TRUE);
	
	
	// Multiply light positions by modelview
	glm::vec4 tmp3;
	glm::vec3 tmp2;
	glm::mat4 lightview;
	glm::mat3 rotOnlyViewMatrix;
	for(int i=0; i<NUMLIGHTS; i++)  
	{
		tmp3 = mvStack.top() * iLightPosList[i]; // world view
		iLightList[i].setPositionX(tmp3.x);  // eye view
		iLightList[i].setPositionY(tmp3.y);  // eye view
		iLightList[i].setPositionZ(tmp3.z);  // eye view

		rotOnlyViewMatrix = glm::mat3(mvStack.top());
		tmp2 = rotOnlyViewMatrix * glm::vec3(iLightConeDirection[i].x,iLightConeDirection[i].y,iLightConeDirection[i].z); // passing cone direction or look at into eye coordinates
		iLightList[i].setConeDirectionX(tmp2.x);
		iLightList[i].setConeDirectionY(tmp2.y);
		iLightList[i].setConeDirectionZ(tmp2.z);
		
	}

	lightview = glm::lookAt(glm::vec3(iLightPosList[0].x, iLightPosList[0].y, iLightPosList[0].z), iLightConeDirection[0], up); //lightview for shadows



	// set uniforms
	setUniform(shaderManager.getShader("shadow"), "attenuation", attenuation);
	setUniform(shaderManager.getShader("shadow"), iLightList);
	setUniform(shaderManager.getShader("shadow"), fogMaxDist, fogMinDist, fogColour);
	
	rt3d::setUniformMatrix4fv(shaderManager.getShader("shadow"), "view", glm::value_ptr(glm::lookAt(eye,at,up)));
	
	//identity matrix so we can access model matrix
	mvStack.push(glm::mat4(1.0f));
	glActiveTexture(GL_TEXTURE1); // depth texture unit
	glBindTexture(GL_TEXTURE_2D,textureMap["depth"]);
	glActiveTexture(GL_TEXTURE0); // texture unit for prop
	glBindTexture(GL_TEXTURE_2D, textureMap[textureID]);
	mvStack.push(mvStack.top());
	rt3d::setMaterial(shaderManager.getShader("shadow"), material0);
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(coords.x, coords.y, coords.z));
	mvStack.top() = glm::scale(mvStack.top(),glm::vec3(size.x,size.y,size.z));
	shadow = biasMatrix*projection*lightview*mvStack.top(); // creates shadow matrix
	rt3d::setUniformMatrix4fv(shaderManager.getShader("shadow"),"shadow",glm::value_ptr(shadow));
	rt3d::setUniformMatrix4fv(shaderManager.getShader("shadow"), "model", glm::value_ptr(mvStack.top()));	
	setUniformMatrix3fv(shaderManager.getShader("shadow"), "normalmatrix", glm::value_ptr(glm::transpose(glm::inverse(glm::mat3(mvStack.top())))));
	rt3d::drawIndexedMesh(meshObjects[0],meshIndexCount,GL_TRIANGLES);
	mvStack.pop(); // pop identity matrix
	mvStack.pop(); // pop mvstack.top
	// remember to use at least one pop operation per push...
	mvStack.pop(); // initial matrix
}

void Renderer::renderLightProps(glm::vec4 lightPosition)
{
	shaderManager.useShader("multiplelights");
	rt3d::setUniformMatrix4fv(shaderManager.getShader("multiplelights"), "projection", glm::value_ptr(projection));
	
	
	glm::mat4 modelview(1.0); // set base position for scene
	mvStack.push(modelview);

	at = Load::moveForward(eye, rotate, 1.0f);
	mvStack.top() = glm::lookAt(eye, at, up);

	setUniform(shaderManager.getShader("multiplelights"), "attenuation", attenuation);
	setUniformMatrix3fv(shaderManager.getShader("multiplelights"), "normalmatrix", glm::value_ptr(glm::transpose(glm::inverse(glm::mat3(mvStack.top())))));


	mvStack.push(mvStack.top());
	mvStack.top() = glm::translate(mvStack.top(), glm::vec3(lightPosition.x, lightPosition.y, lightPosition.z));
	mvStack.top() = glm::scale(mvStack.top(), glm::vec3(1.0f, 1.0f, 1.0f));
	rt3d::setUniformMatrix4fv(shaderManager.getShader("multiplelights"), "modelview", glm::value_ptr(mvStack.top()));
	rt3d::setMaterial(shaderManager.getShader("multiplelights"), material0);
	rt3d::drawIndexedMesh(meshObjects[1], meshIndexCount, GL_TRIANGLES);
	mvStack.pop();

	// remember to use at least one pop operation per push...
	mvStack.pop(); // initial matrix
}

void Renderer::setDepthFBO()
{
		//creates a border for the light if outside this border then in shadow
		GLfloat border[] = {1.0f,1.0f,1.0f,1.0f};
		// Create FBO to render depth into
		glGenTextures(1, &textureMap["depth"]);
		glBindTexture(GL_TEXTURE_2D, textureMap["depth"]);
		// Allocate storage for the texture data
		glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT32, 800, 600, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
		// Set the default filtering modes
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		// Set up depth comparison mode
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE,GL_COMPARE_REF_TO_TEXTURE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
		// Set up wrapping modes
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameterfv(GL_TEXTURE_2D,GL_TEXTURE_BORDER_COLOR, border);
		glBindTexture(GL_TEXTURE_2D, 0);
		// Create FBO to render depth into
		glGenFramebuffers(1, &depthFBO);
		glBindFramebuffer(GL_FRAMEBUFFER, depthFBO);
		// Attach the depth texture to it
		glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT,textureMap["depth"], 0);
		// Disable color rendering as there are no color attachments
		glDrawBuffer(GL_NONE);
}



// sets integer uniforms
void Renderer::setUniform(GLuint shader, const char * uniform, int val)
{
	GLuint temp = glGetUniformLocation(shader, uniform);
	glUniform1i(temp, val);
}

// Used for sending attenuation values to shader
void Renderer::setUniform(GLuint shader, const char * uniform, glm::vec3 val)
{
	GLuint uniformIndex = glGetUniformLocation(shader, uniform);
	glUniform3f(uniformIndex, val.x, val.y, val.z);
}

// Used for sending light array to shader
void Renderer::setUniform(GLuint shader, Light iLightList[]) 
{
	for(int i = 0; i<NUMLIGHTS; i++) {
		std::stringstream ss;
		ss << (i);
		std::string s = ss.str();
		std::string temp = "lights[" + s + "]"+".ambient";
		int uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform4fv(uniformIndex, 1, iLightList[i].getAmbient());
		temp = "lights[" + s + "]"+".diffuse";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform4fv(uniformIndex, 1, iLightList[i].getDiffuse());
		temp = "lights[" + s + "]"+".specular";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform4fv(uniformIndex, 1, iLightList[i].getSpecular());
		temp = "lights[" + s + "]"+".position";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform4fv(uniformIndex, 1, iLightList[i].getPosition());
		temp = "lights[" + s + "]" + ".coneDirection";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform3fv(uniformIndex, 1 , iLightList[i].getConeDirection());
		temp = "lights[" + s + "]" + ".coneFallOff";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform1f(uniformIndex,iLightList[i].getConeFallOff());
		temp = "lights[" + s + "]" + ".attenuation";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform3fv(uniformIndex, 1, iLightList[i].getAttenuation());
		temp = "lights[" + s + "]" + ".active";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform1i(uniformIndex, iLightList[i].getStatus());
		temp = "lights[" + s + "]" + ".type";
		uniformIndex = glGetUniformLocation(shader, temp.c_str());
		glUniform1i(uniformIndex, iLightList[i].getType());
	}
}



// used for passing fog values to shader
void Renderer::setUniform(GLuint shader, GLfloat val1, GLfloat val2, glm::vec3 val3)
{
	// val 1 = fog max distance, val 2 = fog min distance, color = fog colour...
	int uniformIndex = glGetUniformLocation(shader, "fog.maxDist");
	glUniform1f(uniformIndex, val1);
	uniformIndex = glGetUniformLocation(shader, "fog.inDist");
	glUniform1f(uniformIndex, val2);
	uniformIndex = glGetUniformLocation(shader, "fog.color");
	glUniform3f(uniformIndex, val3.x, val3.y, val3.z);
}

// passes in vec3 to shader
void Renderer::setUniformMatrix3fv(const GLuint program, const char * uniform, const GLfloat *data)
{
	int uniformIndex = glGetUniformLocation(program, uniform);
	glUniformMatrix3fv(uniformIndex, 1, GL_FALSE, data); 
}



void Renderer::renderLight(Light iLightList[], glm::vec4 iLightPosList[])
{
	shaderManager.useShader("multiplelights");
	rt3d::setUniformMatrix4fv(shaderManager.getShader("multiplelights"), "projection", glm::value_ptr(projection));

	glm::mat4 modelview(1.0); // set base position for scene
	mvStack.push(modelview);

	at = Load::moveForward(eye, rotate, 1.0f);
	mvStack.top() = glm::lookAt(eye, at, up);

	// Multiply light positions by modelview
	glm::vec4 tmp;
	for(int i=0; i<NUMLIGHTS; i++)  
	{
		tmp = mvStack.top()*iLightPosList[i];
		iLightList[i].setPositionX(tmp.x); 
		iLightList[i].setPositionY(tmp.y);
		iLightList[i].setPositionZ(tmp.z);
	}

	// Set uniforms for shader (attenuation values, array of lights)
	setUniform(shaderManager.getShader("multiplelights"), "attenuation", attenuation);
	setUniformMatrix3fv(shaderManager.getShader("multiplelights"), "normalmatrix", glm::value_ptr(glm::transpose(glm::inverse(glm::mat3(mvStack.top())))));
	setUniform(shaderManager.getShader("multiplelights"), iLightList);
	rt3d::setMaterial(shaderManager.getShader("multiplelights"), material1);

	mvStack.pop();
}

void Renderer::renderParticles(string ID, GLfloat size, glm::vec4 iLightPos)
{
	shaderManager.useShader("particles");
	glPointSize(size);
	rt3d::setUniformMatrix4fv(shaderManager.getShader("particles"), "projection", glm::value_ptr(projection));

	glm::mat4 modelview(1.0); // set base position for scene
	mvStack.push(modelview);

	at = Load::moveForward(eye, rotate, 1.0f);
	mvStack.top() = glm::lookAt(eye, at, up);

	glm::vec4 tmp = mvStack.top()*iLightPos;
	light0.position[0] = tmp.x;
	light0.position[1] = tmp.y;
	light0.position[2] = tmp.z;
	rt3d::setLightPos(shaderManager.getShader("particles"), glm::value_ptr(tmp));
	
	glBindTexture(GL_TEXTURE_2D, textureMap[ID]);
	mvStack.push(mvStack.top());
	rt3d::setUniformMatrix4fv(shaderManager.getShader("particles"), "modelview", glm::value_ptr(mvStack.top()));
	glDepthMask(0);

	particleLight->draw();
	particleLight->update(particleCubePosition);
	particleLight1->draw();
	particleLight1->update(glm::vec3(-3.25f, 3.25f, -39.0f));
	particleLight2->draw();
	particleLight2->update(glm::vec3(-37.50f, 3.25f, -4.75f));
	particleLight3->draw();
	particleLight3->update(glm::vec3(31.0f, 3.25f, -4.75f));

	glDepthMask(1);
	mvStack.pop();

	// remember to use at least one pop operation per push...
	mvStack.pop(); // initial matrix
}

GLuint Renderer::textToTexture(const char * str/*, TTF_Font *font, SDL_Color colour, GLuint &w,GLuint &h*/) {
	TTF_Font *font = textFont;
	SDL_Color colour = { 255, 255, 255 };
	SDL_Color bg = { 0, 0, 0 };

	SDL_Surface *stringImage;
	stringImage = TTF_RenderText_Blended(font,str,colour);

	if (stringImage == NULL)
		//exitFatalError("String surface not created.");
		std::cout << "String surface not created." << std::endl;

	GLuint w = stringImage->w;
	GLuint h = stringImage->h;
	GLuint colours = stringImage->format->BytesPerPixel;

	GLuint format, internalFormat;
	if (colours == 4) {   // alpha
		if (stringImage->format->Rmask == 0x000000ff)
			format = GL_RGBA;
	    else
		    format = GL_BGRA;
	} else {             // no alpha
		if (stringImage->format->Rmask == 0x000000ff)
			format = GL_RGB;
	    else
		    format = GL_BGR;
	}
	internalFormat = (colours == 4) ? GL_RGBA : GL_RGB;

	GLuint texture;

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, w, h, 0,
                    format, GL_UNSIGNED_BYTE, stringImage->pixels);

	// SDL surface was used to generate the texture but is no longer
	// required. Release it to free memory
	SDL_FreeSurface(stringImage);
	return texture;
}

glm::vec3 Renderer::getEye()
{
	return eye;
}

void Renderer::setEye(glm::vec3 newEye)
{
	eye = newEye;
}

GLfloat Renderer::getRotate()
{
	return rotate;
}

void Renderer::setRotate(GLfloat newRotate)
{
	rotate = newRotate;
}
	
glm::vec3 Renderer::getParticleCubePosition()
{
	return particleCubePosition;
}

void Renderer::setParticleCubePosition(glm::vec3 newparticleCubePosition)
{
	particleCubePosition = newparticleCubePosition;
}


GLuint Renderer::getFBO()
{
	return depthFBO;
}

ParticlesList * Renderer::getParticleLight()
{
	return particleLight;
}