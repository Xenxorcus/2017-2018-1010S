#ifndef LCDFUNCTIONS_H_
#define LCDFUNCTIONS_H_

#include "main.h"

// disabled LCD Task
void disablelcd(void*ignore); // code
TaskHandle disablelcd_task; // task

//op_control LCD Task
void opcontrollcd(void*ignore); // code
TaskHandle opcontrollcd_task; // task

//auto LCD Task
void autolcd(void*ignore); // code
TaskHandle autolcd_task; // task


void lcdtune(); // functions used for debugging faster

extern int myauto; // used for autonomous selection


//TEST VARIBLES////////////////

//none


//////////////////////////////

#endif
