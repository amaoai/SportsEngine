#include "SportsRenderer.h"

#include "Platform/OpenGL/OpenGLStandardRenderer.h"

/////////////////////////////////////////////////////
// Static Standard Define.
/////////////////////////////////////////////////////
static StandardRenderer* s_StandardRenderer = NULL;
static StandardRenderCommand* s_StandardRenderCommand = NULL;

/////////////////////////////////////////////////////
// SportsRenderCommand Implements.
/////////////////////////////////////////////////////
void SportsRenderCommand::SetClearColor(float r, float g, float b, float a)
{
    SPORTS_ASSERTS(s_StandardRenderCommand != NULL);
    s_StandardRenderCommand->SetClearColor(r, g, b, a);
}

void SportsRenderCommand::ClearColorBuffer()
{
    SPORTS_ASSERTS(s_StandardRenderCommand != NULL);
    s_StandardRenderCommand->ClearColorBuffer();
}

/////////////////////////////////////////////////////
// SportsRenderer Implements.
/////////////////////////////////////////////////////

void SportsRenderer::InitRenderer(SportsRendererInitializeInfo *pSportsRendererInitializeInfo)
{
    switch (pSportsRendererInitializeInfo->renderAPI) {
        case SportsRenderAPI::OpenGL: {
            s_StandardRenderer = new OpenGLStandardRenderer(pSportsRendererInitializeInfo->pSportsWindow);
            s_StandardRenderCommand = new OpenGLStandardRenderCommand();
            return;
        }
        default:
            sports::runtime_error("Sports Error: not support none api");
    }
}

void SportsRenderer::BeginNewFrame()
{
    SPORTS_ASSERTS(s_StandardRenderer != NULL);
    s_StandardRenderer->BeginNewFrame();
}

void SportsRenderer::EndNewFrame()
{
    SPORTS_ASSERTS(s_StandardRenderer != NULL);
    s_StandardRenderer->EndNewFrame();
}

void SportsRenderer::DrawArray(SportsVertexBuffer vertexBuffer)
{
    SPORTS_ASSERTS(s_StandardRenderer != NULL);
    s_StandardRenderer->DrawArray(vertexBuffer);
}

void SportsRenderer::DrawIndex(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer)
{
    SPORTS_ASSERTS(s_StandardRenderer != NULL);
    s_StandardRenderer->DrawIndex(vertexBuffer, indexBuffer);
}

void SportsRenderer::CreateVertexBuffer(unsigned long size, float *pVertices, SportsVertexBuffer *pSportsVertexBuffer)
{
}

void SportsRenderer::DestroyVertexBuffer(SportsVertexBuffer vertexBuffer)
{
    delete vertexBuffer;
}

void SportsRenderer::CreateIndexBuffer(unsigned long size, unsigned int *pIndices, SportsIndexBuffer *pSportsIndexBuffer)
{

}

void SportsRenderer::DestroyIndexBuffer(SportsIndexBuffer indexBuffer)
{
    delete indexBuffer;
}

void SportsRenderer::CreateShaderModule(const char *filename, SportsShaderModule *pSportsShaderModule)
{

}

void SportsRenderer::DestroyShaderModule(SportsShaderModule shaderModule)
{
    delete shaderModule;
}