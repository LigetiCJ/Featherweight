#include "textureGenerator.h"
#include "stdlib.h"

//initializes a texture with size width*height*4 (RGBA)
void initTexture(NOTE_texture *texture, int width, int height){
    texture->width = width;
    texture->height = height;
    texture->values = malloc(sizeof(float)*width*height*4);
}

void checker(NOTE_texture *texture, int sideLength){

        for(int i = 0; i < texture->width * texture->height; i ++){
            
            texture->values[i*4+0] = 0.0f;
            texture->values[i*4+1] = 0.0f;
            texture->values[i*4+2] = 0.0f;
            texture->values[i*4+3] = 0.0f;
    }
}

void color(NOTE_texture *texture, float red, float green, float blue, float alpha){
    for(int i = 0; i < texture->width*texture->height; i++){
        texture->values[i*4 + 0] = red;
        texture->values[i*4 + 1] = green;
        texture->values[i*4 + 2] = blue;
        texture->values[i*4 + 3] = alpha;
    }
}

/*
UI generation

define a flexible canvas for adding UI elements to
add components to canvas

update values on the render
request render to a texture

grid layout has a pre-defined X by X equally spaced grid that you can add components to


components have a size requirement (1x1, 1x4, 2x3, etc.)
components have an image (tex2d from opengl)

when adding a component to a grid you can define an X and Y position to the grid
if the added component overlaps another or runs off the edge an error will occur

*/
int addCanvasComponent(NOTE_canvas *target, NOTE_canvasComponent *source){
    

}
