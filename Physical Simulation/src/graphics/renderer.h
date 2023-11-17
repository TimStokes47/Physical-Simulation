#ifndef RENDERER_H
#define RENDERER_H

#include "shader.h"
#include "mesh.h"

class Renderer {
public:
	static void initialise();
	static Renderer* getInstance();

	Renderer();
	void clearScreen();

	void renderTriangle();
	void renderPlane();

private:
	static Renderer* _instance;

	ShaderProgram _triangleProgram;
	RenderData _triangleRenderData;
	RenderData _planeRenderData;
};

#endif