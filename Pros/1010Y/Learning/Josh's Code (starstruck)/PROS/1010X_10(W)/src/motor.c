#include "main.h"
#include "motor.h"
#include "util.h"

#define SLEW_STEP 16

int motortarget[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorerror[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorpower[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorport[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void motortask(void*ignore){
int islew;
int in;

while (true){
  delay(20);
  if(!isEnabled()){break;}

  //find motor error, then updates vaule sent to motor
  if(slewcontrol){
    islew = 0;
    while(islew <= 9){
      motorerror[islew] = motortarget[islew] - motorpower[islew];
      motorpower[islew] = motorpower[islew]+slewcap((motorerror[islew]), SLEW_STEP);
      motorSet(motorport[islew], motorpower[islew]);
      islew= 1+ islew;
      }
    }
  else{ // normal operation
    in = 0;
    while(in <= 9){
      motorpower[in] = motortarget[in];
      motorSet(motorport[in], motorpower[in]);
      in=1+in;
      }
    }

    //slew contorl exemptions
/*
    if(!slewcontrol_drive){
        motorpower[DriveBL] = motortarget[DriveBL];
        motorpower[DriveFL] = motortarget[DriveFL];
        motorpower[DriveBR] = motortarget[DriveBR];
        motorpower[DriveFR] = motortarget[DriveFR];
        }
    if(!slewcontrol_arm){
      motorpower[ArmLT] = motortarget[ArmLT];
      motorpower[ArmRT] = motortarget[ArmRT];
      motorpower[ArmLO] = motortarget[ArmLO];
      motorpower[ArmRO] = motortarget[ArmRO];
      motorpower[ArmLB] = motortarget[ArmLB];
    }
    if(!slewcontrol_claw){
      motorpower[ClawR] = motortarget[ClawR];
    }
*/

  }
  taskDelete(motor_task);
}


int slewcap(int value, int cap){
  if (value > cap){
    return cap;}
  else if(value < -cap){
    return -cap;}
  else {
    return value;}
  }
