#ifndef _EVENTS_H_
#define _EVENTS_H_

typedef short EventType;
EventType events = 0;

  //EventType masks
#define LEFTTOUCHPRESSED 1
#define RIGHTTOUCHPRESSED 2
#define INFRAREDTRIGGERED 4
#define STOPMOTOR 8
#define WAITINGTIMEEXCEEDED 16

  //Sets Event of Type ev
void setEvent(EventType ev){
  events |= ev;
}

  //Delets Event of Type ev
void clearEvent(EventType ev){
  events &= ~(ev);
}

  //Checks if Event of Type ev is present
#define eventIsPresent(ev) (events & ev)


#endif
