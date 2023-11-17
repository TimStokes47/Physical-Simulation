#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>

struct Mesh {
	std::vector<float> positionData;
	std::vector<float> normalData;
	std::vector<unsigned int> indexData;
};

Mesh createTriangleMesh();
Mesh loadMeshFromFile(const std::string& filepath);

struct RenderData {
	unsigned int vertexArray;
	unsigned int indexCount;
};

unsigned int createVertexArray(const Mesh& mesh);
RenderData createRenderData(const Mesh& mesh);

#endif