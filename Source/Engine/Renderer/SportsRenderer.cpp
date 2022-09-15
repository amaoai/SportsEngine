#include "SportsRenderer.h"

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
    s_StandardRenderCommand->SetClearColor(r, g, b, a);
}

void SportsRenderCommand::ClearColorBuffer()
{
    s_StandardRenderCommand->ClearColorBuffer();
}

/////////////////////////////////////////////////////
// SportsRenderer Implements.
/////////////////////////////////////////////////////

void SportsRenderer::InitRenderer(SportsRendererInitializeInfo *pSportsRendererInitializeInfo)
{

}

void SportsRenderer::BeginNewFrame()
{
    s_StandardRenderer->BeginNewFrame();
}

void SportsRenderer::EndNewFrame()
{
    s_StandardRenderer->EndNewFrame();
}

void SportsRenderer::DrawArray(SportsVertexBuffer vertexBuffer)
{
    s_StandardRenderer->DrawArray(vertexBuffer);
}

void SportsRenderer::DrawIndex(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer)
{
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