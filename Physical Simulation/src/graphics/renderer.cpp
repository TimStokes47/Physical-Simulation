#include "renderer.h"
#include "renderer.h"
#include "renderer.h"
#include "renderer.h"
#include "renderer.h"
#include "renderer.h"

#include <GL/glew.h>
#include <string>

#include "shader.h"
#include "mesh.h"
#include "../maths/vec3.h"
#include "../physics/particle.h"

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

	_planeRenderData = createRenderData(loadMeshFromFile("../../../../Physical Simulation/res/meshes/plane.obj"));
	_cubeRenderData = createRenderData(loadMeshFromFile("../../../../Physical Simulation/res/meshes/cube.obj"));
	_sphereRenderData = createRenderData(loadMeshFromFile("../../../../Physical Simulation/res/meshes/sphere.obj"));

}

void Renderer::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

Camera& Renderer::getCamera()
{
	return _camera;
}

void Renderer::render(const RenderData& renderData, const Mat4& model)
{
	_standardProgram.bind();
	_standardProgram.setUniform("u_projection", _camera.getPrespectiveProjectionMatrix());
	_standardProgram.setUniform("u_view", _camera.getViewMatrix());
	_standardProgram.setUniform("u_model", model);
	glBindVertexArray(renderData.vertexArray);
	glDrawElements(GL_TRIANGLES, renderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_standardProgram.unbind();
	glBindVertexArray(0);
}

void Renderer::renderPlane(const Mat4& model)
{
	_standardProgram.bind();
	_standardProgram.setUniform("u_projection", _camera.getPrespectiveProjectionMatrix());
	_standardProgram.setUniform("u_view", _camera.getViewMatrix());
	_standardProgram.setUniform("u_model", model);
	glBindVertexArray(_planeRenderData.vertexArray);
	glDrawElements(GL_TRIANGLES, _planeRenderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_standardProgram.unbind();
}

void Renderer::renderCube(const Mat4& model)
{
	_standardProgram.bind();
	_standardProgram.setUniform("u_projection", _camera.getPrespectiveProjectionMatrix());
	_standardProgram.setUniform("u_view", _camera.getViewMatrix());
	_standardProgram.setUniform("u_model", model);
	glBindVertexArray(_cubeRenderData.vertexArray);
	glDrawElements(GL_TRIANGLES, _cubeRenderData.indexCount, GL_UNSIGNED_INT, nullptr);
	_standardProgram.unbind();
}

void Renderer::renderSphere(const Mat4& model)
{
	render(_sphereRenderData, model);
}

void Renderer::renderParticle(const Particle& particle)
{
	renderSphere(Mat4::translation(particle.position));
}

Renderer* Renderer::_instance = nullptr;