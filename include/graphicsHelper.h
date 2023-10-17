#ifndef NOTE_GRAPHICSHELPER_H
#define NOTE_GRAPHICSHELPER_H

typedef struct{
	float *verts;
	int *faces;
}NOTE_model;

unsigned int makeShaderProgram(const char *vertexShaderFilename, const char* fragmentShaderFilename);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

#endif