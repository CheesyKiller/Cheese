export module RenderObjectTexture;

import GLAD;
import std.core;

export namespace RenderObject {
    struct Texture {
        // Constructor: loads an image file and creates a texture
        Texture(const std::string& imagePath, GLAD::GLenum textureUnit = GLAD::GL_TEXTURE0);

        // Activate the texture unit and bind the texture
        void bind() const;

        // Unbind the texture
        void unbind() const;

        // Get the texture ID
        GLAD::GLuint getID() const;

        // Destructor: cleans up the texture resource
        ~Texture();

    private:
        GLAD::GLuint textureID;
        GLAD::GLenum textureUnit;
    };
}