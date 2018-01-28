#ifndef CLAW_H_
#define CLAW_H_

#include "main.h"
#include "pid.h"

PID_terms pid_claw;

int claw_target_global;
int claw_pos_global;

bool c_release;
int c_release_timeout;
int c_release_arm;
int c_release_target;

int c_release_start_time;
int c_release_net_time;
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

void clawpresets();
void clawtask(void*ignore);

#define CLAW_DELAY 200

#define CLAW_CLOSED 880
#define CLAW_V 800 //semi closed
#define CLAW_45 650
#define CLAW_PARALLEL 390
#define CLAW_MAX 30

TaskHandle claw_task;

#endif
