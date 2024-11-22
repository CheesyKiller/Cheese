#pragma once

import GLAD;

#include <iostream>
#include <vector>

import GLM;
import GLM:gtc_matrix_transform;
import GLM:gtc_type_ptr;

class ShaderProgram;

class ObjectBase {
public:
    ~ObjectBase();
    friend class ShaderProgram;

    ObjectBase(std::string objectName, std::vector<float> vertices, std::vector<unsigned int> indices, std::string* fileName, size_t textureSize, const unsigned int shaderProgram, bool wireFrame = false) {
        this->indicesSize = indices.size();
        this->wireFrameInternal = wireFrame;
		this->name = objectName;

        GLAD::glGenVertexArrays(1, &VAO);
        GLAD::glGenBuffers(1, &VBO);
        GLAD::glGenBuffers(1, &EBO);

        GLAD::glBindVertexArray(VAO);
        
        GLAD::glBindBuffer(GLAD::GL_ARRAY_BUFFER, VBO);
        GLAD::glBufferData(GLAD::GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GLAD::GL_STATIC_DRAW);

        GLAD::glBindBuffer(GLAD::GL_ELEMENT_ARRAY_BUFFER, EBO);
        GLAD::glBufferData(GLAD::GL_ELEMENT_ARRAY_BUFFER, this->indicesSize * sizeof(unsigned int), indices.data(), GLAD::GL_STATIC_DRAW);

        // position attribute
        GLAD::glVertexAttribPointer(0, 3, GLAD::GL_FLOAT, GLAD::GL_FALSE, 8 * sizeof(float), (void*)0);
        GLAD::glEnableVertexAttribArray(0);

        // color attribute
        GLAD::glVertexAttribPointer(1, 3, GLAD::GL_FLOAT, GLAD::GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        GLAD::glEnableVertexAttribArray(1);

        // texture attribute
        GLAD::glVertexAttribPointer(2, 2, GLAD::GL_FLOAT, GLAD::GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        GLAD::glEnableVertexAttribArray(2);

        GLAD::glBindVertexArray(0);

		this->textures = std::vector<GLAD::GLuint>();
        if (textureSize > 0) {
			for (unsigned int i = 0; i < textureSize; i++) {
				this->loadTexture(fileName[i], shaderProgram);
			}
        }

        GLAD::glUniform1i(GLAD::glGetUniformLocation(shaderProgram, "texture0"), 0);
        GLAD::glUniform1i(GLAD::glGetUniformLocation(shaderProgram, "texture1"), 1);
    }

protected:
    void draw(unsigned int shaderProgram, float visibility);
    void loadTexture(const std::string filename, const unsigned int shaderProgram);
    std::string name;
    
private:
    GLAD::GLuint VAO, VBO, EBO;
	std::vector<GLAD::GLuint> textures;
    size_t indicesSize;
    bool wireFrameInternal;
};
