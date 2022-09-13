#include "sportswin.h"

SportsWindow::SportsWindow(int w, int h, const char* title)
{
	glfwInit();

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    pGLFWwindow = glfwCreateWindow(w, h, title, NULL, NULL);

	if (pGLFWwindow == NULL)
		sports::error("sports error: create window failed!");

    this->width = w;
    this->height = h;
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