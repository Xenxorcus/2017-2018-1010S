#ifndef ARM_H_
#define ARM_H_

#include "main.h"
#include "pid.h"

PID_terms pidarm_auto;
PID_terms pidarm_op;

int arm_target_global;
int arm_pos_global;

void armpresets();
void armtask(void*ignore);

#define ARM_DELAY 300

TaskHandle arm_task;

#endif
