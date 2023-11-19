#include "input.h"
#include "../graphics/window.h"
#include <GLFW/glfw3.h>

void Input::initialise(const Window& window)
{
	_windowHandle = window._handle;
}

void Input::pollEvents()
{
	glfwPollEvents();
}

bool Input::isKeyPressed(int keycode)
{
	return (glfwGetKey(static_cast<GLFWwindow*>(_windowHandle), keycode) == GLFW_PRESS);
}

bool Input::isMouseButtonPressed(int buttonCode)
{
	return (glfwGetMouseButton(static_cast<GLFWwindow*>(_windowHandle), buttonCode) == GLFW_PRESS);
}

void* Input::_windowHandle = nullptr;