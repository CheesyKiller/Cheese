#include "MaterialManager.h"

Material::Material(const std::string& materialName)
    : name(materialName),
    baseColor(1.0f, 1.0f, 1.0f),
    metallic(0.0f),
    roughness(0.5f),
    emission(0.0f, 0.0f, 0.0f),
    alpha(1.0f),
    specular(0.5f, 0.5f, 0.5f),
    normalMap(0.0f, 0.0f, 0.0f),
    ambientOcclusion(1.0f),
    subsurface(0.0f),
    subsurfaceColor(1.0f, 1.0f, 1.0f),
    transmission(0.0f),
    clearcoat(0.0f),
    clearcoatRoughness(0.0f) {}

MaterialManager* MaterialManager::instance = nullptr;

MaterialManager::MaterialManager() {
	materials = std::vector<Material>();
}

MaterialManager::~MaterialManager() {
    if (instance != nullptr) {
        delete instance;
    }
}

MaterialManager* MaterialManager::getInstance() {
    if (instance == nullptr) {
        instance = new MaterialManager();
    }
    return instance;
}

void MaterialManager::addMaterial(const Material& material) {
    for (Material& m : materials) {
        if (m.name == material.name) {
            m = material;
            return;
        }
    }
    materials.push_back(material);
}


void MaterialManager::deleteMaterial(const std::string& name) {
    materials.erase(std::remove_if(materials.begin(), materials.end(),
        [&name](const Material& material) { return material.name == name; }),
        materials.end());
}

Material MaterialManager::getMaterial(const std::string& name) const {
    for (const auto& material : materials) {
        if (material.name == name)
            return material;
    }
    return Material("");
}