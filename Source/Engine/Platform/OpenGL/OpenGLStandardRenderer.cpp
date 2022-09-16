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
#include "OpenGLStandardRenderer.h"

/////////////////////////////////////////////////////
// OpenGLStandardRenderCommand Implements.
/////////////////////////////////////////////////////

OpenGLStandardRenderCommand::OpenGLStandardRenderCommand()
{

}

OpenGLStandardRenderCommand::~OpenGLStandardRenderCommand()
{

}

void OpenGLStandardRenderCommand::SetClearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}

void OpenGLStandardRenderCommand::ClearColorBuffer()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

/////////////////////////////////////////////////////
// OpenGLStandardRenderer Implements.
/////////////////////////////////////////////////////

OpenGLStandardRenderer::OpenGLStandardRenderer(SportsWindow *sportswin) : pSportsWindow(sportswin)
{
    SportsMakeContextCurrent(pSportsWindow);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        sports::runtime_error("Sports Error: GLAD load faileed");
}

OpenGLStandardRenderer::~OpenGLStandardRenderer()
{

}

void OpenGLStandardRenderer::BeginNewFrame()
{

}

void OpenGLStandardRenderer::EndNewFrame()
{

}

void OpenGLStandardRenderer::DrawArray(SportsVertexBuffer vertexBuffer)
{
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void OpenGLStandardRenderer::DrawIndex(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer)
{
    // glDrawElements(GL_TRIANGLES, )
}
