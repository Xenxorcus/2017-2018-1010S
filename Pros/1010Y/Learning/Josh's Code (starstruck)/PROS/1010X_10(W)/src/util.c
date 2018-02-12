#include "main.h"
#include "util.h"
#include "motor.h"

int originalTrueSpeed[128] = {
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

int motorcap(int value){
  if (value > 127){
    return 127;}
  else if(value < -127){
    return -127;}
  else {
    return value;}
  }

void motorset_claw(int power){
  /*motorSet(ClawR, ClawR_Dir*power);*/
  motortarget[ClawR-1] = ClawR_Dir*power;
  }

void motorset_arm(int power){
  /*motorSet(ArmLT, ArmLT_Dir*power);
  motorSet(ArmRT, ArmRT_Dir*power);
  motorSet(ArmLB, ArmLB_Dir*power);
  motorSet(ArmLO, ArmLO_Dir*power);
  motorSet(ArmRO, ArmRO_Dir*power);*/

  motortarget[ArmLT-1] = ArmLT_Dir*power;
  motortarget[ArmRT-1] = ArmRT_Dir*power;
  motortarget[ArmLB-1] = ArmLB_Dir*power;
  motortarget[ArmLO-1] = ArmLO_Dir*power;
  motortarget[ArmRO-1] = ArmRO_Dir*power;

  }

void motorset_drive_auto(int Lpower, int Rpower){

/*  motorSet(DriveBL, DriveBL_Dir*Lpower);
  motorSet(DriveFL, DriveFL_Dir*Lpower);
  motorSet(DriveBR, DriveBR_Dir*Rpower);
  motorSet(DriveFR, DriveFR_Dir*Rpower);*/
  int Ldirection;
  int Rdirection;

  if(Lpower < 0){Ldirection = -1;}
    else{Ldirection = 1;}
  if(Rpower < 0){Rdirection = -1;}
    else{Rdirection = 1;}

  motortarget[DriveBL-1] = Ldirection*DriveBL_Dir*abs(Lpower);
  motortarget[DriveFL-1] = Ldirection*DriveFL_Dir*abs(Lpower);
  motortarget[DriveBR-1] = Rdirection*DriveBR_Dir*abs(Rpower);
  motortarget[DriveFR-1] = Rdirection*DriveFR_Dir*abs(Rpower);

}


void motorset_drive_op(int Lpower, int Rpower){

/*  motorSet(DriveBL, DriveBL_Dir*Lpower);
  motorSet(DriveFL, DriveFL_Dir*Lpower);
  motorSet(DriveBR, DriveBR_Dir*Rpower);
  motorSet(DriveFR, DriveFR_Dir*Rpower);*/
  int Ldirection;
  int Rdirection;

  if(Lpower < 0){Ldirection = -1;}
    else{Ldirection = 1;}
  if(Rpower < 0){Rdirection = -1;}
    else{Rdirection = 1;}

  motortarget[DriveBL-1] = Ldirection*DriveBL_Dir*originalTrueSpeed[abs(Lpower)];
  motortarget[DriveFL-1] = Ldirection*DriveFL_Dir*originalTrueSpeed[abs(Lpower)];
  motortarget[DriveBR-1] = Rdirection*DriveBR_Dir*originalTrueSpeed[abs(Rpower)];
  motortarget[DriveFR-1] = Rdirection*DriveFR_Dir*originalTrueSpeed[abs(Rpower)];

}


float gyro_read(Gyro port, int multiplier){
  return gyroGet(port)+ gyro_offset;/**(1960/multiplier)*/;
}

float pe_batt(int analogport){
  return (analogRead(analogport)/45.6)*1000;
}

void slewset(bool t_slewcontrol, bool t_slewcontrol_drive, bool t_slewcontrol_arm, bool t_slewcontrol_claw){

  slewcontrol = t_slewcontrol;
  slewcontrol_drive = t_slewcontrol_drive;
  slewcontrol_arm = t_slewcontrol_arm;
  slewcontrol_claw = t_slewcontrol_claw;

}
