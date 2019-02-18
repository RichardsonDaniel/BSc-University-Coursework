#include "Skybox.h"


Skybox::Skybox()
{
}

void Skybox::Initialize()
{
	const char *files[6] = {
		"model/world/skybox/texture1.bmp", 
		"model/world/skybox/texture0.bmp", 
		"model/world/skybox/texture2.bmp", 
		"model/world/skybox/texture3.bmp", 
		"model/world/skybox/texture4.bmp", 
		"model/world/skybox/texture5.bmp"
	};
	Load::CubeMap(files, &texture[0]);
	frame.Initialize();
}

void Skybox::Render()
{
	Shader::Use(Shader::Skybox());
	Shader::SetUniform("ProjectionMatrix", Shader::ProjectionMatrix());
	Shader::SetUniform("ModelViewMatrix", Shader::ModelViewMatrix());
	glDepthMask(GL_FALSE);
	{
		Shader::Push(glm::mat4(glm::mat3(Shader::Top())));
		{
			glCullFace(GL_FRONT);
			//glBindTexture(GL_TEXTURE_CUBE_MAP, texture[0]);
			Shader::Bind(0, "cubeMap", texture[0]);
			frame.Render();
			//glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
			glCullFace(GL_BACK);
		}
		Shader::Pop();
	}
	glDepthMask(GL_TRUE);
}

Skybox::~Skybox()
{
}
