#pragma once
#include "Component.h"
#include "TimeStep.h"
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class StarterPlayer : public Component {
public:
    glm::vec3 Position;
    float VelocityY = 0.0f;
    float Gravity = 9.8f;
    bool IsGrounded = false;

    StarterPlayer(glm::vec3 startPos) : Position(startPos) {}

    void Start() override {}

    void Update(const VeneriX::TimeStep& ts) override {
        VelocityY -= Gravity * ts.Delta;
        Position.y += VelocityY * ts.Delta;

        if (Position.y <= 1.0f) {
            Position.y = 1.0f;
            VelocityY = 0.0f;
            IsGrounded = true;
        }
    }

    void Jump() {
        if (IsGrounded) {
            VelocityY = 5.0f;
            IsGrounded = false;
        }
    }
};