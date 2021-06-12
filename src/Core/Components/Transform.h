#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Component.h"


// Transform must interfere the model matrix to apply all the matrix operations in the model matrix.
// Each object must have their own model matrix, and thr camera must take those matrices and multiply with the vp.

// Both the view matrix and the projection matrix are global, and shared between all objects.

// Transform can hold the model matrix, to ease the manipulation of vertices.

class Transform: public Component
{
public:
    Transform();
    ~Transform();

    void update() override;

    void setPosition(glm::vec3& newPos);

    inline glm::vec3& getPosition() { return position; }
    inline glm::vec3& getRotation() { return rotation; }
    inline glm::vec3& getScale() { return scale; }

    ComponentType& getComponentType() override { return componentType; }

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;
 
    glm::mat4 model;

    ComponentType componentType = ComponentType::Transform;
};
