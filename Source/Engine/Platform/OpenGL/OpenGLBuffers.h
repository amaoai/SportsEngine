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
#ifndef SPORTSENGINE_OPENGLBUFFERS_H
#define SPORTSENGINE_OPENGLBUFFERS_H

#include "Renderer/SportsBuffers.h"

class OpenGLVertexBuffer : public SportsVertexBuffer_T {
public:
    OpenGLVertexBuffer(unsigned int size, float *pVertices);
    ~OpenGLVertexBuffer();

    void            Bind() override;
    void            UnBind() override;

private:
    unsigned int                        VAO;
    unsigned int                        VBO;
};

class OpenGLIndexBuffer : public SportsIndexBuffer_T {
public:
    OpenGLIndexBuffer(unsigned int size, unsigned int* pIndices);
    ~OpenGLIndexBuffer();

    void            Bind() override;
    void            UnBind() override;
    int             GetCount() override;

private:
    int                                 count;
    unsigned int                        EBO;
};

#endif /* SPORTSENGINE_OPENGLBUFFERS_H */
