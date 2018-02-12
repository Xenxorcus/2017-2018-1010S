#ifndef CLAWPIDTERMS_H_
#define CLAWPIDTERMS_H_

#include "API.h"

//claw_pid globals
  //varible
 int claw_pos;
 int clawtarget;
  //constants
 float claw_k_proportion = 0.18;
 float claw_k_integral = 0;
 float claw_integral_activezone = 100;
 float claw_k_derivative = 0;
 int claw_deaccel_delay = 100;
 int claw_joystickrange = 15;

#endif
