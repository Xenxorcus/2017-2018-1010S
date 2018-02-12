#include "main.h"
#include "autofunctions.h"
#include "clawarmextern.h"
#include <math.h>
#include <stdlib.h>


int motorcap_int (int value){
  if (value >= 127)
    return 127;
  else if (value <= -127)
    return -127;
  else
    return value;
  }

void nolag(int direction, int tic_limit, int power){

  int ime_value_BL;
  int ime_value_BR;

  bool nolag_FL = false;
  bool nolag_FR = false;
  bool nolag_BL = false;
  bool nolag_BR = false;

  int orien_FL;
  int orien_FR;
  int orien_BL;
  int orien_BR;

  switch (direction) {
    case 1:
      orien_BL = 1;
      orien_BR = 1;
      orien_FR = 1;
      orien_FL = 1;
    break;
    case 2:
      orien_BL = -1;
      orien_BR = 1;
      orien_FR = -1;
      orien_FL = 1;
    break;
    case 3:
      orien_BL = -1;
      orien_BR = -1;
      orien_FR = -1;
      orien_FL = -1;
    break;
    case 4:
      orien_BL = 1;
      orien_BR = -1;
      orien_FR = 1;
      orien_FL = -1;
    break;
    case 5:
      orien_BL = 0;
      orien_BR = 1;
      orien_FR = 0;
      orien_FL = 1;
    break;
    case 6:
      orien_BL = -1;
      orien_BR = 0;
      orien_FR = -1;
      orien_FL = 0;
    break;
    case 7:
      orien_BL = 0;
      orien_BR = -1;
      orien_FR = 0;
      orien_FL = -1;
    break;
    case 8:
      orien_BL = 1;
      orien_BR = 0;
      orien_FR = 1;
      orien_FL = 0;
    break;
    default:
      orien_BL = 1;
      orien_BR = 1;
      orien_FR = 1;
      orien_FL = 1;
    break;
  }

  encoderReset(encoderFL);
  encoderReset(encoderFR);
  imeReset(ime_BL);
  imeReset(ime_BR);

  while(!nolag_BL || !nolag_BR || !nolag_FR || !nolag_FL){
    delay(20);
    imeGet(ime_BL, &ime_value_BL);
    imeGet(ime_BR, &ime_value_BR);

    if(abs(encoderGet(encoderFL)) < tic_limit){
        motorSet(DriveFL, orien_FL * power * DriveFL_Dir);}
    else{
        motorSet(DriveFL, 0);
        nolag_FL = true;}

    if(abs(encoderGet(encoderFR)) < tic_limit){
        motorSet(DriveFR, orien_FR * power * DriveFR_Dir);}
    else{
        motorSet(DriveFR, 0);
        nolag_FR = true;}

    if(abs(ime_value_BL*(360/261.333)) < tic_limit){
        motorSet(DriveBL, orien_BL * power * DriveBL_Dir);}
    else{
        motorSet(DriveBL, 0);
        nolag_BL = true;}

    if(abs(ime_value_BR*(360/261.333)) < tic_limit){
        motorSet(DriveBR, orien_BR * power * DriveBR_Dir);}
    else{
        motorSet(DriveBR, 0);
        nolag_BR = true;}
      }

}

void drivehalt(int direction, int lapse, float kp, float k_gyro){

  int orien_FL;
  int orien_FR;
  int orien_BL;
  int orien_BR;

  switch (direction) {
    case 1:
      orien_BL = 1;
      orien_BR = 1;
      orien_FR = 1;
      orien_FL = 1;
    break;
    case 2:
      orien_BL = -1;
      orien_BR = 1;
      orien_FR = -1;
      orien_FL = 1;
    break;
    case 3:
      orien_BL = -1;
      orien_BR = -1;
      orien_FR = -1;
      orien_FL = -1;
    break;
    case 4:
      orien_BL = 1;
      orien_BR = -1;
      orien_FR = 1;
      orien_FL = -1;
    break;
    case 5:
      orien_BL = 0;
      orien_BR = 1;
      orien_FR = 0;
      orien_FL = 1;
    break;
    case 6:
      orien_BL = -1;
      orien_BR = 0;
      orien_FR = -1;
      orien_FL = 0;
    break;
    case 7:
      orien_BL = 0;
      orien_BR = -1;
      orien_FR = 0;
      orien_FL = -1;
    break;
    case 8:
      orien_BL = 1;
      orien_BR = 0;
      orien_FR = 1;
      orien_FL = 0;
    break;
    default:
      orien_BL = 1;
      orien_BR = 1;
      orien_FR = 1;
      orien_FL = 1;
    break;
  }

  int tics_FL;
  int tics_FR;
  int tics_BL;
  int tics_BR;

  int ime_value_BL;
  int ime_value_BR;

  encoderReset(encoderFL);
  encoderReset(encoderFR);
  imeReset(ime_BL);
  imeReset(ime_BR);

  int start_time = millis();

  int gyro_zero = gyroGet(gyro);

  while((millis() - start_time) < lapse){

    imeGet(ime_BL, &ime_value_BL);
    imeGet(ime_BR, &ime_value_BR);
    tics_FL = abs(encoderGet(encoderFL));
    tics_FR = abs(encoderGet(encoderFR));
    tics_BL = abs(ime_value_BL*(360/261.333));
    tics_BR = abs(ime_value_BR*(360/261.333));

    int error_FL = 0 - tics_FL;
    int error_FR = 0 - tics_FR;
    int error_BL = 0 - tics_BL;
    int error_BR = 0 - tics_BR;

    int gyro_error = gyroGet(gyro) - gyro_zero;
    //clockwise is +
    //counter is -

    motorSet(DriveFL, orien_FL*( (DriveFL_Dir*error_FL * kp) - (gyro_error*k_gyro) ) );
    motorSet(DriveFR, orien_FR*( (DriveFR_Dir*error_FR * kp) + (gyro_error*k_gyro) ) );
    motorSet(DriveBL, orien_BL*( (DriveBL_Dir*error_BL * kp) - (gyro_error*k_gyro) ) );
    motorSet(DriveBR, orien_BR*( (DriveBR_Dir*error_BR * kp) + (gyro_error*k_gyro) ) );

    delay(20);

  }
  motorSet(DriveFL, 0);
  motorSet(DriveFR, 0);
  motorSet(DriveBL, 0);
  motorSet(DriveBR, 0);

}

