#include "main.h"
#include "drive.h"

void driveSet(int rightPower, int leftPower)
{
  motorSet(DriveFL, -leftPower*DriveFL_Dir);
  motorSet(DriveBL, -leftPower*DriveBL_Dir);
  motorSet(DriveFR, -rightPower*DriveFR_Dir);
  motorSet(DriveBR, -rightPower*DriveBR_Dir);
  if(rightPower > 90){rightPower = 90;}
  if(leftPower > 90){leftPower = 90;}
  if(rightPower < -90){rightPower = -90;}
  if(leftPower < -90){leftPower = -90;}

}
