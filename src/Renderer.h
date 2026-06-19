#pragma once
#include "Core.h"
#include "Texture2D.h"
#include <glm/glm.hpp>

namespace VeneriX {
    class VENERIX_API Renderer {
    public:
        static void Init();

        static void DrawCube(glm::vec3 position, glm::vec3 scale, glm::vec3 color, glm::mat4 view, glm::mat4 projection);
        static void DrawTexturedCube(glm::vec3 position, glm::vec3 scale, const Texture2D* texture, glm::mat4 view, glm::mat4 projection);
        static void DrawInstancedCubes(const Texture2D* texture, glm::mat4* matrices, int count, glm::mat4 view, glm::mat4 projection);
    };
}