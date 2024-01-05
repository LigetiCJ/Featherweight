#ifndef H_ECS
#define H_ECS

#define MAX_ENTITIES 10

typedef int entity;

typedef enum{
    NOTE_empty,
    NOTE_shell,
    NOTE_projectile,
    NOTE_particle,
    NOTE_world
}NOTE_entityType;

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
    void (*behavior)(entity target);
}behavior;

typedef struct{
    NOTE_entityType type;
}type;

//all components you can put on an entity

position positions[MAX_ENTITIES];
velocity velocities[MAX_ENTITIES];
health healths[MAX_ENTITIES];
rotation rotations[MAX_ENTITIES];
behavior behaviors[MAX_ENTITIES];
type types[MAX_ENTITIES];

entity NOTE_requestNewEntity();
void NOTE_freeEntity(entity target);
void processBehavior();
void processMovement();

#endif