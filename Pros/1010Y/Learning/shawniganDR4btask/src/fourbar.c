#include "main.h"
#include "fourbar.h"

void fourSet(int power){
  motorSet(fourBar,power);
}

void fourTask(void*ignore){
  int kp = 1;
  int fourGlobalTarget;
  while(true){

    if(!isEnabled()){break;}

if(fourbar_function_running == 0 || stack_function_running == 0){
  int current = analogRead(1);
  int error = fourGlobalTarget - current;
  int fourpower = error*kp;

  fourSet(-fourpower);
}
    delay(20);
    }

  fourSet(0);
  taskDelete(fourAutoTask); // when loop break (i.e robot not enabled)
}
