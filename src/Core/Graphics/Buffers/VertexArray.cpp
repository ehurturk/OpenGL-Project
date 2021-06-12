//
// Created by Emir Hürtürk on 5.06.2021.
//


#include <iostream>
#include <glad/glad.h>

#include "VertexArray.h"


VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_RendererId);
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &m_RendererId);
}

void VertexArray::addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout) {
    std::cout << &vb << std::endl;
    // we are passing as a reference, otherwise it copies into another memory, which we can't alter the actual class.
    bind();
    vb.bind();
    const auto& elements = layout.getVertexBufferLayoutElements();
    unsigned int offset = 0;
    for (unsigned int i = 0; i < elements.size(); i++) {
        const auto& element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.getStride(), (const void*)offset);

        offset += element.count * VertexBufferLayoutElement::getSizeOfType(element.type);

    }

}

void VertexArray::bind() const{
    glBindVertexArray(m_RendererId);
}

void VertexArray::unbind() const {
    glBindVertexArray(0);
}