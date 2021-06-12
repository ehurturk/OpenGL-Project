//
// Created by Emir Hürtürk on 2.06.2021.
//

#include "Window.h"
#include "GLFW/glfw3.h"

#include <iostream>

Window::Window(const char *title, int width, int height) {
    this->title = title;
    this->width = width;
    this->height = height;
}

void Window::create()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "[GLFW ERROR]: Could not initialize the window.\n";
        glfwTerminate();
        return;
    } 

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "[GLAD ERROR]: Could not initialize glad.\n";
        return;
    }
}

void Window::update()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
