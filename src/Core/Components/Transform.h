#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Component.h"

// Transform must interfere the model matrix to apply all the matrix operations in the model matrix.
// Each object must have their own model matrix, and thr camera must take those matrices and multiply with the vp.

// Both the view matrix and the projection matrix are global, and shared between all objects.

// Transform can hold the model matrix, to ease the manipulation of vertices.

class Transform : public Component {
public:
    Transform();
    ~Transform() override;

    void update() override;

    inline glm::vec3& getPosition() { return position; }
    inline glm::vec3& getRotation() { return rotation; }
    inline glm::vec3& getScale() { return scale; }

    inline glm::mat4 getModelMatrix() { return model; }

    void setPosition(float x, float y, float z);
    void setPosition(glm::vec3& position);

    void setRotation(float x, float y, float z);
    void setRotation(glm::vec3& rotation);

    void setScale(float x, float y, float z);
    void setScale(glm::vec3& scale);

    void translate(glm::vec3& amount);
    void translate(float x, float y, float z);

private:
    glm::vec3 position;
    glm::vec3 rotation;
    glm::vec3 scale;

    glm::mat4 model;
};
