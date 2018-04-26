#ifndef _SENSOR_REG_H_
#define _SENSOR_REG_H_

task left_sensor(){
  int val_old = 0;
  while(true){
  int val_new = SensorValue(S4);
  if((val_old == 0 && val_new == 1)){
    setEvent(LEFTTOUCHPRESSED);
  }
  val_old = val_new;
  Wait(100);
  }
}

task right_sensor(){
  int val_old = 0;
  while(true){
  int val_new = SensorValue(S1);
  if((val_old == 0 && val_new == 1)){
    setEvent(RIGHTTOUCHPRESSED);
  }
  val_old = val_new;
  Wait(100);
  }
}

#endif
