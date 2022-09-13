#include <iostream>
#include "sportswin.h"

void SportsWindowResizeCallback(SportsWindow *sportswin, int w, int h)
{
	sports::info("resize callback: %d,%d\n", w, h);
}

int main()
{
	auto sportswin = new SportsWindow(800, 600, "sports");
	sportswin->SetWindowResizeCallback(SportsWindowResizeCallback);

	while (!sportswin->ShouldClose()) {
		SportsPollEvents();

        if (sportswin->GetKey(GLFW_KEY_A))
            sportswin->SetWindowSize(sportswin->GetWidth() + 1, sportswin->GetHeight() + 1);

        if (sportswin->GetKey(GLFW_KEY_D))
            sportswin->SetWindowSize(sportswin->GetWidth() - 1, sportswin->GetHeight() - 1);

	}

	delete sportswin;
	SportsTerminate();

	return 0;
}