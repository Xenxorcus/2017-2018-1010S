#include "main.h"
#include "mg.h"

void mgSet(int power){
  motorSet(mg,power);
}



//// task task task task

void mgTask (void*ignore){
  int kp = 1;
  int mgGlobalTarget;
  while(true){
    if(!isEnabled()){break;} // when disabled, arm task ends - allows for new tassk ot be started when enabled

int current = analogRead(3);
int error = mgGlobalTarget - current;
int mgpower = error*kp;

mgSet(mgpower);
    delay(20);
    }

  mgSet(0);
  taskDelete(mgAutoTask); // when loop break (i.e robot not enabled)
  }
