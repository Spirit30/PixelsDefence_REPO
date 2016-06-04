#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
// Include GLEW. Always include it before gl.h and glfw.h
#include <GL/glew.h>

class Shader
{
public:
	static GLuint Load(const string vertex_file_path, const string fragment_file_path);
};

