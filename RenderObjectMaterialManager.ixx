export module RenderObjectMaterialManager;

import std.core;
import RenderObjectMaterial;

export namespace RenderObject {
    class MaterialManager {
    private:
        MaterialManager();

        // Use unordered_map for efficient lookup and shared_ptr for shared ownership
        std::unordered_map<std::string, std::shared_ptr<Material>> materials;

    public:
        static MaterialManager& getInstance();

        ~MaterialManager() = default;

        // Return shared_ptr to share ownership
        std::shared_ptr<Material> addMaterial(const Material& material);
        void deleteMaterial(const std::string& name);
        std::shared_ptr<Material> getMaterial(const std::string& name) const;

        // Delete copy constructor and assignment operator
        MaterialManager(const MaterialManager&) = delete;
        MaterialManager& operator=(const MaterialManager&) = delete;
    };
}