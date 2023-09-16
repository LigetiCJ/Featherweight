#include "fileHelper.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "stdio.h"
#include "stdlib.h"

int success;
char infoLog[512];

typedef struct {
	unsigned int VBO;
	unsigned int VAO;
	unsigned int shaderProgram;
} note_graphicsContainer;

void framebuffer_size_callback(GLFWwindow *window, int width, int height){
	printf("resized window, updating viewport\n");
	glViewport(0,0,width,height);
	
}

void checkShader(unsigned int shaderhandle){
	printf("checking shader... ");
	glGetShaderiv(shaderhandle, GL_COMPILE_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(shaderhandle, 512, 0, infoLog);
		printf(infoLog);
	}else{
		printf("success\n");
	}
}
void checkProgram(unsigned int programhandle){
	printf("checking program... ");
	glGetProgramiv(programhandle, GL_LINK_STATUS, &success);
	if(!success){
		glGetShaderInfoLog(programhandle, 512, 0, infoLog);
		printf(infoLog);
	}else{
		printf("success\n");
	}
}

///takes in the filepath of vertex and fragment shader and returns shader program handle
unsigned int makeShaderProgram(const char *vertexShaderFilename, const char* fragmentShaderFilename){
	
	//load shader files
	const char *vertexShaderSource = loadFile(vertexShaderFilename);
	const char *fragmentShaderSource = loadFile(fragmentShaderFilename);
	
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, 0);
	glCompileShader(vertexShader);
	
	checkShader(vertexShader);

	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, 0);
	glCompileShader(fragmentShader);
	
	checkShader(fragmentShader);
	
	unsigned int shaderProgram;
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	checkProgram(shaderProgram);
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	
	free((void*)vertexShaderSource);
	free((void*)fragmentShaderSource);
	
	return shaderProgram;
}

void consoleLog(char *str){
	//draw str as bitmap font to screen
	//blit font to texture file
}