//
// Created by Emir Hürtürk on 2.06.2021.
//

#ifndef OPENGLPROJECT_Engine_H
#define OPENGLPROJECT_Engine_H

#include <iostream>
#include <memory>
#include <vector>

#include "IO/Window.h"
#include "IO/Input.h"
#include "Utils/Debug.h"
#include "Graphics/Shader.h"
#include "GameObject.h"
#include "Components/Transform.h"

#define LOG(x)     std::cout << x << std::endl;
#define SCR_WIDTH  800
#define SCR_HEIGHT 600

class Engine {
private:
    static Engine *instance;  // singleton

    std::unique_ptr<Window> window;
    std::vector<GameObject *> gameObjects;
    void pollInputs();

    GameObject *createGameObject();

public:
    static Engine &getEngine();  // if instance is null, return new Engine.

    Engine();

    void free();

    Window &getWindow();

    void start();
    void update();
};

#endif  //OPENGL-PROJECT_Engine_H
