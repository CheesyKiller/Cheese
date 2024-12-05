export module WindowContextCamera;

import GLM;

export namespace WindowContext {
    struct Camera {
        Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
        ~Camera() = default;

        glm::mat4 getViewMatrix() const;

        glm::mat4 getProjectionMatrix(float aspectRatio) const;

        bool CheckMouseLock() const;
        void processInput(const std::pair<int, int>& offset, const float& deltaTime);

        // Camera attributes
        glm::vec3 position;
        glm::vec3 front;
        glm::vec3 up;
        glm::vec3 right;
        glm::vec3 worldUp;

        // Euler angles
        float yaw;
        float pitch;

        // Camera options
        float movementSpeed;
        float mouseSensitivity;
        float zoom;
    private:
        void processKeyboardMovement(const float& deltaTime);
        void processMouseMovement(const std::pair<int, int>& offset, const bool& constrainPitch);
        void processMouseScroll(const float& yOffset);

        void updateCameraVectors();
    };
}