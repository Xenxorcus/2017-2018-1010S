#include "main.h"
#include "ports.h"
//turning is good, forward/backwards is wrong
void driveSet(int left, int right){
  motorSet(DriveFL, -right);
  motorSet(DriveBL, right);
  motorSet(DriveBR, -left);
  motorSet(DriveFR, left);
}
