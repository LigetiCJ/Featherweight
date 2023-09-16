#ifndef NOTE_GRAPHICSHELPER_H
#define NOTE_GRAPHICSHELPER_H

unsigned int makeShaderProgram(const char *vertexShaderFilename, const char* fragmentShaderFilename);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

#endif