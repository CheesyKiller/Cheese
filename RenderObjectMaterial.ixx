export module RenderObjectMaterial;

import GLM;
import RenderObjectNodeTree;

export namespace RenderObject {
    struct Material {
        std::string name;
        glm::vec4 baseColor;
        float metallic;
        float roughness;
        glm::vec3 emission;
        float alpha;
        glm::vec3 specular;
        glm::vec3 normalMap;
        float ambientOcclusion;
        float subsurface;
        glm::vec3 subsurfaceColor;
        float transmission;
        float clearcoat;
        float clearcoatRoughness;

		NodeTree nodeTree;

        Material(const std::string& materialName);
    };
}