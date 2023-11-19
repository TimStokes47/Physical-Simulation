#include "mesh.h"
#include <GL/glew.h>

#include <cmath>

#include <fstream>
#include <sstream>


Mesh createTriangleMesh()
{
	Mesh triangleMesh;

	triangleMesh.positionData.push_back({ 0.0f, std::sqrtf(3) / 4.0f, 0.0f });
	triangleMesh.positionData.push_back({ -0.5f, -std::sqrtf(3) / 4.0f, 0.0f });
	triangleMesh.positionData.push_back({ 0.5f, -std::sqrtf(3) / 4.0f, 0.0f });

	triangleMesh.normalData.push_back({ 0.0f, 0.0f, 1.0f });
	triangleMesh.normalData.push_back({ 0.0f, 0.0f, 1.0f });
	triangleMesh.normalData.push_back({ 0.0f, 0.0f, 1.0f });

	triangleMesh.indexData.push_back({ 0, 1, 2 });

	return triangleMesh;
}

Mesh loadMeshFromFile(const std::string& filepath)
{
    Mesh mesh;

    std::ifstream objFile(filepath);
    std::string line;

	while (std::getline(objFile, line)) {
		if (line.substr(0, 2) == "v ")
		{
			std::istringstream positionalData(line.substr(2));
			Vec3 position;
			positionalData >> position.x;
			positionalData >> position.y;
			positionalData >> position.z;
			mesh.positionData.push_back(position);
		}

		if (line.substr(0, 3) == "vn ")
		{
			std::istringstream normalData(line.substr(3));
			Vec3 normal;
			normalData >> normal.x;
			normalData >> normal.y;
			normalData >> normal.z;
			mesh.normalData.push_back(normal);
		}

		if (line.substr(0, 2) == "f ")
		{
			std::istringstream indexData(line.substr(2));
			std::string indexList;
			while (indexData >> indexList) {
				UVec3 indexVector;
				std::stringstream indexStream(indexList);
				std::string index;

				std::getline(indexStream, index, '/');
				indexVector[0]  = std::stoi(index);
				std::getline(indexStream, index, '/');
				indexVector[1] = std::stoi(index);
				std::getline(indexStream, index, '/');
				indexVector[2] = std::stoi(index);

				mesh.indexData.push_back(indexVector);
			}
		}
	}
    return mesh;
}

unsigned int createVertexArray(const Mesh& mesh, unsigned int& indicesCount)
{
	std::vector<float> vertices;
	std::vector<unsigned int> indices;

	unsigned int index = 0;

	std::vector<std::pair<unsigned int, unsigned int>> previousVertices;

	for (const UVec3& indexList : mesh.indexData) {
		std::pair<unsigned int, unsigned int> vertexData = { indexList[0] - 1, indexList[2] - 1 };


		auto vertexIterator = std::find(previousVertices.begin(), previousVertices.end(), vertexData);
		unsigned int previousIndex = 0;
		while (previousIndex < index) {
			if (previousVertices[previousIndex] == vertexData) {
				break;
			}
			previousIndex++;
		}
		if (previousIndex < index) {
			indices.push_back(previousIndex);
		}
		else {
			indices.push_back(index);
			index++;

			vertices.push_back(mesh.positionData[vertexData.first].x);
			vertices.push_back(mesh.positionData[vertexData.first].y);
			vertices.push_back(mesh.positionData[vertexData.first].z);
			vertices.push_back(mesh.normalData[vertexData.second].x);
			vertices.push_back(mesh.normalData[vertexData.second].y);
			vertices.push_back(mesh.normalData[vertexData.second].z);
			previousVertices.push_back(vertexData);
		}
	}

	unsigned int vertexArray;
	unsigned int vertexBuffer, elementBuffer;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(float), indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), nullptr);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));

	glBindVertexArray(0);

	indicesCount = indices.size();
	return vertexArray;
}

RenderData createRenderData(const Mesh& mesh)
{
	RenderData data;
	unsigned int indicesCount;
	data.vertexArray = createVertexArray(mesh, indicesCount);
	data.indexCount = indicesCount;
	return data;
}
