#include "ecs.h"
#include "stdio.h"

position positions[MAX_ENTITIES];
velocity velocities[MAX_ENTITIES];
health healths[MAX_ENTITIES];
rotation rotations[MAX_ENTITIES];
behavior behaviors[MAX_ENTITIES];
 type types[MAX_ENTITIES];

entity NOTE_requestNewEntity(){
    for(int i = 0; i < MAX_ENTITIES; i++){
        if(types[i].type == NOTE_empty){
            return i;
        }
    }
    return -1;
}

void NOTE_freeEntity(entity target){
    types[target].type = NOTE_empty; 
}

void processMovement(){
    //handle movement processes here
    for(int i = 0; i < MAX_ENTITIES; i++){
        //may be unsafe, check if vel and pos exist if issues arrise
        if( types[i].type != NOTE_empty){
            positions[i].posX += velocities[i].velX;
            positions[i].posY += velocities[i].velY;
        }
    }
}

void processBehavior(){
    for(int i = 0; i < MAX_ENTITIES; i++){
        //may be unsafe, check if behavior exist if issues arrise
        if( types[i].type != NOTE_empty){
            behaviors[i].behavior(i);
        }
    }
}
