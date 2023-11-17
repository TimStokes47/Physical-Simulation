#include "mesh.h"
#include <GL/glew.h>

Mesh createTriangleMesh()
{
	Mesh triangleMesh;
	triangleMesh.vertexData.push_back(0.0f); triangleMesh.vertexData.push_back(0.5f); triangleMesh.vertexData.push_back(0.0f);
	triangleMesh.vertexData.push_back(-0.4f); triangleMesh.vertexData.push_back(-0.5f); triangleMesh.vertexData.push_back(0.0f);
	triangleMesh.vertexData.push_back(0.4f); triangleMesh.vertexData.push_back(-0.5f); triangleMesh.vertexData.push_back(0.0f);

	triangleMesh.indexData.push_back(0);
	triangleMesh.indexData.push_back(1);
	triangleMesh.indexData.push_back(2);

	return triangleMesh;
}

unsigned int createVertexArray(const Mesh& mesh)
{
	unsigned int vertexArray;
	unsigned int vertexBuffer, elementBuffer;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, mesh.vertexData.size() * sizeof(float), mesh.vertexData.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indexData.size() * sizeof(float), mesh.indexData.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	glBindVertexArray(0);
	return vertexArray;
}

RenderData createRenderData(const Mesh& mesh)
{
	RenderData data;
	data.indexCount = mesh.indexData.size();
	data.vertexArray = createVertexArray(mesh);
	return data;
}