void newdrive(int direction, int total_tics, int target_min, int target_max, float kskew_max, float kskew_min, float k_gyro, int timeout){

  int orien_FL;
  int orien_FR;
  int orien_BL;
  int orien_BR;

  switch (direction) {
    case 1:
      orien_BL = 1;
      orien_BR = 1;
      orien_FR = 1;
      orien_FL = 1;
    break;
    case 2:
      orien_BL = -1;
      orien_BR = 1;
      orien_FR = -1;
      orien_FL = 1;
    break;
    case 3:
      orien_BL = -1;
      orien_BR = -1;
      orien_FR = -1;
      orien_FL = -1;
    break;
    case 4:
      orien_BL = 1;
      orien_BR = -1;
      orien_FR = 1;
      orien_FL = -1;
    break;
    case 5:
      orien_BL = 0;
      orien_BR = 1;
      orien_FR = 0;
      orien_FL = 1;
    break;
    case 6:
      orien_BL = -1;
      orien_BR = 0;
      orien_FR = -1;
      orien_FL = 0;
    break;
    case 7:
      orien_BL = 0;
      orien_BR = -1;
      orien_FR = 0;
      orien_FL = -1;
    break;
    case 8:
      orien_BL = 1;
      orien_BR = 0;
      orien_FR = 1;
      orien_FL = 0;
    break;
    default:
      orien_BL = 1;
      orien_BR = 1;
      orien_FR = 1;
      orien_FL = 1;
    break;
  }

  int accel_tics = 0;
  int deaccel_tics = 0;

  int encoder_average = 0;

  int power_FL;
  int power_FR;
  int power_BL;
  int power_BR;

  int tics_FL;
  int tics_FR;
  int tics_BL;
  int tics_BR;

  int ime_value_BL;
  int ime_value_BR;

  int timestart = millis();

  encoderReset(encoderFL);
  encoderReset(encoderFR);
  imeReset(ime_BL);
  imeReset(ime_BR);

  int target_speed;
  int target_net = target_max - target_min;
  float kskew;
  float kskew_net = kskew_max - kskew_min;

  int gyro_zero = gyroGet(gyro);

  delay(50);

  while((encoder_average < total_tics) && ( (millis() - timestart) < timeout)){

    encoderReset(encoderFL);
    encoderReset(encoderFR);
    imeReset(ime_BL);
    imeReset(ime_BR);

    delay(30);

    if(encoder_average < accel_tics){
        target_speed = target_min + (encoder_average/accel_tics)*target_net;
        kskew = ((encoder_average/accel_tics)*kskew_net) + kskew_min;
        }
    else if ((total_tics - encoder_average) < deaccel_tics){
        target_speed = target_min + ((total_tics - encoder_average)/deaccel_tics)*target_net;
        kskew = ((total_tics - encoder_average)/deaccel_tics)*kskew_net + kskew_min;}
    else {
        target_speed = target_min + target_net;
        kskew = kskew_min + kskew_net;}

    imeGet(ime_BL, &ime_value_BL);
    imeGet(ime_BR, &ime_value_BR);

    tics_FL = abs(encoderGet(encoderFL));
    tics_FR = abs(encoderGet(encoderFR));
    tics_BL = abs(ime_value_BL*(360/261.333));
    tics_BR = abs(ime_value_BR*(360/261.333));

    encoder_average = encoder_average + ((tics_FL + tics_FR + tics_BL + tics_BR)/4);

    int error_FL = target_speed - tics_FL;
    int error_FR = target_speed - tics_FR;
    int error_BL = target_speed - tics_BL;
    int error_BR = target_speed - tics_BR;

    int gyro_error = gyroGet(gyro) - gyro_zero;

    //lcdPrint(uart1, 1, "tFL%d tFR%d", tics_FL, tics_FR);
    //lcdPrint(uart1, 2, "tBL%d tBR%d", tics_BL, tics_BR);

    power_FL = orien_FL*((error_FL*kskew) - (gyro_error*k_gyro));
    power_FR = orien_FR*((error_FR*kskew) + (gyro_error*k_gyro));
    power_BL = orien_BL*((error_BL*kskew) - (gyro_error*k_gyro));
    power_BR = orien_BR*((error_BR*kskew) + (gyro_error*k_gyro));

    motorSet(DriveFL, DriveFL_Dir*power_FL);
    motorSet(DriveFR, DriveFR_Dir*power_FR);
    motorSet(DriveBL, DriveBL_Dir*power_BL);
    motorSet(DriveBR, DriveBR_Dir*power_BR);
  }

  motorSet(DriveFL, 0);
  motorSet(DriveFR, 0);
  motorSet(DriveBL, 0);
  motorSet(DriveBR, 0);
}

