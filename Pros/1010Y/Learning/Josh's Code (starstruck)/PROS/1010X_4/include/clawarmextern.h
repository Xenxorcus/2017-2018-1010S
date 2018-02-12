#ifndef CLAWARMEXTERN_H_
#define CLAWARMEXTERN_H_

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
  extern int arm_power_L;
  extern int arm_power_R;
  extern int arm_height_L;
  extern int arm_height_R;
  extern int arm_error_L;
  extern int arm_error_R;
  extern int arm_target_L;
  extern int arm_target_R;
  extern int arm_skew;

//arm constants
extern float arm_k_skew;
extern float arm_k_proportion;
extern float arm_k_integral;
extern int arm_integral_activezone;
extern float arm_k_derivative ;
extern int arm_deaccel_delay;
extern int arm_joystickrange;

TaskHandle clawcontrol_drive;
TaskHandle clawcontrol_auto;
void clawcontrol(void *ignore);

//claw functions
void clawpresets();

//claw constants
extern float claw_k_proportion;
extern float claw_k_integral;
extern float claw_integral_activezone;
extern float claw_k_derivative;
extern int claw_deaccel_delay;
extern int claw_joystickrange;

#define CLAW_MAX 3030
#define CLAW_CLOSED 275
#define CLAW_SEMI_OPEN 1100
#define CLAW_PARALLEL 2000
#define CLAW_REALMAX 3360
//claw tasks

//claw_pid globals
//varible
extern int claw_power_L;
extern int claw_power_R;
extern int claw_error;
extern int claw_pos;
extern int claw_target;

#endif
