#pragma once

#define CPP_GLSL_INCLUDE

#include "ShaderProgram.h"
#include "ShaderBase.h"

import ShaderSources;

#include "DynamicWindow.h"

std::shared_ptr<ShaderProgram> ShaderProgram::instance;

ShaderProgram::ShaderProgram() {
    this->id = GLAD::glCreateProgram();

    ShaderBase vertexShader = ShaderBase(id, "Vertex", GLAD::GL_VERTEX_SHADER, VertexShaderSource);
    ShaderBase fragmentShader = ShaderBase(id, "Fragment", GLAD::GL_FRAGMENT_SHADER, FragmentShaderSource);

    int success;
    char infoLog[512];

    GLAD::glLinkProgram(id);
    GLAD::glGetProgramiv(id, GLAD::GL_LINK_STATUS, &success);
#ifdef _DEBUG
    if (!success) {
        GLAD::glGetProgramInfoLog(id, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    GLAD::GLenum error = GLAD::glGetError();
    if (error != GLAD::GL_NO_ERROR) {
        std::cerr << "OpenGL Error: " << error << std::endl;
    }
#endif
}

ShaderProgram::~ShaderProgram() {
    GLAD::glDeleteProgram(id);

#ifdef _DEBUG
	std::cout << "Shader Removed" << std::endl;
#endif
}

bool TESTBOOL = true;

void ShaderProgram::draw() {
    GLAD::glUseProgram(id);
    for (unsigned int i = 0; i < currentObjects.size(); i++) {
        currentObjects[i]->draw();

		if (TESTBOOL) {
			std::cout << currentObjects.size() << std::endl;
            std::cout << currentObjects[i]->blenderData.name << std::endl;
            std::cout << currentObjects[i]->getVertexInformation() << std::endl;
            std::cout << currentObjects[i]->blenderData.indices << std::endl;
			TESTBOOL = false;
		}
    }
}

void ShaderProgram::addBlenderObject(std::shared_ptr<BlenderObject> blenderObject) {
	this->removeObject(blenderObject.get()[0].blenderData.name);

	currentObjects.push_back(blenderObject);
}

void ShaderProgram::removeObject(std::string objectName) {
	for (int i = 0; i < currentObjects.size(); i++) {
		if (currentObjects[i]->blenderData.name == objectName) {
			currentObjects.erase(currentObjects.begin() + i);
			break;
		}
	}
}