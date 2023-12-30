#ifndef H_EVENT
#define H_EVENT

//maybe make this bigger later?
#define MAX_LISTENERS 16

//struct for events
typedef struct{
	int eventID;
}NOTE_event;

//listener function layout
typedef void (*NOTE_eventListener)(NOTE_event);

typedef struct{
	NOTE_eventListener subscribers[MAX_LISTENERS];
	int numSubscribers;
}NOTE_eventManager;

void NOTE_initEventManager(NOTE_eventManager *eventManager);
void NOTE_subscribe(NOTE_eventManager *eventManager, NOTE_eventListener eventListener);
void NOTE_postEvent(NOTE_eventManager *eventManager, NOTE_event event);

static NOTE_eventManager playerInputEvent;
static NOTE_eventManager playerMoveEvent;
static NOTE_eventManager playerDamageEvent;
static NOTE_eventManager playerPickUpEvent;
static NOTE_eventManager playerCollideEvent;

static NOTE_eventManager networkEvent;



#endif