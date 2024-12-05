export module Shader;

import std.core;
import RenderObjectData;
import RenderObjectTexture;
import RenderObject;
import WindowContext;

export struct Shader {
    unsigned int ID;
    std::vector<std::shared_ptr<RenderObject::RenderObject>> renderObjects;
    std::vector<std::shared_ptr<RenderObject::Texture>> textures;

    Shader();
    Shader(const char* vertexSource, const char* fragmentSource, bool globalOverride = false);
    ~Shader();

    void Compile(const char* vertexSource, const char* fragmentSource);
    void Use();

    void drawObjects(const std::string& camera, const float& currentTime);
    std::shared_ptr<RenderObject::RenderObject> createObject(RenderObject::Data renderObjectData);
    std::shared_ptr<RenderObject::Texture> createTexture(const std::string& imagePath);
};

export struct GlobalShader {
    static GlobalShader* getInstance();

    void trySetShader(Shader* shader);

    void setShader(Shader* shader);

    void drawShaderObjects(const std::string& windowName, const float& deltaTime);

    Shader* shader = nullptr;  // Explicitly initialized

    GlobalShader(const GlobalShader&) = delete;
    GlobalShader& operator=(const GlobalShader&) = delete;
private:
    GlobalShader() = default;
};