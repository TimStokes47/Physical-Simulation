// Physical Simulation.cpp : Defines the entry point for the application.
//
#include "graphics/window.h"
#include "core/input.h"

#include <iostream>

int main()
{
	Window window(960, 540, "Physical Simulation");
	Input input(window);

	while (!window.isClosed()) {
		window.swapBuffers();
		input.pollEvents();

		if (input.isKeyPressed(GLFW_KEY_A)) {
			std::cout << "A\n";
		}
		if (input.isMouseButtonPressed(GLFW_MOUSE_BUTTON_RIGHT)) {
			std::cout << "Right\n";
		}
	}
	return 0;
}
