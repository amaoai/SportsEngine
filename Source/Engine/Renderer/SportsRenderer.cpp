#include "SportsRenderer.h"

SportsVertexBuffer* SportsRenderer::CreateVertexBuffer(unsigned long size, float* pVertices)
{
    return NULL;
}

void SportsRenderer::DestroyVertexBuffer(SportsVertexBuffer* pSportsVertexBuffer)
{
    delete pSportsVertexBuffer;
}

SportsIndexBuffer* SportsRenderer::CreateIndexBuffer(unsigned long size, unsigned int* pIndices)
{
    return NULL;
}

void SportsRenderer::DestroyIndexBuffer(SportsIndexBuffer* pSportsIndexBuffer)
{
    delete pSportsIndexBuffer;
}

SportsRenderer* SportsCreateRenderer(SportsWindow* pSportsWindow)
{
    return NULL;
}

void SportsDestroyRenderer(SportsRenderer *pSportsRenderer)
{
    delete pSportsRenderer;
}
