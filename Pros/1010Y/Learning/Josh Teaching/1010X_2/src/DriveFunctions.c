#include "main.h"
#include "API.h"


void drivestraight(int direction, int totdist, int timeout, int acceldist, int deacceldist, int maxpower , int minpower , float kdrift)
{
  encoderReset(encoderL);
  encoderReset(encoderR);
  long encoderaverage;
  long starttime = millis();
  int drift;
  int accel;
  int netpower = maxpower-minpower;
  encoderaverage = abs((encoderGet(encoderL)+encoderGet(encoderR))/2);

  while(encoderaverage < abs(totdist))
  {
lcdClear(uart1);
lcdPrint(uart1, 1, "ave = %ld", encoderaverage);

    encoderaverage = abs((encoderGet(encoderL)+encoderGet(encoderR))/2);
    drift = encoderGet(encoderL)-encoderGet(encoderR);

    if(abs(encoderaverage) <= acceldist)
      {accel = abs(encoderaverage/acceldist)*netpower;} //accel - fraction of value
    else if (abs(encoderaverage) >= deacceldist)
      {accel = ((totdist-abs(encoderaverage))/(totdist-deacceldist))*netpower;}//deaccel - fraction of value
    else
      {accel = netpower;}

int powerL = direction*motorcap(minpower+accel)-(kdrift*drift);
int powerR = direction*motorcap(minpower+accel)+(kdrift*drift);

motorSet(DriveBL, DriveBL_Dir*powerL);
motorSet(DriveFL, DriveFL_Dir*powerL);
motorSet(DriveFR, DriveFR_Dir*powerR);
motorSet(DriveBR, DriveBR_Dir*powerR);

    long currenttime = millis();
    if((currenttime-starttime)>timeout)
      {break;}
  delay(25);
    }
    motorSet(DriveBL, 0);
    motorSet(DriveFL, 0);
    motorSet(DriveFR, 0);
    motorSet(DriveBR, 0);
}

void turnexact(int direction, int tardegrees, int timeout, int accelang, int deaccelang, int maxpower, int minpower, float kturn){

gyroReset(gyro1);
int curdegrees;
int motorpower;
long starttime = millis();
curdegrees = abs(gyroGet(gyro1));

while (abs(curdegrees) < tardegrees){
  lcdClear(uart1);
  lcdPrint(uart1, 1, "ave = %d", curdegrees);
  curdegrees = abs(gyroGet(gyro1));

  if(curdegrees <= accelang)
  {motorpower = maxpower*(curdegrees/accelang);}
  else if(curdegrees >= deaccelang)
  {motorpower = maxpower*((tardegrees-curdegrees)/(tardegrees-deaccelang));}
  else
  {motorpower = maxpower;}

  int powerL = (-(motorpower*kturn)-minpower)*direction;
  int powerR = ((motorpower*kturn)+minpower)*direction;
//go fuck yourself
  motorSet(DriveBL, DriveBL_Dir*powerL);
  motorSet(DriveFL, DriveFL_Dir*powerL);
  motorSet(DriveFR, DriveFR_Dir*powerR);
  motorSet(DriveBR, DriveBR_Dir*powerR);

  long currenttime = millis();
  if((currenttime-starttime) > timeout)
    {break;}
delay(25);
  }
  motorSet(DriveBL, 0);
  motorSet(DriveFL, 0);
  motorSet(DriveFR, 0);
  motorSet(DriveBR, 0);
}
