#ifndef UTIL_H_
#define UTIL_H_

#include "main.h"

int motorcap(int value);

void motorset_arm(int power);

void motorset_claw(int power);

void motorset_drive(int Lpower, int Rpower);

float gyro_read(Gyro port, int multiplier);

float pe_batt(int analogport);
#endif
