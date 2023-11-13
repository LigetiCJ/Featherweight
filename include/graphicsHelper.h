#ifndef NOTE_GRAPHICSHELPER_H
#define NOTE_GRAPHICSHELPER_H

typedef struct{
	int numVerts;
	float *verts;
	int *faces;
}NOTE_model;

GLFWwindow* initGraphics();
unsigned int makeShaderProgram(const char *vertexShaderFilename, const char* fragmentShaderFilename);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

#endif