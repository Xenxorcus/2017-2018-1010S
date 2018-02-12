#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

void autoDrive(int direction, int target, int timeout);

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd);

void mobileGoal(int direction, int target);

void lift(int direction, int target);

void fourbar(int direction, int target);

void autoStack(void*parameter);
TaskHandle autoStackHandle;

void fourAUp();

void fourADown();

void clawOpen();

void clawClose();

void stop();
#endif
