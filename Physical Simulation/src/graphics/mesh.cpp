#include "mesh.h"

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