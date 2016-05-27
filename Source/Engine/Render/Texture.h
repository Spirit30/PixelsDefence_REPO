#pragma once
#include <string>
using namespace std;
// Include GLEW. Always include it before gl.h and glfw.h
#include <GL/glew.h>

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

class Texture
{
public:
	static GLuint LoadDDS(const string imagepath);
};

