//
// Created by Emir Hürtürk on 5.06.2021.
//

#ifndef COPENGLTEST_GAMEOBJECT_H
#define COPENGLTEST_GAMEOBJECT_H

#include <glad/glad.h>
#include <vector>
#include "Mesh.h"
#include "Component.h"

class GameObject {
  public:
    explicit GameObject(Mesh& mesh);
    GameObject();

    void update();
    void setMesh(Mesh& mesh) { this->mesh = &mesh; }

    void addComponent(Component& component);
    // more things like unity's game object

  private:
    Mesh* mesh;
    std::vector<Component*> components; // MIGHT BE REDUNDANT!!
};

#endif //COPENGLTEST_GAMEOBJECT_H
