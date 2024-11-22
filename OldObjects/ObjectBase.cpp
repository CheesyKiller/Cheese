#include "ObjectBase.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

ObjectBase::~ObjectBase() {
    //glDeleteVertexArrays(1, &VAO);
    GLAD::glDeleteBuffers(1, &VBO);
    GLAD::glDeleteBuffers(1, &EBO);
    std::cout << "ObjectBase destroyed." << std::endl;
}

void ObjectBase::draw(unsigned int shaderProgram, float visibility) {
    GLAD::glUseProgram(shaderProgram);

    if (wireFrameInternal) {
        GLAD::glPolygonMode(GLAD::GL_FRONT_AND_BACK, GLAD::GL_LINE);
    }
    else {
        GLAD::glPolygonMode(GLAD::GL_FRONT_AND_BACK, GLAD::GL_FILL);
    }

    GLAD::glUniform1f(GLAD::glGetUniformLocation(shaderProgram, "visibility"), visibility);

    GLAD::glActiveTexture(GLAD::GL_TEXTURE0);
    GLAD::glBindTexture(GLAD::GL_TEXTURE_2D, textures[0]);
    GLAD::glActiveTexture(GLAD::GL_TEXTURE1);
    GLAD::glBindTexture(GLAD::GL_TEXTURE_2D, textures[1]);

    GLAD::glBindVertexArray(VAO);

    glm::mat4 trans = glm::mat4(1.0f);
    trans = glm::translate(trans, glm::vec3(0.5f, -0.5f, 0.0f));
    trans = glm::rotate(trans, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));
    int modelLoc = GLAD::glGetUniformLocation(shaderProgram, "model");
    GLAD::glUniformMatrix4fv(modelLoc, 1, GLAD::GL_FALSE, glm::value_ptr(model));

    glm::mat4 view = glm::mat4(1.0f);
    // note that we're translating the scene in the reverse direction of where we want to move
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    int viewLoc = GLAD::glGetUniformLocation(shaderProgram, "view");
    GLAD::glUniformMatrix4fv(viewLoc, 1, GLAD::GL_FALSE, glm::value_ptr(view));

    glm::mat4 projection;
    projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    int projectionLoc = GLAD::glGetUniformLocation(shaderProgram, "projection");
    GLAD::glUniformMatrix4fv(projectionLoc, 1, GLAD::GL_FALSE, glm::value_ptr(projection));

    GLAD::glDrawElements(GLAD::GL_TRIANGLES, this->indicesSize, GLAD::GL_UNSIGNED_INT, 0);

    GLAD::glBindVertexArray(0);

    GLAD::GLenum error = GLAD::glGetError();
    if (error != GLAD::GL_NO_ERROR) {
        std::cerr << "OpenGL error: " << error << std::endl << "Shader Program: " << shaderProgram << std::endl;
        std::terminate();
    }
}

void ObjectBase::loadTexture(const std::string filename, const unsigned int shaderProgram)
{
    GLAD::glUseProgram(shaderProgram);

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
    GLAD::GLuint textureID;
    GLAD::glGenTextures(1, &textureID);
    GLAD::glBindTexture(GLAD::GL_TEXTURE_2D, textureID);

    // Set texture parameters
    GLAD::glTexParameteri(GLAD::GL_TEXTURE_2D, GLAD::GL_TEXTURE_WRAP_S, GLAD::GL_REPEAT);
    GLAD::glTexParameteri(GLAD::GL_TEXTURE_2D, GLAD::GL_TEXTURE_WRAP_T, GLAD::GL_REPEAT);
    GLAD::glTexParameteri(GLAD::GL_TEXTURE_2D, GLAD::GL_TEXTURE_MIN_FILTER, GLAD::GL_LINEAR);
    GLAD::glTexParameteri(GLAD::GL_TEXTURE_2D, GLAD::GL_TEXTURE_MAG_FILTER, GLAD::GL_LINEAR);

    // Determine the format of the image
    GLAD::GLenum format = GLAD::GL_RGBA;
    if (nrChannels == 1)
        format = GLAD::GL_RED;
    else if (nrChannels == 3)
        format = GLAD::GL_RGB;

    // Upload the image data to the GPU
    GLAD::glTexImage2D(GLAD::GL_TEXTURE_2D, 0, format, width, height, 0, format, GLAD::GL_UNSIGNED_BYTE, data);
    GLAD::glGenerateMipmap(GLAD::GL_TEXTURE_2D);

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