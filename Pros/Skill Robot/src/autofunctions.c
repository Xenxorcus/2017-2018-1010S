#include "main.h"
#include "autofunctions.h"
#include "drive.h"
#include "mogo.h"
#include "lcdfuctions.h"

/**************************************************


**************************************************/

#define UP 1
#define Down -1
#define  Forward 1
#define Backward -1
#define Right 1
#define Left -1

//*****************************************
// Stop every function
//*****************************************

void stopeveything(){
  MoveDrive(0, 0)
  MoveMogo(0)
}

//********************************************
//   Motor Speed Limit
//*********************************************

void motorSpeed(int value, int speed){
  if (value > speed){
    value = speed;//motor reach the max speed
  }
  else if(value <= -speed){
    value = -speed;//motor get the min speed
  }
}

//******************************
// Drive PID
//*******************************

void drive(int direction, int target){
  //Drive Variables
  int lPower;
  int rPower;
  int rValue
  int lValue
  int avgValue

  // reset values and sensors
  avgValue = 0;
  encoderReset(encoderR);
  encoderReset(encoderL);

  while(avgValue < target){
    rValue = encoderGet(encoderR);//get the right encoder value
    lValue = encoderGet(encoderL);//get the left encoder value
    avgValue = (abs(rValue) + abs(lValue))/2//get the avergae value of encoders

    if(avgValue < target){
      lPower = 127;
      rPower = 127;}
    else if{
      lPower = 0;
      rPower = 0;}

      moveDrive(direction*rPower, direction*lPower);//move drive

      delay(20);
    }
  }

//**********************************
//          Turn PID
//**********************************

void Turn(int direction, int targetTurn, int timeout, float kp, float kd){

  //Turn Variables
  int error = 0;
  int error_last = 0;
  int error_diff = 0;
  int error_sum = 0;
  int pos = 0;
  float ki = 0 ;
  float p;
  float d;
  float i;
  int drivepower;

  //Reset Values and sensors
  gyroReset(gyro);
  int startTime = millis();

  while(millis()-startTime)<timeout){
    //Timeout
    pos = abs(gyroGet(gyro));
    error = Target - pos;

    error_diff = error - error_last;//difference betwween errors = current error - last error
    error_last = error;
    error_sum += error;//same as error sum = errorsum + error

    p = kp*error;// the p value
    d = kd*error_diff;//the d value

    if (error < 5){
      i = ki*error_sum;
    }
    drivepower = p + i + d; // PID

      if(drivepower>127){drivepower = 127;}//motor limit Max
      if(drivepower<-127){drivepower = -127;}//motor limit Min

      int leftside = direction*drivepower;
      int rightside = direction*drivepower; // Turn Drive

      delay(40)
  }
  delay(20)
}

void mogoIn(int timeout){
  moveMogo(127);
  delay(timeout);
  moveMogo(0);
}

void mogoOut(int timeout){
  moveMogo(-127);
  delay(timeout);
  moveMogo(0);
}

void mogoScore(){
  while(analogRead(MOGOPOT)<1000){
    moveMogo(-90)
  }
  delay(400);
}

void mogoTwenty(int direction, int target){
  int pValue = analogRead(MOGOPOT);
  int startTime = millis();
  if(direction == 1 && (millis()-startTime)<3000){
    pValue = analogRead(MOGOPOT);
    moveMogo(-90);}
  else{
    pValue = analogRead(MOGOPOT);
    while(direction == 1 && (millis()-startTime)<3000){
      pValue = analogRead(MOGOPOT);
      moveMogo(-90);}
  }
    moveMogo(0);
  }
}
