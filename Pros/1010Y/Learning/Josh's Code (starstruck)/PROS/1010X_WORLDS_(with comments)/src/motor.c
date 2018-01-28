#include "main.h"
#include "motor.h"
#include "util.h"

//defines of slew steps (controlling slew varible)
#define SLEW_STEP_DRIVE 5 // 17 // 4.25
#define SLEW_STEP_CLAW 4 // 16
#define SLEW_STEP_ARM 4.5 // 18

//defninition of arrays for slew control
int motortarget[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorerror[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorpower[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int motorport[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//note: 10 motors, 0-9 are array elements


void motortask(void*ignore){
    // slew task

int islew; // denotes motor number in slew
int in; //  denotes motor number in normal operation
int slew_step = 4; // denotes slew step(not constant anymore)

while (true){
  delay(5); // was 20
  if(!isEnabled()){break;} // breaks when robot disabled (end task)



  //find motor error, then updates vaule sent to motor
  if(slewcontrol){ // checks if slew control enabled (by slewset function (see util.c))
    islew = 0; // starts at motor 1
    while(islew <= 9){ // loops through all motor values
      //note : for strucutre not used for debugging


      motorerror[islew] = motortarget[islew] - motorpower[islew]; // finds error based off new motor power commands

      if( (islew==0)||(islew==2)||(islew==3)||(islew==4)||(islew==9)){ slew_step = SLEW_STEP_ARM;} // checks if motor is for arm
      else if((islew==7)){ slew_step = SLEW_STEP_CLAW; } // checks if motor is for claw
      else{ slew_step = SLEW_STEP_DRIVE;}  // else, motor is on drive

      // was ; after bracket here, Likely erro ?

      motorpower[islew] = motorpower[islew]+slewcap((motorerror[islew]), slew_step); // updates motor power, by adding the limit of error (slew cap)
      motorSet(motorport[islew], motorpower[islew]); //sends power to motor
      islew= 1+ islew; //chanegs to the next motor, and continues loop
      }
    }
  else{ // normal operation
    in = 0; // starts at motor 1
    while(in <= 9){
      motorpower[in] = motortarget[in]; // sets motor target power equal to motor power
      motorSet(motorport[in], motorpower[in]); // updates motor power value
      in=1+in; // changes to next motor
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
  taskDelete(motor_task); // delets task when robot diabl
}


int slewcap(int value, int cap){
  //limits value of error term in slew
  if (value > cap){
    return cap;}
  else if(value < -cap){
    return -cap;}
  else {
    return value;}
  }
