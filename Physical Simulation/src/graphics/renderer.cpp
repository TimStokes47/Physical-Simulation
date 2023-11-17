#include "renderer.h"

#include <GL/glew.h>
#include <string>

#include "shader.h"
#include "mesh.h"

void Renderer::initialise() {
	glewInit();
	_instance = new Renderer;
}

Renderer* Renderer::getInstance()
{
	return _instance;
}

Renderer::Renderer()
{
	Shader vertexShader("../../../../Physical Simulation/res/shaders/Triangle Shader.vs", GL_VERTEX_SHADER);
	Shader fragmentShader("../../../../Physical Simulation/res/shaders/Triangle Shader.fs", GL_FRAGMENT_SHADER);

	_triangleProgram.attachShader(vertexShader);
	_triangleProgram.attachShader(fragmentShader);
	_triangleProgram.compile();
}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::renderTriangle()
{
	unsigned int vertexBuffer, elementBuffer, vertexArray;

	Mesh triangleMesh = createTriangleMesh();

	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, triangleMesh.vertexData.size() * sizeof(float), triangleMesh.vertexData.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, triangleMesh.indexData.size() * sizeof(float), triangleMesh.indexData.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
	
	_triangleProgram.bind();
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
	_triangleProgram.unbind();
}

Renderer* Renderer::_instance = nullptr;