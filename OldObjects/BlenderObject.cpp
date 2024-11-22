#include "BlenderObject.h"
#include "ShaderProgram.h"
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <memory>
#include "VectorOutput.h"

BlenderObject::BlenderObject(const BlenderObjectData& blenderObjectData)
    : blenderData(blenderObjectData) {
    std::vector<float> vertexInformation = getVertexInformation();

	std::cout << vertexInformation << std::endl;

    auto shaderProgram = ShaderProgram::getInstance()->id;
    glUseProgram(shaderProgram);

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertexInformation.size() * sizeof(float), vertexInformation.data(), GL_STATIC_DRAW);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, blenderData.indices.size() * sizeof(unsigned int), blenderData.indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(VAO, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glVertexAttribPointer(VAO, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(VAO);

    glBindVertexArray(0);

    ShaderProgram::getInstance()->addBlenderObject(std::make_shared<BlenderObject>(*this));
}

BlenderObject::~BlenderObject() {
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
}

void BlenderObject::draw() const {
    auto shaderProgram = ShaderProgram::getInstance()->id;
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, blenderData.position);
    model = glm::rotate(model, glm::radians(blenderData.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(blenderData.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(blenderData.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, blenderData.scale);

    int modelLoc = glGetUniformLocation(shaderProgram, "model");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    int viewLoc = glGetUniformLocation(shaderProgram, "view");
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    int projectionLoc = glGetUniformLocation(shaderProgram, "projection");
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glDrawElements(GL_TRIANGLES, blenderData.indices.size(), GL_UNSIGNED_INT, 0);

    glBindVertexArray(0);
}

void BlenderObject::addTransformKeyframe(float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl) {
    blenderData.transformKeyframes.push_back({ frame, pos, rot, scl });
}

void BlenderObject::addShapeKey(const std::string& name) {
    blenderData.shapeKeys.push_back({ name, {} });
}

void BlenderObject::addShapeKeyframe(const std::string& shapeKeyName, float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl) {
    for (auto& shapeKey : blenderData.shapeKeys) {
        if (shapeKey.name == shapeKeyName) {
            shapeKey.keyframes.push_back({ frame, pos, rot, scl });
            break;
        }
    }
}

void BlenderObject::addVertexAnimation(size_t shapeKeyIndex, const std::vector<glm::vec3>& vertices) {
    if (shapeKeyIndex < blenderData.vertexAnimations.size()) {
        blenderData.vertexAnimations[shapeKeyIndex] = vertices;
    }
    else {
        blenderData.vertexAnimations.resize(shapeKeyIndex + 1);
        blenderData.vertexAnimations[shapeKeyIndex] = vertices;
    }
}

void BlenderObject::setVertices(const std::vector<float>& verts) {
    blenderData.vertices = verts;
}

void BlenderObject::setColors(const std::vector<float>& vertColors) {
    blenderData.colors = vertColors;
}

void BlenderObject::setIndices(const std::vector<unsigned int>& inds) {
    blenderData.indices = inds;
}

void BlenderObject::addMaterial(const Material& material) {
    blenderData.materials.push_back(material.name);
    MaterialManager::getInstance()->addMaterial(material);
}

std::vector<float> BlenderObject::getVertexInformation() {
    std::vector<float> finalVertices = std::vector<float>();

    for (size_t i = 0; i < blenderData.vertices.size() / 3; ++i) {
		finalVertices.push_back(blenderData.vertices[i * 3]);
        finalVertices.push_back(blenderData.vertices[i * 3 + 1]);
        finalVertices.push_back(blenderData.vertices[i * 3 + 2]);

        finalVertices.push_back(blenderData.colors[i * 3]);
        finalVertices.push_back(blenderData.colors[i * 3 + 1]);
        finalVertices.push_back(blenderData.colors[i * 3 + 2]);
    }

    return finalVertices;
}
