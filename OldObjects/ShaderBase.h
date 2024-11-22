#pragma once

import GLAD;

#include <string>

#ifdef _DEBUG
#include <iostream>
#endif

class ShaderProgram;

class ShaderBase {
public:
	~ShaderBase();

private:
	std::string shaderSource;
	unsigned int shaderIndex;

	std::string shaderName;

	friend class ShaderProgram;
	std::string ToUpperCase(const std::string& str);

protected:
	ShaderBase(unsigned int shaderProgram, const std::string& shaderName, const GLAD::GLuint& glShaderType, const std::string& shaderSourceInput);

	void compileShader() const;
	void attachShader(const unsigned int& shaderProgram) const;
};