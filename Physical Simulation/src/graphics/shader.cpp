#include "shader.h"
#include <GL/glew.h>

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

Shader::Shader(const std::string& shaderSrc, unsigned int shaderType)
{
	_handle = glCreateShader(shaderType);
	const char* shaderSrcCStr = shaderSrc.c_str();
	glShaderSource(_handle, 1, &shaderSrcCStr, NULL);
	glCompileShader(_handle);
}

Shader::~Shader()
{
	glDeleteShader(_handle);
}
