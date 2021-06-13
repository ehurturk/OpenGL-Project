//
// Created by Emir Hürtürk on 5.06.2021.
//

#include "GameObject.h"
#include <memory>
#include "Components/Component.h"
GameObject::GameObject(Mesh& mesh) { component_map[ComponentType::Mesh] = &mesh; }

GameObject::GameObject() {}

GameObject::~GameObject()
{
    // delete the component pointer of the map.
    std::cout << "deleting\n";
    for (auto& it : component_map) {
        delete it.second;
    }
    component_map.clear();
}

void GameObject::update()
{
    for (auto& it: component_map) {
        it.second->update();
    }
    glDrawArrays(GL_TRIANGLES, 0, static_cast<Mesh*>(component_map[ComponentType::Mesh])->getVertexCount()); // does this even work?
}

void GameObject::addComponent(Component& component)
{
    component_map[component.getComponentType()] = &component;
}


