#ifndef NOTE_GRAPHICSHELPER_H
#define NOTE_GRAPHICSHELPER_H

typedef struct{
	int numVerts;
	float *verts;
	int *faces;
}NOTE_model;

typedef struct {
	unsigned int VBO;
	unsigned int VAO;
	unsigned int shaderProgram;
} NOTE_graphicsContainer;

GLFWwindow* initGraphics();
unsigned int makeShaderProgram(const char *vertexShaderFilename, const char* fragmentShaderFilename);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

NOTE_graphicsContainer *createNewGraphicsContainer();

#endif