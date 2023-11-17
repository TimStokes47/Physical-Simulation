#include "renderer.h"
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

	_triangleRenderData = createRenderData(createTriangleMesh());
	_planeRenderData = createRenderData(loadMeshFromFile("../../../../Physical Simulation/res/meshes/cube.obj"));
}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::renderTriangle()
{	
	_triangleProgram.bind();
	glBindVertexArray(_triangleRenderData.vertexArray);
	glDrawElements(GL_TRIANGLES, _triangleRenderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_triangleProgram.unbind();
}

void Renderer::renderPlane()
{
	_triangleProgram.bind();
	glBindVertexArray(_planeRenderData.vertexArray);
	glDrawElements(GL_TRIANGLES, _planeRenderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_triangleProgram.unbind();
}

Renderer* Renderer::_instance = nullptr;