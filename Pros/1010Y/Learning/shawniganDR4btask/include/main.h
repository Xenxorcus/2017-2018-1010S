
#ifndef MAIN_H_
#define MAIN_H_

#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif

//back drive is 1
//drive forwards is -1
// 1 is clockwise
//-1 is counterclockwise

 //mg all the way in 1820
 //mg all the way out 235
 //mg score 1400
 //mg pick up safe 800

// fourbar up is -127
//fourbar down is 127
//fourbar down 3200, up 1200

//double reverse all the way up -470, all the way down is 0
//double reverse up is negative, down is positive


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

#define fourPot 1
#define mgPot 3


Encoder encoderTen;
Encoder encoderL;
Encoder encoderR;
Gyro gyro;

int myauto;
int mgGlobalTarget;
int liftGlobalTarget;
int fourGlobalTarget;
int fourbar_function_running;
int rollerGlobalTarget;
int stack_function_running;
int stacking;
int driverStackingOn;

void autonomous();
void initializeIO();
void initialize();
void operatorControl();
#ifdef __cplusplus
}
#endif

#endif
