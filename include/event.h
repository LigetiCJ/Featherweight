#ifndef H_EVENT
#define H_EVENT

typedef struct{
	int canceled;
	char *eventType;
}NOTE_event;

typedef struct{
	int numEvents;
	NOTE_event* events;
}NOTE_eventBuffer;


void NOTE_initEvents();
void NOTE_sendEvent(char* event);
eventBuffer* NOTE_pollEvents();

#endif