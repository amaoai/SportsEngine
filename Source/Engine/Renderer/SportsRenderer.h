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

/* Creates on 2022/9/14. */
#pragma once

#include <Sports.h>
#include "Window/SportsWindow.h"
#include "Renderer/SportsBuffers.h"

/* 所有支持的渲染 API 枚举 */
enum SportsRenderAPI {
    OpenGL,
    Vulkan,
    DirectX,
};

/* 渲染器 */
class SportsRenderer {
public:
    virtual        ~SportsRenderer() {};
                                       
    virtual void    BeginNewFrame() = 0;
    virtual void    EndNewFrame() = 0;
    virtual void    SetClearColor(float r, float g, float b, float a) = 0;
    virtual void    ClearColorBuffer() = 0;

public:
    static SportsVertexBuffer *CreateVertexBuffer(unsigned long size, float* pVertices); /* create vertex buffer */
    static void DestroyVertexBuffer(SportsVertexBuffer* pSportsVertexBuffer);
    static SportsIndexBuffer *CreateIndexBuffer(unsigned long size, unsigned int* pIndices);  /* create index buffer */
    static void DestroyIndexBuffer(SportsIndexBuffer* pSportsIndexBuffer);
};

extern SportsRenderer* SportsCreateRenderer(SportsWindow* pSportsWindow);
extern void SportsDestroyRenderer(SportsRenderer* pSportsRenderer);