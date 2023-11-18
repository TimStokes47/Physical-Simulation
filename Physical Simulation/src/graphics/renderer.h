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

	void renderTriangle();

private:
	static Renderer* _instance;

	ShaderProgram _triangleProgram;
	RenderData _triangleRenderData;
	Mat4 _projectionMatrix;
};

#endif