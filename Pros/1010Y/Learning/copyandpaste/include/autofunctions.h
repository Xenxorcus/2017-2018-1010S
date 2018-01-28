#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

void autoDrive(int direction, int target);

void gyroTurn(int direction, int targetTurn);

void mobileGoalOut(int target);

void mobileGoalIn(int target);

void armDown(int target, int side);

void armUp(int target, int side);

void clawOpenIt(int target);

void stop();
#endif
