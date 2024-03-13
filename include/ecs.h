#ifndef H_ECS
#define H_ECS

#define MAX_ENTITIES 10

typedef int entity;

typedef enum{
    NOTE_empty,
    NOTE_shell,
    NOTE_projectile,
    NOTE_particle
}NOTE_entityType;

typedef struct{
    float posX;
    float posY;
    float posZ;
}position;

typedef struct{
    float velX;
    float velY;
    float velZ;
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

extern position positions[];
extern velocity velocities[];
extern health healths[];
extern rotation rotations[];
extern behavior behaviors[];
extern type types[];

entity NOTE_requestNewEntity();
void NOTE_freeEntity(entity target);
void processBehavior();
void processMovement();

#endif