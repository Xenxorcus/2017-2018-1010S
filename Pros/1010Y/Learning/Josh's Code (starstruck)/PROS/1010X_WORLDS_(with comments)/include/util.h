#ifndef UTIL_H_
#define UTIL_H_

#include "main.h"

int motorcap(int value); // 127 motor cap

void motorset_arm(int power); // setting arm motors

void motorset_claw(int power); // setting claw motors

void motorset_drive_auto(int Lpower, int Rpower); // setting drive motors is auto

void motorset_drive_op(int Lpower, int Rpower); // setting drive motors in op_control

float gyro_read(Gyro port, int multiplier); // reading gyro - multiplier is for gyro tuning to convert new value to degrees

float pe_batt(int analogport); // power expander battery (NOT WORKING)

void slewset(bool t_slewcontrol, bool t_slewcontrol_drive, bool t_slewcontrol_arm, bool t_slewcontrol_claw); // enabling/disabling slew control( auto and op)
#endif
