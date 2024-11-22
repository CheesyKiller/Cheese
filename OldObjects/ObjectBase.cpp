#include "ObjectBase.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

ObjectBase::~ObjectBase() {
    //glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    std::cout << "ObjectBase destroyed." << std::endl;
}

void ObjectBase::draw(unsigned int shaderProgram, float visibility) {
    glUseProgram(shaderProgram);

    if (wireFrameInternal) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }
    else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

	glUniform1f(glGetUniformLocation(shaderProgram, "visibility"), visibility);

    glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, textures[0]);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textures[1]);

    glBindVertexArray(VAO);

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    int modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glm::mat4 view = glm::mat4(1.0f);
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    int viewLoc = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glDrawElements(GL_TRIANGLES, this->indicesSize, GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL error: " << error << std::endl << "Shader Program: " << shaderProgram << std::endl;
        std::terminate();
    }
}

void ObjectBase::loadTexture(const std::string filename, const unsigned int shaderProgram)
{
    glUseProgram(shaderProgram);

    // Load the image
    int width, height, nrChannels;
    unsigned char* data = stbi_load(("D://Visual Studio//Distortion//Textures//" + filename).c_str(), &width, &height, &nrChannels, 0);
    if (!data)
    {
#ifdef _DEBUG
        //std::cerr << "Failed to load texture: " << filename << ("\n\tD://Visual Studio//Distortion//Textures//" + filename).c_str() << std::endl;
#endif
        return;
    }

    // Generate an OpenGL texture ID
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Set texture parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Determine the format of the image
    GLenum format = GL_RGBA;
    if (nrChannels == 1)
        format = GL_RED;
    else if (nrChannels == 3)
        format = GL_RGB;

    // Upload the image data to the GPU
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    // Free the image data after uploading to GPU
    stbi_image_free(data);
    stbi_set_flip_vertically_on_load(true);

    if (!textureID)
    {
#ifdef _DEBUG
        std::cerr << "Failed to generate texture: " << filename << std::endl;
#endif
    }

	this->textures.push_back(textureID);
}