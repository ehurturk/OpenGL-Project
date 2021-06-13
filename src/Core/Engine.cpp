//
// Created by Emir Hürtürk on 2.06.2021.
//

#include "Engine.h"

Engine *Engine::instance = nullptr;
Engine &Engine::getEngine()
{
    if (instance == nullptr) {
        instance = new Engine();
    }
    return *instance;
}

Window &Engine::getWindow()
{
    return *window;
}

void Engine::pollInputs()
{
    if (Input::isKeyDown(Input::Keys::ESCAPE))
        window->setShouldWindowClose(1);
}

GameObject *Engine::createGameObject()
{
    auto *go = new GameObject();
    gameObjects.push_back(go);
    return go;
}

void Engine::start()
{
    std::cout << "Start" << std::endl;
    window->create();

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f};

    Shader shader;
    shader.attach("../res/shaders/cube.vs", "../res/shaders/cube.fs");

    Mesh *mesh = new Mesh(vertices, sizeof(vertices));
    mesh->setShader(shader);

    Transform *transform = new Transform();
    transform->translate(-1, 0.1, 0);
    auto *go = createGameObject();
    go->setMesh(*mesh);
    go->addComponent(*transform);
    // returns reference, so you must explicitly cast the result to a Mesh reference. (&)
}

void Engine::update()
{
    // updating logic.
    pollInputs();
    window->update();
    for (GameObject *go : gameObjects) {
        go->update();
    }
}

Engine::Engine()
{
    window = std::make_unique<Window>("Tank Wars Engine", SCR_WIDTH, SCR_HEIGHT);
}

void Engine::free()
{
    for (auto *go : gameObjects) {
        delete go;
    }
    delete instance;
}

// TODO:
// 1) Improving the Component system.
// 2) Implementing the Transform component, which handles how the shape is drawn.
// 3) Implementing 3D Coordinate System
// 4) Implementing .obj file loader.
// 5) Implementing Textures
// 6) Implementing math, and camera.
