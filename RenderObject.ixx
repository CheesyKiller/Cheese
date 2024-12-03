export module RenderObject;

export import RenderObjectData;
export import GLM;

import std.core;

export namespace RenderObject {
    export class RenderObject {
    public:
        // Constructor and destructor
        RenderObject(const Data& data);
        ~RenderObject();

        // Rendering function
        void draw(const unsigned int& shaderProgram, const float& currentTime);

        // Transformation functions
        void addTransformKeyframe(float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl);
        glm::mat4 interpolateTransform(const float& currentTime);

        // Shape key functions
        void addShapeKey(const std::string& name);
        void addShapeKeyframe(const std::string& shapeKeyName, float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl);
        void addVertexAnimation(size_t shapeKeyIndex, const std::vector<glm::vec3>& vertices);

        // Material functions
        void addMaterial(const std::string& materialName);

        // Wireframe mode
        void enableWireframe();
        void disableWireframe();

        // Data setters
        void setVertices(const std::vector<float>& verts);
        void setColors(const std::vector<float>& vertColors);
        void setIndices(const std::vector<unsigned int>& inds);

    private:
        // Data
        Data data;

        // OpenGL handles
        unsigned int VAO;
        unsigned int VBO;

        // Wireframe mode flag
        bool wireFrameInternal;

        // Structure to hold material-specific indices and EBO
        struct MaterialIndices {
            std::shared_ptr<Material> material;
            std::vector<unsigned int> indices;
            unsigned int EBO; // Element Buffer Object
        };

        // List of material indices for efficient rendering
        std::vector<MaterialIndices> materialIndicesList;

        // Private methods
        std::vector<float> getVertexInformation();
        void preprocessMaterialIndices();
    };
}