#ifndef H_TEXTUREGENERATOR
#define H_TEXTUREGENERATOR

typedef struct{
    int width;
    int height;
    float *values;
}NOTE_texture;

void initTexture(NOTE_texture *texture, int width, int height);

void color(NOTE_texture *texture, float red, float green, float blue, float alpha);
void checker(NOTE_texture *texture, int sideLength);


#endif