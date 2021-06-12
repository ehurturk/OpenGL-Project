//
// Created by Emir Hürtürk on 5.06.2021.
//

#include "GameObject.h"
#include "Components/Component.h"
GameObject::GameObject(Mesh& mesh) { component_map[ComponentType::Mesh] = &mesh; }

GameObject::GameObject() {}

void GameObject::update()
{
    for (const std::pair<ComponentType, Component*>& component : component_map) {
        component.second->update();
    }
    glDrawArrays(GL_TRIANGLES, 0, ((Mesh*)component_map[ComponentType::Mesh])->getVertexCount()); // does this even work?
}

void GameObject::addComponent(Component& component)
{
    component_map[component.getComponentType()] = &component;
}

template <ComponentType T>
Component& GameObject::getComponent()
{
    return *component_map[T];
}


