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
#ifndef SPORTSENGINE_STANDARDRENDERER_H
#define SPORTSENGINE_STANDARDRENDERER_H

#include <Sports.h>

SPORTS_DEFINE_HANDLE(SportsVertexBuffer)
SPORTS_DEFINE_HANDLE(SportsIndexBuffer)
SPORTS_DEFINE_HANDLE(SportsShaderModule)

enum SportsPolygonMode {
    SPORTS_POLYGON_MODE_FILL,
    SPORTS_POLYGON_MODE_LINE
};

/*! @brief 标准渲染渲染命令定义
 *
 */
class StandardRenderCommand {
public:
    virtual void    ClearColor(float r, float g, float b, float a) = 0;
    virtual void    ClearColorBuffer() = 0;
    virtual void    BindShaderModule(SportsShaderModule shaderModule) = 0;
    virtual void    PolygonMode(SportsPolygonMode polygonMode) = 0;
    virtual void    DrawArray(SportsVertexBuffer vertexBuffer) = 0;
    virtual void    DrawIndexed(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer) = 0;
};

/*! @brief 标准渲染器函数定义
 */
class StandardRenderer {
public:
    virtual void    BeginNewFrame() = 0;
    virtual void    EndNewFrame() = 0;
    virtual void    DrawArray(SportsVertexBuffer vertexBuffer) = 0;
    virtual void    DrawIndex(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer) = 0;
};

/*! @brief 标准分配器，负责创建和销毁不同 API 的缓冲区和对象
 */
class StandardAllocate {
public:
    virtual void    CreateVertexBuffer(unsigned long size, float* pVertices, SportsVertexBuffer* pSportsVertexBuffer) = 0;
    virtual void    DestroyVertexBuffer(SportsVertexBuffer vertexBuffer) = 0;
    virtual void    CreateIndexBuffer(unsigned long size, unsigned int* pIndices, SportsIndexBuffer* pSportsIndexBuffer) = 0;
    virtual void    DestroyIndexBuffer(SportsIndexBuffer indexBuffer) = 0;
    virtual void    CreateShaderModule(const char *vertfile, const char *fragfile, SportsShaderModule* pSportsShaderModule) = 0;
    virtual void    DestroyShaderModule(SportsShaderModule shaderModule) = 0;
};

#endif /* SPORTSENGINE_STANDARDRENDERER_H */
