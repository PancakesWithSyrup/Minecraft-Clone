#include "OpenGLRenderer.h"

#include <iostream>

void FrameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

OpenGLRenderer::OpenGLRenderer()
{
    window = CreateWindow(1280, 720, "Minecraft-Clone", false);
	if (window == nullptr)
	{
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        exit(-1);
	}
    glfwMakeContextCurrent(window);
	
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-1);
    }
	
    glfwSetFramebufferSizeCallback(window, FrameBufferSizeCallback);
}

OpenGLRenderer::~OpenGLRenderer()
{
    glfwTerminate();
}

GLFWwindow* OpenGLRenderer::GetWindow() const
{
    return window;
}

GLFWwindow* OpenGLRenderer::CreateWindow(int windowHeight, int windowWidth, const char* windowTitle, bool fullscreen)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 8); // Anti-aliasing
	return glfwCreateWindow(windowHeight, windowWidth, windowTitle, nullptr, nullptr);
}

void OpenGLRenderer::render()
{
    
}
