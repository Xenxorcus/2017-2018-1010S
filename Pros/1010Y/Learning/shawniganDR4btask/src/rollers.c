#include "main.h"
#include "rollers.h"

void rollerSet(int power){
  motorSet(rollers, power);
}

void rollerTask(void*ignore){
  int rollerGlobalTarget;
  while(true){
    if(!isEnabled()){break;}
if(stack_function_running == 0){
  rollerSet(rollerGlobalTarget);
}
    delay(20);
    }

  rollerSet(0);
  taskDelete(rollerAutoTask); // when loop break (i.e robot not enabled)
  }
