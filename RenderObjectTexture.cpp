import RenderObjectTexture;

import GLAD;
import std;

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace RenderObject {
    Texture::Texture(const std::string& imagePath, GLAD::GLenum textureUnit)
        : textureUnit(textureUnit) {

		if (!std::filesystem::exists(imagePath)) {
			std::cerr << "Texture file \"" + imagePath +"\" does not exist" << std::endl;
		}

        // Generate a texture ID
        GLAD::glGenTextures(1, &textureID);

        // Bind the texture to the specified texture unit
        GLAD::glActiveTexture(textureUnit);
        GLAD::glBindTexture(GLAD::GL_TEXTURE_2D, textureID);

        // Set texture wrapping and filtering parameters
        GLAD::glTexParameteri(GLAD::GL_TEXTURE_2D, GLAD::GL_TEXTURE_WRAP_S, GLAD::GL_REPEAT);    // Wrap horizontally
        GLAD::glTexParameteri(GLAD::GL_TEXTURE_2D, GLAD::GL_TEXTURE_WRAP_T, GLAD::GL_REPEAT);    // Wrap vertically
        GLAD::glTexParameteri(GLAD::GL_TEXTURE_2D, GLAD::GL_TEXTURE_MIN_FILTER, GLAD::GL_LINEAR_MIPMAP_LINEAR); // Minify with mipmaps
        GLAD::glTexParameteri(GLAD::GL_TEXTURE_2D, GLAD::GL_TEXTURE_MAG_FILTER, GLAD::GL_LINEAR);               // Magnify

        // Load the image data
        int width, height, nrChannels;
        unsigned char* data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, 0);
        if (data) {
            // Determine the format based on the number of channels
            GLAD::GLenum format;
            if (nrChannels == 1)
                format = GLAD::GL_RED;
            else if (nrChannels == 3)
                format = GLAD::GL_RGB;
            else if (nrChannels == 4)
                format = GLAD::GL_RGBA;
            else {
                std::cerr << "Unsupported number of channels: " << nrChannels << std::endl;
                stbi_image_free(data);
                return;
            }

            // Upload the image data to the GPU
            GLAD::glTexImage2D(GLAD::GL_TEXTURE_2D, 0, format, width, height, 0, format, GLAD::GL_UNSIGNED_BYTE, data);

            // Generate mipmaps for better scaling
            GLAD::glGenerateMipmap(GLAD::GL_TEXTURE_2D);
        }
        else {
            std::cerr << "Failed to load texture: " << imagePath << std::endl;
        }
        // Free the image memory
        stbi_image_free(data);

        // Unbind the texture
        GLAD::glBindTexture(GLAD::GL_TEXTURE_2D, 0);
    }

    void Texture::bind() const {
        GLAD::glActiveTexture(textureUnit);
        GLAD::glBindTexture(GLAD::GL_TEXTURE_2D, textureID);
    }

    void Texture::unbind() const {
        GLAD::glBindTexture(GLAD::GL_TEXTURE_2D, 0);
    }

    GLAD::GLuint Texture::getID() const {
        return textureID;
    }

    Texture::~Texture() {
        GLAD::glDeleteTextures(1, &textureID);
    }
}