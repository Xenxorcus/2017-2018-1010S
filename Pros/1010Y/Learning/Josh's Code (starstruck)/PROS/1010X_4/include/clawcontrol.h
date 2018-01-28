#ifndef CLAWCONTROL_H_
#define CLAWCONTROL_H_

#include "API.h"

//claw definitions
  #define CLAW_MAX 3030
  #define CLAW_CLOSED 275
  #define CLAW_SEMI_OPEN 1100
  #define CLAW_PARALLEL 2000
  #define CLAW_REALMAX 3360
//claw tasks
  TaskHandle clawcontrol_drive;
  TaskHandle clawcontrol_auto;
  void clawcontrol(void *ignore);

//claw functions
  void clawpresets();

//claw_pid globals
  //varible
  int claw_power_L;
  int claw_power_R;
  int claw_error;
  int claw_pos;
  int claw_target;

  //constants
 float claw_k_proportion = 0.18;
 float claw_k_integral = 0;
 float claw_integral_activezone = 100;
 float claw_k_derivative = 0;
 int claw_deaccel_delay = 100;
 int claw_joystickrange = 15;

#endif
