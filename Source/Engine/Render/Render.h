#pragma once
#include "Shader.h"
#include "Texture.h"

#include "Camera.h"

#include "../../Pathes.h"

//-----------------------------

class Render
{
public:
	GLuint vertex_buffer;
	GLuint uvbuffer;
	GLuint MatrixID;

	Render();
	void Add();
	void Draw();
	
};



