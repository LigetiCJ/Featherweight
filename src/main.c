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
	for(int i = 0; i < (3*size*size); i++){
		//imageOut[i] = (0+i%3)*1.0f + (1+i%3)*0.0f + (2+i%3)*0.5f;
		//imageOut[i] = 1.0f;
		imageOut[i] = 1.0f*i / (size*size*3);
	}
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
	glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	//sets offset and stride of second concept in the vertex array (colors)
	glVertexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);
	
	//sets offset and stride of third concept in the vertex array (UVs)
	glVertexAttribPointer(2,2,GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
	glEnableVertexAttribArray(2);
	
	//texture setup
	int texSize = 256;
	float *debugTex = malloc(sizeof(float)*texSize*texSize*3);;
	generateTestTexture(texSize, debugTex);

	
	unsigned int tex;
	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	
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