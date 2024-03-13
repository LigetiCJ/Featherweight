#include "ecs.h"


entity NOTE_createCamera(){
    entity camera = NOTE_requestNewEntity();


    types[camera].type = NOTE_shell;
    positions[camera].posX = 0.0f;
    positions[camera].posY = 0.0f;
    positions[camera].posZ = 0.0f;
    rotations[camera].yaw = 0.0f;
    rotations[camera].pitch = 0.0f;
    rotations[camera].roll = 0.0f;

    return camera;

}

//Binds a camera to a target
void NOTE_setCameraTarget(entity Camera, entity target, int followType){

    
}