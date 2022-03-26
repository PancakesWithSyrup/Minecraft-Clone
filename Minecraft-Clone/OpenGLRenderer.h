#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

class OpenGLRenderer
{
public:
	OpenGLRenderer();
	~OpenGLRenderer();

	void render();
	GLFWwindow* GetWindow() const;
private:
	GLFWwindow* window;
	GLFWwindow* CreateWindow(int windowHeight, int windowWidth, const char* windowTitle, bool fullscreen);
};
