#include <iostream>
#include "sportswin.h"

int main()
{
	auto sportswin = new SportsWindow(800, 600, "sports");

	while (!sportswin->ShouldClose()) {
		SportsPollEvents();
	}

	delete sportswin;
	SportsTerminate();

	return 0;
}