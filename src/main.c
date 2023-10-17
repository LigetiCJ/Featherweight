#define GLFW_DLL
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "stdio.h"
#include "time.h"
#include "graphicsHelper.h"
#include "fileHelper.h"
#include "time.h"
#include "cglm/cglm.h"
#include "input.h"

int _width = 500;
int _height = 500;

//X is left(-) right(+) (left handed 3D)
//y is height
//z is depth


unsigned int shaderProgram;
int shouldReload = 1;

float *image;

float verticies[] = {
	//points            colors
	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, 0.3f, 0.0f, 1.0f, 0.0f,
	 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
};

float pyramidVerts[] = {
	-0.5f, -0.5f,  0.0f, 1.0f,1.0f,1.0f,
	 0.5f, -0.5f,  0.0f, 0.0f,0.0f,1.0f,
	 0.0f,  0.5f, -0.5f, 1.0f,0.0f,0.0f,
	 0.0f,  0.5f,  0.5f, 0.0f,1.0f,0.0f,
};

int pyramidFaces[] = {
	0,1,2,
	2,3,1,
	0,2,3,
	1,0,3
};


void generateTestTexture(int size, float *imageOut){
	imageOut = malloc(sizeof(float)*size*size*3);
	
	for(int i = 0; i < size*size; i++){
		imageOut[i] = i*1.0f/size*size;
	}
	
	
}



int main(int argc, char **argv){
	
	//initialize the engine
	//initialize the audio
	
	///initalize glfw
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE);
	glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
	
	GLFWwindow* window = glfwCreateWindow(_width,_height, "Project", 0,0);
	
	if(window == 0){
			printf("failed to create window, aborting");
			glfwTerminate();
			return -40;
	}
	glfwMakeContextCurrent(window);
	
	GLenum err = glewInit();
	if(err != GLEW_OK){
		printf("failed to initialize GLEW, aborting");
		return -41;
	}
	glViewport(0,0,_width,_height);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	///
	
	//make the shader program
	shaderProgram = makeShaderProgram("etc/vertShader.vs", "etc/fragShader.fs");
	
	//sets up the Vertex Attribute Object (VAO) that stores the configuration of an array for a model
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	//sets up the Vertex Buffer Object (VBO) that stores the actual vertex(and color) data for a model
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(pyramidVerts), pyramidVerts, GL_STATIC_DRAW);
	
	//sets up the Element Buffer Object (EBO) that stores construction data for verts to faces
	unsigned int EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(pyramidFaces), pyramidFaces, GL_STATIC_DRAW);
	
	
	//sets offset and stride of first concept in the vertex array (verts)
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	//sets offset and stride of second concept in the vertex array (colors)
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	
	float timeValue = glfwGetTime();
	
	int deltaTimeTarget = glGetUniformLocation(shaderProgram, "deltaTime");
	
	glClearColor(0.3f,0.2f,0.4f,1.0f);

	//glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	///core loop
	while(!glfwWindowShouldClose(window)){
		timeValue = glfwGetTime();
		
		processInput(window);
		//processGame
		
		//processEvents (do not canceled events and free them)
		//render
		
		//drawing timer
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUniform1f(deltaTimeTarget, timeValue );

		
		glUseProgram(shaderProgram);		
		glBindVertexArray(VAO);
		//glDrawArrays(GL_TRIANGLES, 0,6); //ONLY DRAWS ONE TRIANGLE
		
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
		
		glBindVertexArray(0);
		
		
		
		glfwSwapBuffers(window);
	
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}