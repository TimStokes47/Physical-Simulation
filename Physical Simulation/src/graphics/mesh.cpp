#include "mesh.h"
#include <GL/glew.h>

#include <cmath>

#include <fstream>
#include <sstream>


Mesh createTriangleMesh()
{
	Mesh triangleMesh;

	triangleMesh.positionData.push_back(0.0f); triangleMesh.positionData.push_back(std::sqrtf(3) / 4.0f); triangleMesh.positionData.push_back(0.0f);
	triangleMesh.positionData.push_back(-0.5f); triangleMesh.positionData.push_back(-std::sqrtf(3) / 4.0f); triangleMesh.positionData.push_back(0.0f);
	triangleMesh.positionData.push_back(0.5f); triangleMesh.positionData.push_back(-std::sqrtf(3) / 4.0f); triangleMesh.positionData.push_back(0.0f);


	triangleMesh.indexData.push_back(0);
	triangleMesh.indexData.push_back(1);
	triangleMesh.indexData.push_back(2);

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
            for (int i = 0; i < 3; i++) {
                float position;
                positionalData >> position;
                mesh.positionData.push_back(position);
            }
        }

        if (line.substr(0, 3) == "vn ")
        {
            std::istringstream normalData(line.substr(3));
            for (int i = 0; i < 3; i++) {
                float normal;
                normalData >> normal;
                mesh.normalData.push_back(normal);
            }
        }

        if (line.substr(0, 2) == "f ")
        {
            std::istringstream indexData(line.substr(2));
            std::string indexList;
            while (indexData >> indexList) {
                unsigned int index;
                std::stringstream indexStream(indexList);
                std::string indexString;

                std::getline(indexStream, indexString, '/');
                index = std::stoi(indexString);
                mesh.indexData.push_back(index);

                std::getline(indexStream, indexString, '/');
                index = std::stoi(indexString);
                mesh.indexData.push_back(index);

                std::getline(indexStream, indexString, '/');
                index = std::stoi(indexString);
                mesh.indexData.push_back(index);
            }
        }
    }
    return mesh;
}

unsigned int createVertexArray(const Mesh& mesh)
{
	unsigned int vertexArray;
	unsigned int vertexBuffer, elementBuffer;
	glGenVertexArrays(1, &vertexArray);
	glBindVertexArray(vertexArray);

	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, mesh.positionData.size() * sizeof(float), mesh.positionData.data(), GL_STATIC_DRAW);

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
