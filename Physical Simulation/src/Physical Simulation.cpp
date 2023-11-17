#include "graphics/renderer.h"
#include "graphics/window.h"
#include "core/input.h"

#include <iostream>

int main()
{
	Window window(960, 540, "Physical Simulation");
	Input input(window);
	Renderer::initialise();

	while (!window.isClosed()) {
		window.swapBuffers();
		input.pollEvents();

		Renderer::clearScreen();
		Renderer::renderTriangle();

		if (input.isKeyPressed(GLFW_KEY_A)) {
			std::cout << "A\n";
		}
		if (input.isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT)) {
			std::cout << "Right\n";
		}
	}
	return 0;
}
