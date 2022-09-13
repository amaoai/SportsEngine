#include "sportswin.h"

SportsWindow::SportsWindow(int w, int h, const char* title)
{
	glfwInit();

	glfwWindowHint(GLFW_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	pWindow = glfwCreateWindow(w, h, title, NULL, NULL);

	if (pWindow == NULL)
		sports::error("sports error: create window failed!");
}

SportsWindow::~SportsWindow()
{
	glfwDestroyWindow(pWindow);
}