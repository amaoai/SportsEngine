#pragma once

#include "tools/logs.h"
#include <GLFW/glfw3.h>

#define SportsPollEvents() glfwPollEvents()
#define SportsTerminate() glfwTerminate();

class SportsWindow;

typedef void (*SportsfnSetWindowSizeCallback) (SportsWindow *sportswin, int w, int h);

class SportsWindow {
public:
    SportsWindow(int w, int h, const char *title);
    ~SportsWindow();

    void            SetWindowSize(int w, int h);
    void            SetWindowResizeCallback(SportsfnSetWindowSizeCallback callback);

    bool            GetKey(int key)     { return glfwGetKey(pGLFWwindow, key); }
    bool            ShouldClose()       { return glfwWindowShouldClose(pGLFWwindow); }
    int             GetWidth()          { return width; }
    int             GetHeight()         { return height; }
    GLFWwindow*     GetHandle()         { return pGLFWwindow; }

private:
    int                                 width;
    int                                 height;
    GLFWwindow*                         pGLFWwindow;
    SportsfnSetWindowSizeCallback       sportsfnSetWindowSizeCallback;
};

/* if define vulkan */
#if defined(VK_VERSION_1_0)

inline static VkResult SportsCreateSurfaceKHR(VkInstance instance, SportsWindow *pSportsWindow,
                                              VkSurfaceKHR *pSurfaceKHR)
{
    return glfwCreateWindowSurface(instance, pSportsWindow->GetHandle(),
                                   NULL,
                                   pSurfaceKHR);
}

#endif