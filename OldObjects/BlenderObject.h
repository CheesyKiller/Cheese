#pragma once

#include "MaterialManager.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>
#include <glm.hpp>

#ifdef _DEBUG
#include "VectorOutput.h"
#include <iostream>
#endif

struct Keyframe {
    float frame;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
};

struct ShapeKey {
    std::string name;
    std::vector<Keyframe> keyframes;
};

struct BlenderObjectData {
    std::string name;
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    std::vector<Keyframe> transformKeyframes;
    std::vector<ShapeKey> shapeKeys;
    std::vector<std::vector<glm::vec3>> vertexAnimations;
    std::vector<float> vertices;
    std::vector<float> colors;
    std::vector<unsigned int> indices;
    std::vector<std::string> materials;
};

class BlenderObject {
    GLuint VAO, VBO, EBO;

public:
    BlenderObjectData blenderData;

    BlenderObject(const BlenderObjectData& blenderData);
    ~BlenderObject();

    void addTransformKeyframe(float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl);
    void addShapeKey(const std::string& name);
    void addShapeKeyframe(const std::string& shapeKeyName, float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl);
    void addVertexAnimation(size_t shapeKeyIndex, const std::vector<glm::vec3>& vertices);
    void setVertices(const std::vector<float>& verts);
    void setColors(const std::vector<float>& vertColors);
    void setIndices(const std::vector<unsigned int>& inds);
    void addMaterial(const Material& material);
    std::vector<float> getVertexInformation();

    void draw() const;
};