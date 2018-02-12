#include "main.h"
#include "motor.h"
#include "util.h"


#define SLEW_STEP_DRIVE 5 // 17 // 4.25
#define SLEW_STEP_CLAW 4 // 16
#define SLEW_STEP_ARM 4.5 // 18

int motortarget[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorerror[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorpower[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorport[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void motortask(void*ignore){
int islew;
int in;
int slew_step = 4;

while (true){
  delay(5); // was 20
  if(!isEnabled()){break;}



  //find motor error, then updates vaule sent to motor
  if(slewcontrol){
    islew = 0;
    while(islew <= 9){


      motorerror[islew] = motortarget[islew] - motorpower[islew];

      if( (islew==0)||(islew==2)||(islew==3)||(islew==4)||(islew==9)){ slew_step = SLEW_STEP_ARM;}
      else if((islew==7)){ slew_step = SLEW_STEP_CLAW; }
      else{ slew_step = SLEW_STEP_DRIVE;} // was ; after bracket here, Likely erro ?

      motorpower[islew] = motorpower[islew]+slewcap((motorerror[islew]), slew_step);
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
