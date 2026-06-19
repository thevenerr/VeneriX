#include "Input.h"
#include <GLFW/glfw3.h>

namespace VeneriX {
    bool Input::IsKeyPressed(int keycode) {
        GLFWwindow* window = glfwGetCurrentContext();
        if (!window) return false;

        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }
}