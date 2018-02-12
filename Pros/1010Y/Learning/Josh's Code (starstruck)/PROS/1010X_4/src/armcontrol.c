#include "main.h"
#include "armcontrol.h"
#include <math.h>

void armcontrol (void *ignore)
  {
   int lasterror_L;
  int lasterror_R;
  int proportion_L;
  int proportion_R;
  int integral_L;
  int integral_R;
  int derivative_L;
  int derivative_R;

  //set target to current height
  arm_target_L = abs(analogRead(potarmL)+potarmL_direction);
  arm_target_R = abs(analogRead(potarmR)+potarmR_direction);

  while(true){

    //set value
    arm_height_L = abs(analogRead(potarmL)+potarmL_direction);
    arm_height_R = abs(analogRead(potarmR)+potarmR_direction);

    //find error
    arm_error_L = arm_target_L - arm_height_L;
    arm_error_R = arm_target_R - arm_height_R;

    //calculate P
    proportion_L = arm_error_L;
    proportion_R = arm_error_R;

    //intergral cap+calcualte I
    if(abs(arm_error_L) < arm_integral_activezone){integral_L = integral_L + (arm_error_L);}
    else{integral_L = 0;}
    if(abs(arm_error_R) < arm_integral_activezone){integral_R = integral_R + (arm_error_R);}
    else{integral_R = 0;}

    //calculate D
    derivative_L =  arm_error_L - lasterror_L;
    lasterror_L = arm_error_L;
    derivative_R =  arm_error_R - lasterror_R;
    lasterror_R = arm_error_R;

    //calcualte power values
    arm_power_L = (derivative_L*arm_k_derivative) + (integral_L*arm_k_integral)+(proportion_L*arm_k_proportion);
    arm_power_R = (derivative_R*arm_k_derivative) + (integral_R*arm_k_integral)+(proportion_R*arm_k_proportion);

    // (R - L) + OFF SET
    arm_skew = (arm_height_R - arm_height_L) + OFFSET_ARM;
  //driver
    if(!isAutonomous() && isEnabled()){

          if(isEnabled()){}
          else{taskDelete(armcontrol_drive);}

        if(joystickGetDigital(1,6,JOY_UP)){
          motorSet(ArmLT, (ArmLT_Dir*127)+(arm_skew*arm_k_skew));
          motorSet(ArmLB, (ArmLB_Dir*127)+(arm_skew*arm_k_skew));
          motorSet(ArmRT, (ArmRT_Dir*127)-(arm_skew*arm_k_skew));
          motorSet(ArmRB, (ArmRB_Dir*127)-(arm_skew*arm_k_skew));
          delay(arm_deaccel_delay);
          arm_target_L = abs(analogRead(potarmL)+potarmL_direction);
          arm_target_R = abs(analogRead(potarmR)+potarmR_direction);}

        else if(joystickGetDigital(1,6,JOY_DOWN)){
          motorSet(ArmLT, (ArmLT_Dir*-127)-(arm_skew*arm_k_skew));
          motorSet(ArmLB, (ArmLB_Dir*-127)-(arm_skew*arm_k_skew));
          motorSet(ArmRT, (ArmRT_Dir*-127)+(arm_skew*arm_k_skew));
          motorSet(ArmRB, (ArmRB_Dir*-127)+(arm_skew*arm_k_skew));
          delay(arm_deaccel_delay);
          arm_target_L = abs(analogRead(potarmL)+potarmL_direction);
          arm_target_R = abs(analogRead(potarmR)+potarmR_direction);}

          else if (joystickGetAnalog(2, 3) > arm_joystickrange){
            motorSet(ArmLT, (ArmLT_Dir*joystickGetAnalog(2, 3)));
            motorSet(ArmLB, (ArmLB_Dir*joystickGetAnalog(2, 3)));
            motorSet(ArmRT, (ArmRT_Dir*joystickGetAnalog(2, 3)));
            motorSet(ArmRB, (ArmRB_Dir*joystickGetAnalog(2, 3)));
            delay(arm_deaccel_delay);
            arm_target_L = abs(analogRead(potarmL)+potarmL_direction);
            arm_target_R = abs(analogRead(potarmR)+potarmR_direction);}

          else if (joystickGetAnalog(2, 3) < -arm_joystickrange){
            motorSet(ArmLT, (ArmLT_Dir*joystickGetAnalog(2, 3)));
            motorSet(ArmLB, (ArmLB_Dir*joystickGetAnalog(2, 3)));
            motorSet(ArmRT, (ArmRT_Dir*joystickGetAnalog(2, 3)));
            motorSet(ArmRB, (ArmRB_Dir*joystickGetAnalog(2, 3)));
            delay(arm_deaccel_delay);
            arm_target_L = abs(analogRead(potarmL)+potarmL_direction);
            arm_target_R = abs(analogRead(potarmR)+potarmR_direction);}
          else {
            motorSet(ArmLT, ArmLT_Dir*arm_power_L);
            motorSet(ArmLB, ArmLB_Dir*arm_power_L);
            motorSet(ArmRT, ArmRT_Dir*arm_power_R);
            motorSet(ArmRB, ArmRB_Dir*arm_power_R);}
      }
    //auto
      else if (isAutonomous() && isEnabled()){
        motorSet(ArmLT, ArmLT_Dir*arm_power_L);
        motorSet(ArmLB, ArmLB_Dir*arm_power_L);
        motorSet(ArmRT, ArmRT_Dir*arm_power_R);
        motorSet(ArmRB, ArmRB_Dir*arm_power_R);

        if(isAutonomous())
          {}
        else{taskDelete(armcontrol_auto);}
      }
      else{}

    //delay
    delay(25);
    }
  }

void armpresets(){
    if(joystickGetDigital(1,8,JOY_UP)){
      arm_target_L = ARM_MAX_L;
      arm_target_R = ARM_MAX_R;}
    else if(joystickGetDigital(1,8,JOY_DOWN)){
      arm_target_L = ARM_GROUND_L;
      arm_target_R = ARM_GROUND_R;}
    else if (joystickGetDigital(1,8,JOY_LEFT)){
      arm_target_L = ARM_LOWMID_L;
      arm_target_R = ARM_LOWMID_R;}
    else if(joystickGetDigital(1,8,JOY_RIGHT)){
      arm_target_L = ARM_MID_L;
      arm_target_R = ARM_MID_R;
    }
    else{}
  }
