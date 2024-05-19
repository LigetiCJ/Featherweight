#ifndef N_CAMERA
#define N_CAMERA

#include "ecs.h"
#include "math.h"

typedef struct{
    NOTE_vec3f position; //x, y, and z
    NOTE_vec3f rotation; //yaw, pitch, and roll
}NOTE_camera;

entity NOTE_createCamera();

#endif