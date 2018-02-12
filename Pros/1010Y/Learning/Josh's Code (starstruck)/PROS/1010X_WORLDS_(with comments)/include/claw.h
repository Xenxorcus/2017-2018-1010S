#ifndef CLAW_H_
#define CLAW_H_

#include "main.h"
#include "pid.h"

PID_terms pid_claw;

int claw_target_global; // declaration of target varible for claw P(ID)
int claw_pos_global; // declaration of position varible for claw P(ID)

/////////////////////varibles used in claw task autonomous
// for releasing claw when going up
bool c_release;  // tells whether enabled
int c_release_timeout; // timeout value
int c_release_arm; // arm position when claw releases
int c_release_target; // new claw target

int c_release_start_time; // used in timeout for claw release
int c_release_net_time; // used in timeout for claw release

// for hanging releasing claw when going up
bool c_hang; // tells whether enabled
int c_hang_arm ; // arm target when claw releases
int c_hang_target; // new claw target
///////////////////////////


//old claw pid terms and varibles below
/*
PID_terms pid_claw_L;
PID_terms pid_claw_R;

int claw_target_global_L;
int claw_pos_global_L;

int claw_target_global_R;
int claw_pos_global_R;

#define CLAW_OFFSET_UP 0
#define CLAW_OFFSET_DOWN 0;
*/

void clawpresets(); // declaration of claw preset fucntion
void clawtask(void*ignore); // task delcaration of claw P(ID) code

#define CLAW_DELAY 200 // used to reducing lag from op_control claw contoller (the lag in closing or opening with buttons)

TaskHandle claw_task; // claw task declaration

#endif
