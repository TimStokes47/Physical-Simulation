#ifndef MESH_H
#define MESH_H

#include <vector>
#include <string>

#include "../maths/vec3.h"
#include "../maths/uvec3.h"

struct Mesh {
	std::vector<Vec3> positionData;
	std::vector<Vec3> normalData;
	std::vector<UVec3> indexData;
};

Mesh createTriangleMesh();
Mesh loadMeshFromFile(const std::string& filepath);

struct RenderData {
	unsigned int vertexArray;
	unsigned int indexCount;
};

unsigned int createVertexArray(const Mesh& mesh, unsigned int& indicesCount);
RenderData createRenderData(const Mesh& mesh);

#endif