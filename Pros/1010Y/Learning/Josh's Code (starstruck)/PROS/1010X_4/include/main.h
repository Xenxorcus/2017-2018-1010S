#ifndef MAIN_H_
// This prevents multiple inclusion, which isn't bad for this file but is good practice
#define MAIN_H_
#include <API.h>
// Allow usage of this file in C++ programs
#ifdef __cplusplus
extern "C" {
#endif

//drive motors ports
  #define DriveBL 2
    #define DriveBL_Dir 1
  #define DriveFL 1
    #define DriveFL_Dir -1
  #define DriveFR 10
    #define DriveFR_Dir 1
  #define DriveBR 9
    #define DriveBR_Dir -1

//Intake motors ports
  #define ClawL 8
    #define ClawL_Dir -1
  #define ClawR 3
    #define ClawR_Dir 1

//Arm motors ports
  #define ArmLT 7
    #define ArmLT_Dir 1
  #define ArmLB 6
    #define ArmLB_Dir 1
  #define ArmRT 4
    #define ArmRT_Dir -1
  #define ArmRB 5
    #define ArmRB_Dir 1

//analog sensors ports
  #define accel_x 3
  #define accel_y 4
  #define gyroport 5
  #define potarmR 6
    #define potarmR_direction 0
  #define potarmL 7
    #define potarmL_direction -4095
  #define potclaw 8
    #define potclaw_direction 0

//digital sensors ports
  #define encoderFR_TOP 5
  #define encoderFR_BOT 6

  #define encoderFL_TOP 1
  #define encoderFL_BOT 2

  #define encoderBR_TOP 11
  #define encoderBR_BOT 12

  #define encoderBL_TOP 7
  #define encoderBL_BOT 8

  #define ime_BL 1
  #define ime_BR 0
// Sensor Hanndles
  Encoder encoderFL;
  Encoder encoderFR;
  Encoder encoderBL;
  Encoder encoderBR;
  Gyro gyro;
  Ultrasonic ultrasonic;


//#define AUTO_DEBUG
// A function prototype looks exactly like its declaration, but with a semicolon instead of
// actual code. If a function does not match a prototype, compile errors will occur.

// Prototypes for initialization, operator control and autonomous
void autonomous();
void initializeIO();
void initialize();
void operatorControl();

// End C++ export structure
#ifdef __cplusplus
}
#endif

#endif
