#define GLFW_DLL
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "stdio.h"
#include "graphicsHelper.h"
#include "input.h"
#include "stdlib.h"
#include "fileHelper.h"
#include "event.h"

//find key value and return the number
void extractConfig(const char *key, const char *config, int *container){
	//loop over lines
	//find line with desired key
	//string to int found key pair
	//put int into address of container 

}


void loadConfig(){
	const char* conf = loadFile("config.ini");
	if(conf == -1){
		printf("no config file exists, making a new one\n");
		saveFile("config.ini", "EMPTY");
	}
	//parse config


	printf("%s", conf);
}


int main(int argc, char **argv){
	loadConfig();


	glfwInit();
	GLFWwindow *window = glfwCreateWindow(640, 480, "projectN", 0, 0);

	///core loop
	while(!glfwWindowShouldClose(window)){
		glfwPollEvents();
		processInput(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);
	
	}
	
	glfwTerminate();
	return 0;
}