//
// Created by Emir Hürtürk on 5.06.2021.
//

#ifndef COPENGLTEST_MESH_H
#define COPENGLTEST_MESH_H

#include "../Graphics/Buffers/VertexArray.h"
#include "../Graphics/Buffers/VertexBuffer.h"
#include "../Graphics/Buffers/VertexBufferLayout.h"
#include "../Graphics/Shader.h"

#include "Component.h"

// Buffers:

// EXPECTATION:
/*
    Mesh mesh = Mesh::createMeshFromVertices(vertices, sizeof(vertices));
    Shader shader(".vs", ".fs");
    mesh.setShader(shader);
    Texture texture(".png");
    mesh.setTexture(texture);

    GameObject* go = new GameObject(mesh);
    gameObjects.push_back(go);
*/

/*  for (GameObject* go: gameObjects) {
         go.update(); == mesh.shader.use(); mesh.vao.bind(); glDrawArrays(GL_TRIANGLES_0, mesh.vertexCount);
     }
 */

class Mesh : public Component {
public:
    static Mesh &createMeshFromVertices(float *data, unsigned int sizeOfData)
    {
        auto *vao = new VertexArray();
        //VertexArray vao{}; // I guess it needs to be a pointer since the object is destroyed at the end of this function.
        // TODO: 1) Don't declare the vao here, instead use the already declared VAO and then assign it. No need for a parameter to constructor.
        VertexBuffer vbo(data, sizeOfData);
        VertexBufferLayout layout;

        layout.push<float>(3, false);

        vao->addBuffer(vbo, layout);
        vbo.unbind();
        vao->unbind();

        int vertexCount = sizeOfData / layout.getStride();

        Mesh *mesh = new Mesh(vao, vertexCount);
        return *mesh;
    }

    void setShader(Shader &_shader) { shader = _shader; }

    Shader &getShader() { return shader; }
    VertexArray &getGeometry() { return *vao; }
    int getVertexCount() const { return vertexCount; }

    void update() override
    {
        shader.use();
        vao->bind();
    }

    ComponentType& getComponentType() override { return componentType; }

    Mesh() = default;

private:
    VertexArray *vao;
    Shader shader;
    int vertexCount;

    ComponentType componentType = ComponentType::Mesh;
    explicit Mesh(VertexArray *_vao, int vCount) : vao(_vao), vertexCount(vCount), shader() {}
};

#endif  //COPENGLTEST_MESH_H
