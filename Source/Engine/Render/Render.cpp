#include "Render.h"

Render::Render() {

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	Add();
}

//-----------------------------
//-----------------------------
//-----------------------------

//OOP
//http://codereview.stackexchange.com/questions/116143/opengl-mesh-renderer-implementation
void Render::Add() {

	Debug::Log("Add!");

	//-----------------------------
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	static const GLfloat g_vertex_buffer_data[] = {
		-1.0f,-1.0f,-1.0f, // triangle 1 : begin
		-1.0f,-1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f, // triangle 1 : end
		1.0f, 1.0f,-1.0f, // triangle 2 : begin
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f, // triangle 2 : end
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		-1.0f,-1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		-1.0f,-1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f,-1.0f,
		1.0f,-1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f,-1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f,-1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f, 1.0f, 1.0f,
		-1.0f, 1.0f, 1.0f,
		1.0f,-1.0f, 1.0f
	};

	// This will identify our vertex buffer
	//GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertex_buffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	// Give our vertices to OpenGL.
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

	//-----------------------------

	// Two UV coordinates for each vertex. They were created with Blender.
	static const GLfloat g_uv_buffer_data[] = {
		0.000059f, 1.0f - 0.000004f,
		0.000103f, 1.0f - 0.336048f,
		0.335973f, 1.0f - 0.335903f,
		1.000023f, 1.0f - 0.000013f,
		0.667979f, 1.0f - 0.335851f,
		0.999958f, 1.0f - 0.336064f,
		0.667979f, 1.0f - 0.335851f,
		0.336024f, 1.0f - 0.671877f,
		0.667969f, 1.0f - 0.671889f,
		1.000023f, 1.0f - 0.000013f,
		0.668104f, 1.0f - 0.000013f,
		0.667979f, 1.0f - 0.335851f,
		0.000059f, 1.0f - 0.000004f,
		0.335973f, 1.0f - 0.335903f,
		0.336098f, 1.0f - 0.000071f,
		0.667979f, 1.0f - 0.335851f,
		0.335973f, 1.0f - 0.335903f,
		0.336024f, 1.0f - 0.671877f,
		1.000004f, 1.0f - 0.671847f,
		0.999958f, 1.0f - 0.336064f,
		0.667979f, 1.0f - 0.335851f,
		0.668104f, 1.0f - 0.000013f,
		0.335973f, 1.0f - 0.335903f,
		0.667979f, 1.0f - 0.335851f,
		0.335973f, 1.0f - 0.335903f,
		0.668104f, 1.0f - 0.000013f,
		0.336098f, 1.0f - 0.000071f,
		0.000103f, 1.0f - 0.336048f,
		0.000004f, 1.0f - 0.671870f,
		0.336024f, 1.0f - 0.671877f,
		0.000103f, 1.0f - 0.336048f,
		0.336024f, 1.0f - 0.671877f,
		0.335973f, 1.0f - 0.335903f,
		0.667969f, 1.0f - 0.671889f,
		1.000004f, 1.0f - 0.671847f,
		0.667979f, 1.0f - 0.335851f
	};

	//GLuint uvbuffer;
	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

	//-----------------------------

	//// One color for each vertex. They were generated randomly.
	//static const GLfloat g_color_buffer_data[] = {
	//	0.583f,  0.771f,  0.014f,
	//	0.609f,  0.115f,  0.436f,
	//	0.327f,  0.483f,  0.844f,
	//	0.822f,  0.569f,  0.201f,
	//	0.435f,  0.602f,  0.223f,
	//	0.310f,  0.747f,  0.185f,
	//	0.597f,  0.770f,  0.761f,
	//	0.559f,  0.436f,  0.730f,
	//	0.359f,  0.583f,  0.152f,
	//	0.483f,  0.596f,  0.789f,
	//	0.559f,  0.861f,  0.639f,
	//	0.195f,  0.548f,  0.859f,
	//	0.014f,  0.184f,  0.576f,
	//	0.771f,  0.328f,  0.970f,
	//	0.406f,  0.615f,  0.116f,
	//	0.676f,  0.977f,  0.133f,
	//	0.971f,  0.572f,  0.833f,
	//	0.140f,  0.616f,  0.489f,
	//	0.997f,  0.513f,  0.064f,
	//	0.945f,  0.719f,  0.592f,
	//	0.543f,  0.021f,  0.978f,
	//	0.279f,  0.317f,  0.505f,
	//	0.167f,  0.620f,  0.077f,
	//	0.347f,  0.857f,  0.137f,
	//	0.055f,  0.953f,  0.042f,
	//	0.714f,  0.505f,  0.345f,
	//	0.783f,  0.290f,  0.734f,
	//	0.722f,  0.645f,  0.174f,
	//	0.302f,  0.455f,  0.848f,
	//	0.225f,  0.587f,  0.040f,
	//	0.517f,  0.713f,  0.338f,
	//	0.053f,  0.959f,  0.120f,
	//	0.393f,  0.621f,  0.362f,
	//	0.673f,  0.211f,  0.457f,
	//	0.820f,  0.883f,  0.371f,
	//	0.982f,  0.099f,  0.879f
	//};

	/*GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);*/

	//// 2nd attribute buffer : colors
	//glEnableVertexAttribArray(1);
	//glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	//glVertexAttribPointer(
	//	1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
	//	3,                                // size
	//	GL_FLOAT,                         // type
	//	GL_FALSE,                         // normalized?
	//	0,                                // stride
	//	(void*)0                          // array buffer offset
	//	);

	//-----------------------------

	// Create and compile our GLSL program from the shaders
	GLuint programID = Shader::Load(
		shaders_path + "TransformVertexShader.glsl",
		shaders_path + "TextureFragmentShader.glsl");
	// Use our shader
	glUseProgram(programID);

	//-----------------------------

	// Load the texture using any two methods
	GLuint texture = Texture::LoadDDS(
		textures_path + "CubeMainTest.DDS");

	// Get a handle for our "myTextureSampler" uniform
	GLuint TextureID = glGetUniformLocation(programID, "myTextureSampler");

	// Bind our texture in Texture Unit 0
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	// Set our "myTextureSampler" sampler to user Texture Unit 0
	glUniform1i(TextureID, 0);

	//-----------------------------

	// Get a handle for our "MVP" uniform
	// Only during the initialisation
	MatrixID = glGetUniformLocation(programID, "MVP");
	
}

