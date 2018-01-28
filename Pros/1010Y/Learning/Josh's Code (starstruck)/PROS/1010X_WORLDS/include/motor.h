#ifndef MOTOR_H_
#define MOTOR_H_

#include "main.h"

int motortarget[10];
int motorpower[10];
int motorerror[10];
int motorport[10];

bool slewcontrol; // need to set
bool slewcontrol_drive;
bool slewcontrol_arm;
bool slewcontrol_claw;


int slewcap(int value, int cap);
void motortask(void*ignore);

TaskHandle motor_task;

#endif
