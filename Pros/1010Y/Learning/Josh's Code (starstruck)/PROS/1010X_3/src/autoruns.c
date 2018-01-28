#include "main.h"
#include "autoruns.h"
void lift_basic (int claw_release, int height_arm){
  delay(200);
  armtarget_L = height_arm;
  armtarget_R = height_arm - OFFSET_ARM;
  while((((4095-analogRead(potarmL))+analogRead(potarmR))/2)< claw_release){
    delay(20);}
  clawtarget = CLAW_MAX;
  delay(2000);
  //while(analogRead(potclaw) < CLAW_MAX){delay(20);}
  }

void auto0_programming(){
  drivestraight(SOUTH, 100, 40, 50, 0.05, 0.05, 15, 5000);
  clawtarget = CLAW_SEMI_OPEN;
  delay(1500);
  clawtarget = CLAW_CLOSED;
  delay(1000);
  drivestraight(SOUTH, 500, 40, 50, 0.05, 0.05, 15, 5000);
  lift_basic(2500, ARM_MAX_L);
  }

void auto1_centerfence_R(){
  clawtarget = CLAW_SEMI_OPEN;
  drivestraight(NORTH, 350, 40, 50, 0.05, 0.05, 15, 5000);
  clawtarget = CLAW_CLOSED;
  delay(1500);
  armtarget_L = 700;
  armtarget_R = 700 - OFFSET_ARM;
  delay(1500);
  turnexact(COUNTER_CLOCKWISE, 100, 40, 50, 0.05, 0.05, 15, 5000);
  delay(200);
  drivestraight(SOUTH, 250, 40, 50, 0.1, 0.05, 15, 5000);
  delay(200);
  armtarget_L = ARM_MAX_L;
  armtarget_R = ARM_MAX_R;
  while( ((analogRead(potarmL)+analogRead(potarmR))/2) < 2500){
    delay(40);}
  clawtarget = CLAW_MAX;
  delay(1000);
  }

void auto2_centerfence_L(){}

void auto3_close_R(){
  clawtarget = CLAW_SEMI_OPEN;
  delay(200);
  drivestraight(NORTH, 150, 40, 50, 0.05, 0.05, 15, 5000);
  clawtarget = CLAW_CLOSED;
  delay(1500);
  armtarget_L = 700;
  armtarget_R = 700 - OFFSET_ARM;
  delay(1500);
  turnexact(CLOCKWISE, 70, 40, 50, 0.05, 0.05, 15, 20000);
  delay(200);
  drivestraight(SOUTH, 600, 40, 50, 0.1, 0.05, 15, 20000);
  delay(200);
  armtarget_L = ARM_MAX_L;
  armtarget_R = ARM_MAX_R;
  while(((analogRead(potarmL)+analogRead(potarmR))/2)< 2500){
    delay(40);}
  clawtarget = CLAW_MAX;
  delay(1000);
  }

void auto4_close_L(){}

void auto5_wall_R(){
  delay(250);
  clawtarget = CLAW_SEMI_OPEN;
  delay(1000);
  turnexact(COUNTER_CLOCKWISE, 45, 40, 50, 0.05, 0.05, 15, 5000);
  delay(500);
  drivestraight(NORTH, 500, 40, 50, 0.1, 0.05, 15, 5000);
  clawtarget = CLAW_CLOSED;
  delay(1500);
  armtarget_L = ARM_MID_L;
  armtarget_R = ARM_MID_R;
  delay(1000);
  drivestraight(SOUTH, 500, 40, 50, 0.1, 0.05, 15, 5000);
  drivestraight(EAST, 100, 40, 50, 0.2, 0.1, 15, 5000);
  turnexact(COUNTER_CLOCKWISE, 900, 40, 50, 0.05, 0.05, 15, 5000);
  delay(200);
  drivestraight(SOUTH, 1000, 40, 50, 0.1, 0.05, 15, 5000);
  armtarget_L = ARM_MAX_L;
  armtarget_R = ARM_MAX_R;
  while(((analogRead(potarmL)+analogRead(potarmR))/2)< 2500){
    delay(40);}
  clawtarget = CLAW_MAX;
  delay(1000);
}

void auto6_wall_L(){}

void auto7_hang_R(){};

void auto8_hang_L(){};

//void auto8_programming(){}
