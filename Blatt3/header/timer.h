#ifndef _TIMER_H_
#define _TIMER_H_

typedef unsigned int TimerType;
#define MAX_COUNT_TIMERS 10

#define TIMER_0 0
#define TIMER_1 1
#define TIMER_2 2
#define TIMER_3 3
#define TIMER_4 4
#define TIMER_5 5
#define TIMER_6 6
#define TIMER_7 7
#define TIMER_8 8
#define TIMER_9 9

  //Timer Struct
typedef struct{
  unsigned int duration;   //Duration of the timer in mSec
  unsigned long startTime; //Starting Time of the Timer
  EventType event;   //Event send at the end of the Timer
  bool isActive;   //True if Timer is active
}Timer;

  //Timer-Array to handle multiple Timers
Timer timers[MAX_COUNT_TIMERS]; //Timer Array of length MAX_COUNT_TIMERS

  //Sets a Timer t_id with a specific duration that sends an Event of Type ev
void setTimer(TimerType t_id,unsigned int duration_, EventType ev){
  timers[t_id].duration = duration_;
  timers[t_id].event = ev;
}

  //Starts Timer t_id if specified
void startTimer(TimerType t_id){
    timers[t_id].startTime = CurrentTick();
    timers[t_id].isActive = true;
}

  //Cancles Timer t_id
void cancleTimer(TimerType t_id){
  timers[t_id].isActive = false;
}

   //Checks all Timers of the exceeded
task checkTimers(){
  while(true){
  for(int i = 0 ; i < MAX_COUNT_TIMERS;i++){
    if(timers[i].isActive && (CurrentTick() - timers[i].startTime > timers[i].duration)){
      timers[i].isActive = false;
      setEvent(timers[i].event);
    }
  }
  Wait(1);
  }
}

void initTimers(){
  for(int i = 0; i < MAX_COUNT_TIMERS; i++){
    timers[i].isActive = false;
  }
}

void enableTimers(){
  initTimers();
  StartTask(checkTimers);
}


#endif
