#include "main.h"
#include "API.h"

void clawtaskcode (void*ignore){

  //float kclaw = 0.5;
    while(true){

      if (joystickGetDigital(1, 5, JOY_UP)){
        motorSet(RollL, RollL_Dir*127);
        motorSet(RollR, RollR_Dir*127);
        clawtarget = analogRead(potclaw);
      }else if(joystickGetDigital(1,5,JOY_DOWN)){
        motorSet(RollL, RollL_Dir*-127);
        motorSet(RollR, RollR_Dir*-127);
        clawtarget = analogRead(potclaw);
      }
      else if(joystickGetDigital(2,5,JOY_UP)){
        motorSet(RollL, RollL_Dir*127);
        motorSet(RollR, RollR_Dir*127);
        clawtarget = analogRead(potclaw);
      }
      else if(joystickGetDigital(2,5,JOY_DOWN)){
        motorSet(RollL, RollL_Dir*-127);
        motorSet(RollR, RollR_Dir*-127);
        clawtarget = analogRead(potclaw);
      }
      else {
          /*int clawpos = analogRead(potclaw);
          int clawdifference = clawtarget - clawpos;

          motorSet(RollL, motorcap(RollL_Dir*clawdifference*kclaw));
          motorSet(RollR, motorcap(RollR_Dir*clawdifference*kclaw));
*/
motorSet(RollL, 0);
motorSet(RollR, 0);
}
          delay(25);
      }
  }

void clawpresets(){
  if(joystickGetDigital(2,7,JOY_UP)){
    clawtarget = CLAW_OPEN_FULL;}
  else if(joystickGetDigital(2,7,JOY_DOWN)){
    clawtarget = CLAW_CLOSED_FULL;}
  else if (joystickGetDigital(2,7,JOY_LEFT)){
    clawtarget = CLAW_OPEN_PART;}
  else if(joystickGetDigital(2,7,JOY_RIGHT)){
    clawtarget = CLAW_CLOSED_PART;}
  else{}
}
