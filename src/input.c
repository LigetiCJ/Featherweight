#include "input.h"


int up, down, left, right, a, b, x, y, l, r, start, select;
int shouldOpenConsole;

//we can do better...
void processInput(GLFWwindow *window){
	//force quit
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS && glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, 1);
	
	if(glfwGetKey(window, GLFW_KEY_GRAVE_ACCENT) == GLFW_PRESS){
		//open console
		printf("opened console\n");
	}
	
	if(glfwGetKey(window, up) == GLFW_PRESS){ /*SEND UP MESSAGE*/};
	if(glfwGetKey(window, down) == GLFW_PRESS){ /*SEND DOWN MESSAGE*/};
	if(glfwGetKey(window, left) == GLFW_PRESS){ /*SEND LEFT MESSAGE*/};
	if(glfwGetKey(window, right) == GLFW_PRESS){ /*SEND RIGHT MESSAGE*/};
	if(glfwGetKey(window, a) == GLFW_PRESS){ /*SEND A MESSAGE*/};
	if(glfwGetKey(window, b) == GLFW_PRESS){ /*SEND B MESSAGE*/};
	if(glfwGetKey(window, x) == GLFW_PRESS){ /*SEND X MESSAGE*/};
	if(glfwGetKey(window, y) == GLFW_PRESS){ /*SEND Y MESSAGE*/};
	if(glfwGetKey(window, l) == GLFW_PRESS){ /*SEND L MESSAGE*/};
	if(glfwGetKey(window, r) == GLFW_PRESS){ /*SEND R MESSAGE*/};
	if(glfwGetKey(window, start) == GLFW_PRESS){ /*SEND START MESSAGE*/};
	if(glfwGetKey(window, select) == GLFW_PRESS){ /*SEND SELECT MESSAGE*/};
	
}