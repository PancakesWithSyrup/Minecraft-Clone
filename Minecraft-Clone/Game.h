#pragma once
#include "OpenGLRenderer.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Game
{
public:
	Game();
	~Game();
	
	bool ShouldGameClose() const;
private:
	OpenGLRenderer opengl_renderer{};
	bool running = true;
	
	void StartMainLoop();
};
