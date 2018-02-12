#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

void autoDrive(int direction, int target);

void gyroTurn(int direction, int targetTurn);

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd);

void mobileGoalTen(int direction, int target);

void mobileGoalTwenty(int direction, int target);

void lift(int direction, int target);

void fourbar(int direction, int target);

void rollerAuto(int direction, int power);

<<<<<<< HEAD
<<<<<<< HEAD
void stackTask(void*ignore);

TaskHandle stackAutoTask;
=======
void rollOut(int timeout);

void rollIn(int timeout);
>>>>>>> parent of 7a7efca... Tasks for Autonomous and New Driver Control for Partner (Stack Task)
=======
void scoreoneauto(int timeout);
>>>>>>> parent of 682d7b6... ok look at this cool

void stop();
#endif
