#include "graphics/renderer.h"
#include "graphics/window.h"
#include "core/input.h"
#include "graphics/camera.h"

#include <iostream>
#include <chrono>

int main()
{
	Window window(960, 540, "Physical Simulation");
	Input::initialise(window);
	Renderer::initialise();

	while (!window.isClosed()) {
		window.swapBuffers();
		Input::pollEvents();

		Renderer::getInstance()->getCamera().update(0.0001f);

		Renderer::getInstance()->clearScreen();
		Renderer::getInstance()->renderSphere();
	}
	return 0;
}
