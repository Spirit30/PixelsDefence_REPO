#pragma once
#include "Shader.h"
#include "Texture.h"

#include "../../Pathes.h"
#include "../Debug.h"

//Include GLM
#include <GLM/glm.hpp>
#include <glm/gtx/transform.hpp> // after <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

//-----------------------------

class Render
{
public:
	static int WIDTH;
	static int HEIGHT;
	GLuint vertex_buffer;
	GLuint uvbuffer;
	//static std::vector<GLuint> vertex_buffers;

	Render();
	void Add();
	void Draw();
	
};



