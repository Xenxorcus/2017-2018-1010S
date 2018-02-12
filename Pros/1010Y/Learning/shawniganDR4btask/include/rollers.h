#ifndef ROLLERS_H_
#define ROLLERS_H_

void rollerSet(int power);

void rollerTask(void*ignore);

TaskHandle rollerAutoTask;

#endif
