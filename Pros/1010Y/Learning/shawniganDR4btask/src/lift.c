#include "main.h"
#include "lift.h"

void liftSet(int power){
  motorSet(liftTL,-power);
  motorSet(liftTR,power);
  motorSet(liftB, power);
}

void liftTask(void*ignore){
  int kp = 1;
  int liftGlobalTarget;
  while(true){
    if(!isEnabled()){break;}
  int current = encoderGet(encoderTen);
  int error = liftGlobalTarget - current;
  int liftpower = error*kp;

  liftSet(-liftpower);

    delay(20);
    }

  liftSet(0);
  taskDelete(liftAutoTask); // when loop break (i.e robot not enabled)
}