void newturn(int direction, int total_degrees, int target_min, int target_max, float kskew_max, float kskew_min, int timeout){
  int current_degrees = 0;
  int accel_degrees = 0;
  int deaccel_degrees  = 0;

  int power_FL;
  int power_FR;
  int power_BL;
  int power_BR;

  int ime_value_BL;
  int ime_value_BR;

  int timestart = millis();

  int target_speed;
  int target_net = target_max - target_min;
  float kskew;
  float kskew_net = kskew_max - kskew_min;

  gyroReset(gyro);

  while((current_degrees < total_degrees) && ((millis()-timestart) < timeout)) {
      encoderReset(encoderFL);
      encoderReset(encoderFR);
      imeReset(ime_BL);
      imeReset(ime_BR);

      delay(30);

      current_degrees = abs(gyroGet(gyro));

      if(current_degrees < accel_degrees){
          target_speed = target_min + (current_degrees/accel_degrees)*target_net;
          kskew = ((current_degrees/accel_degrees)*kskew_net) + kskew_min;
          }
      else if ((total_degrees - current_degrees) < deaccel_degrees){
          target_speed = target_min + ((total_degrees - current_degrees)/deaccel_degrees)*target_net;
          kskew = ((total_degrees - current_degrees)/deaccel_degrees)*kskew_net + kskew_min;}
      else {
          target_speed = target_min + target_net;
          kskew = kskew_min + kskew_net;}

      imeGet(ime_BL, &ime_value_BL);
      imeGet(ime_BR, &ime_value_BR);

      int tics_FL = abs(encoderGet(encoderFL));
      int tics_FR = abs(encoderGet(encoderFR));
      int tics_BL = abs(ime_value_BL*(360/261.333));
      int tics_BR = abs(ime_value_BR*(360/261.333));

      int error_FL = target_speed - tics_FL;
      int error_FR = target_speed - tics_FR;
      int error_BL = target_speed - tics_BL;
      int error_BR = target_speed - tics_BR;

      power_FL = direction*((error_FL*kskew));
      power_FR = -direction*((error_FR*kskew));
      power_BL = direction*((error_BL*kskew));
      power_BR = -direction*((error_BR*kskew));

      motorSet(DriveFL, DriveFL_Dir*power_FL);
      motorSet(DriveFR, DriveFR_Dir*power_FR);
      motorSet(DriveBL, DriveBL_Dir*power_BL);
      motorSet(DriveBR, DriveBR_Dir*power_BR);

    }
    motorSet(DriveFL, 0);
    motorSet(DriveFR, 0);
    motorSet(DriveBL, 0);
    motorSet(DriveBR, 0);
}

void checkdump(int clawrelease, int avoid_direction){

  int ultra_limit = 40;

  arm_target_L = ARM_LOWMID_L;
  arm_target_R = ARM_LOWMID_R;
  delay(500);

  if (ultrasonicGet(ultrasonic) < ultra_limit){
    newdrive(avoid_direction, 400, 30, 40, 15, 10, 02, 5000);}

  arm_target_L = ARM_MAX_L;
  arm_target_R = ARM_MAX_R;
  while(((abs(analogRead(potarmL)+potarmL_direction)+abs(analogRead(potarmR)+potarmR_direction))/2) < clawrelease){ delay(50);}
  claw_target = CLAW_PARALLEL;
  while (abs(analogRead(potclaw)+potclaw_direction) < CLAW_PARALLEL) {delay(50);}
  delay(100);
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  claw_target = CLAW_MAX;
  delay(100);
}

void standarddump(){
  int clawrelease = 2800;
  arm_target_L = ARM_MAX_L;
  arm_target_R = ARM_MAX_R;
  while(((abs(analogRead(potarmL)+potarmL_direction)+abs(analogRead(potarmR)+potarmR_direction))/2) < clawrelease){ delay(50);}
  claw_target = CLAW_PARALLEL;
  while (abs(analogRead(potclaw)+potclaw_direction) < CLAW_PARALLEL) {delay(50);}
  delay(100);
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  claw_target = CLAW_MAX;
  delay(100);
}
