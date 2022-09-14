#include "renderer.h"

#include "platform/opengl/opengl_renderer.h"
#include "platform/vulkan/vulkan_renderer.h"

SportsRenderer* SportsCreateRenderer(SportsWindow* pSportsWindow)
{
	return new OpenGLRenderer(pSportsWindow);
}