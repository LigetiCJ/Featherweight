#include "event.h"


void NOTE_initEventManager(NOTE_eventManager *eventManager){
    eventManager->numSubscribers = 0;
}

void NOTE_subscribe(NOTE_eventManager *eventManager, NOTE_eventListener eventListener){
    eventManager->subscribers[eventManager->numSubscribers++] = eventListener;

}

void NOTE_postEvent(NOTE_eventManager *eventManager, NOTE_event event){
    for(int i = 0; i < eventManager->numSubscribers; i++){
        eventManager->subscribers[i](event);
    }
}

