cmake_minimum_required(VERSION 3.28.2)

set(CMAKE_C_COMPILER gcc)

#name the project
project(featherweight C)

#find opengl
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

#add GLFW
#add_subdirectory(/usr/include)

#include GLFW headers
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories("include/")


link_directories(${GLFW_INCLUDE_DIRS})


set(SOURCES
    src/camera.c
    src/ecs.c 
    src/engine.c 
    src/event.c 
    src/fileHelper.c 
    src/graphicsHelper.c 
    src/input.c 
    src/main.c 
    src/stateMachine.c 
    src/textureGenerator.c
    src/math.c
)

add_executable(${PROJECT_NAME} ${SOURCES})


#link libraries
target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} GLEW)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)
