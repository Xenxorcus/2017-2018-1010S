#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "claw.h"

//back drive is 1
//drive forwards is -1
// 1 is clockwise
//-1 is counterclockwise

 //mg all the way in 1820
 //mg all the way out 235
 //mg score 1400
 //mg pick up safe 800

// fourbar up is -90
//fourbar down is 90
//fourbar down 3200, up 1200

//double reverse all the way up -470, all the way down is 0
//double reverse up is negative, down is positive

void autoDrive(int direction, int target, int timeout){///DRIVING STRAIGHT

  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;
///RESET ALL VALUES AND SENSORS
  tics = 0;
  encoderReset(encoderL);
  encoderReset(encoderR);
  int startTime = millis();

while(tics < target && (millis()-startTime)<timeout){///UNDER TARGET

  ticsL = encoderGet(encoderL);
  ticsR = encoderGet(encoderR);
  tics = (abs(ticsL) + abs(ticsR))/2;

if(tics < target){
      leftPower = -90;
      rightPower = 90;}
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

void mobileGoalTwenty(int direction, int target){
  int pos = analogRead(mgPot);
  int startTime = millis();

  if(direction == 1){//OUT
   pos = analogRead(mgPot);
   while(pos>target && (millis()-startTime)<3000)//OUT
   {
     pos = analogRead(mgPot);
     mgSet(-90);//CHANGE IF DIRECTION IS WRONG
   }
   }

    else{
    pos = analogRead(mgPot);
     while(pos<target && (millis()-startTime)<3000)
     {pos = analogRead(mgPot);
      mgSet(90);}//IN
    }
    mgSet(0);//STOP
    }

void lift(int direction, int target){
int  pos = analogRead(mgLift);

///direction 1 is up, encoder decreases as lift moves up

if(direction == 1){
pos = analogRead(mgLift);
while(pos>target)
{
pos = analogRead(mgLift);
liftSet(-90);
delay(20);
}
}

if(direction == -1){
  while(pos<target){
  pos = analogRead(mgLift);
liftSet(90);
  delay(20);
  }
  }

liftSet(-20*direction);//HOLD IN AUTO
}

void fourbar(int direction, int target){
  int pos = analogRead(fourPot);
    if(direction == 1){
     pos = analogRead(fourPot);
     while(pos>target)
     {
       pos = analogRead(fourPot);
       fourSet(-90);
     }
     }
      else{
      pos = analogRead(fourPot);
       while(pos<target){
        pos = analogRead(fourPot);
        fourSet(90);}
      }
      fourSet(0);
      }

void fourAUp(){
fourbar(1,1300);
}

void fourADown(){
  fourbar(-1,3200);
  fourSet(20);
}

void clawOpen(){
  clawSet(90);
  delay(200);
  clawSet(0);
}

void clawClose(){
  clawSet(-90);
  delay(200);
  clawSet(-10);
}

void autoStack(void*parameter){
  while(true){
    if(joystickGetDigital(2,8,JOY_DOWN)){
    lcdPrint(uart1,1,"TaskRunning");
    stackglobal =1;
    int armpos = analogRead(liftPot);

  	lift(1,(armpos-20));
  	fourAUp();
  	lift(-1,(armpos-10));
    clawSet(90);
  	fourADown();
    clawSet(0);
  	delay(10);
  	lift(-1,-30);
    stackglobal = 0;

  }
  delay(20);
  lcdPrint(uart1,1,"TaskLoop");
}
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
