#include "graphics/renderer.h"
#include "graphics/window.h"
#include "core/input.h"
#include "graphics/camera.h"

#include <iostream>
#include <chrono>
#include <thread>

int main()
{
	Window window(960, 540, "Physical Simulation");
	Input::initialise(window);
	Renderer::initialise();

	int fps = 240;
	float totalTime = 0.0f;
	auto timeBetweenFrames = std::chrono::microseconds(std::chrono::seconds(1)) / fps;
	auto targetTimepoint = std::chrono::steady_clock::now();
	float dt = (float)timeBetweenFrames.count() / std::chrono::microseconds(std::chrono::seconds(1)).count();

	while (!window.isClosed()) {
		targetTimepoint += timeBetweenFrames;
		std::this_thread::sleep_until(targetTimepoint);

		window.swapBuffers();
		Input::pollEvents();

		Renderer::getInstance()->getCamera().update(dt);

		Renderer::getInstance()->clearScreen();
		Renderer::getInstance()->renderSphere(Mat4::translation({1.0f, 1.0f, 0.0f}));
	}
	return 0;
}
