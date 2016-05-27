#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;

// Include GLEW. Always include it before gl.h and glfw.h
#include <GL/glew.h>
#include "../../Pathes.h"
#include "../Debug.h"

//Include GLM
#include <GLM/glm.hpp>
#include <glm/gtx/transform.hpp> // after <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

#include "Shader.h"
#include "Texture.h"

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



