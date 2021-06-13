//
// Created by Emir Hürtürk on 2.06.2021.
//

#ifndef OPENGLPROJECT_WINDOW_H
#define OPENGLPROJECT_WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(const char* title, int width, int height);

    void create();
    inline GLFWwindow* getNativeWindow() { return window; }

    inline int shouldWindowClose() { return glfwWindowShouldClose(window); }
    inline void setShouldWindowClose(int state) { glfwSetWindowShouldClose(window, state); }

    void update();

private:
    const char* title;
    int width;
    int height;

    GLFWwindow* window;
};

#endif  //OPENGL-PROJECT_WINDOW_H
