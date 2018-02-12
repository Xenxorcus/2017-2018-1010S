#include "mian.h"

void MoveDrive(int left, int right){

motorSet(Drive_RF, (right));
motorSet(Drive_RB, (right));

motorSet(Drive_LB,(left));
motorSet(Drive_LF,(left));
}
