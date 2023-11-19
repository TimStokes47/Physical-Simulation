#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "mesh.h"
#include "camera.h"

class Renderer {
public:
	static void initialise();
	static Renderer* getInstance();

	Renderer();
	void clearScreen();

	Camera& getCamera();

	void renderPlane();
	void renderCube();
	void renderSphere();

private:
	static Renderer* _instance;

	ShaderProgram _standardProgram;
	RenderData _sphereRenderData;
	RenderData _cubeRenderData;
	RenderData _planeRenderData;

	Camera _camera;
};

#endif