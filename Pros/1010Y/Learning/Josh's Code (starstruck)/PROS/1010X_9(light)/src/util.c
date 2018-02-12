#include "main.h"
#include "util.h"


int motorcap(int value){
  if (value > 127){
    return 127;}
  else if(value < -127){
    return -127;}
  else {
    return value;}
  }

void motorset_claw(int power){
  //motorSet(ClawL, ClawL_Dir*power);
  motorSet(ClawR, ClawR_Dir*power);
  }

void motorset_arm(int power){
  motorSet(ArmL, ArmL_Dir*power);
  motorSet(ArmR, ArmR_Dir*power);
  motorSet(ArmOFF, ArmOFF_Dir*power);

  }

void motorset_drive(int Lpower, int Rpower){

  motorSet(DriveBL, DriveBL_Dir*Lpower);
  motorSet(DriveFL, DriveFL_Dir*Lpower);
  motorSet(DriveML, DriveML_Dir*Lpower);
  motorSet(DriveBR, DriveBR_Dir*Rpower);
  motorSet(DriveFR, DriveFR_Dir*Rpower);
  motorSet(DriveMR, DriveMR_Dir*Rpower);
}

float gyro_read(Gyro port, int multiplier){
  return gyroGet(port)/**(1960/multiplier)*/;
  }

float pe_batt(int analogport){
  return (analogRead(analogport)/45.6)*1000;
}
