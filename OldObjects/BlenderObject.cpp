#include "BlenderObject.h"
#include "ShaderProgram.h"
import GLM:gtc_matrix_transform;
import GLM:gtc_type_ptr;
import GLAD;
#include <memory>
#include "VectorOutput.h"

BlenderObject::BlenderObject(const BlenderObjectData& blenderObjectData)
    : blenderData(blenderObjectData) {
    std::vector<float> vertexInformation = getVertexInformation();

	std::cout << vertexInformation << std::endl;

    auto shaderProgram = ShaderProgram::getInstance()->id;
    GLAD::glUseProgram(shaderProgram);

    GLAD::glGenVertexArrays(1, &VAO);
    GLAD::glBindVertexArray(VAO);

    GLAD::glGenBuffers(1, &VBO);
    GLAD::glBindBuffer(GLAD::GL_ARRAY_BUFFER, VBO);
    GLAD::glBufferData(GLAD::GL_ARRAY_BUFFER, vertexInformation.size() * sizeof(float), vertexInformation.data(), GLAD::GL_STATIC_DRAW);

    GLAD::glGenBuffers(1, &EBO);
    GLAD::glBindBuffer(GLAD::GL_ELEMENT_ARRAY_BUFFER, EBO);
    GLAD::glBufferData(GLAD::GL_ELEMENT_ARRAY_BUFFER, blenderData.indices.size() * sizeof(unsigned int), blenderData.indices.data(), GLAD::GL_STATIC_DRAW);

    GLAD::glVertexAttribPointer(VAO, 3, GLAD::GL_FLOAT, GLAD::GL_FALSE, 6 * sizeof(float), (void*)0);
    GLAD::glVertexAttribPointer(VAO, 3, GLAD::GL_FLOAT, GLAD::GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    GLAD::glEnableVertexAttribArray(VAO);

    GLAD::glBindVertexArray(0);

    ShaderProgram::getInstance()->addBlenderObject(std::make_shared<BlenderObject>(*this));
}

BlenderObject::~BlenderObject() {
    GLAD::glDeleteVertexArrays(1, &VAO);
    GLAD::glDeleteBuffers(1, &VBO);
    GLAD::glDeleteBuffers(1, &EBO);
}

void BlenderObject::draw() const {
    auto shaderProgram = ShaderProgram::getInstance()->id;
    GLAD::glUseProgram(shaderProgram);
    GLAD::glBindVertexArray(VAO);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, blenderData.position);
    model = glm::rotate(model, glm::radians(blenderData.rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(blenderData.rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(blenderData.rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, blenderData.scale);

    int modelLoc = GLAD::glGetUniformLocation(shaderProgram, "model");
    GLAD::glUniformMatrix4fv(modelLoc, 1, GLAD::GL_FALSE, glm::value_ptr(model));

    glm::mat4 view = glm::mat4(1.0f);
    view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
    int viewLoc = GLAD::glGetUniformLocation(shaderProgram, "view");
    GLAD::glUniformMatrix4fv(viewLoc, 1, GLAD::GL_FALSE, glm::value_ptr(view));

    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    int projectionLoc = GLAD::glGetUniformLocation(shaderProgram, "projection");
    GLAD::glUniformMatrix4fv(projectionLoc, 1, GLAD::GL_FALSE, glm::value_ptr(projection));

    GLAD::glDrawElements(GLAD::GL_TRIANGLES, blenderData.indices.size(), GLAD::GL_UNSIGNED_INT, 0);

    GLAD::glBindVertexArray(0);
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
