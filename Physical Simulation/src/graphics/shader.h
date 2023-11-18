#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader {
	friend class ShaderProgram;
public:
	Shader(const std::string& shaderSrcFilepath, unsigned int shaderType);
	~Shader();

private:
	unsigned int _handle;
};

class Mat4;

class ShaderProgram {
public:
	ShaderProgram();
	~ShaderProgram();

	void attachShader(const Shader& shader);
	void compile();
	void bind();
	void unbind();

	void setUniform(const std::string& uniformName, const Mat4& matrix);

private:
	unsigned int _handle;
};

#endif