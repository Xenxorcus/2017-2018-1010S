#ifndef MOTOR_H_
#define MOTOR_H_

#include "main.h"

// arrays for slew control
//10 is number of elements in array =   number of motors
int motortarget[10];
int motorpower[10];
int motorerror[10];
int motorport[10];

// bools for whether slew is enabled
bool slewcontrol; // need to set in auto or op control
bool slewcontrol_drive; //for disabling drive
bool slewcontrol_arm; // for disabling arm
bool slewcontrol_claw;// for disabling claw


int slewcap(int value, int cap); // similiar to
void motortask(void*ignore); // task declaration for slew control

TaskHandle motor_task; // task declaration

#endif
