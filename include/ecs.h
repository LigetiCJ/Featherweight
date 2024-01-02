#ifndef H_ECS
#define H_ECS

#define MAX_ENTITIES 1024

typedef struct{
    float posX;
    float posY;
}position;

typedef struct{
    float velX;
    float velY;
}velocity;

typedef struct{
    float health;
}health;

typedef struct {
    float yaw;
    float pitch;
    float roll;
}rotation;

typedef struct{
    void (*behavior)(entity);
}behavior;

typedef int entity;

//all components you can put on an entity
static position positions[MAX_ENTITIES];
static velocity velocities[MAX_ENTITIES];
static health healths[MAX_ENTITIES];
static rotation rotations[MAX_ENTITIES];
static behavior behaviors[MAX_ENTITIES];

entity NOTE_requestNewEntity();
void NOTE_freeEntity(entity target);


#endif