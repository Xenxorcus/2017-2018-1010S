#ifndef AUTORUNS_H_
#define AUTORUNS_H_

#include "API.h"

extern int drive_armheight_L;
extern int drive_armheight_R;
extern int armtarget_L;
extern int armtarget_R;
extern int arm_skew;

  //constants
extern float arm_k_skew;
extern float arm_k_proportion;
extern float arm_k_integral;
extern int arm_integral_activezone;
extern float arm_k_derivative;
extern int arm_deaccel_delay;
extern int arm_joystickrange;


//claw_pid globals
  //varible
extern int claw_pos;
extern int clawtarget;
  //constants
extern float claw_k_proportion;
extern float claw_k_integral;
extern float claw_integral_activezone;
extern float claw_k_derivative;
extern int claw_deaccel_delay;
extern int claw_joystickrange;

//functions declarations
void lift_basic(int claw_release, int height_arm);

void auto0_programming();
void auto1_centerfence_R();
void auto2_centerfence_L();
void auto3_close_R();
void auto4_close_L();
void auto5_wall_R();
void auto6_wall_L();
void auto7_hang_R();
void auto8_hang_L();

#endif
