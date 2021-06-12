//
// Created by Emir Hürtürk on 2.06.2021.
//

#ifndef COPENGLTEST_Engine_H
#define COPENGLTEST_Engine_H

#include <iostream>
#include <memory>
#include <vector>

#include "IO/Window.h"
#include "IO/Input.h"
#include "Graphics/Shader.h"
#include "GameObject.h"

#define LOG(x) std::cout << x << std::endl;
#define SCR_WIDTH 800
#define SCR_HEIGHT 600

class Engine {
  private:
    static Engine *instance; // singleton

    std::unique_ptr<Window> window;
    std::vector<GameObject *> gameObjects;
    void pollInputs();

    GameObject *createGameObject(Mesh &mesh);

  public:
    static Engine &getEngine(); // if instance is null, return new Engine.

    Engine();

    void free();

    Window &getWindow();

    void start();
    void update();
};

#endif //COPENGLTEST_Engine_H