//-----------------------------
//-----------------------------
//-----------------------------

//glm::mat4 ViewMatrix;
//glm::mat4 ProjectionMatrix;
//
//// Initial position : on +Z
//glm::vec3 position = glm::vec3(0, 0, 5);
//// Initial horizontal angle : toward -Z
//float horizontalAngle = 3.14f;
//// Initial vertical angle : none
//float verticalAngle = 0.0f;
//// Initial Field of View
//float initialFoV = 45.0f;
//
//float speed = 3.0f; // 3 units / second
//float mouseSpeed = 0.005f;



//void computeMatricesFromInputs() {
//
//	// glfwGetTime is called only once, the first time this function is called
//	static double lastTime = glfwGetTime();
//
//	// Compute time difference between current and last frame
//	double currentTime = glfwGetTime();
//	float deltaTime = float(currentTime - lastTime);
//
//	// Compute new orientation
//	horizontalAngle += mouseSpeed * float(1024 / 2 - xpos);
//	verticalAngle += mouseSpeed * float(768 / 2 - ypos);
//
//	// Direction : Spherical coordinates to Cartesian coordinates conversion
//	glm::vec3 direction(
//		cos(verticalAngle) * sin(horizontalAngle),
//		sin(verticalAngle),
//		cos(verticalAngle) * cos(horizontalAngle)
//	);
//
//	// Right vector
//	glm::vec3 right = glm::vec3(
//		sin(horizontalAngle - 3.14f / 2.0f),
//		0,
//		cos(horizontalAngle - 3.14f / 2.0f)
//	);
//
//	// Up vector
//	glm::vec3 up = glm::cross(right, direction);
//
//	// Move forward
//	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
//		position += direction * deltaTime * speed;
//	}
//	// Move backward
//	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
//		position -= direction * deltaTime * speed;
//	}
//	// Strafe right
//	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
//		position += right * deltaTime * speed;
//	}
//	// Strafe left
//	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
//		position -= right * deltaTime * speed;
//	}
//
//	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.
//
//						   // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
//	ProjectionMatrix = glm::perspective(glm::radians(FoV), 4.0f / 3.0f, 0.1f, 100.0f);
//	// Camera matrix
//	ViewMatrix = glm::lookAt(
//		position,           // Camera is here
//		position + direction, // and looks here : at the same position, plus "direction"
//		up                  // Head is up (set to 0,-1,0 to look upside-down)
//	);
//
//	// For the next frame, the "last time" will be "now"
//	lastTime = currentTime;
//}

//-----------------------------
//-----------------------------
//-----------------------------

void Render::Draw() {

	// Send our transformation to the currently bound shader, in the "MVP" uniform
	// This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &Camera::instance->mvp[0][0]);



	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.0f, 0.25f, 1.0f, 1.0f);

	// 1rst attribute buffer : vertices
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glVertexAttribPointer(
		0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
		);

	// 2nd attribute buffer : UVs
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		2,                                // size : U+V => 2
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
		);

	// Draw the triangle !
	glDrawArrays(GL_TRIANGLES, 0, 12 * 3); // 12*3 indices starting at 0 -> 12 triangles

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}