#ifndef ARM_H_
#define ARM_H_

#include "main.h"
#include "pid.h" // needed as reference to PID_terms

PID_terms pidarm_auto; // PId typedef
PID_terms pidarm_op; // pid  typedef

int arm_target_global; // declaration of target varible for arm P(ID) controller
int arm_pos_global; // delclaratino of target varible for arm P(ID) controller

void armpresets(); // declaration of function for arm preset values
void armtask(void*ignore); // task declaration of arm P(ID) function code

#define ARM_DELAY 300 // used in reducing lag from op_control arm contoller (the lag in going up or down with buttons)

TaskHandle arm_task; // arm task declaration

#endif
