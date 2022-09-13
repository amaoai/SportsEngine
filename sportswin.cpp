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
#include "sportswin.h"

SportsWindow::SportsWindow(int w, int h, const char* title) : width(w), height(h)
{
	glfwInit();

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    pGLFWwindow = glfwCreateWindow(w, h, title, NULL, NULL);
    glfwSetWindowUserPointer(pGLFWwindow, this);

	if (pGLFWwindow == NULL)
		sports::error("sports error: create window failed!");
}

SportsWindow::~SportsWindow()
{
	glfwDestroyWindow(pGLFWwindow);
}

void SportsWindow::SetWindowSize(int w, int h)
{
    w < 0 ? this->width = 0 : this->width = w;
    h < 0 ? this->height = 0 : this->height = h;

    glfwSetWindowSize(pGLFWwindow, w, h);
}

void SportsWindow::SetWindowResizeCallback(SportsfnSetWindowResizeCallback callback)
{
    this->sportsfnSetWindowResizeCallback = callback;

    glfwSetWindowSizeCallback(pGLFWwindow, [](GLFWwindow *glfWwindow, int w, int h) {
        SportsWindow *sportswin = (SportsWindow *) glfwGetWindowUserPointer(glfWwindow);
        sportswin->sportsfnSetWindowResizeCallback(sportswin, w, h);
    });
}

void SportsWindow::SetFramebufferCallback(SportsfnSetFramebufferCallback callback)
{
	this->sportsfnSetFramebufferCallback = callback;

	glfwSetWindowSizeCallback(pGLFWwindow, [](GLFWwindow* glfWwindow, int w, int h) {
		SportsWindow* sportswin = (SportsWindow*)glfwGetWindowUserPointer(glfWwindow);
		sportswin->sportsfnSetFramebufferCallback(sportswin, w, h);
	});
}