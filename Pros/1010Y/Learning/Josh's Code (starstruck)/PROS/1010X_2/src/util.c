#include "main.h"
#include "API.h"

int motorcap(int value){
  if(value > 127)
  		return 127;
  	else if (value < -127)
  		return -127;
    else
      return value;
  }

void clawopen()
{
clawtarget = 400;
armtargetL = 700;
armtargetR = 1000;
delay(500);
armtargetR = GROUND_R;
armtargetL = GROUND_L;
delay(500);
}
