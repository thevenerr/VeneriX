#pragma once
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum Player_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

class Player {
public:
    glm::vec3 Position;
    glm::vec3 Velocity;

    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;

    float Yaw;
    float Pitch;

    float MovementSpeed;
    float MouseSensitivity;
    float JumpForce;
    float Gravity;
    bool IsGrounded;

    Player(glm::vec3 startPosition = glm::vec3(0.0f, 1.0f, 0.0f));

    glm::mat4 GetViewMatrix();

    void ProcessKeyboard(Player_Movement direction, float deltaTime);
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);
    void Jump();

    void UpdatePhysics(float deltaTime);

private:
    void updateCameraVectors();
};