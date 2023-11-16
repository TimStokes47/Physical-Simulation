// Physical Simulation.cpp : Defines the entry point for the application.
//
#include "graphics/window.h"
#include "core/input.h"

int main()
{
	Window window(960, 540, "Physical Simulation");
	Input input(window);

	while (!window.isClosed()) {
		window.swapBuffers();
		input.pollEvents();
	}
	return 0;
}
