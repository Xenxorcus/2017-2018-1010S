#ifndef LCDFUNCTIONS_H_
#define LCDFUNCTIONS_H_

#include "API.h"

extern int myauto;

void disablelcd(void *ignore);
void opcontrollcd(void *ignore);
void autolcd(void *ignore);

TaskHandle disable_lcd;
TaskHandle opcontrol_lcd;
TaskHandle auto_lcd;

#endif
