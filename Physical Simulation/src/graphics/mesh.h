#ifndef MESH_H
#define MESH_H

#include <vector>

struct Mesh {
	std::vector<float> vertexData;
	std::vector<unsigned int> indexData;
};

Mesh createTriangleMesh();

struct RenderData {
	unsigned int vertexArray;
	unsigned int indexCount;
};

unsigned int createVertexArray(const Mesh& mesh);
RenderData createRenderData(const Mesh& mesh);

#endif