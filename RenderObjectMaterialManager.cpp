import RenderObjectMaterialManager;

namespace RenderObject {

    Material::Material(const std::string& materialName)
        : name(materialName),
        baseColor(1.0f, 1.0f, 1.0f, 1.0f),
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

    // MaterialManager implementation
    MaterialManager::MaterialManager() = default;

    MaterialManager& MaterialManager::getInstance() {
        static MaterialManager instance;
        return instance;
    }

    std::shared_ptr<Material> MaterialManager::addMaterial(const Material& material) {
        auto it = materials.find(material.name);
        if (it != materials.end()) {
            // Update existing material
            *(it->second) = material;
            return it->second;
        }
        else {
            // Add new material
            auto materialPtr = std::make_shared<Material>(material);
            materials[material.name] = materialPtr;
            return materialPtr;
        }
    }

    void MaterialManager::deleteMaterial(const std::string& name) {
        materials.erase(name);
    }

    std::shared_ptr<Material> MaterialManager::getMaterial(const std::string& name) const {
        auto it = materials.find(name);
        if (it != materials.end()) {
            return it->second;
        }
        else {
            return nullptr; // Return nullptr if material not found
        }
    }

}