#include "main.h"
#include "API.h"


void armtaskcode (void *ignore)
{
  lcdClear(uart1);
  armtargetL = analogRead(potarmL);
  armtargetR = analogRead(potarmR);
float karm = 0.15;
  while(true){
    int armheightL = analogRead(potarmL);
    int armheightR = analogRead(potarmR);
    lcdSetBacklight(uart1, true);
    lcdPrint(uart1, 1, "PotL = %d", armheightL);
    lcdPrint(uart1, 2, "PotR = %d", armheightR);

    if (joystickGetDigital(1, 6, JOY_UP)){
        if(analogRead(potarmL) < ARM_MAX_L){
          motorSet(ArmLT, ArmLT_Dir*127);
          motorSet(ArmLB, ArmLB_Dir*127);
        }
        if(analogRead(potarmR < ARM_MAX_R)){
            motorSet(ArmRT, ArmRT_Dir*127);
            motorSet(ArmRB, ArmRB_Dir*127);
          }
      armtargetL = analogRead(potarmL);
      armtargetR = analogRead(potarmR);
    }else if(joystickGetDigital(1,6,JOY_DOWN)){
      motorSet(ArmLT, ArmLT_Dir*-127);
      motorSet(ArmLB, ArmLB_Dir*-127);
      motorSet(ArmRT, ArmRT_Dir*-127);
      motorSet(ArmRB, ArmRB_Dir*-127);
      armtargetL = analogRead(potarmL);
      armtargetR = analogRead(potarmR);
    }
    else if(joystickGetDigital(2,6,JOY_UP)){
      motorSet(ArmLT, ArmLT_Dir*joystickGetAnalog(2, 2));
      motorSet(ArmLB, ArmLB_Dir*joystickGetAnalog(2, 2));
      motorSet(ArmRT, ArmRT_Dir*joystickGetAnalog(2, 2));
      motorSet(ArmRB, ArmRB_Dir*joystickGetAnalog(2, 2));
      armtargetL = analogRead(potarmL);
      armtargetR = analogRead(potarmR);
    }

    else {

        int armdifferenceL = armtargetL - armheightL;
        int armdifferenceR = armtargetR - armheightR;

        motorSet(ArmLT, motorcap(ArmLT_Dir*armdifferenceL*karm));
        motorSet(ArmLB, motorcap(ArmLB_Dir*armdifferenceL*karm));
        motorSet(ArmRT, motorcap(ArmRT_Dir*armdifferenceR*karm));
        motorSet(ArmRB, motorcap(ArmRB_Dir*armdifferenceR*karm));
/*
motorSet(ArmLT, 0);
motorSet(ArmLB, 0);
motorSet(ArmRT, 0);
motorSet(ArmRB, 0);
*/
            }
            delay(30);
  }
}

void armpresets(){
  if(joystickGetDigital(1,8,JOY_UP)){
    armtargetL = OFF_GROUND_L;
    armtargetR = OFF_GROUND_R;
  }
  else if(joystickGetDigital(1,8,JOY_DOWN)){
    armtargetL = GROUND_L;
    armtargetR = GROUND_R;
    }
  else if (joystickGetDigital(1,8,JOY_LEFT)){
    armtargetL = FENCE_HIGH_L;
    armtargetR = FENCE_HIGH_R;
  }
  else if(joystickGetDigital(1,8,JOY_RIGHT)){
    armtargetL = FENCE_LOW_L;
    armtargetR = FENCE_LOW_R;
  }
  else{}
}

void autoarmtaskcode (void*ignore){

float karm = 0.15;

//armtargetL = analogRead(potarmL);
//armtargetR = analogRead(potarmR);

while(true){
  int armheightL = analogRead(potarmL);
  int armheightR = analogRead(potarmR);
  int armdifferenceL = armtargetL - armheightL;
  int armdifferenceR = armtargetR - armheightR;

lcdClear(uart1);
lcdPrint(uart1, 1, "diffR = %d", armdifferenceR);
lcdPrint(uart1, 2, "diffL = %d", armdifferenceL);
  motorSet(ArmLT, motorcap(ArmLT_Dir*armdifferenceL*karm));
  motorSet(ArmLB, motorcap(ArmLB_Dir*armdifferenceL*karm));
  motorSet(ArmRT, motorcap(ArmRT_Dir*armdifferenceR*karm));
  motorSet(ArmRB, motorcap(ArmRB_Dir*armdifferenceR*karm));

  delay(25);
  if( isAutonomous() )
  { }
  else{
taskDelete(autoarmtask);
  }

  }
}
