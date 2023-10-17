#include "stdlib.h"
#include "stateMachine.h"

//taken from https://prdeving.wordpress.com/2019/05/30/how-to-write-a-game-engine-in-pure-c-part-1-state-manager/


int STATEMANAGER_init(NOTE_stateManager *statemanager){
	statemanager -> capacity = 4;
	statemanager -> stack = malloc(statemanager -> capacity * sizeof(NOTE_state));
	statemanager -> top = -1;
	return 0;
}

int STATEMANAGER_free(NOTE_stateManager *statemanager){
	do{
		STATEMANAGER_pop(statemanager);
	}while(statemanager -> top > -1);
	free(statemanager -> stack);
	
	return 0;
}

int STATEMANAGER_scale(NOTE_stateManager *statemanager){
	statemanager -> capacity *= 2;
	statemanager -> stack = realloc(statemanager -> stack, statemanager -> capacity * sizeof(NOTE_state));
	return statemanager -> capacity;
	
}

int STATEMANAGER_push(NOTE_stateManager *statemanager, NOTE_state *state){
	return 0;
}

int STATEMANAGER_pop(NOTE_stateManager *statemanager){
	return 0;
}

NOTE_state *STATEMANAGER_top(NOTE_stateManager *statemanager){
	return 0;
}

int STATEMANAGER_update(NOTE_stateManager *statemanager, float deltaTime){
	return 0;
}

int STATEMANAGER_draw(NOTE_stateManager *statemanager, float deltaTime){
	return 0;
}