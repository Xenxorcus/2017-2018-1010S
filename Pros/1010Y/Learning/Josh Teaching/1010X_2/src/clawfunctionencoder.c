#include "main.h"
#include "API.h"

void clawencodertaskcode (void *ignore){

float kclaw = 0.2;
encoderReset(encoderclaw);

while (1){
int clawencodervalue = encoderGet(encoderclaw);

if (joystickGetDigital(1, 5, JOY_UP)){
  motorSet(RollL, RollL_Dir*127);
  motorSet(RollR, RollR_Dir*127);
  clawtarget = encoderGet(encoderclaw);
}
else if(joystickGetDigital(1,5, JOY_DOWN)){
  motorSet(RollL, RollL_Dir*-127);
  motorSet(RollR, RollR_Dir*-127);
  clawtarget = encoderGet(encoderclaw);
}
else if(joystickGetDigital(2, 5, JOY_UP)){
  motorSet(RollL, RollL_Dir*joystickGetAnalog(2, 3));
  motorSet(RollR, RollR_Dir*joystickGetAnalog(2, 3));
  clawtarget = encoderGet(encoderclaw);
}
else {
   int clawdifference = clawtarget - clawencodervalue;

    motorSet(RollL, motorcap(RollL_Dir*clawdifference*kclaw));
    motorSet(RollR, motorcap(RollR_Dir*clawdifference*kclaw));
/*
motorSet(RollL, 0);
motorSet(RollR, 0);
*/

}
delay(30);
}
}

void autoclawencodertaskcode (void*ignore){

float kclaw = 0.5;
while(true){
int clawpos = encoderGet(encoderclaw);
int clawdifference = clawtarget - clawpos;
motorSet(RollL, motorcap(RollL_Dir*clawdifference*kclaw));
motorSet(RollR, motorcap(RollR_Dir*clawdifference*kclaw));

  delay(25);
  if(isAutonomous()){}
  else{
    taskDelete(autoclawtask);
  }
}

}
