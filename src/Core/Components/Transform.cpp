#include "Transform.h"

#include <iostream>


Transform::Transform() : position(glm::vec3(0.0f, 0.0f, 0.0f)), rotation(glm::vec3(0.0f, 0.0f, 0.0f)), scale(glm::vec3(0.0f, 0.0f, 0.0f)),
                         model(glm::mat4(1.0f))

{
    id = "Transform";
    type = ComponentType::Transform;
}

Transform::~Transform() { std::cout << "Freeing the transform component.\n"; }

void Transform::update()
{
    // the transform update logic.
    // idk what is going on here.
}

void Transform::setPosition(glm::vec3 &newPos)
{
    position = newPos;
}
