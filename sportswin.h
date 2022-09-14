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
#pragma once

#include "tools/logs.h"
#include <GLFW/glfw3.h>

#define SportsPollEvents() glfwPollEvents()
#define SportsTerminate() glfwTerminate()

class SportsWindow;

/* window resize callback */
typedef void (*SportsfnSetWindowResizeCallback) (SportsWindow *sportswin, int w, int h);
/* window framebuffer callback */
typedef void (*SportsfnSetFramebufferCallback) (SportsWindow *sportswin, int w, int h);

class SportsWindow {
public:
    SportsWindow(int w, int h, const char *title);
    ~SportsWindow();

    void            SetWindowSize(int w, int h);
    void            SetWindowResizeCallback(SportsfnSetWindowResizeCallback callback);
    void            SetFramebufferCallback(SportsfnSetFramebufferCallback callback);

    bool            GetKey(int key)     { return glfwGetKey(pGLFWwindow, key); }
    bool            ShouldClose()       { return glfwWindowShouldClose(pGLFWwindow); }
    int             GetWidth()          { return width; }
    int             GetHeight()         { return height; }
    GLFWwindow*     GetHandle()         { return pGLFWwindow; }
    void            SwapBuffers()       { glfwSwapBuffers(pGLFWwindow); }

private:
	int                                 width;
	int                                 height;
	GLFWwindow* pGLFWwindow;
    SportsfnSetWindowResizeCallback     sportsfnSetWindowResizeCallback;
    SportsfnSetFramebufferCallback      sportsfnSetFramebufferCallback;
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

inline static const char **SportsGetRequiredInstanceExtensions(uint32_t *p_size)
{
    return glfwGetRequiredInstanceExtensions(p_size);
}

#endif

/* if define opengl */
#if defined(GL_VERSION_1_1)

inline static void SportsMakeContextCurrent(SportsWindow *pSportsWindow)
{
    glfwMakeContextCurrent(pSportsWindow->GetHandle());
}

#endif