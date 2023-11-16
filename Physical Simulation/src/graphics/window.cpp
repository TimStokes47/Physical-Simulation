#include "window.h"
#include "window.h"
#include "window.h"
#include "window.h"
#include <GLFW/glfw3.h>

Window::Window(int width, int height, const std::string& title) {
	glfwInit();
	_handle = static_cast<void*>(glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr));
	glfwMakeContextCurrent(static_cast<GLFWwindow*>(_handle));
}

void Window::swapBuffers()
{
	glfwSwapBuffers(static_cast<GLFWwindow*>(_handle));
}

bool Window::isClosed()
{
	return glfwWindowShouldClose(static_cast<GLFWwindow*>(_handle));
}