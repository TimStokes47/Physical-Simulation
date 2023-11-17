#include "renderer.h"

#include <GL/glew.h>

void Renderer::initialise() {
	glewInit();
}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
