//
// Created by Emir Hürtürk on 5.06.2021.
//

#pragma once

#include <iostream>
class VertexBuffer {
  private:
    unsigned int m_RendererId;
  public:
    VertexBuffer(const void* data, unsigned int size);
    ~VertexBuffer();

    void bind() const;
    void unbind() const;
};