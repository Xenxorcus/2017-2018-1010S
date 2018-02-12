#include "autofunctions.h"
#include "ports.h"
#include "main.h"
#include "drive.h"
#include "lift.h"
#include "claw.h"


void autoDrive(int direction, int target){

  int leftPower;
  int rightPower;
  int tics;
  int ticsL;
  int ticsR;

  tics = 0;
  encoderReset(encoder_L);
  encoderReset(encoder_R);

while(tics < target){

  ticsL = encoderGet(encoder_L);
  ticsR = encoderGet(encoder_R);
  tics = (abs(ticsL) + abs(ticsR))/2;


if(tics < target){
      leftPower = -127;
      rightPower = 127;}
    else{
      leftPower = 0;
      rightPower = 0;}
    // checking R
driveSet(direction*leftPower,direction*rightPower);
      /*  motorSet(DriveFL, direction*-rightPower);
        motorSet(DriveBL, direction*rightPower);
        motorSet(DriveBR, direction*-leftPower);
        motorSet(DriveFR, direction*leftPower);
*/
      delay(20);
}
//
}
void gyroTurn(int direction, int targetTurn)
{
  int rightPower;
  int leftPower;
  int  gyroAverage = 0;
  gyroReset(gyro);

while(gyroAverage < targetTurn)
{
    gyroAverage = abs(gyroGet(gyro));
    if(gyroAverage < targetTurn)
    {
      rightPower = 127;
      leftPower = 127;
    }
    else{
    rightPower = 0;
    leftPower = 0;}

    driveSet(direction*leftPower, direction*rightPower);
      delay(20);
}
}

void mobileGoalOut(int target){
int autoEncoderLift = 0;
int liftPower;
encoderReset(encoderLift);
while(autoEncoderLift < target)
{
autoEncoderLift = abs(encoderGet(encoderLift));
if(autoEncoderLift < target){liftPower = 127;}
else{liftPower = 0;}
liftSet(liftPower);
delay(20);
}
}

void mobileGoalIn(int target){
int autoEncoderLift = 0;
encoderReset(encoderLift);
while(autoEncoderLift < target)
{
autoEncoderLift = abs(encoderGet(encoderLift));
int liftPower;
if(autoEncoderLift < target){liftPower = (-127);}
else{liftPower = 0;}

liftSet(liftPower);

delay(20);
}
}




void armDown(int target, int side){
int autoCurrent = 0;
int armPower;
encoderReset(encoder);
while(autoCurrent < target)
{
  autoCurrent = abs(encoderGet(encoder));
  lcdPrint(uart1, 2, "armLift%d", autoCurrent);

  if(autoCurrent < target){
  autoCurrent = encoderGet(encoder);
  armPower = 127;
}
  else{
  armPower = 20*side;}///////////
  motorSet(ArmT,armPower);
  motorSet(ArmLB,armPower);
  motorSet(ArmRB,armPower);
  delay(20);
}

}

void armUp(int target, int side){
  int autoCurrent = 0;
  int armPower;
  encoderReset(encoder);
  while(autoCurrent < target)
  {
    autoCurrent = abs(encoderGet(encoder));
    lcdPrint(uart1, 2, "armLift%d", autoCurrent);

    if(autoCurrent < target){
    autoCurrent = encoderGet(encoder);
    armPower = -127;
  }
    else{
    armPower = 30*side;}///////////////change used to be 0
    motorSet(ArmT,armPower);
    motorSet(ArmLB,armPower);
    motorSet(ArmRB,armPower);
    delay(20);
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


void clawOpenIt(int target){
int clawPower;
int current = analogRead(2);
while(current<target){
current = analogRead(2);
if(current < target){clawPower = 70;}
else{clawPower = 0;}
clawSet(clawPower);
delay(20);
}
}
