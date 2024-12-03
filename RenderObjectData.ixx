export module RenderObjectData;

export import RenderObjectShapeKey;
export import RenderObjectMaterial;
import std;

export namespace RenderObject {
    struct Data {
        std::string name;
        glm::vec3 position = glm::vec3(0.0f);
        glm::vec3 rotation = glm::vec3(0.0f);
        glm::vec3 scale = glm::vec3(1.0f);

        std::vector<Keyframe> transformKeyframes;
        std::vector<ShapeKey> shapeKeys;
        std::vector<std::vector<glm::vec3>> vertexAnimations;
        std::vector<float> vertices;
        std::vector<float> colors;
        std::vector<unsigned int> indices;
        std::vector<std::shared_ptr<Material>> materials;

        // New addition
        std::vector<unsigned int> faceMaterialIndices;
    };
}