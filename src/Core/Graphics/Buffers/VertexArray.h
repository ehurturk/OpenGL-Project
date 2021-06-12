//
// Created by Emir Hürtürk on 5.06.2021.
//

#pragma once
#include <iostream>
#include "VertexBufferLayout.h"
#include "VertexBuffer.h"

class VertexArray {
  private:
    unsigned int m_RendererId;
  public:

    VertexArray();
    ~VertexArray();


    void addBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    // TODO: Try to prove that when reference is not used, the class is copied! Try to output the adresses to find out.

    void bind() const;
    void unbind() const;

};