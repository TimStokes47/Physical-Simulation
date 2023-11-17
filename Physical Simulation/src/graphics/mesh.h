#ifndef MESH_H
#define MESH_H

#include <vector>

struct Mesh {
	std::vector<float> vertexData;
	std::vector<unsigned int> indexData;
};

Mesh createTriangleMesh();

#endif