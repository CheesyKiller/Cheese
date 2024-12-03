import RenderObject;

import GLAD;
import GLM;
import Shader;
import RenderObjectMaterialManager;

import std.core;

namespace RenderObject {

    // Constants
    const int MAX_SHAPE_KEYS = 2; // Adjust based on the number of shape keys you support

    RenderObject::RenderObject(const Data& dataIn)
        : data(dataIn), VAO(0), VBO(0), wireFrameInternal(false) {

        // Generate and bind VAO
        GLAD::glGenVertexArrays(1, &VAO);
        GLAD::glBindVertexArray(VAO);

        // Get the final vertex data, including shape key positions
        std::vector<float> finalVertices = getVertexInformation();

        // Generate and bind VBO
        GLAD::glGenBuffers(1, &VBO);
        GLAD::glBindBuffer(GLAD::GL_ARRAY_BUFFER, VBO);
        GLAD::glBufferData(GLAD::GL_ARRAY_BUFFER, finalVertices.size() * sizeof(float), finalVertices.data(), GLAD::GL_STATIC_DRAW);

        // Calculate stride: position(3) + shape keys(3 * MAX_SHAPE_KEYS)
        GLAD::GLsizei stride = (3 + 3 * MAX_SHAPE_KEYS) * sizeof(float);

        // Vertex attribute pointers
        // Position attribute
        GLAD::glVertexAttribPointer(0, 3, GLAD::GL_FLOAT, GLAD::GL_FALSE, stride, (void*)0);
        GLAD::glEnableVertexAttribArray(0);

        // Shape key attributes
        for (int i = 0; i < MAX_SHAPE_KEYS; ++i) {
            GLAD::glVertexAttribPointer(1 + i, 3, GLAD::GL_FLOAT, GLAD::GL_FALSE, stride, (void*)((3 + i * 3) * sizeof(float)));
            GLAD::glEnableVertexAttribArray(1 + i);
        }

        // Preprocess and group indices by material
        preprocessMaterialIndices();

        // Unbind VAO
        GLAD::glBindVertexArray(0);

        std::cout << "Vertices: " << data.vertices.size() << "\n";
        std::cout << "Colors: " << data.colors.size() << "\n";
        std::cout << "Indices: " << data.indices.size() << "\n";
    }

    RenderObject::~RenderObject() {
        GLAD::glDeleteVertexArrays(1, &VAO);
        GLAD::glDeleteBuffers(1, &VBO);

        // Delete material-specific EBOs
        for (auto& matIndices : materialIndicesList) {
            GLAD::glDeleteBuffers(1, &matIndices.EBO);
        }
    }

    // Function to interpolate transform keyframes and compute the model matrix
    glm::mat4 RenderObject::interpolateTransform(const float& currentTime) {
        if (data.transformKeyframes.empty()) {
            // No keyframes, return default transform
            glm::mat4 model = glm::translate(glm::mat4(1.0f), data.position);
            model = glm::rotate(model, glm::radians(data.rotation.x), glm::vec3(1, 0, 0));
            model = glm::rotate(model, glm::radians(data.rotation.y), glm::vec3(0, 1, 0));
            model = glm::rotate(model, glm::radians(data.rotation.z), glm::vec3(0, 0, 1));
            model = glm::scale(model, data.scale);
            return model;
        }

        // Find the two keyframes surrounding the current time
        Keyframe* prevKeyframe = nullptr;
        Keyframe* nextKeyframe = nullptr;

        for (size_t i = 0; i < data.transformKeyframes.size(); ++i) {
            if (data.transformKeyframes[i].frame <= currentTime) {
                prevKeyframe = &data.transformKeyframes[i];
            }
            if (data.transformKeyframes[i].frame > currentTime) {
                nextKeyframe = &data.transformKeyframes[i];
                break;
            }
        }

        if (!prevKeyframe) {
            // Current time is before the first keyframe
            prevKeyframe = &data.transformKeyframes.front();
            nextKeyframe = &data.transformKeyframes.front();
        }
        else if (!nextKeyframe) {
            // Current time is after the last keyframe
            prevKeyframe = &data.transformKeyframes.back();
            nextKeyframe = &data.transformKeyframes.back();
        }

        float frameDelta = nextKeyframe->frame - prevKeyframe->frame;
        float t = 0.0f;
        if (frameDelta != 0.0f) {
            t = (currentTime - prevKeyframe->frame) / frameDelta;
        }

        // Interpolate position, rotation, and scale
        glm::vec3 interpolatedPosition = glm::mix(prevKeyframe->position, nextKeyframe->position, t);
        glm::vec3 interpolatedRotation = glm::mix(prevKeyframe->rotation, nextKeyframe->rotation, t);
        glm::vec3 interpolatedScale = glm::mix(prevKeyframe->scale, nextKeyframe->scale, t);

        // Construct transformation matrices
        glm::mat4 translationMat = glm::translate(glm::mat4(1.0f), interpolatedPosition);
        glm::mat4 rotationMat = glm::mat4(1.0f);
        rotationMat = glm::rotate(rotationMat, glm::radians(interpolatedRotation.x), glm::vec3(1, 0, 0));
        rotationMat = glm::rotate(rotationMat, glm::radians(interpolatedRotation.y), glm::vec3(0, 1, 0));
        rotationMat = glm::rotate(rotationMat, glm::radians(interpolatedRotation.z), glm::vec3(0, 0, 1));
        glm::mat4 scaleMat = glm::scale(glm::mat4(1.0f), interpolatedScale);

        // Combine into the final model matrix
        glm::mat4 model = translationMat * rotationMat * scaleMat;

        return model;
    }

