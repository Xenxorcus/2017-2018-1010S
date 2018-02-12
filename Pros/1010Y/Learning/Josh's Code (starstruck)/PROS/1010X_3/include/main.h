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
    #define potarmL_direction 0
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


//arm definitions
  #define OFFSET_ARM 105 //L-R
  #define ARM_MAX_L 3000
  #define ARM_MAX_R (3000 - OFFSET_ARM)
  #define ARM_GROUND_L 260
  #define ARM_GROUND_R (260 - OFFSET_ARM)
  #define ARM_MID_L 2000
  #define ARM_MID_R (2000 - OFFSET_ARM)
  #define ARM_REALMAX_L 3400
  #define ARM_REALMAX_R (3400 - OFFSET_ARM)
//arm tasks
  TaskHandle armtaskpid;
  TaskHandle armtaskpid_auto;
  void drive_armcontrol(void *ignore);
  void auto_armcontrol(void *ignore);
//arm functions
  void armpresets();

//claw definitions
  #define CLAW_MAX 3030
  #define CLAW_CLOSED 275
  #define CLAW_SEMI_OPEN 1100
  #define CLAW_PARALLEL 2000
  #define CLAW_REALMAX 3360
//claw tasks
  TaskHandle clawtaskpid;
  TaskHandle clawtaskpid_auto;
  void drive_clawcontrol(void *ignore);
  void auto_clawcontrol(void *ignore);
//claw functions
  void clawpresets();

  TaskHandle driver_lcd;
  void drive_lcd_task(void *ignore);

//auto functions
void drivestraight(
  int direction,
  int total_tics,
  int target_speed, //use 40
  int power_default, //use 50
  float accel_frac, //use 0.1
  float deaccel_frac, //use 0.05
  float kp, //use 15
  int timeout);

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4
#define NORTHEAST 5
#define SOUTHEAST 6
#define SOUTHWEST 7
#define NORTHWEST 8

void turnexact(
  int direction,
  int target_degrees,
  int target_speed,
  int power_default,
  float accel_frac,
  float deaccel_frac,
  float kp,
  int timeout);

#define CLOCKWISE 1
#define COUNTER_CLOCKWISE -1

TaskHandle autoselect;
void autoselector_code(void*ignore);
int myauto;

void disable_functions(void *ingore);





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
