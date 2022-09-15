#include "SportsRenderer.h"

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