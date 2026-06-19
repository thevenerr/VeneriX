#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace VeneriX {

    Camera::Camera() {
        Position = glm::vec3(0.0f, 5.0f, 15.0f);
        Target = glm::vec3(0.0f, 0.0f, 0.0f);
        Up = glm::vec3(0.0f, 1.0f, 0.0f);
        Fov = 45.0f;
        AspectRatio = 1280.0f / 720.0f;
    }

    glm::mat4 Camera::GetViewMatrix() const {
        return glm::lookAt(Position, Target, Up);
    }

    glm::mat4 Camera::GetProjectionMatrix() const {
        return glm::perspective(glm::radians(Fov), AspectRatio, 0.1f, 100.0f);
    }
}