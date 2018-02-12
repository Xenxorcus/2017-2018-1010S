
#ifndef MAIN_H_
#define MAIN_H_

#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif

#define rollers 1
#define liftTL 2

#define DriveFL 3
  #define DriveFL_Dir -1

#define mg 4

#define DriveBL 5
  #define DriveBL_Dir -1

#define DriveFR 6
  #define DriveFR_Dir -1

#define liftTR 7

#define DriveBR 8
  #define DriveBR_Dir -1

#define liftB 9
#define fourBar 10

#define dirL 1
#define dirR 1

Encoder encoderTen;
Encoder encoderL;
Encoder encoderR;
Gyro gyro;

int myauto;
<<<<<<< HEAD
int mgGlobalTarget;
int liftGlobalTarget;
int fourGlobalTarget;
int fourbar_function_running;
int rollerGlobalTarget;
int stack_function_running;
int stacking;
int driverStackingOn;
=======
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)

void autonomous();
void initializeIO();
void initialize();
void operatorControl();
#ifdef __cplusplus
}
#endif

#endif
