#ifndef MAIN_H_
#define MAIN_H_
#include <API.h>
#ifdef __cplusplus
extern "C" {
#endif
void autonomous();
void initializeIO();
Encoder encoder;
Encoder encoder_L;
Encoder encoder_R;
Encoder encoderLift;

Gyro gyro;

int myauto;
void initialize();
void operatorControl();
#ifdef __cplusplus
}
#endif

#endif
