#ifndef ARM_H_
#define ARM_H_

#include "main.h"
#include "pid.h"

PID_terms pid_arm;

int arm_target_global;
int arm_pos_global;

void armpresets();
void armtask(void*ignore);

#define ARM_DELAY 300

#define ARM_GROUND 0
#define ARM_LOW 200
#define ARM_PARALLEL 370
#define ARM_45 670
#define ARM_MAX 1100

TaskHandle arm_task;

#endif
