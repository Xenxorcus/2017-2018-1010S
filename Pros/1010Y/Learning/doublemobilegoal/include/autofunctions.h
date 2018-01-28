#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

void autoDrive(int direction, int target);

void gyroTurn(int direction, int targetTurn);

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd);

void mobileGoalTen(int direction, int target);

void mobileGoalTwenty(int direction, int target);

void stop();
#endif
