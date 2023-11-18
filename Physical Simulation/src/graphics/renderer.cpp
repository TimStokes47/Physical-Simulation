#include "renderer.h"

#include <GL/glew.h>
#include <string>

#include "shader.h"
#include "mesh.h"
#include "../maths/vec3.h"

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

	_triangleRenderData = createRenderData(createTriangleMesh());
	_projectionMatrix = Mat4::perspectiveProjection(96.0f / 54.0f, 0.6f, 0.1f, 100.0f);
}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::renderTriangle()
{	
	_triangleProgram.bind();
	_triangleProgram.setUniform("u_projection", _projectionMatrix);
	_triangleProgram.setUniform("u_model", Mat4::translation({0.0f, 0.0f, -10.0f}));
	glBindVertexArray(_triangleRenderData.vertexArray);
	glDrawElements(GL_TRIANGLES, _triangleRenderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_triangleProgram.unbind();
}

Renderer* Renderer::_instance = nullptr;