#include "renderer.h"

#include <GL/glew.h>
#include <string>

void Renderer::initialise() {
	glewInit();
}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::renderTriangle()
{
	unsigned int vertexBuffer, elementBuffer, vertexArray;

	float vertexData[] = {
		0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		-0.4f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
		0.4f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f
	};

	unsigned int indexData[] = {
		0, 1, 2
	};

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indexData), indexData, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));


	const char* vertexShaderSource = "#version 330 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"layout (location = 1) in vec3 aColor;\n"
		"out vec3 color;\n"
		"void main()\n"
		"{\n"
		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"	color = aColor;\n"
		"}\0";

	const char* fragmentShaderSource = "#version 330 core\n"
		"in vec3 color;\n"
		"out vec4 FragColor;\n"
		"void main()\n"
		"{\n"
		"FragColor = vec4(color, 1.0f);\n"
		"}\0";
	
	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glUseProgram(shaderProgram);

	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}
