#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

int myauto;

int motorcap_int(int value);

void drivehalt(int direction, int lapse, float kp, float k_gyro);
void nolag(int direction, int tic_limit, int power);

void newdrive(
  int direction,
  int total_tics,
   int target_min,
   int target_max,
   float kskew_max,
   float kskew_min,
   float k_gyro,
   int timeout);

#define DEFAULT_drive_target_speed 40
#define DEFAULT_drive_minpower 50
#define DEFAULT_drive_ka 15
#define DEFAULT_drive_accel_dist 0
#define DEFAULT_drive_kd 15
#define DEFAULT_drive_deaccel_dist 1
#define DEFAULT_drive_kskew 10
#define DEFAULT_drive_timeout 10000

#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4
#define NORTHEAST 5
#define SOUTHEAST 6
#define SOUTHWEST 7
#define NORTHWEST 8

void newturn(
  int direction,
  int total_degrees,
  int target_min,
  int target_max,
  float kskew_max,
  float kskew_min,
  int timeout
  );

  #define DEFAULT_turn_target_speed 40
  #define DEFAULT_turn_minpower 50
  #define DEFAULT_turn_ka 10
  #define DEFAULT_turn_accel_dist 0.5
  #define DEFAULT_turn_kd 10
  #define DEFAULT_turn_deaccel_dist 0.5
  #define DEFAULT_turn_kskew 15
  #define DEFAULT_turn_timeout 10000


  #define CLOCKWISE 1
  #define COUNTER_CLOCKWISE -1

void checkdump(int clawrelease, int avoid_direction);
void standarddump();
#endif
