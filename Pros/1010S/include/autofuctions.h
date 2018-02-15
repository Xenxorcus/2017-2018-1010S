#ifndef AUTOFUNCTIONS_H_
#define AUTOFUNCTIONS_H_

#include "main.h"

void stopEverything(); //function to stop everything

void motorSpeed(int value, int speed); //Limit Speed

void drive(int direction, int target); //Auto Drive

void turn(int direction, int targetTurn, int timeout, float kp, float, kd); //Auto turn

void mogoIn(int timeout);

void mogoOut(int timeout);

void mogoScore();

void mogoTwenty(int direction, int target);

void LineTrack();
