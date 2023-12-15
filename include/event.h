#ifndef H_EVENT
#define H_EVENT

typedef struct{
	char willProcess;
	char message[15];
	void* data;
}NOTE_event;


void postMessage(NOTE_event event);
void addListener(void (*listenerFunction)(NOTE_event));

#endif