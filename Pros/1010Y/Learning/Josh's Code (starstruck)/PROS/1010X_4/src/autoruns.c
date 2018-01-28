#include "main.h"
#include "autoruns.h"
#include "autofunctions.h"
#include "clawarmextern.h"

void programmingskills(){

  int back_forth = 1000;

  claw_target = CLAW_PARALLEL;
  newdrive(SOUTH, 150, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);


  claw_target = CLAW_CLOSED+200;
  delay(1000);
  newdrive(SOUTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();
  claw_target = CLAW_PARALLEL;
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  newdrive(NORTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);

  claw_target = CLAW_CLOSED+200;
  delay(1000);
  newdrive(SOUTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();
  claw_target = CLAW_PARALLEL;
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  newdrive(NORTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);

  claw_target = CLAW_CLOSED+200;
  delay(1000);
  newdrive(SOUTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();
  claw_target = CLAW_PARALLEL;
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  newdrive(NORTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);

  claw_target = CLAW_CLOSED+200;
  delay(1000);
  newdrive(SOUTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();
  claw_target = CLAW_PARALLEL;
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  newdrive(NORTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);

  claw_target = CLAW_CLOSED+200;
  delay(1000);
  newdrive(SOUTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();
  claw_target = CLAW_PARALLEL;
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  newdrive(NORTH, back_forth, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);



}

void centerfence_R(){

  claw_target = CLAW_PARALLEL;
  //nolag(NORTH, 4, 25);
  newdrive(NORTH, 1200, 30, 40, 15, 10, 0.3, 10000);
  drivehalt(NORTH, 750, 0.5, 0.01);
  delay(750);
  nolag(WEST, 2, 30);
  newdrive(WEST, 750, 30, 40, 15, 10, 0.3, 10000);
  //drivehalt(WEST, 750, 0.5, 0.01);
  arm_target_L = ARM_MID_L;
  arm_target_R = ARM_MID_R;
  delay(1000);
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  claw_target = CLAW_MAX;
  delay(1000);
  newturn(CLOCKWISE, 200, 20, 40, 10, 8, 100000);
  //nolag(NORTH, 4, 25);
  newdrive(NORTH, 200, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  claw_target = CLAW_CLOSED+300;
  delay(1000);
  //nolag(SOUTH, 4, 25);
  newdrive(SOUTH, 350, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  checkdump(2700, WEST);
  delay(500);
}

void centerfence_L(){}

void cubedirect_R(){
  delay(250);
  //claw_target = CLAW_PARALLEL-400;
  newturn(COUNTER_CLOCKWISE, 10, 20, 40, 10, 8, 100000);
  delay(250);
  newdrive(NORTH, 800, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  claw_target = CLAW_CLOSED + 200;
  delay(1300);
  newturn(COUNTER_CLOCKWISE, 120, 20, 40, 10, 8, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  arm_target_L = ARM_LOWMID_L;
  arm_target_R = ARM_LOWMID_R;
  delay(600);
  newdrive(SOUTH, 700, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();
  delay(500);
  claw_target = CLAW_PARALLEL;
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  newdrive(NORTH, 1200, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  claw_target = CLAW_CLOSED;
  delay(600);
  arm_target_L = ARM_LOWMID_L;
  arm_target_R = ARM_LOWMID_R;
  delay(500);
  newdrive(SOUTH, 1200, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();
  }

void cubedirect_L(){
  delay(250);
  //claw_target = CLAW_PARALLEL-400;
  newturn(CLOCKWISE, 10, 20, 40, 10, 8, 100000);
  delay(250);
  newdrive(NORTH, 800, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  claw_target = CLAW_CLOSED + 200;
  delay(1300);
  newturn(CLOCKWISE, 120, 20, 40, 10, 8, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  arm_target_L = ARM_LOWMID_L;
  arm_target_R = ARM_LOWMID_R;
  delay(600);
  newdrive(SOUTH, 700, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();
  delay(500);
  claw_target = CLAW_PARALLEL;
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  newdrive(NORTH, 1200, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  claw_target = CLAW_CLOSED;
  delay(600);
  arm_target_L = ARM_LOWMID_L;
  arm_target_R = ARM_LOWMID_R;
  delay(500);
  newdrive(SOUTH, 1200, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();

}

void nearauto_R(){
  delay(250);
  claw_target = CLAW_PARALLEL+100;
  newdrive(NORTH, 1150, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  arm_target_L = ARM_MID_L;
  arm_target_R = ARM_MID_R;
  delay(1000);
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  delay(750);
  newturn(CLOCKWISE, 115, 20, 40, 10, 8, 100000);
  delay(400);
  claw_target = CLAW_SEMI_OPEN+300;
  newdrive(NORTH, 1100, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  claw_target = CLAW_CLOSED;
  delay(750);
  newdrive(SOUTH, 500, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  newturn(CLOCKWISE, 10, 20, 40, 10, 8, 100000);
  arm_target_L = ARM_LOWMID_L;
  arm_target_R = ARM_LOWMID_R;
  delay(750);
  newdrive(SOUTH, 400, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();

}

void nearauto_L(){
  delay(250);
  claw_target = CLAW_PARALLEL+100;
  newdrive(NORTH, 1150, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  arm_target_L = ARM_MID_L;
  arm_target_R = ARM_MID_R;
  delay(1000);
  arm_target_L = ARM_GROUND_L;
  arm_target_R = ARM_GROUND_R;
  delay(750);
  newturn(COUNTER_CLOCKWISE, 115, 20, 40, 10, 8, 100000);
  delay(400);
  claw_target = CLAW_SEMI_OPEN+300;
  newdrive(NORTH, 1100, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  claw_target = CLAW_CLOSED;
  delay(750);
  newdrive(SOUTH, 500, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(NORTH, 750, 0.5, 0.1);
  newturn(COUNTER_CLOCKWISE, 10, 20, 40, 10, 8, 100000);
  arm_target_L = ARM_LOWMID_L;
  arm_target_R = ARM_LOWMID_R;
  delay(750);
  newdrive(SOUTH, 400, 30, 40, 15, 10, 0.1, 100000);
  drivehalt(SOUTH, 750, 0.5, 0.1);
  standarddump();

}

void hangauto_R(){}

void hangauto_L(){}
