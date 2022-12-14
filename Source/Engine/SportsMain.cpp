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
#include <iostream>
#include "Renderer/SportsRenderer.h"
#include <imgui.h>
#include "ImGui/ImGuiRenderer.h"

int main()
{
    auto sportswin = new SportsWindow(800, 600, "sports");

    SportsRendererInitializeInfo sportsRendererInitializeInfo = {};
    sportsRendererInitializeInfo.renderAPI = SportsRenderAPI::OpenGL;
    sportsRendererInitializeInfo.pSportsWindow = sportswin;

    SportsRenderer::InitRenderer(&sportsRendererInitializeInfo);

    ImGuiRenderer::InitImGuiRenderer(sportswin);

    float vertices[] = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };

    unsigned int indices[] = {
        0, 1, 3,
        1, 2, 3
    };

    SportsVertexBuffer vertexBuffer;
    SportsRenderer::CreateVertexBuffer(sizeof(vertices), vertices, &vertexBuffer);

    SportsIndexBuffer indexBuffer;
    SportsRenderer::CreateIndexBuffer(sizeof(indices), indices, &indexBuffer);

    SportsShaderModule simpleShaderModule;
    SportsRenderer::CreateShaderModule("../Shaders/SimpleShader.vert", "../Shaders/SimpleShader.frag", &simpleShaderModule);

    bool showDemoWindow = true;
    while (!sportswin->ShouldClose()) {
        SportsPollEvents();

        SportsRenderer::BeginNewFrame();
        {
            ImGuiRenderer::BeginImGuiNewFrame();
            ImGui::ShowDemoWindow(&showDemoWindow);
            ImGuiRenderer::EndImGuiNewFrame();

            SportsRenderCommand::ClearColor(0.0f, 0.2f, 0.4f, 0.0f);
            SportsRenderCommand::ClearColorBuffer();
            SportsRenderCommand::BindShaderModule(simpleShaderModule);
            SportsRenderCommand::DrawIndexed(vertexBuffer, indexBuffer);
        }
        SportsRenderer::EndNewFrame();

        sportswin->SwapBuffers();
    }

    SportsRenderer::TerminateRenderer();
    delete sportswin;
    SportsTerminate();

    return 0;
}