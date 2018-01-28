
#ifndef MAIN_H_
#define MAIN_H_

#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif

#define post 1
#define MG20 2

#define DriveFL 3
  #define DriveFL_Dir -1

#define DriveML 4
  #define DriveML_Dir -1

#define DriveBL 5
  #define DriveBL_Dir -1

#define DriveFR 6
  #define DriveFR_Dir -1

#define DriveMR 7
  #define DriveMR_Dir -1

#define DriveBR 8
  #define DriveBR_Dir -1

#define MG10 9
#define nothing 10

#define dirL 1
#define dirR 1

Encoder encoderTen;
Encoder encoderL;
Encoder encoderR;
Gyro gyro;

int myauto;

void autonomous();
void initializeIO();
void initialize();
void operatorControl();
#ifdef __cplusplus
}
#endif

#endif
