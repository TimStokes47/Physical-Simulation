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

	void render(const RenderData& renderData, const Mat4& model);
	void renderPlane(const Mat4& model);
	void renderCube(const Mat4& model);
	void renderSphere(const Mat4& model);

private:
	static Renderer* _instance;

	ShaderProgram _standardProgram;
	RenderData _sphereRenderData;
	RenderData _cubeRenderData;
	RenderData _planeRenderData;

	Camera _camera;
};

#endif