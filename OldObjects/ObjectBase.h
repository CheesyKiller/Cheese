#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

class ShaderProgram;

class ObjectBase {
public:
    ~ObjectBase();
    friend class ShaderProgram;

    ObjectBase(std::string objectName, std::vector<float> vertices, std::vector<unsigned int> indices, std::string* fileName, size_t textureSize, const unsigned int shaderProgram, bool wireFrame = false) {
        this->indicesSize = indices.size();
        this->wireFrameInternal = wireFrame;
		this->name = objectName;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indicesSize * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        // texture attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        glBindVertexArray(0);

		this->textures = std::vector<GLuint>();
        if (textureSize > 0) {
			for (unsigned int i = 0; i < textureSize; i++) {
				this->loadTexture(fileName[i], shaderProgram);
			}
        }

        glUniform1i(glGetUniformLocation(shaderProgram, "texture0"), 0);
        glUniform1i(glGetUniformLocation(shaderProgram, "texture1"), 1);
    }

protected:
    void draw(unsigned int shaderProgram, float visibility);
    void loadTexture(const std::string filename, const unsigned int shaderProgram);
    std::string name;
    
private:
    GLuint VAO, VBO, EBO;
	std::vector<GLuint> textures;
    size_t indicesSize;
    bool wireFrameInternal;
};
