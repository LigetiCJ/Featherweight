cmake_minimum_required(VERSION 3.28.2)

#name the project
project(featherweight C)

#find OpenGL
find_package(OpenGL REQUIRED)

#add GLFW
add_subdirectory(lib/glfw)

#include GLFW headers
include_directories(${GLFW_INCLUDE_DIRS})

set(SOURCES
    src/main.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

#link libraries
target_link_libraries(${PROJECT_NAME} glfw OpenGL:GL)
