#include "main.h"
#include <math.h>
#include <stdlib.h>

int motorcap_int (double value){
  if (value >= 127)
    return 127;
  else if (value <= -127)
    return -127;
  else
    return (int) value;
  }

int motorcap_double (double value){
  if(value >= 127){return 127;}
  else if(value <= -127){return -127;}
  else{return (int)value;}
}

//3 = back
//4 = left
//5 = Forward-Right
//6 = Backward-Right
//7 = Backward-Left
//8 = Forward-Left
void drivestraight(int direction, int total_tics, int target_speed, int power_default, float accel_frac, float deaccel_frac, float kp, int timeout){

  int dist_total = 0;
  int power_FL;
  int power_FR;
  int power_BL;
  int power_BR;
  double last_tics_FL = 0;
  double last_tics_FR = 0;
  double last_tics_BL = 0;
  double last_tics_BR = 0;
  //declare ime varibles
  int ime_value_BL;
  int ime_value_BR;
  //reset
  encoderReset(encoderFL);
  encoderReset(encoderFR);
  imeReset(ime_BL);
  imeReset(ime_BR);
  //as target speed changes
  int original_target_speed = target_speed;
  int starttime = millis();

  while(dist_total < total_tics){
    //calculate target (accel and deaccel)
    if(dist_total <= total_tics*accel_frac){
      target_speed = original_target_speed * ( total_tics / (accel_frac*dist_total)  );}
    else if(dist_total >= (total_tics-(total_tics*deaccel_frac))){
      target_speed = original_target_speed*((total_tics-dist_total)/(total_tics*deaccel_frac));
      kp = 5;
    }
    else {
      target_speed = original_target_speed;}

    //get imes values + encoder values
    imeGet(ime_BL, &ime_value_BL);
    imeGet(ime_BR, &ime_value_BR);

    double tics_FL = labs(encoderGet(encoderFL));
    double tics_FR = labs(encoderGet(encoderFR));
    double tics_BL = labs(ime_value_BL*(360/261.333));
    double tics_BR = labs(ime_value_BR*(360/261.333));

    double delta_tics_FL = tics_FL - last_tics_FL;
    double delta_tics_FR = tics_FR - last_tics_FR;
    double delta_tics_BL = tics_BL - last_tics_BL;
    double delta_tics_BR = tics_BR - last_tics_BR;

    last_tics_FL = tics_FL;
    last_tics_FR = tics_FR;
    last_tics_BL = tics_BL;
    last_tics_BR = tics_BR;

    //calculate error
    double error_FL = target_speed - delta_tics_FL;
    double error_FR = target_speed - delta_tics_FR;
    double error_BL = target_speed - delta_tics_BL;
    double error_BR = target_speed - delta_tics_BR;

    // total distance
    dist_total = (abs(encoderGet(encoderFL)) + abs(encoderGet(encoderFR)) + abs((imeGet(ime_BL, &ime_value_BL)*(360/261.333))) + abs((imeGet(ime_BR, &ime_value_BR)*(360/261.333))))/4;

      switch (direction) {
        case 1: //forward - north
          power_FL = (motorcap_int(power_default + (error_FL*kp)));
          power_FR = (motorcap_int(power_default + (error_FR*kp)));
          power_BL = (motorcap_int(power_default + (error_BL*kp)));
          power_BR = (motorcap_int(power_default + (error_BR*kp)));
          /* for testing delta value
          power_FL = 127;
          power_BL = 127;
          power_BR = 127;
          power_FR = 127;
          */
        break;
        case 2://right - east
          power_FL = motorcap_int(power_default + (error_FL*kp));
          power_FR = motorcap_int(-1*(power_default + (error_FR*kp)));
          power_BL = motorcap_int(-1*(power_default + (error_BL*kp)));
          power_BR = motorcap_int((power_default + (error_BR*kp)));
        break;
        case 3://backwards - south
          power_FL = -1*(power_default + (error_FL*kp));
          power_FR = -1*(power_default + (error_FR*kp));
          power_BL = -1*(power_default + (error_BL*kp));
          power_BR = -1*(power_default + (error_BR*kp));
        break;
        case 4://left - west
          power_FL = -1*(power_default + (error_FL*kp));
          power_FR = (power_default + (error_FR*kp));
          power_BL = (power_default + (error_BL*kp));
          power_BR = -1*(power_default + (error_BR*kp));
        break;
        case 5://forward right - northeast
          power_FL = (power_default + (error_FL*kp));
          power_FR = 0*(power_default + (error_FR*kp));
          power_BL = 0*(power_default + (error_BL*kp));
          power_BR = (power_default + (error_BR*kp));
        break;
        case 6://backwards right - south east
          power_FL = 0*(power_default + (error_FL*kp));
          power_FR = -1*(power_default + (error_FR*kp));
          power_BL = -1*(power_default + (error_BL*kp));
          power_BR = 0*(power_default + (error_BR*kp));
        break;
        case 7:// backwards left - south west
          power_FL = -1*(power_default + (error_FL*kp));
          power_FR = 0*(power_default + (error_FR*kp));
          power_BL = 0*(power_default + (error_BL*kp));
          power_BR = -1*(power_default + (error_BR*kp));
        break;
        case 8: // forwards left - northwest
          power_FL = 0*(power_default + (error_FL*kp));
          power_FR = (power_default + (error_FR*kp));
          power_BL = (power_default + (error_BL*kp));
          power_BR = 0*(power_default + (error_BR*kp));
        break;
        default:
        break;
      }
      //set motor speeds
      motorSet(DriveFL, DriveFL_Dir*power_FL);
      motorSet(DriveFR, DriveFR_Dir*power_FR);
      motorSet(DriveBL, DriveBL_Dir*power_BL);
      motorSet(DriveBR, DriveBR_Dir*power_BR);

      //debug lcd
      //lcdPrint(uart1, 1, "erBL=%f", error_BL);
      //lcdPrint(uart1, 2, "pBL=%d", power_BL);

      long currenttime = millis();
      if((currenttime-starttime)>timeout)
      {break;}

      delay(30);
    }
  motorSet(DriveFL, 0);
  motorSet(DriveFR, 0);
  motorSet(DriveBL, 0);
  motorSet(DriveBR, 0);
}

