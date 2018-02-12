#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"
#include "stack.h"

void driverStackTask(void*ignore){
    while(1){
      if(!isEnabled()){break;} // when disabled, arm task ends - allows for new tassk ot be started when enabled

if(driverStackingOn == 1){
  lcdPrint(uart1, 1, "running stack");
  rollerSet(-15);
  int armpos = encoderGet(encoderTen);
  lift(1,(armpos-50));
  fourAUp();
  lift(-1,(armpos+30));
  rollerSet(127);
  delay(350);
  lift(1, (armpos-50));
  delay(60);
  fourADown();
  delay(10);
  lift(-1,20);
  rollerSet(-127);
  driverStackingOn = 0;
}
    delay(20);
    lcdPrint(uart1, 1, "task loop");
    }
  taskDelete(driverStackAutoTask); // when loop break (i.e robot not enabled)
  }
