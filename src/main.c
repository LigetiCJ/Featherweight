#define GLFW_DLL
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "graphicsHelper.h"
#include "input.h"
#include "stdlib.h"
#include "event.h"
#include "ecs.h"

int main(int argc, char **argv){

	//initialize the engine
	//initialize the audio
	

	glfwInit();
	GLFWwindow *window = glfwCreateWindow(640, 480, "projectN", 0, 0);
	
	
	///core loop (input, network, process, render)
	while(!glfwWindowShouldClose(window)){
		
	

		processBehavior();

		glfwPollEvents();
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);

	
	}
	
	glfwTerminate();
	return 0;
}