import Shader;

#include <iostream>

Shader::Shader() {
	ID = 0;
}

Shader::Shader(const char* vertexSource, const char* fragmentSource, bool globalOverride) {
	Compile(vertexSource, fragmentSource);
	if (globalOverride) {
		GlobalShader::getInstance()->setShader(this);
	}
	else {
		GlobalShader::getInstance()->trySetShader(this);
	}
}

void Shader::Compile(const char* vertexSource, const char* fragmentSource) {
	// vertex shader
	unsigned int vertexShader = GLAD::glCreateShader(GLAD::GL_VERTEX_SHADER);
	GLAD::glShaderSource(vertexShader, 1, &vertexSource, nullptr);
	GLAD::glCompileShader(vertexShader);
	// check for shader compile errors
	int success;
	char infoLog[512];
	GLAD::glGetShaderiv(vertexShader, GLAD::GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLAD::glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// fragment shader
	unsigned int fragmentShader = GLAD::glCreateShader(GLAD::GL_FRAGMENT_SHADER);
	GLAD::glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
	GLAD::glCompileShader(fragmentShader);
	// check for shader compile errors
	GLAD::glGetShaderiv(fragmentShader, GLAD::GL_COMPILE_STATUS, &success);
	if (!success)
	{
		GLAD::glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
	// link shaders
	ID = GLAD::glCreateProgram();
	GLAD::glAttachShader(ID, vertexShader);
	GLAD::glAttachShader(ID, fragmentShader);
	GLAD::glLinkProgram(ID);
	// check for linking errors
	GLAD::glGetProgramiv(ID, GLAD::GL_LINK_STATUS, &success);
	if (!success) {
		GLAD::glGetProgramInfoLog(ID, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	GLAD::glDeleteShader(vertexShader);
	GLAD::glDeleteShader(fragmentShader);
}

Shader::~Shader() {
	GLAD::glDeleteProgram(ID);
}

void Shader::Use() {
	GLAD::glUseProgram(ID);
}