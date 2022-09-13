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
#include <iostream>
#include <glad/glad.h>
#include "sportswin.h"

void SportsWindowResizeCallback(SportsWindow *sportswin, int w, int h)
{
	sports::info("resize callback: %d,%d\n", w, h);
}

int main()
{
	auto sportswin = new SportsWindow(800, 600, "sports");
	sportswin->SetWindowResizeCallback(SportsWindowResizeCallback);

	SportsMakeContextCurrent(sportswin);

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