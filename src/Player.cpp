#include "Player.h"

Player::Player(glm::vec3 startPosition)
    : Position(startPosition), Velocity(0.0f), Yaw(-90.0f), Pitch(0.0f),
    MovementSpeed(5.0f), MouseSensitivity(0.1f), JumpForce(5.0f), Gravity(9.8f), IsGrounded(false)
{
    WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);
    updateCameraVectors();
}

glm::mat4 Player::GetViewMatrix() {
    return glm::lookAt(Position, Position + Front, Up);
}

void Player::ProcessKeyboard(Player_Movement direction, float deltaTime) {
    float velocity = MovementSpeed * deltaTime;
    glm::vec3 flatFront = glm::normalize(glm::vec3(Front.x, 0.0f, Front.z));

    if (direction == FORWARD)
        Position += flatFront * velocity;
    if (direction == BACKWARD)
        Position -= flatFront * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
}

void Player::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch) {
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw += xoffset;
    Pitch += yoffset;

    if (constrainPitch) {
        if (Pitch > 89.0f) Pitch = 89.0f;
        if (Pitch < -89.0f) Pitch = -89.0f;
    }
    updateCameraVectors();
}

void Player::Jump() {
    if (IsGrounded) {
        Velocity.y = JumpForce;
        IsGrounded = false;
    }
}

void Player::UpdatePhysics(float deltaTime) {
    Velocity.y -= Gravity * deltaTime;

    Position += Velocity * deltaTime;

    bool isOverPlatform = (Position.x >= -10.0f && Position.x <= 10.0f &&
        Position.z >= -10.0f && Position.z <= 10.0f);

    if (Position.y <= 1.0f && isOverPlatform) {
        Position.y = 1.0f;
        Velocity.y = 0.0f;
        IsGrounded = true;
    }
    else {
        IsGrounded = false;
    }

    if (Position.y < -20.0f) {
        Position = glm::vec3(0.0f, 5.0f, 0.0f);
        Velocity = glm::vec3(0.0f); 
    }
}
void Player::updateCameraVectors() {
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    Right = glm::normalize(glm::cross(Front, WorldUp));
    Up = glm::normalize(glm::cross(Right, Front));
}