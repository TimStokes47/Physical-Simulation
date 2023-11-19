#include "window.h"
#include <GLFW/glfw3.h>

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_stdlib.h"

Window::Window(int width, int height, const std::string& title) {
	glfwInit();
	_handle = static_cast<void*>(glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr));
	glfwMakeContextCurrent(static_cast<GLFWwindow*>(_handle));

	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(static_cast<GLFWwindow*>(_handle), true);
	ImGui_ImplOpenGL3_Init("#version 130");
}

void Window::swapBuffers()
{
	glfwSwapBuffers(static_cast<GLFWwindow*>(_handle));
}

bool Window::isClosed()
{
	return glfwWindowShouldClose(static_cast<GLFWwindow*>(_handle));
}