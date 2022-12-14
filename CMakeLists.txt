# ************************************************************************ #
#
# Copyright (C) 2022 Vincent Luo All rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# ************************************************************************ #

# Creates on 2022/9/14. #

# CMakeList.txt: SportsEngine 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("SportsEngine")

set(CMAKE_CXX_STANDARD 23)

# 添加 include
include_directories(
    Source/Engine
    Source/Utils
)

# 添加 system include
include_directories(SYSTEM
        Source/Pch
        Source/Utils/Include
        Source/ThirdParty/
        Source/ThirdParty/imgui
        Source/ThirdParty/glfw/include
        Source/ThirdParty/glad/include
)

message(STATUS "Compile ID: ${CMAKE_CXX_COMPILER_ID}")

# glfw 动态链接库
if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    link_directories(Source/ThirdParty/glfw/lib-mingw-w64)
elseif((${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC))
    link_directories(Source/ThirdParty/glfw/lib-vc2022)
endif()

# 查找 vulkan 库
find_package(Vulkan REQUIRED FATAL_ERROR)
if(${Vulkan_FOUND})
    message(STATUS "FOUND VULKAN: ${Vulkan_INCLUDE_DIRS}")
    include_directories(SYSTEM ${Vulkan_INCLUDE_DIRS})
endif()

link_libraries(imm32)

# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} 
    "Source/Engine/SportsMain.cpp"
    "Source/Engine/Window/SportsWindow.cpp"
    "Source/Utils/Loggers.cpp"
    "Source/ThirdParty/glad/src/glad.c"
    "Source/Engine/Renderer/SportsRenderer.cpp"
    "Source/Engine/Platform/OpenGL/OpenGLRenderer.cpp"
    "Source/Engine/Platform/OpenGL/OpenGLBuffers.cpp"
    "Source/Engine/Platform/OpenGL/OpenGLShaderModule.cpp"
    "Source/Engine/ImGui/ImGuiRenderer.cpp"
    # --* ThirdParty/ImGui *-- #
    "Source/ThirdParty/imgui/imgui.cpp"
    "Source/ThirdParty/imgui/imgui_tables.cpp"
    "Source/ThirdParty/imgui/imgui_demo.cpp"
    "Source/ThirdParty/imgui/imgui_draw.cpp"
    "Source/ThirdParty/imgui/imgui_widgets.cpp"
    "Source/ThirdParty/imgui/backends/imgui_impl_opengl3.cpp"
    "Source/ThirdParty/imgui/backends/imgui_impl_glfw.cpp"
)

# 根据编译器匹配 glfw 动态库
if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
    target_link_libraries(${PROJECT_NAME} -lglfw3)
elseif((${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC))
    target_link_libraries(${PROJECT_NAME} glfw3)
endif()

target_link_libraries(${PROJECT_NAME} ${Vulkan_LIBRARIES})