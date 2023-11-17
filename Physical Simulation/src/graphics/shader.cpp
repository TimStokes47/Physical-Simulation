#include "shader.h"
#include <GL/glew.h>
#include <fstream>
#include <sstream>
#include <iostream>

ShaderProgram::ShaderProgram()
{
	_handle = glCreateProgram();
}

ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(_handle);
}

void ShaderProgram::attachShader(const Shader& shader)
{
	glAttachShader(_handle, shader._handle);
}

void ShaderProgram::compile()
{
	glLinkProgram(_handle);
}

void ShaderProgram::bind()
{
	glUseProgram(_handle);
}

void ShaderProgram::unbind()
{
	glUseProgram(0);
}

Shader::Shader(const std::string& shaderSrcFilepath, unsigned int shaderType)
{
	_handle = glCreateShader(shaderType);

	std::ifstream shaderFile;
	shaderFile.open(shaderSrcFilepath);

	if (!shaderFile.is_open()) {
		std::cout << "File not found. Filepath: " << shaderSrcFilepath << std::endl;
	}
	std::stringstream stream;
	stream << shaderFile.rdbuf();
	std::string shaderSrc = stream.str();

	const char* shaderSrcCStr = shaderSrc.c_str();
	glShaderSource(_handle, 1, &shaderSrcCStr, NULL);
	glCompileShader(_handle);
}

Shader::~Shader()
{
	glDeleteShader(_handle);
}
