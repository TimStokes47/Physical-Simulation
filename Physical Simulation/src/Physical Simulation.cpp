// Physical Simulation.cpp : Defines the entry point for the application.
//
#include "graphics/window.h"

int main()
{
	Window window(960, 540, "Physical SImulation");

	while (!window.isClosed()) {
		window.swapBuffers();
	}
	return 0;
}
