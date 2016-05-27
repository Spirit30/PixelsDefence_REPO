#pragma once
#include "Render.h"

class Shader
{
public:
	static GLuint Load(const string vertex_file_path, const string fragment_file_path);
};

