#include "input.h"
#include "input.h"
#include "input.h"
#include "../graphics/window.h"
#include "eventListener.h"
#include <GLFW/glfw3.h>

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

void Input::initialise(const Window& window)
{
	_windowHandle = window._handle;
	glfwSetMouseButtonCallback(static_cast<GLFWwindow*>(_windowHandle), mouseButtonCallback);
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

void Input::registerEventListener(EventListener* newListener)
{
	_listeners.push_back(newListener);
}

void Input::sendMousePressEvent(int buttonCode)
{
	for (EventListener* listener : _listeners) {
		listener->onMouseButtonPress(buttonCode);
	}
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (action == GLFW_PRESS) {
		Input::sendMousePressEvent(button);
	}
}

void* Input::_windowHandle = nullptr;
std::vector<EventListener*> Input::_listeners;