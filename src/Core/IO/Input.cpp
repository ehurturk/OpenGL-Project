#include "Input.h"

#include "../Engine.h"
#include <iostream>

int Input::isKeyDown(int key)
{
    auto window = Engine::getEngine().getWindow().getNativeWindow();
    int state = glfwGetKey(window, key);
    return state == GLFW_REPEAT || state == GLFW_PRESS;
}

int Input::isMouseButtonDown(int button)
{
    auto window = Engine::getEngine().getWindow().getNativeWindow();
    int state = glfwGetMouseButton(window, button);
    return state == GLFW_PRESS;
}

int Input::isKeyUp(int key)
{
    auto window = Engine::getEngine().getWindow().getNativeWindow();
    int state = glfwGetKey(window, key);
    return state == GLFW_RELEASE;
}

int Input::isMouseButtonUp(int button)
{
    auto window = Engine::getEngine().getWindow().getNativeWindow();
    int state = glfwGetMouseButton(window, button);
    return state == GLFW_RELEASE;
}

// Seperating each axis since I don't want them to interfere each other.
int h_factor = 1, v_factor = 1;
float h_counter = 0.0f;
float v_counter = 0.0f;

float Input::getAxis(const char *axis)
{
    if (strcmp(axis, "Horizontal") == 0) // (x) -> w and s keys
    {
        if (Input::isKeyDown(GLFW_KEY_W)) {
            h_factor = 1;

            if (h_counter < 1.0f) {
                h_counter += 0.05f;
            }
        }

        if (Input::isKeyDown(GLFW_KEY_S)) {

            h_factor = -1;

            if (h_counter < 1.0f) {
                h_counter += 0.05f;
            }
        }

        else if ((Input::isKeyUp(GLFW_KEY_W) && Input::isKeyUp(GLFW_KEY_S))) {
            if (h_counter > 0.01f)
                h_counter -= 0.05f;
        }

        h_counter = h_counter < 0.01f ? 0.0f : h_counter;

        return h_factor * (h_counter > 1.0f ? 1.0f : h_counter);
    }

    if (strcmp(axis, "Vertical") == 0) // (z) -> a and d keys
    {
        if (Input::isKeyDown(GLFW_KEY_D)) {
            v_factor = 1;

            if (v_counter < 1.0f) {
                v_counter += 0.05f;
            }
        }

        if (Input::isKeyDown(GLFW_KEY_A)) {
            v_factor = -1;
            if (v_counter < 1.0f) {
                v_counter += 0.05f;
            }
        }

        else if (Input::isKeyUp(GLFW_KEY_A) && Input::isKeyUp(GLFW_KEY_D)) {
            if (v_counter > 0.0f)
                v_counter -= 0.05f;
        }

        v_counter = (v_counter < 0.01f) ? 0.0f : v_counter;

        return (float)v_factor * (v_counter > 1.0f ? 1.0f : v_counter);
    }

    return 0;
}
