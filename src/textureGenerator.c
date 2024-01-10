#include "textureGenerator.h"
#include "stdlib.h"

//initializes a texture with size width*height*4 (RGBA)
void initTexture(NOTE_texture *texture, int width, int height){
    texture->width = width;
    texture->height = height;
    texture->values = malloc(sizeof(float)*width*height*4);
}





void checker(NOTE_texture *texture){

        for(int i = 0; i < texture->width * texture->height; i ++){
            
            texture->values[i*4+0] = 0.0f;
            texture->values[i*4+1] = 0.0f;
            texture->values[i*4+2] = 0.0f;
            texture->values[i*4+3] = 0.0f;
    }

}

void color(NOTE_texture *texture, float red, float green, float blue, float alpha){
    for(int i = 0; i < texture->width*texture->height*4; i++){
        texture->values[i] = (i%4==0)*red + (i%4==1)*green + (i%4==2)*blue + (i%4==3)*alpha;
    }

}

