import RenderObject;

import GLAD;
import Shader;

#include <iostream>

RenderObject::RenderObject() {
	GLAD::glGenVertexArrays(1, &VAO);
	GLAD::glGenBuffers(1, &VBO);
	GLAD::glGenBuffers(1, &EBO);

	GLAD::glBindVertexArray(VAO);

	GLAD::glBindBuffer(GLAD::GL_ARRAY_BUFFER, VBO);
	GLAD::glBufferData(GLAD::GL_ARRAY_BUFFER, sizeof(vertices), vertices, GLAD::GL_STATIC_DRAW);

	GLAD::glBindBuffer(GLAD::GL_ELEMENT_ARRAY_BUFFER, EBO);
	GLAD::glBufferData(GLAD::GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GLAD::GL_STATIC_DRAW);

	GLAD::glVertexAttribPointer(0, 3, GLAD::GL_FLOAT, GLAD::GL_FALSE, 3 * sizeof(float), (void*)0);
	GLAD::glEnableVertexAttribArray(0);

	GLAD::glBindBuffer(GLAD::GL_ARRAY_BUFFER, 0);
	GLAD::glBindVertexArray(0);
}

RenderObject::~RenderObject() {
	GLAD::glDeleteVertexArrays(1, &VAO);
	GLAD::glDeleteBuffers(1, &VBO);
}

void RenderObject::Draw() {
	GLAD::glBindVertexArray(VAO);
	GLAD::glDrawElements(GLAD::GL_TRIANGLES, 6, GLAD::GL_UNSIGNED_INT, 0);
	GLAD::glBindVertexArray(0);
}