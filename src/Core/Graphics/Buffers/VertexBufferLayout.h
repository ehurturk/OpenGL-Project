//
// Created by Emir Hürtürk on 5.06.2021.
//

#pragma once
#include <iostream>
#include <vector>
#include <glad/glad.h>

struct VertexBufferLayoutElement {
    unsigned int type;
    unsigned int count;
    unsigned int normalized;

    static unsigned int getSizeOfType(unsigned int type) {
        switch (type) {
        case GL_FLOAT: return 4;
        case GL_UNSIGNED_INT: return 4;
        case GL_UNSIGNED_BYTE: return 1;
        }
        return 0;
    }
};

class VertexBufferLayout {
  private:
    std::vector<VertexBufferLayoutElement> elements;
    unsigned int stride = 0;

  public:

    template<typename T>
    void push(unsigned int count, unsigned int normalized) { }

    template<>
    void push<float>(unsigned int count, unsigned int normalized)
    {
        stride += sizeof(float) * count;
        elements.push_back({ GL_FLOAT, count, normalized });
    }

    template<>
    void push<unsigned int>(unsigned int count, unsigned int normalized)
    {
        stride += sizeof(unsigned int) * count;
        elements.push_back({ GL_UNSIGNED_INT, count, normalized });
    }

    template<>
    void push<unsigned char>(unsigned int count, unsigned int normalized)
    {
        stride += sizeof(unsigned char) * count;
        elements.push_back({ GL_UNSIGNED_BYTE, count, normalized });
    }

    inline const std::vector<VertexBufferLayoutElement> getVertexBufferLayoutElements() const& { return elements; }
    inline unsigned int getStride() const { return stride; }
};