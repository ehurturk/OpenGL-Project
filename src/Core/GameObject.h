//
// Created by Emir Hürtürk on 5.06.2021.
//

#ifndef COPENGLTEST_GAMEOBJECT_H
#define COPENGLTEST_GAMEOBJECT_H

#include <glad/glad.h>
#include <unordered_map>
#include "Components/Mesh.h"
#include "Components/Component.h"


class GameObject {
public:
    explicit GameObject(Mesh& mesh);
    GameObject();

    void update();
    void setMesh(Mesh& mesh) { component_map[ComponentType::Mesh] = &mesh;}

    void addComponent(Component& component);

    template <ComponentType T>
    Component& getComponent();


private:
    std::unordered_map<ComponentType, Component*> component_map;
};

#endif  //COPENGLTEST_GAMEOBJECT_H
