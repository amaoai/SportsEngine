# CMakeList.txt: SportsEngine 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("SportsEngine")

set(CMAKE_CXX_STANDARD 23)

# 添加 include
include_directories(SYSTEM 
	${PROJECT_SOURCE_DIR}/third-party/glfw/include
)

# glfw 动态链接库
link_directories(${PROJECT_SOURCE_DIR}/third-party/glfw/lib-mingw-w64)

# 查找 vulkan 库
find_package(Vulkan REQUIRED FATAL_ERROR)
IF(${Vulkan_FOUND})
    message(STATUS "FOUND VULKAN: ${Vulkan_INCLUDE_DIRS}")
    include_directories(SYSTEM ${Vulkan_INCLUDE_DIRS})
ENDIF()

# 将源代码添加到此项目的可执行文件。
add_executable (${PROJECT_NAME} 
	"main.cpp" 
	"sportswin.cpp"
	"tools/logs.cpp"
)

target_link_libraries(${PROJECT_NAME} -lglfw3 ${Vulkan_LIBRARIES})