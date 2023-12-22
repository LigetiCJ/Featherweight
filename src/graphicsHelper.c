#include "fileHelper.h"
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "stdio.h"
#include "stdlib.h"
#include "graphicsHelper.h"

int success;
char infoLog[512];





GLFWwindow* initGraphics(int windowWidth, int windowHeight){
	///initalize glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
	
	GLFWwindow* window = glfwCreateWindow(windowWidth,windowHeight, "Project", 0,0);
	
	if(window == 0){
			printf("failed to create window, aborting");
			glfwTerminate();
			exit(-40);
	}
	glfwMakeContextCurrent(window);
	
	GLenum err = glewInit();
	if(err != GLEW_OK){
		printf("failed to initialize GLEW, aborting");
		exit (-41);
	}
	glViewport(0,0,windowWidth,windowHeight);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	return window;
	
}

void createBufferObjects(NOTE_bufferObjects *container, float *verts, int *faces ){
	//sets up the Vertex Attribute Object (VAO) that stores the configuration of an array for a model
	glGenVertexArrays(1, &container.VAO);
	glBindVertexArray(container->VAO);
	
	//sets up the Vertex Buffer Object (VBO) that stores the actual vertex(and color) data for a model
	glGenBuffers(1, &container.VBO);
	glBindBuffer(GL_ARRAY_BUFFER, container->VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidVerts), pyramidVerts, GL_STATIC_DRAW);
	
	//sets up the Element Buffer Object (EBO) that stores construction data for verts to faces
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(pyramidFaces), pyramidFaces, GL_STATIC_DRAW);
	
	//move this to a different function
}

void setStrides(){
	
	//sets offset and stride of first concept in the vertex array (verts)
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	//sets offset and stride of second concept in the vertex array (colors)
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	
	//sets offset and stride of third concept in the vertex array (UVs)
	glVertexAttribPointer(2,2,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(2);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height){
	printf("resized window, updating viewport\n");
	glViewport(0,0,width,height);
	
}

NOTE_graphicsContainer *createNewGraphicsContainer(){
	return 0;

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