    void RenderObject::draw(const unsigned int& shaderProgram, const float& currentTime) {
        // Set wireframe mode if enabled
        if (wireFrameInternal) {
            GLAD::glPolygonMode(GLAD::GL_FRONT_AND_BACK, GLAD::GL_LINE);
        }
        else {
            GLAD::glPolygonMode(GLAD::GL_FRONT_AND_BACK, GLAD::GL_FILL);
        }

        // Bind the shader program
        GLAD::glUseProgram(shaderProgram);

        // Interpolate the model matrix based on keyframes
        glm::mat4 model = interpolateTransform(currentTime);

        // Pass the model matrix to the shader
        int modelLoc = GLAD::glGetUniformLocation(shaderProgram, "model");
        GLAD::glUniformMatrix4fv(modelLoc, 1, GLAD::GL_FALSE, glm::value_ptr(model));

        // Pass shape key weights to the shader (set to zero if not used)
        float shapeKeyWeights[MAX_SHAPE_KEYS] = { 0.0f }; // Initialize weights
        // TODO: Implement interpolation of shape key weights based on keyframes or set statically
        int shapeKeyWeightsLoc = GLAD::glGetUniformLocation(shaderProgram, "shapeKeyWeights");
        GLAD::glUniform1fv(shapeKeyWeightsLoc, MAX_SHAPE_KEYS, shapeKeyWeights);

        // Bind VAO
        GLAD::glBindVertexArray(VAO);

        // Loop through material indices and draw
        for (const auto& matIndices : materialIndicesList) {
            auto material = matIndices.material;

            // Set material uniforms
            GLAD::glUniform4fv(GLAD::glGetUniformLocation(shaderProgram, "material.baseColor"), 1, glm::value_ptr(material->baseColor));
            GLAD::glUniform1f(GLAD::glGetUniformLocation(shaderProgram, "material.metallic"), material->metallic);
            GLAD::glUniform1f(GLAD::glGetUniformLocation(shaderProgram, "material.roughness"), material->roughness);
            GLAD::glUniform3fv(GLAD::glGetUniformLocation(shaderProgram, "material.emission"), 1, glm::value_ptr(material->emission));
            // Set other material properties as needed

            // Bind material-specific EBO
            GLAD::glBindBuffer(GLAD::GL_ELEMENT_ARRAY_BUFFER, matIndices.EBO);

            // Draw elements
            GLAD::glDrawElements(GLAD::GL_TRIANGLES, static_cast<GLAD::GLsizei>(matIndices.indices.size()), GLAD::GL_UNSIGNED_INT, 0);
        }

        // Unbind VAO
        GLAD::glBindVertexArray(0);

        // Reset polygon mode if wireframe was enabled
        if (wireFrameInternal) {
            GLAD::glPolygonMode(GLAD::GL_FRONT_AND_BACK, GLAD::GL_FILL);
        }
    }

