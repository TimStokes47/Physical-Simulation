#include <GL/glew.h>
#include <GLFW/glfw3.h>

void run() {
	glfwInit();
	GLFWwindow* window = glfwCreateWindow(960, 540, "Physical Simulation", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	glewInit();

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	while (!glfwWindowShouldClose(window)) {
		glfwSwapBuffers(window);
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
	}

	glfwTerminate();
}