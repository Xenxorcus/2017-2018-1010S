#include  "main.h"
#include  "util.h"
#include  "motor.h"
 // standdard drive speed
int originalTrueSpeed[128] =
// joystick remappeding (USED)
{1, 2,3,4,5,6,7,8,9,10,11,12,13,
14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,
46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,
70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,
95,96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,
113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,128};




/*
{ // original TRUE SPEED
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	20, 21, 21, 21, 22, 22, 22, 23, 24, 24,
	25, 25, 25, 25, 26, 27, 27, 28, 28, 28,
	28, 29, 30, 30, 30, 31, 31, 32, 32, 32,
	33, 33, 34, 34, 35, 35, 35, 36, 36, 37,
	37, 37, 37, 38, 38, 39, 39, 39, 40, 40,
	41, 41, 42, 42, 43, 44, 44, 45, 45, 46,
	46, 47, 47, 48, 48, 49, 50, 50, 51, 52,
	52, 53, 54, 55, 56, 57, 57, 58, 59, 60,
	61, 62, 63, 64, 65, 66, 67, 67, 68, 70,
	71, 72, 72, 73, 74, 76, 77, 78, 79, 79,
	80, 81, 83, 84, 84, 86, 86, 87, 87, 88,
	88, 89, 89, 90, 90, 127, 127, 127
};
*/

int motorcap(int value){
    //used to cap motor accel and power terms for auto functions, allowing error term to have impact
  if (value > 127){
    return 127;}
  else if(value < -127){
    return -127;}
  else {
    return value;}
  }

void motorset_claw(int power){
  //updates motor command to claw thourgh slew
  motortarget[ClawR-1] = ClawR_Dir*power;
    /*motorSet(ClawR, ClawR_Dir*power);*/ // old motor command update
  }

void motorset_arm(int power){
  //old mootr command update
  /*motorSet(ArmLT, ArmLT_Dir*power);
  motorSet(ArmRT, ArmRT_Dir*power);
  motorSet(ArmLB, ArmLB_Dir*power);
  motorSet(ArmLO, ArmLO_Dir*power);
  motorSet(ArmRO, ArmRO_Dir*power);*/

  //updates motor command to arm thourgh slew
  motortarget[ArmLT-1] = ArmLT_Dir*power;
  motortarget[ArmRT-1] = ArmRT_Dir*power;
  motortarget[ArmLM-1] = ArmLM_Dir*power;
  motortarget[ArmRM-1] = ArmRM_Dir*power;
  motortarget[ArmOFF-1] = ArmOFF_Dir*power;

  }

void motorset_drive_auto(int Lpower, int Rpower){
  //for drive base updates in auto
  // needed for debugging from slew and joystick remapping

  // old drive motor updates
/*  motorSet(DriveBL, DriveBL_Dir*Lpower);
  motorSet(DriveFL, DriveFL_Dir*Lpower);
  motorSet(DriveBR, DriveBR_Dir*Rpower);
  motorSet(DriveFR, DriveFR_Dir*Rpower);*/
  int Ldirection;
  int Rdirection;

  //determines direction of motor power
  ///abs value needed for jotstick remapping
  ////////////////////(DIFFERENT SINCE AUTO function exclusive)//////////////////////
  if(Lpower < 0){Ldirection = -1;}
    else{Ldirection = 1;}
  if(Rpower < 0){Rdirection = -1;}
    else{Rdirection = 1;}

  motortarget[DriveBL-1] = Ldirection*DriveBL_Dir*abs(Lpower);
  motortarget[DriveFL-1] = Ldirection*DriveFL_Dir*abs(Lpower);
  motortarget[DriveBR-1] = Rdirection*DriveBR_Dir*abs(Rpower);
  motortarget[DriveFR-1] = Rdirection*DriveFR_Dir*abs(Rpower);
  // minus 1 required since using motor port definitions from main.h
}


void motorset_drive_op(int Lpower, int Rpower){
  //for drive base updates in opcontrol

  // old drive motor updates
/*  motorSet(DriveBL, DriveBL_Dir*Lpower);
  motorSet(DriveFL, DriveFL_Dir*Lpower);
  motorSet(DriveBR, DriveBR_Dir*Rpower);
  motorSet(DriveFR, DriveFR_Dir*Rpower);*/
  int Ldirection;
  int Rdirection;

  //determines direction of motor power
  ///abs value needed for jotstick remapping
  if(Lpower < 0){Ldirection = -1;}
    else{Ldirection = 1;}
  if(Rpower < 0){Rdirection = -1;}
    else{Rdirection = 1;}

    motortarget[DriveBL-1] = Ldirection*DriveBL_Dir*originalTrueSpeed[abs(Lpower)];
  motortarget[DriveFL-1] = Ldirection*DriveFL_Dir*originalTrueSpeed[abs(Lpower)];
  motortarget[DriveBR-1] = Rdirection*DriveBR_Dir*originalTrueSpeed[abs(Rpower)];
  motortarget[DriveFR-1] = Rdirection*DriveFR_Dir*originalTrueSpeed[abs(Rpower)];
  // minus 1 required since using motor port definitions from main.h
  // original truespeed array for joystick remapping
}


float gyro_read(Gyro port, int multiplier){
  // returns gryo values adjusted by multiplier
  return gyroGet(port)+ gyro_offset;/**(1960/multiplier)*/;
}

float pe_batt(int analogport){
  // returns pe_battery level (NOT WORKING, CONVERSION VALUES WRONG)
  return (analogRead(analogport)/45.6)*1000;
}

void slewset(bool t_slewcontrol, bool t_slewcontrol_drive, bool t_slewcontrol_arm, bool t_slewcontrol_claw){
  // sets binarys to enable or diable slew in auto or op control (used for debugging)
  slewcontrol = t_slewcontrol; // all aspect of slew
  slewcontrol_drive = t_slewcontrol_drive; // just drive
  slewcontrol_arm = t_slewcontrol_arm; // just arm
  slewcontrol_claw = t_slewcontrol_claw; // just claw

}
