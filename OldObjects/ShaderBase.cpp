#include "ShaderBase.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <filesystem>

ShaderBase::~ShaderBase() {
	glDeleteShader(shaderIndex);
}

ShaderBase::ShaderBase(unsigned int shaderProgram, const std::string& shaderName, const GLuint& glShaderType, const std::string& shaderSourceInput) {
	this->shaderSource = shaderSourceInput;
	this->shaderIndex = glCreateShader(glShaderType);
#ifdef _DEBUG
	this->shaderName = ToUpperCase(shaderName);
#endif
	this->compileShader();
	this->attachShader(shaderProgram);
};

void ShaderBase::compileShader() const {
	int success;
	char infoLog[512];

	const char* sourcePtr = shaderSource.c_str();
	glShaderSource(shaderIndex, 1, &sourcePtr, NULL);
	glCompileShader(shaderIndex);

	glGetShaderiv(this->shaderIndex, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(this->shaderIndex, 512, NULL, infoLog);
#ifdef _DEBUG
		std::cout << "ERROR::SHADER::" << shaderName << "::COMPILATION_FAILED\n" << std::endl << shaderSource << std::endl << std::endl;
#endif
	}
}

void ShaderBase::attachShader(const unsigned int& shaderProgram) const {
    glAttachShader(shaderProgram, this->shaderIndex);

    // Check for OpenGL errors
    GLenum error = glGetError();
#ifdef _DEBUG
    if (error != GL_NO_ERROR) {
        std::cerr << "Error attaching shader: " << error << std::endl;
    }
#endif

    // Check shader program info log
    GLint infoLogLength = 0;
    glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
        std::vector<char> infoLog(infoLogLength);
        glGetProgramInfoLog(shaderProgram, infoLogLength, nullptr, infoLog.data());
#ifdef _DEBUG
        std::cerr << "Program Info Log: " << infoLog.data() << std::endl;
#endif // _DEBUG
    }

    // Check attached shaders
    GLint attachedShadersCount = 0;
    glGetProgramiv(shaderProgram, GL_ATTACHED_SHADERS, &attachedShadersCount);
    std::vector<GLuint> attachedShaders(attachedShadersCount);
    glGetAttachedShaders(shaderProgram, attachedShadersCount, nullptr, attachedShaders.data());

    bool shaderAttached = false;
    for (GLuint shader : attachedShaders) {
        if (shader == this->shaderIndex) {
            shaderAttached = true;
            break;
        }
    }

    if (!shaderAttached) {
#ifdef _DEBUG
        std::cerr << "Failed to attach shader " << this->shaderIndex << " to program " << shaderProgram << std::endl;
#endif
		std::terminate();
    }
}

#ifdef _DEBUG
std::string ShaderBase::ToUpperCase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
        return std::toupper(c);
    });
    return result;
}
#endif