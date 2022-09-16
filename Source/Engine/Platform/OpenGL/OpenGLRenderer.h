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
#pragma once

#include "Renderer/StandardRenderer.h"
#include "Window/SportsWindow.h"

class OpenGLRenderCommand : public StandardRenderCommand {
public:
    OpenGLRenderCommand();
    ~OpenGLRenderCommand();

    void            SetClearColor(float r, float g, float b, float a) override;
    void            ClearColorBuffer() override;
    void            BindShaderModule(SportsShaderModule shaderModule) override;
    void            DrawArray(SportsVertexBuffer vertexBuffer) override;
    void            DrawIndexed(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer) override;
};

class OpenGLRenderer : public StandardRenderer {
public:
    OpenGLRenderer(SportsWindow* sportswin);
    ~OpenGLRenderer();

    void            BeginNewFrame() override;
    void            EndNewFrame() override;
    void            DrawArray(SportsVertexBuffer vertexBuffer) override;
    void            DrawIndex(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer) override;

private:
    SportsWindow*                       pSportsWindow;
};

class OpenGLAllocate : public StandardAllocate {
public:
    OpenGLAllocate();
    ~OpenGLAllocate();

    void            CreateVertexBuffer(unsigned long size, float* pVertices, SportsVertexBuffer* pSportsVertexBuffer) override;
    void            DestroyVertexBuffer(SportsVertexBuffer vertexBuffer) override;
    void            CreateIndexBuffer(unsigned long size, unsigned int* pIndices, SportsIndexBuffer* pSportsIndexBuffer) override;
    void            DestroyIndexBuffer(SportsIndexBuffer indexBuffer) override;
    void            CreateShaderModule(const char *vertfile, const char *fragfile, SportsShaderModule* pSportsShaderModule) override;
    void            DestroyShaderModule(SportsShaderModule shaderModule) override;
};