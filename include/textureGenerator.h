#ifndef H_TEXTUREGENERATOR
#define H_TEXTUREGENERATOR

#include "GL/gl.h"


typedef struct{
    int width;
    int height;
    float *values;
}NOTE_texture;

typedef struct{
    unsigned int textureReference;
    int componentWidth;
    int componentHeight;
}NOTE_canvasComponent;

typedef struct{
    int canvasWidth;
    int canvasHeight;
    int numComponents;
    NOTE_canvasComponent *components;
    unsigned int render;
}NOTE_canvas;





void initTexture(NOTE_texture *texture, int width, int height);
void color(NOTE_texture *texture, float red, float green, float blue, float alpha);
void checker(NOTE_texture *texture, int sideLength);

int addCanvasComponent(NOTE_canvas *target, NOTE_canvasComponent *source);
int renderCanvas(NOTE_canvas *target);


#endif