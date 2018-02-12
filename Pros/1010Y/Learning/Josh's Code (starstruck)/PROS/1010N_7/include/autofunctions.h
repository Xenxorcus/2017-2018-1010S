#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_


#define FORWARD 1
#define BACKWARDS -1
#define CLOCKWISE 1
#define COUNTERCLOCKWISE -1

void drive_encoder(int direction, int target, int timeout, int maxpower, int minpower, float kdrift_encoder, float kaccel, float kdeaccel);

void drive_stop(int direction, int delta_trip, int maxpower, float kdrift_encoder);

void drive_gyro(int direction, int target, int timeout, int maxpower, int minpower, float kdrift_gyro, float kaccel, float kdeaccel);

void nolag(int demo_tics, int demo_movepower, int demo_holdpower);

void turn_gyro(int direction, int target, int timeout, int maxpower, int minpower, float kaccel, float kdeaccel);

void claw_release(int claw_target, int arm_pos, int timeout);

void turn_time(int direction, int target, int error_range, int error_time, int power, float ktune, float ktunezone);

void lock_encoder(int timeout, float kp);

#endif
