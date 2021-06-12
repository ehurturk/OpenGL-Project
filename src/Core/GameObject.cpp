//
// Created by Emir Hürtürk on 5.06.2021.
//

#include "GameObject.h"
GameObject::GameObject(Mesh &mesh): mesh(&mesh) { }

GameObject::GameObject() {}

void GameObject::update() {
    mesh->update();
    for (Component* component: components) {
        component->update();
    }
    glDrawArrays(GL_TRIANGLES, 0, mesh->getVertexCount());
}

void GameObject::addComponent(Component& component)
{
    components.push_back(&component);
}
