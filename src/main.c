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
#include "math.h"
#include "stdlib.h"
int _width = 500;
int _height = 500;

//X is left(-) right(+) (left handed 3D)
//y is height
//z is depth


unsigned int shaderProgram;
int shouldReload = 1;

float *image;

float rectVerts[] = {
	//points            colors            UVs
	 0.0f,  0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
	 0.0f,  1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
	 1.0f,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f,
	 1.0f,  1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f
};

int rectFaces[] = {
	0,1,2,
	1,3,2
};

float pyramidVerts[] = {
	//points             colors          UVs
	-0.5f, -0.5f,  0.0f, 1.0f,1.0f,1.0f, 0.0f, 0.0f,
	 0.5f, -0.5f,  0.0f, 0.0f,0.0f,1.0f, 0.0f, 1.0f,
	 0.0f,  0.5f, -0.5f, 1.0f,0.0f,0.0f, 1.0f, 0.0f,
	 0.0f,  0.5f,  0.5f, 0.0f,1.0f,0.0f, 1.0f, 1.0f
};



int pyramidFaces[] = {
	0,1,2,
	3,2,1,
	0,2,3,
	1,0,3
};


void generateTestTexture(int size, float* imageOut ){
	//fill the bits with color data
	/*
	for(int i = 0; i < (size*size*3); i = i+3){
		//imageOut[i] = (0+i%3)*1.0f + (1+i%3)*0.0f + (2+i%3)*0.5f;
		//imageOut[i] = 1.0f;
		imageOut[i+0] = 1.0f*i * (i%size > size/2);
		imageOut[i+1] = 0.0f*i * (i%size > size/2);
		imageOut[i+2] = 1.0f*i * (i%size > size/2);
	}
	*/
	
	imageOut[ 0] = 1.0f;
	imageOut[ 1] = 0.0f;
	imageOut[ 2] = 1.0f;
	imageOut[ 3] = 0.0f;
	imageOut[ 4] = 0.0f;
	imageOut[ 5] = 0.0f;
	imageOut[ 6] = 0.0f;
	imageOut[ 7] = 0.0f;
	imageOut[ 8] = 0.0f;
	imageOut[ 9] = 1.0f;
	imageOut[10] = 0.0f;
	imageOut[11] = 1.0f;
}


//make a struct that has pointer to verts, faces, and texture
void newGraphicsObject(){
	//make VAO
	//make VBO
	//make EBO
	
}

int main(int argc, char **argv){
	
	//initialize the engine
	//initialize the audio
		
	GLFWwindow* window = initGraphics(_width, _height);
	///
	
	//make the shader program
	shaderProgram = makeShaderProgram("etc/vertShader.hlsl", "etc/fragShader.hlsl");
	
	NOTE_NYI pyramidStorage = {0};
	
	
	//texture setup
	int texSize = 2;
	float *debugTex = malloc(sizeof(float)*texSize*texSize*3);;
	generateTestTexture(texSize, debugTex);

	
	unsigned int tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	
	
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texSize, texSize, 0, GL_RGB, GL_FLOAT, debugTex);
	glGenerateMipmap(GL_TEXTURE_2D);
	

	glfwSwapInterval(1);
	
	float timeValue = glfwGetTime();
	
	
	int deltaTimeTarget = glGetUniformLocation(shaderProgram, "deltaTime");
	
	glClearColor(0.0f,0.5f,0.0f,1.0f);

	glDisable(GL_CULL_FACE);
	glEnable(GL_DEPTH_TEST);
	
	
	
	//float currentTime = 0.0f;
	//float previousTime = 0.0f;
	//float deltaTime = 0.0f;
	
	///core loop
	while(!glfwWindowShouldClose(window)){
		timeValue = glfwGetTime();
		
		//previousTime = currentTime;
		//currentTime = glfwGetTime();
		//deltaTime = currentTime-previousTime;
		
		processInput(window);
		//processGame
		
		//processEvents (do not canceled events and free them)
		//render
		
		//drawing timer
		
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUniform1f(deltaTimeTarget, timeValue );


		//replace this with on screen drawing of string
		//printf("%f\n", 1/deltaTime);
		
		glUseProgram(shaderProgram);	
		glBindTexture(GL_TEXTURE_2D, tex);
		glBindVertexArray(pyramidStorage.VAO);
		//glDrawArrays(GL_TRIANGLES, 0,6); //ONLY DRAWS ONE TRIANGLE
		
		glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
		
		glBindVertexArray(0);
		
		
		
		glfwSwapBuffers(window);
	
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
}