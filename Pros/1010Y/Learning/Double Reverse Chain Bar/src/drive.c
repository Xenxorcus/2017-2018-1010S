#include "main.h"
#include "ports.h"

void driveSet(int left, int right){
  motorSet(DriveFL, left);
  motorSet(DriveBL, left);
  motorSet(DriveFR, right);
  motorSet(DriveBR, right);
}
