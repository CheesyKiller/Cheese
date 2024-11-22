#pragma once

import GLM;

#include <string>
#include <vector>

struct Material {
    std::string name;
    glm::vec3 baseColor;
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

    Material(const std::string& materialName);
};

class MaterialManager {
private:
    static MaterialManager* instance;

    MaterialManager();
    ~MaterialManager();

	std::vector<Material> materials;
public:
    static MaterialManager* getInstance();

	void addMaterial(const Material& material);
	void deleteMaterial(const std::string& name);
    Material getMaterial(const std::string& name) const;
};