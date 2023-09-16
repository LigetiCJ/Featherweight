#include "event.h"

NOTE_eventBuffer eb*;


NOTE_initEvent(){
	eb = malloc(sizeof(int) + sizeof(NOTE_event)*512);
}

void NOTE_sendEvent(char* event){
	eb->numEvents++;
	eb+sizeof(NOTE_event)*eb->numEvents = event;
	
}
NOTE_eventBuffer* requestEvents(){
	return &eb;
}

NOTE_cleanEventBuffer(){
	eb->numEvents = -1;
	
}