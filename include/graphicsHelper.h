#ifndef NOTE_GRAPHICSHELPER_H
#define NOTE_GRAPHICSHELPER_H

typedef struct{
	int numVerts;
	float *verts;
	int *faces;
}NOTE_model;

typedef struct{
	unsigned int VAO;
	unsigned int VBO;
	unsigned int EBO;
	unsigned int TEX;

}NOTE_bufferObjects;

GLFWwindow* initGraphics();
unsigned int makeShaderProgram(const char *vertexShaderFilename, const char* fragmentShaderFilename);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void createBufferObjects(NOTE_bufferObjects *container, float *verts, int *faces );


#endif