void turnexact(int direction, int target_degrees, int target_speed, int power_default, float accel_frac, float deaccel_frac, float kp, int timeout){
  int total_degrees = 0;
  int power_FL;
  int power_FR;
  int power_BL;
  int power_BR;
  int ime_value_BL;
  int ime_value_BR;
  int original_target_speed = target_speed;
  int last_tics_FL = 0;
  int last_tics_FR = 0;
  int last_tics_BL = 0;
  int last_tics_BR = 0;
  int starttime = millis();

  encoderReset(encoderFL);
  encoderReset(encoderFR);
  imeReset(ime_BL);
  imeReset(ime_BR);
  gyroReset(gyro);

  while(total_degrees < target_degrees){

    if(total_degrees <= target_degrees*accel_frac){
      target_speed = original_target_speed * ( target_degrees/(accel_frac*total_degrees)  );}
    else if(total_degrees >= (target_degrees-(target_degrees*deaccel_frac))){
      target_speed = original_target_speed*((target_degrees-total_degrees)/(target_degrees*deaccel_frac));}
    else {
      target_speed = original_target_speed;}

    imeGet(ime_BL, &ime_value_BL);
    imeGet(ime_BR, &ime_value_BR);

    int tics_FL = abs(encoderGet(encoderFL));
    int tics_FR = abs(encoderGet(encoderFR));
    int tics_BL = abs(ime_value_BL*(360/261.333));
    int tics_BR = abs(ime_value_BR*(360/261.333));

    int delta_tics_FL = tics_FL - last_tics_FL;
    int delta_tics_FR = tics_FR - last_tics_FR;
    int delta_tics_BL = tics_BL - last_tics_BL;
    int delta_tics_BR = tics_BR - last_tics_BR;

    last_tics_FL = tics_FL;
    last_tics_FR = tics_FR;
    last_tics_BL = tics_BL;
    last_tics_BR = tics_BR;

    //calculate error
    int error_FL = target_speed - delta_tics_FL;
    int error_FR = target_speed - delta_tics_FR;
    int error_BL = target_speed - delta_tics_BL;
    int error_BR = target_speed - delta_tics_BR;

    total_degrees = abs(gyroGet(gyro));

    power_FL = direction*(power_default + (error_FL*kp));
    power_FR = -direction*(power_default + (error_FR*kp));
    power_BL = direction*(power_default + (error_BL*kp));
    power_BR = -direction*(power_default + (error_BR*kp));

    motorSet(DriveFL, DriveFL_Dir*power_FL);
    motorSet(DriveFR, DriveFR_Dir*power_FR);
    motorSet(DriveBL, DriveBL_Dir*power_BL);
    motorSet(DriveBR, DriveBR_Dir*power_BR);

    long currenttime = millis();
    if((currenttime-starttime)>timeout)
    {break;}

    delay(30);
    }
  motorSet(DriveFL, 0);
  motorSet(DriveFR, 0);
  motorSet(DriveBL, 0);
  motorSet(DriveBR, 0);
}

void disable_functions(void *ignore){
    bool loop = true;
  while (loop){
    delay(60);
    if(!isAutonomous()){
      taskDelete(armtaskpid);
      taskDelete(clawtaskpid);}
      else{}
      if(!isAutonomous())
        {break;}
  }
}
