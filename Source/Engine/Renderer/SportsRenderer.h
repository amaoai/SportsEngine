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
#include "StandardRenderer.h"

/*! @brief 所有支持的渲染 API 枚举
 */
enum SportsRenderAPI {
    OpenGL,
    Vulkan,
    DirectX,
};

/*! @brief 渲染命令
 * 
 *   需要在 SportsRenderer::BeginNewFrame() 和 SportsRenderer::EndNewFrame() 的作用
 * 范围内调用渲染命令才得以生效。
 */
class SportsRenderCommand {
public:
    static void     SetClearColor(float r, float g, float b, float a);
    static void     ClearColorBuffer();
    static void     BindShaderModule(SportsShaderModule shaderModule);
    static void     DrawArray(SportsVertexBuffer vertexBuffer);
};

/*! @brief 渲染器初始化结构体
 */
struct SportsRendererInitializeInfo {
    SportsRenderAPI renderAPI;
    SportsWindow*   pSportsWindow;
};

/*! @brief 渲染器
 */
class SportsRenderer {
public:
    static void     InitRenderer(SportsRendererInitializeInfo *pSportsRendererInitializeInfo); /* 初始化渲染器，指定图形API */
    static void     TerminateRenderer(); /* 销毁渲染器 */

    static void     BeginNewFrame();
    static void     EndNewFrame();

public:
    static void     CreateVertexBuffer(unsigned long size, float* pVertices, SportsVertexBuffer* pSportsVertexBuffer); /* create vertex buffer */
    static void     DestroyVertexBuffer(SportsVertexBuffer vertexBuffer);
    static void     CreateIndexBuffer(unsigned long size, unsigned int* pIndices, SportsIndexBuffer* pSportsIndexBuffer);  /* create index buffer */
    static void     DestroyIndexBuffer(SportsIndexBuffer indexBuffer);
    static void     CreateShaderModule(const char* vertfile, const char* fragfile, SportsShaderModule* pSportsShaderModule); /* create shader module */
    static void     DestroyShaderModule(SportsShaderModule shaderModule);
};
