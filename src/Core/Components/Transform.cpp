#include "Transform.h"

#include <iostream>
#include "glm/ext/matrix_transform.hpp"
#include "glm/fwd.hpp"

Transform::Transform() : position(glm::vec3(0.0f, 0.0f, 0.0f)), rotation(glm::vec3(0.0f, 0.0f, 0.0f)), scale(glm::vec3(0.0f, 0.0f, 0.0f)), model(glm::mat4(1.0f))
{
    id   = "Transform";
    type = ComponentType::Transform;
}

Transform::~Transform() { std::cout << "Freeing the transform component.\n"; }

void Transform::update()
{
    // the transform update logic.
    // pass the model matrix to the shader.
    // somehow, the shader must know the model matrix.
}

void Transform::setPosition(glm::vec3& position)
{
    this->position = position;
}

void Transform::setPosition(float x, float y, float z)
{
    position = glm::vec3(x, y, z);
}

void Transform::setRotation(float x, float y, float z)
{
    rotation = glm::vec3(x, y, z);
}

void Transform::setRotation(glm::vec3& rotation)
{
    this->rotation = rotation;
}

void Transform::setScale(float x, float y, float z)
{
    scale = glm::vec3(x, y, z);
}

void Transform::setScale(glm::vec3& scale)
{
    this->scale = scale;
}

void Transform::translate(glm::vec3& amount)
{
    model = glm::translate(model, amount);
}

void Transform::translate(float x, float y, float z)
{
    model = glm::translate(model, {x, y, z});
}