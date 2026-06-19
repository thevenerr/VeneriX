#pragma once
#include "Core.h"
#include <glm/glm.hpp>

namespace VeneriX {
    class VENERIX_API Camera {
    public:
        Camera();

        glm::vec3 Position;
        glm::vec3 Target;
        glm::vec3 Up;

        float Fov;
        float AspectRatio;

        glm::mat4 GetViewMatrix() const;
        glm::mat4 GetProjectionMatrix() const;
    };
}