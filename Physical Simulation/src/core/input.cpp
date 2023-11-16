#include "input.h"
#include "../graphics/window.h"
#include <GLFW/glfw3.h>

Input::Input(const Window& window)
	: _windowHandle(window._handle)
{
}

void Input::pollEvents() const
{
	glfwPollEvents();
}

bool Input::isKeyPressed(int keycode) const
{
	return (glfwGetKey(static_cast<GLFWwindow*>(_windowHandle), keycode) == GLFW_PRESS);
}
