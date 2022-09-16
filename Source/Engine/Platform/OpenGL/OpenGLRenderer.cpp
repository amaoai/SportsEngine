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
#include <glad/glad.h>

#include "OpenGLRenderer.h"
#include "OpenGLBuffers.h"
#include "OpenGLShaderModule.h"

/////////////////////////////////////////////////////
// OpenGLRenderCommand Implements.
/////////////////////////////////////////////////////
OpenGLRenderCommand::OpenGLRenderCommand()
{

}

OpenGLRenderCommand::~OpenGLRenderCommand()
{

}

void OpenGLRenderCommand::SetClearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void OpenGLRenderCommand::ClearColorBuffer()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRenderCommand::BindShaderModule(SportsShaderModule shaderModule)
{
    shaderModule->Bind();
}

void OpenGLRenderCommand::DrawArray(SportsVertexBuffer vertexBuffer)
{
    vertexBuffer->Bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLRenderCommand::DrawIndexed(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer)
{
    vertexBuffer->Bind();
    indexBuffer->Bind();
    glDrawElements(GL_TRIANGLES, indexBuffer->GetCount(), GL_UNSIGNED_INT, 0);
}

/////////////////////////////////////////////////////
// OpenGLRenderer Implements.
/////////////////////////////////////////////////////
OpenGLRenderer::OpenGLRenderer(SportsWindow *sportswin) : pSportsWindow(sportswin)
{
    SportsMakeContextCurrent(pSportsWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        sports::runtime_error("Sports Error: GLAD load faileed");
}

OpenGLRenderer::~OpenGLRenderer()
{

}

void OpenGLRenderer::BeginNewFrame()
{

}

void OpenGLRenderer::EndNewFrame()
{

}

void OpenGLRenderer::DrawArray(SportsVertexBuffer vertexBuffer)
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLRenderer::DrawIndex(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer)
{
    // glDrawElements(GL_TRIANGLES, )
}

/////////////////////////////////////////////////////
// OpenGLAllocate Implements.
/////////////////////////////////////////////////////
OpenGLAllocate::OpenGLAllocate()
{

}

OpenGLAllocate::~OpenGLAllocate()
{

}

void OpenGLAllocate::CreateVertexBuffer(unsigned long size, float *pVertices,
                                        SportsVertexBuffer *pSportsVertexBuffer)
{
    *pSportsVertexBuffer = new OpenGLVertexBuffer(size, pVertices);
}

void OpenGLAllocate::DestroyVertexBuffer(SportsVertexBuffer vertexBuffer)
{
    delete vertexBuffer;
}

void OpenGLAllocate::CreateIndexBuffer(unsigned long size, unsigned int *pIndices,
                                       SportsIndexBuffer *pSportsIndexBuffer)
{
    *pSportsIndexBuffer = new OpenGLIndexBuffer(size, pIndices);
}

void OpenGLAllocate::DestroyIndexBuffer(SportsIndexBuffer indexBuffer)
{
    delete indexBuffer;
}

void OpenGLAllocate::CreateShaderModule(const char *vertfile, const char *fragfile,
                                        SportsShaderModule *pSportsShaderModule)
{
    *pSportsShaderModule = new OpenGLShaderModule(vertfile, fragfile);
}

void OpenGLAllocate::DestroyShaderModule(SportsShaderModule shaderModule)
{
    delete shaderModule;
}
