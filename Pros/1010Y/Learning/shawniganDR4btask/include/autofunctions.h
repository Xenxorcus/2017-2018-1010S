#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

void autoDrive(int direction, int target);

void gyroTurn(int direction, int targetTurn);

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd);

void mobileGoalTwenty(int direction, int target);

void lift(int direction, int target);

void fourbar(int direction, int target);

void fourAUp();

void fourADown();

void stackTask(void*ignore);

TaskHandle stackAutoTask;

void stop();
#endif
