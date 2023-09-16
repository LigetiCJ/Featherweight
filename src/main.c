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



float verticies[] = {
	//points            colors
	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f, 0.3f, 0.0f, 1.0f, 0.0f,
	 0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f
};

float debugModel[] = {
	//points            colors
	
	
};

int debugModelFaces[] = {
	
};




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
	
	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
	
	
	
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	
	float timeValue = glfwGetTime();
	
	int deltaTimeTarget = glGetUniformLocation(shaderProgram, "deltaTime");
	
	///core loop
	while(!glfwWindowShouldClose(window)){
		timeValue = glfwGetTime();
		
		processInput(window);
		//processGame
		
		//processEvents (do not canceled events and free them)
		//render
		
		//drawing timer
		
		glClearColor(0.2f,0.2f,0.2f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glUseProgram(shaderProgram);
		glUniform4f(deltaTimeTarget, timeValue, 0.0f, 0.0f, 0.0f);
		
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0,3);
		
		glfwSwapBuffers(window);
	
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}