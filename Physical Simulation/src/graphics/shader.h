#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
	friend class ShaderProgram;
public:
	Shader(const std::string& shaderSrc, unsigned int shaderType);
	~Shader();

private:
	unsigned int _handle;
};

class ShaderProgram {
public:
	ShaderProgram();
	~ShaderProgram();

	void attachShader(const Shader& shader);
	void compile();
	void bind();
	void unbind();

private:
	unsigned int _handle;
};

#endif