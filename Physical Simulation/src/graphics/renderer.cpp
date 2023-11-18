#include "renderer.h"
#include "renderer.h"
#include "renderer.h"

#include <GL/glew.h>
#include <string>

#include "shader.h"
#include "mesh.h"
#include "../maths/vec3.h"

void Renderer::initialise() {
	glewInit();
	glEnable(GL_DEPTH_TEST);
	_instance = new Renderer;
}

Renderer* Renderer::getInstance()
{
	return _instance;
}

Renderer::Renderer()
{
	Shader vertexShader("../../../../Physical Simulation/res/shaders/Standard.vs", GL_VERTEX_SHADER);
	Shader fragmentShader("../../../../Physical Simulation/res/shaders/Standard.fs", GL_FRAGMENT_SHADER);

	_standardProgram.attachShader(vertexShader);
	_standardProgram.attachShader(fragmentShader);
	_standardProgram.compile();

	_projectionMatrix = Mat4::perspectiveProjection(96.0f / 54.0f, 0.6f, 0.1f, 100.0f);

	_planeRenderData = createRenderData(loadMeshFromFile("../../../../Physical Simulation/res/meshes/plane.obj"));
	_cubeRenderData = createRenderData(loadMeshFromFile("../../../../Physical Simulation/res/meshes/cube.obj"));
	_sphereRenderData = createRenderData(loadMeshFromFile("../../../../Physical Simulation/res/meshes/sphere.obj"));

}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::renderPlane()
{
	_standardProgram.bind();
	_standardProgram.setUniform("u_projection", _projectionMatrix);
	_standardProgram.setUniform("u_model", Mat4::translation({ 0.0f, 1.0f, -10.0f }));
	glBindVertexArray(_planeRenderData.vertexArray);
	glDrawElements(GL_TRIANGLES, _planeRenderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_standardProgram.unbind();
}

void Renderer::renderCube()
{
	_standardProgram.bind();
	_standardProgram.setUniform("u_projection", _projectionMatrix);
	_standardProgram.setUniform("u_model", Mat4::translation({ 0.0f, 1.0f, -10.0f }));
	glBindVertexArray(_cubeRenderData.vertexArray);
	glDrawElements(GL_TRIANGLES, _cubeRenderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_standardProgram.unbind();
}

void Renderer::renderSphere()
{
	_standardProgram.bind();
	_standardProgram.setUniform("u_projection", _projectionMatrix);
	_standardProgram.setUniform("u_model", Mat4::translation({ 0.0f, 1.0f, -10.0f }));
	glBindVertexArray(_sphereRenderData.vertexArray);
	glDrawElements(GL_TRIANGLES, _sphereRenderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_standardProgram.unbind();
}

Renderer* Renderer::_instance = nullptr;