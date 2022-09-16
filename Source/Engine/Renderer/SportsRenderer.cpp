#include "SportsRenderer.h"

#include "Platform/OpenGL/OpenGLRenderer.h"

/////////////////////////////////////////////////////
// Static Standard Define.
/////////////////////////////////////////////////////
static StandardRenderer* s_StandardRenderer = NULL;
#define ASSTER_STANDARD_RENDERER() SPORTS_ASSERTS(s_StandardRenderer != NULL)

static StandardRenderCommand* s_StandardRenderCommand = NULL;
#define ASSTER_STANDARD_RENDER_COMMAND() SPORTS_ASSERTS(s_StandardRenderCommand != NULL)

static StandardAllocate* s_StandardAllocate = NULL;
#define ASSTER_STANDARD_ALLOCATER() SPORTS_ASSERTS(s_StandardAllocate != NULL)

/////////////////////////////////////////////////////
// SportsRenderCommand Implements.
/////////////////////////////////////////////////////
void SportsRenderCommand::SetClearColor(float r, float g, float b, float a)
{
    ASSTER_STANDARD_RENDER_COMMAND();
    s_StandardRenderCommand->SetClearColor(r, g, b, a);
}

void SportsRenderCommand::ClearColorBuffer()
{
    ASSTER_STANDARD_RENDER_COMMAND();
    s_StandardRenderCommand->ClearColorBuffer();
}

void SportsRenderCommand::BindShaderModule(SportsShaderModule shaderModule)
{
    ASSTER_STANDARD_RENDER_COMMAND();
    s_StandardRenderCommand->BindShaderModule(shaderModule);
}

void SportsRenderCommand::DrawArray(SportsVertexBuffer vertexBuffer)
{
    ASSTER_STANDARD_RENDER_COMMAND();
    s_StandardRenderCommand->DrawArray(vertexBuffer);
}

void SportsRenderCommand::DrawIndexed(SportsVertexBuffer vertexBuffer, SportsIndexBuffer indexBuffer)
{
    ASSTER_STANDARD_RENDER_COMMAND();
    s_StandardRenderCommand->DrawIndexed(vertexBuffer, indexBuffer);
}

/////////////////////////////////////////////////////
// SportsRenderer Implements.
/////////////////////////////////////////////////////
void SportsRenderer::InitRenderer(SportsRendererInitializeInfo *pSportsRendererInitializeInfo)
{
    switch (pSportsRendererInitializeInfo->renderAPI) {
        case SportsRenderAPI::OpenGL: {
            s_StandardRenderer = new OpenGLRenderer(pSportsRendererInitializeInfo->pSportsWindow);
            s_StandardRenderCommand = new OpenGLRenderCommand();
            s_StandardAllocate = new OpenGLAllocate();
            return;
        }
        default:
            sports::runtime_error("Sports Error: not support none api");
    }
}

void SportsRenderer::TerminateRenderer()
{
    ASSTER_STANDARD_RENDERER();
    delete s_StandardRenderer;
    s_StandardRenderer = NULL;

    ASSTER_STANDARD_RENDER_COMMAND();
    delete s_StandardRenderCommand;
    s_StandardRenderCommand = NULL;

    ASSTER_STANDARD_ALLOCATER();
    delete s_StandardAllocate;
    s_StandardAllocate = NULL;
}

void SportsRenderer::BeginNewFrame()
{
    ASSTER_STANDARD_RENDERER();
    s_StandardRenderer->BeginNewFrame();
}

void SportsRenderer::EndNewFrame()
{
    ASSTER_STANDARD_RENDERER();
    s_StandardRenderer->EndNewFrame();
}

/////////////////////////////////////////////////////
// StandardAllocater Implements.
/////////////////////////////////////////////////////
void SportsRenderer::CreateVertexBuffer(unsigned long size, float *pVertices, SportsVertexBuffer *pSportsVertexBuffer)
{
    ASSTER_STANDARD_ALLOCATER();
    s_StandardAllocate->CreateVertexBuffer(size, pVertices, pSportsVertexBuffer);
}

void SportsRenderer::DestroyVertexBuffer(SportsVertexBuffer vertexBuffer)
{
    ASSTER_STANDARD_ALLOCATER();
    s_StandardAllocate->DestroyVertexBuffer(vertexBuffer);
}

void SportsRenderer::CreateIndexBuffer(unsigned long size, unsigned int *pIndices, SportsIndexBuffer *pSportsIndexBuffer)
{
    ASSTER_STANDARD_ALLOCATER();
    s_StandardAllocate->CreateIndexBuffer(size, pIndices, pSportsIndexBuffer);
}

void SportsRenderer::DestroyIndexBuffer(SportsIndexBuffer indexBuffer)
{
    ASSTER_STANDARD_ALLOCATER();
    s_StandardAllocate->DestroyIndexBuffer(indexBuffer);
}

void SportsRenderer::CreateShaderModule(const char *vertfile, const char *fragfile, SportsShaderModule *pSportsShaderModule)
{
    ASSTER_STANDARD_ALLOCATER();
    s_StandardAllocate->CreateShaderModule(vertfile, fragfile, pSportsShaderModule);
}

void SportsRenderer::DestroyShaderModule(SportsShaderModule shaderModule)
{
    ASSTER_STANDARD_ALLOCATER();
    s_StandardAllocate->DestroyShaderModule(shaderModule);
}