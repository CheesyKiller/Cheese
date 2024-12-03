import WindowContextCamera;

import KeyboardInput;
import std.core;

namespace WindowContext {
    // Constructors
    Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
        : position(position), worldUp(up), yaw(yaw), pitch(pitch), movementSpeed(0.002f),
        mouseSensitivity(1.0f), zoom(45.0f) {
        updateCameraVectors();
    }

    // Getters
    glm::mat4 Camera::getViewMatrix() const {
        return glm::lookAt(position, position + front, up);
    }

    glm::mat4 Camera::getProjectionMatrix(float aspectRatio) const {
        return glm::perspective(glm::radians(zoom), aspectRatio, 0.1f, 100.0f);
    }

    bool Camera::CheckMouseLock() const {
        return Input::InputManager::GetInstance()->IsJustPressed(Input::KEY_ALT);
    }
    
    void Camera::processInput(const std::pair<int, int>& offset, const float& deltaTime) {
        processKeyboardMovement(deltaTime);
        processMouseMovement(offset, true);
    }

    void Camera::processKeyboardMovement(const float& deltaTime) {
        float velocity = movementSpeed * deltaTime;
		Input::InputManager* inputManager = Input::InputManager::GetInstance();
        if (inputManager->IsPressed(Input::KEY_W)) position += front * velocity;
        if (inputManager->IsPressed(Input::KEY_S)) position -= front * velocity;
        if (inputManager->IsPressed(Input::KEY_A)) position -= right * velocity;
        if (inputManager->IsPressed(Input::KEY_D)) position += right * velocity;
    }

    void Camera::processMouseMovement(const std::pair<int, int>& offset, const bool& constrainPitch) {
        yaw += offset.first * mouseSensitivity;
        pitch += offset.second * mouseSensitivity * -1;

        if (constrainPitch) {
            pitch = std::clamp(pitch, -89.0f, 89.0f);
        }
        updateCameraVectors();
    }

    void Camera::processMouseScroll(const float& yOffset) {
        zoom -= yOffset;
        if (zoom < 1.0f)
            zoom = 1.0f;
        if (zoom > 45.0f)
            zoom = 45.0f;
    }

    void Camera::updateCameraVectors() {
        glm::vec3 frontVec;
        frontVec.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        frontVec.y = sin(glm::radians(pitch));
        frontVec.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        front = glm::normalize(frontVec);
        right = glm::normalize(glm::cross(front, worldUp));
        up = glm::normalize(glm::cross(right, front));
    }
}