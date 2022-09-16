/* ************************************************************************
 *
 * Copyright (C) 2022 Vincent Luo All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * ************************************************************************/

/* Creates on 2022/9/16. */
#include "OpenGLBuffers.h"

#include <glad/glad.h>

/////////////////////////////////////////////////////
// OpenGLVertexBuffer Implements.
/////////////////////////////////////////////////////
OpenGLVertexBuffer::OpenGLVertexBuffer(unsigned int size, float* pVertices)
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, size, pVertices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);

    this->UnBind();
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}

void OpenGLVertexBuffer::Bind()
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_VERTEX_ARRAY, VBO);
}

void OpenGLVertexBuffer::UnBind()
{
    glBindBuffer(GL_VERTEX_ARRAY, 0);
    glBindVertexArray(0);
}

/////////////////////////////////////////////////////
// OpenGLIndexBuffer Implements.
/////////////////////////////////////////////////////
OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int size, unsigned int* pIndices)
{
    this->count = size / sizeof(int);

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, pIndices, GL_STATIC_DRAW);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
    glDeleteBuffers(1, &EBO);
}

void OpenGLIndexBuffer::Bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
}

void OpenGLIndexBuffer::UnBind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

int OpenGLIndexBuffer::GetCount()
{
    return this->count;
}