    void RenderObject::preprocessMaterialIndices() {
        // Preprocess and group indices by material
        std::unordered_map<unsigned int, std::vector<unsigned int>> matIndexToIndicesMap;

        // Assuming each face has 3 indices (triangles)
        size_t numFaces = data.faceMaterialIndices.size();
        for (size_t faceIdx = 0; faceIdx < numFaces; ++faceIdx) {
            unsigned int matIndex = data.faceMaterialIndices[faceIdx];

            // Each face has 3 indices
            size_t indexStart = faceIdx * 3;
            matIndexToIndicesMap[matIndex].insert(
                matIndexToIndicesMap[matIndex].end(),
                data.indices.begin() + indexStart,
                data.indices.begin() + indexStart + 3
            );
        }

        // Create MaterialIndices structures
        for (const auto& pair : matIndexToIndicesMap) {
            unsigned int matIndex = pair.first;
            const auto& indices = pair.second;

            MaterialIndices matIndices;
            matIndices.material = data.materials[matIndex];
            matIndices.indices = indices;

            // Generate EBO
            GLAD::glGenBuffers(1, &matIndices.EBO);
            GLAD::glBindBuffer(GLAD::GL_ELEMENT_ARRAY_BUFFER, matIndices.EBO);
            GLAD::glBufferData(GLAD::GL_ELEMENT_ARRAY_BUFFER,
                indices.size() * sizeof(unsigned int),
                indices.data(), GLAD::GL_STATIC_DRAW);

            materialIndicesList.push_back(matIndices);
        }
    }

    void RenderObject::addMaterial(const std::string& materialName) {
        // Get the material from the manager
        auto materialPtr = MaterialManager::getInstance().getMaterial(materialName);
        if (!materialPtr) {
            // Material not found, create a new one
            Material newMaterial(materialName);
            materialPtr = MaterialManager::getInstance().addMaterial(newMaterial);
        }

        // Add the shared pointer to the data materials vector
        data.materials.push_back(materialPtr);
    }

    std::vector<float> RenderObject::getVertexInformation() {
        std::vector<float> finalVertices;

        size_t numVertices = data.vertices.size() / 3;
        for (size_t i = 0; i < numVertices; ++i) {
            // Base position
            finalVertices.push_back(data.vertices[i * 3]);
            finalVertices.push_back(data.vertices[i * 3 + 1]);
            finalVertices.push_back(data.vertices[i * 3 + 2]);

            // Shape key positions
            for (int sk = 0; sk < MAX_SHAPE_KEYS; ++sk) {
                if (sk < data.vertexAnimations.size() && i < data.vertexAnimations[sk].size()) {
                    // Shape key vertex position
                    finalVertices.push_back(data.vertexAnimations[sk][i].x);
                    finalVertices.push_back(data.vertexAnimations[sk][i].y);
                    finalVertices.push_back(data.vertexAnimations[sk][i].z);
                }
                else {
                    // If no shape key data, repeat base position
                    finalVertices.push_back(data.vertices[i * 3]);
                    finalVertices.push_back(data.vertices[i * 3 + 1]);
                    finalVertices.push_back(data.vertices[i * 3 + 2]);
                }
            }
        }

        return finalVertices;
    }


    void RenderObject::enableWireframe() {
        wireFrameInternal = true;
    }

    void RenderObject::disableWireframe() {
        wireFrameInternal = false;
    }

    // Implement other methods like addTransformKeyframe, addShapeKey, etc.

    void RenderObject::addTransformKeyframe(float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl) {
        data.transformKeyframes.push_back({ frame, pos, rot, scl });
    }

    void RenderObject::addShapeKey(const std::string& name) {
        data.shapeKeys.push_back({ name, {} });
    }

    void RenderObject::addShapeKeyframe(const std::string& shapeKeyName, float frame, const glm::vec3& pos, const glm::vec3& rot, const glm::vec3& scl) {
        for (auto& shapeKey : data.shapeKeys) {
            if (shapeKey.name == shapeKeyName) {
                shapeKey.keyframes.push_back({ frame, pos, rot, scl });
                break;
            }
        }
    }

    void RenderObject::addVertexAnimation(size_t shapeKeyIndex, const std::vector<glm::vec3>& vertices) {
        if (shapeKeyIndex < data.vertexAnimations.size()) {
            data.vertexAnimations[shapeKeyIndex] = vertices;
        }
        else {
            data.vertexAnimations.resize(shapeKeyIndex + 1);
            data.vertexAnimations[shapeKeyIndex] = vertices;
        }
    }

    void RenderObject::setVertices(const std::vector<float>& verts) {
        data.vertices = verts;
    }

    void RenderObject::setColors(const std::vector<float>& vertColors) {
        data.colors = vertColors;
    }

    void RenderObject::setIndices(const std::vector<unsigned int>& inds) {
        data.indices = inds;
    }
}
