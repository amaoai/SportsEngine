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

/* Creates on 2022/9/16. */
#include "OpenGLShaderModule.h"

#include <Utils/Loggers.h>
#include <glad/glad.h>
#include <fstream>
#include <vector>

OpenGLShaderModule::OpenGLShaderModule(const char *vertfile, const char *fragfile)
{
    char* vertexShaderBuffer;
    char* fragmentShaderBuffer;

    // read vertex file
    std::ifstream vertexFile(vertfile, std::ios::ate | std::ios::binary);

    if (!vertexFile.is_open())
        sports::runtime_error("Sports Error: open vertex shader file failed!\n");

    size_t vertexFileSize = vertexFile.tellg();
    vertexShaderBuffer = (char *) malloc(vertexFileSize + 1);
    vertexFile.seekg(0);
    vertexFile.read(vertexShaderBuffer, vertexFileSize);
    vertexShaderBuffer[vertexFileSize] = '\0';
    vertexFile.close();

    // read fragment file
    std::ifstream fragmentFile(fragfile, std::ios::ate | std::ios::binary);

    if (!fragmentFile.is_open())
        sports::runtime_error("Sports Error: open fragment shader file failed!\n");

    size_t fragmentFileSize = fragmentFile.tellg();
    fragmentShaderBuffer = (char *) malloc(fragmentFileSize + 1);
    fragmentFile.seekg(0);
    fragmentFile.read(fragmentShaderBuffer, fragmentFileSize);
    fragmentShaderBuffer[fragmentFileSize] = '\0';
    fragmentFile.close();

    // load shader to gl.
    int   success;
    char  infoLog[512];

    unsigned int vertexShaderId;
    vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShaderId, 1, &vertexShaderBuffer, NULL);
    glCompileShader(vertexShaderId);

    // check for shader compile errors
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
        sports::runtime_error("Sports Error: Vertex shader compile error: %s\n", infoLog);
    }

    unsigned int fragmentShaderId;
    fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShaderId, 1, &fragmentShaderBuffer, NULL);
    glCompileShader(fragmentShaderId);

    // check for shader compile errors
    glGetShaderiv(vertexShaderId, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShaderId, 512, NULL, infoLog);
        sports::runtime_error("Sports Error: Fragment shader compile error: %s\n", infoLog);
    }

    shaderModule = glCreateProgram();
    glAttachShader(shaderModule, vertexShaderId);
    glAttachShader(shaderModule, fragmentShaderId);
    glLinkProgram(shaderModule);

    // check for shader program link.
    glGetProgramiv(shaderModule, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderModule, 512, NULL, infoLog);
        sports::runtime_error("Sports Error: Link shader error: %s\n", infoLog);
    }

    glDeleteShader(vertexShaderId);
    glDeleteShader(fragmentShaderId);

    free(vertexShaderBuffer);
    free(fragmentShaderBuffer);
}

OpenGLShaderModule::~OpenGLShaderModule()
{
    glDeleteProgram(shaderModule);
}

void OpenGLShaderModule::Bind()
{
    glUseProgram(shaderModule);
}

void OpenGLShaderModule::UnBind()
{
    glUseProgram(0);
}
