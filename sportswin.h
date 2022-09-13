#pragma once

#include "tools/logs.h"
#include <GLFW/glfw3.h>

#define SportsPollEvents() glfwPollEvents()
#define SportsTerminate() glfwTerminate();

class SportsWindow {
public:
    SportsWindow(int w, int h, const char *title);
    ~SportsWindow();

    bool        ShouldClose()   { return glfwWindowShouldClose(pWindow); }
    int         GetWidth()      { return width; }
    int         GetHeight()     { return height; }
    GLFWwindow *GetHandle()     { return pWindow; }

private:
    int width;
    int height;
    GLFWwindow *pWindow;
};

/* define vulkan */
#if defined(VK_VERSION_1_0)

inline static VkResult SportsCreateSurfaceKHR(VkInstance instance, SportsWindow *pSportsWindow,
                                              VkSurfaceKHR *pSurfaceKHR)
{
    return glfwCreateWindowSurface(instance, pSportsWindow->GetHandle(),
                                   NULL,
                                   pSurfaceKHR);
}

#endif