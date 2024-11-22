#include "ShaderBase.h"

#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <filesystem>

ShaderBase::~ShaderBase() {
	GLAD::glDeleteShader(shaderIndex);
}

ShaderBase::ShaderBase(unsigned int shaderProgram, const std::string& shaderName, const GLAD::GLuint& glShaderType, const std::string& shaderSourceInput) {
	this->shaderSource = shaderSourceInput;
	this->shaderIndex = GLAD::glCreateShader(glShaderType);
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
    GLAD::glShaderSource(shaderIndex, 1, &sourcePtr, NULL);
    GLAD::glCompileShader(shaderIndex);

    GLAD::glGetShaderiv(this->shaderIndex, GLAD::GL_COMPILE_STATUS, &success);

	if (!success)
	{
        GLAD::glGetShaderInfoLog(this->shaderIndex, 512, NULL, infoLog);
#ifdef _DEBUG
		std::cout << "ERROR::SHADER::" << shaderName << "::COMPILATION_FAILED\n" << std::endl << shaderSource << std::endl << std::endl;
#endif
	}
}

void ShaderBase::attachShader(const unsigned int& shaderProgram) const {
    GLAD::glAttachShader(shaderProgram, this->shaderIndex);

    // Check for OpenGL errors
    GLAD::GLenum error = GLAD::glGetError();
#ifdef _DEBUG
    if (error != GLAD::GL_NO_ERROR) {
        std::cerr << "Error attaching shader: " << error << std::endl;
    }
#endif

    // Check shader program info log
    GLAD::GLint infoLogLength = 0;
    GLAD::glGetProgramiv(shaderProgram, GLAD::GL_INFO_LOG_LENGTH, &infoLogLength);
    if (infoLogLength > 0) {
        std::vector<char> infoLog(infoLogLength);
        GLAD::glGetProgramInfoLog(shaderProgram, infoLogLength, nullptr, infoLog.data());
#ifdef _DEBUG
        std::cerr << "Program Info Log: " << infoLog.data() << std::endl;
#endif // _DEBUG
    }

    // Check attached shaders
    GLAD::GLint attachedShadersCount = 0;
    GLAD::glGetProgramiv(shaderProgram, GLAD::GL_ATTACHED_SHADERS, &attachedShadersCount);
    std::vector<GLAD::GLuint> attachedShaders(attachedShadersCount);
    GLAD::glGetAttachedShaders(shaderProgram, attachedShadersCount, nullptr, attachedShaders.data());

    bool shaderAttached = false;
    for (GLAD::GLuint shader : attachedShaders) {
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