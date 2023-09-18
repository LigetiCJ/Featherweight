#ifndef H_STATEMACHINE
#define H_STATEMACHINE

//taken from https://prdeving.wordpress.com/2019/05/30/how-to-write-a-game-engine-in-pure-c-part-1-state-manager/

typedef unsigned int (*fnPtr)();
typedef unsigned int (*fnPtrFl)();

typedef struct{
	fnPtr init;
	fnPtrFl update;
	fnPtrFl draw;
	fnPtr destroy;
}NOTE_state;

typedef struct{
	State **stack;
	int capacity;
	int top;
}NOTE_stateManager;

int STATEMANAGER_init(NOTE_stateManager *statemanager);
int STATEMANAGER_free(NOTE_stateManager *statemanager);
int STATEMANAGER_push(NOTE_stateManager *statemanager, NOTE_state *state);
int STATEMANAGER_pop(NOTE_stateManager *statemanager);
NOTE_state *STATEMANAGER_top(NOTE_stateManager *statemanager);
int STATEMANAGER_update(NOTE_stateManager *statemanager, float deltaTime);
int STATEMANAGER_draw(NOTE_stateManager *statemanager, float deltaTime);

#endif