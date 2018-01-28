#include "autofunctions.h"
#include "main.h"
#include "drive.h"
#include "mgten.h"
#include "mgtwenty.h"


void autoDrive(int direction, int target){

  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;

  tics = 0;
  encoderReset(encoderL);
  encoderReset(encoderR);

while(tics < target){

  ticsL = encoderGet(encoderL);
  ticsR = encoderGet(encoderR);
  tics = (abs(ticsL) + abs(ticsR))/2;


if(tics < target){
      leftPower = -127;
      rightPower = 127;}
    else{
      leftPower = 0;
      rightPower = 0;}
    // checking R
driveSet(direction*rightPower,direction*leftPower);
lcdPrint(uart1, 1, "tics%d", tics);
      delay(20);
}
}

void gyroTurnPID(int direction, int targetTurn, int timeout, float kp, float kd)
{
gyroReset(gyro);

int error = 0;
int error_last = 0;
int error_diff = 0;
int error_sum = 0;
int pos =  0;
float ki = 0;
float p;
float d;
float i;
int drivepower;

int startTime = millis();
while((millis()-startTime)<timeout)
{
lcdPrint(uart1, 1, "error%d", error);
lcdPrint(uart1, 2, "power%d", drivepower);

pos = abs(gyroGet(gyro));
error =  targetTurn - pos;

error_diff = error - error_last;
error_last = error;
error_sum  += error; // same as errorsum  = errorsum + error

p = kp * error;

d  = kd * error_diff;
if(error < 5) //icap
{i = ki * error_sum;}

drivepower = p+i+d;
if(drivepower>90){drivepower = 90;}
if(drivepower<-90){drivepower = -90;}

int leftside = direction*drivepower;
int rightside = direction*drivepower;
driveSet(leftside, rightside);
delay(40);
}
lcdSetText(uart1,1,"done");
delay(20);
}

void gyroTurn(int direction, int targetTurn)
{
  int rightPower;
  int leftPower;
  int  gyroAverage = 0;
  gyroReset(gyro);
while(gyroAverage < targetTurn){
  gyroAverage = abs(gyroGet(gyro));
  lcdPrint(uart1, 2, "GyroPos%d", gyroAverage);
  if(gyroAverage < (0.6*targetTurn))
  {
    rightPower = 55;
    leftPower = 55;
  }
  else if(gyroAverage < targetTurn)
  {
    rightPower = 45;
    leftPower = 45;
  }
  driveSet(direction*leftPower, direction*rightPower);
  delay(20);
}
driveSet(-direction*15, -direction*15);
driveSet(0,0);
}

void mobileGoalTen(int direction, int target){
int pos = encoderGet(encoderTen);
if(direction == 1){
pos= encoderGet(encoderTen);
while(pos>target)
{
pos = encoderGet(encoderTen);
if(pos>target){mgtenSet(-127);}
}
}
else{
  while(pos<target){
  pos = encoderGet(encoderTen);
  if(pos<target){mgtenSet(127);}
  }
}
mgtenSet(-30*direction);
}


void mobileGoalTwenty(int direction, int target){
int pos = analogRead(1);
if(direction == 1){
 pos = analogRead(1);
 while(pos>target)
 {
   pos = analogRead(1);
   mgtwentySet(90);
 }
 }
else{
pos = analogRead(1);
 while(pos<target)
 {pos = analogRead(1);
  mgtwentySet(-90);}
}
mgtwentySet(0);
}
void stop()
{
  while (1) {
  motorSet(1, 0);
  motorSet(2, 0);
  motorSet(3, 0);
  motorSet(4, 0);
  motorSet(5, 0);
  motorSet(6, 0);
  motorSet(7, 0);
  motorSet(8, 0);
  motorSet(9, 0);
  motorSet(10, 0);
}
}
