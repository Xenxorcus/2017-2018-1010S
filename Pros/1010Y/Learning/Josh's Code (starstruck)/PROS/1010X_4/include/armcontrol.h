#ifndef ARMPIDTERMS_H_
#define ARMPIDTERMS_H_

#include "API.h"

//arm definitions
  #define OFFSET_ARM 105 //L-R
  #define ARM_MAX_L 3000
  #define ARM_MAX_R (3000 - OFFSET_ARM)
  #define ARM_GROUND_L 260
  #define ARM_GROUND_R (260 - OFFSET_ARM)
  #define ARM_LOWMID_L 800
  #define ARM_LOWMID_R (800 - OFFSET_ARM)
  #define ARM_MID_L 2000
  #define ARM_MID_R (2000 - OFFSET_ARM)
  #define ARM_REALMAX_L 3400
  #define ARM_REALMAX_R (3400 - OFFSET_ARM)
//arm tasks
  TaskHandle armcontrol_drive;
  TaskHandle armcontrol_auto;
  void armcontrol(void *ignore);
//arm functions
  void armpresets();



//drive_pid globals
  //varibles
  int arm_power_L;
  int arm_power_R;
  int arm_height_L;
  int arm_height_R;
  int arm_error_L;
  int arm_error_R;
  int arm_target_L;
  int arm_target_R;
  int arm_skew;

  //constants
 float arm_k_skew = 0.15;
 float arm_k_proportion = 0.15;
 float arm_k_integral = 0;
 int arm_integral_activezone = 100;
 float arm_k_derivative = 0;
 int arm_deaccel_delay = 100;
 int arm_joystickrange = 15;

#endif
