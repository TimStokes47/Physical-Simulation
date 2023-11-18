#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "mesh.h"
#include "../maths/mat4.h"

class Renderer {
public:
	static void initialise();
	static Renderer* getInstance();

	Renderer();
	void clearScreen();

	void renderPlane();
	void renderCube();
	void renderSphere();

private:
	static Renderer* _instance;

	ShaderProgram _standardProgram;
	RenderData _sphereRenderData;
	RenderData _cubeRenderData;
	RenderData _planeRenderData;

	Mat4 _projectionMatrix;
};

#endif