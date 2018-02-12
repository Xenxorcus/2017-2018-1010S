#ifndef ARMPIDTERMS_H_
#define ARMPIDTERMS_H_

#include "API.h"

//drive_pid globals
  //varibles
 int drive_armheight_L;
 int drive_armheight_R;
 int armtarget_L;
 int armtarget_R;
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
