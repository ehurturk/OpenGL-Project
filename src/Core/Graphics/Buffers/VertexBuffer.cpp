//
// Created by Emir Hürtürk on 5.06.2021.
//

#include "VertexBuffer.h"
#include <glad/glad.h>

void VertexBuffer::unbind() const {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

VertexBuffer::~VertexBuffer() {
    glDeleteBuffers(1, &m_RendererId);
}

void VertexBuffer::bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
}

VertexBuffer::VertexBuffer(const void* data, unsigned int size) {
    glGenBuffers(1, &m_RendererId);
    glBindBuffer(GL_ARRAY_BUFFER, m_RendererId);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}