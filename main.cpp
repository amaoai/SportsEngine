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
#include "render/renderer.h"
#include "render/buffer/vertexbuf.h"
#include "render/buffer/indexbuf.h"

void SportsWindowResizeCallback(SportsWindow *sportswin, int w, int h)
{
	sports::info("resize callback: %d,%d\n", w, h);
}

void SportsFramebufferCallback(SportsWindow* sportswin, int w, int h)
{
	glViewport(0, 0, w, h);
}

const char* vertexShaderSource = "#version 330 core\n"
								 "layout (location = 0) in vec3 aPos;\n"
								 "void main()\n"
								 "{\n"
								 "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
								 "}\0";

const char* fragmenetShaderSource = "#version 330 core\n"
								    "out vec4 FragColor;\n"
								    "void main()\n"
								    "{\n"
								    "	FragColor = vec4(1.0f, 0.2f, 0.3f, 1.0f);\n"
								    "}\0";

int main()
{
	auto sportswin = new SportsWindow(800, 600, "sports");

	sportswin->SetWindowResizeCallback(SportsWindowResizeCallback);
	sportswin->SetFramebufferCallback(SportsFramebufferCallback);

    auto sportsRenderer = SportsCreateRenderer(sportswin);

	SportsMakeContextCurrent(sportswin);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, sportswin->GetWidth(), sportswin->GetHeight());

	unsigned int vertexShader;
	vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	unsigned int fragmentShader;
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmenetShaderSource, NULL);
	glCompileShader(fragmentShader);

	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glUseProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	float vertices[] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f
	};

	unsigned int indices[] = {
		0, 1, 3, // 第一个
		1, 2, 3  // 第二个
	};

    SportsVertexBuffer vertexBuffer(sizeof(vertices), vertices);
    SportsIndexBuffer  indexBuffer(sizeof(indices), indices);

	while (!sportswin->ShouldClose()) {
		SportsPollEvents();

		sportsRenderer->BeginDrawFrame();
		{
			sportsRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			sportsRenderer->ClearColorBuffer();
			glUseProgram(shaderProgram);

			vertexBuffer.Bind();
			indexBuffer.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		}
		sportsRenderer->EndDrawFrame();

        if (sportswin->GetKey(GLFW_KEY_A))
            sportswin->SetWindowSize(sportswin->GetWidth() + 1, sportswin->GetHeight() + 1);

        if (sportswin->GetKey(GLFW_KEY_D))
            sportswin->SetWindowSize(sportswin->GetWidth() - 1, sportswin->GetHeight() - 1);

		sportswin->SwapBuffers();
	}

	delete sportswin;
    delete sportsRenderer;
	SportsTerminate();

	return 0;
}