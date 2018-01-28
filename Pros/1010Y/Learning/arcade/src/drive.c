#include "main.h"
void driveSet(int left, int right){
  motorSet(2, right);
  motorSet(3, right);
  motorSet(8, left);
  motorSet(9, left);
}
