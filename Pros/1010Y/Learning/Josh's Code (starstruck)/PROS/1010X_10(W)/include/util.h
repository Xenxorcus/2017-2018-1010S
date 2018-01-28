#ifndef UTIL_H_
#define UTIL_H_

#include "main.h"

int motorcap(int value);

void motorset_arm(int power);

void motorset_claw(int power);

void motorset_drive_auto(int Lpower, int Rpower);

void motorset_drive_op(int Lpower, int Rpower);

float gyro_read(Gyro port, int multiplier);

float pe_batt(int analogport);

void slewset(bool t_slewcontrol, bool t_slewcontrol_drive, bool t_slewcontrol_arm, bool t_slewcontrol_claw);
#endif
