#include "mian.h"

void MoveMogo(int speed){

motorSet(MogoLF, speed);
motorSet(MogoRF, speed);
motorSet(MogoLB, speed);
motorSet(MogoRB, speed);

}
