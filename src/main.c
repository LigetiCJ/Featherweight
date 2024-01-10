#define GLFW_DLL
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "graphicsHelper.h"
#include "input.h"
#include "stdlib.h"
#include "event.h"
#include "textureGenerator.h"

void debugTexture(NOTE_texture *tex){
	for(int i = 0; i < tex->width*tex->height*4; i++){
		printf("%f, ", tex->values[i]);
		if(i%4 == 3) printf("\n");
	}
}


float rect = {
	// points           //UVs
	 0.5f,  0.5f, 0.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,
	-0.5f,  0.5f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 1.0f, 1.0f
};
int rectindicies[] = {
	0, 1, 2,
	2, 3, 1
};

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
	
	debugTexture(&tex);

	
	///core loop (input, network, process, render)
	while(!glfwWindowShouldClose(window)){
		
		glfwPollEvents();
		processInput(window);
		processBehavior();
		//render

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);

	
	}
	
	glfwTerminate();
	return 0;
}