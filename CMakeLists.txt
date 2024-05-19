cmake_minimum_required(VERSION 3.28.2)

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)



#name the project
project(featherweight C)

if(WIN32)
    set(CMAKE_GENERATOR "MinGW Makefiles" CACHE INTERNAL "" FORCE)
    set(CMAKE_MAKE_PROGRAM mingw32-make)
    set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
endif()


#find opengl
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

if(WIN32)
    find_package(glew REQUIRED)
endif()
if(LINUX)
    find_package(GLEW REQUIRED)
endif()

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
if(WIN32)
    target_link_libraries(${PROJECT_NAME} glew32)
endif()
if(LINUX)
    target_link_libraries(${PROJECT_NAME} GLEW)
endif()
target_link_libraries(${PROJECT_NAME} OpenGL::GL)
