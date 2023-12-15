#include "event.h"
#include "stdlib.h"

static void (**listeners)(NOTE_event) = 0;
static int numListeners = 0;
static int maxSize = 1;



void initEventSystem(){
	listeners = malloc(sizeof(unsigned int)*maxSize);
}

void addListener(void (*listenerFunction)(NOTE_event)){
    //add the function to the listener list
    if((numListeners+1) > maxSize){
        maxSize *= 2;
        listeners = realloc(listeners, sizeof(unsigned int) * maxSize);
        numListeners++;
        listeners[numListeners] = &listenerFunction;
    }

}


void postMessage(NOTE_event event){
    for(int i = 0; i < numListeners; i++){
        listeners[i](event);

    }

}
