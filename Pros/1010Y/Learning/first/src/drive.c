#include "main.h"
#include "ports.h"
//turning is good, forward/backwards is wrong
void driveSet(int left, int right){
  motorSet(DriveFL, left);
<<<<<<< HEAD
  //motorSet(DriveMBL, left);
  motorSet(DriveBL, left);
  motorSet(DriveBR, right);
  motorSet(DriveFR, right);
  //motorSet(DriveMBR, right);
=======
  motorSet(DriveBL, left);
  motorSet(DriveBR, right);
  motorSet(DriveFR, right);
>>>>>>> 84189b9170b2d9087baaf0e587b36af5c57654f1
}
