
#include "main.h"
#include "lcdfunctions.h"
#include "autofunctions.h"
#include "util.h"
#include "claw.h"
#include "arm.h"

void autonomous() {

  TaskHandle autolcd_task = taskCreate(autolcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle claw_task = taskCreate(clawtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle arm_task = taskCreate(armtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

switch (myauto) {

case 0:


lcdPrint(uart1, 1, "Arm STart");
delay(500);

arm_target_global = 1000;
  lcdPrint(uart1, 1, "Arm UP");
claw_release(100, 600);
  lcdPrint(uart1, 1, "Arm release");
delay(4000);

//turn_time(1, 100, 5, 500, 127, 5, 10);

break;
case 1: // initial skills = corner cube
  //backout
  delay(200);
  claw_target_global = 140;
  drive_encoder(-1, 1000, 10000, 127, 50, 3, 0.2, 0.2);
  delay(1000);

  //back in grab
  drive_encoder(1, 500, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay (1000);

  //drive to dump
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(750);

  //lower turn drive to corner
  arm_target_global = 0;
  delay(1500);
  turn_time(-1, 30, 5, 200, 127, 7, 12);
  drive_encoder(1, 2100, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);

  //lift, turn and dump
  drive_encoder(-1, 400, 10000, 127, 50, 3, 0.2, 0.2);
  arm_target_global = 200;
  delay(1000);
  turn_time(1, 30, 5, 200, 127, 8, 12);
  arm_target_global = 1000;
  drive_encoder(-1, 1700, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(400);

  //lower and back for final cube
  arm_target_global = 0;
  delay(1500);
  drive_encoder(1, 1650, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);
  arm_target_global = 1000;
  drive_encoder(-1, 1650, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(400);

  //down, turn and drive
  claw_target_global = 150;
  arm_target_global = 0;
  delay(1000);
  drive_encoder(-1, 200, 10000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(1, 350, 10000, 127, 50, 3, 0.2, 0.2);
  turn_time(1, 155, 4, 250, 127, 7, 12);
  drive_encoder(1, 5500, 10000, 127, 60, 4, 0.2, 0.2);
  claw_target_global = 200;
  delay(1200);
  arm_target_global = 200;
  delay(500);

  //turn, move to dump

  turn_time(-1, 150, 5, 200, 127, 5, 12);
  arm_target_global = 1000;
  drive_encoder(-1, 300, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(400);
  arm_target_global = 0;
  delay(1000);

  //drive to (w/ turn) grab cube and back star
  claw_target_global = 120;
  drive_encoder(1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 190;
  delay(1000);
  arm_target_global = 200;
  delay(1000);
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(1000);
  arm_target_global = 0;
  delay(1500);

  // turn can grab second cube
  turn_time(-1, 90, 5, 200, 127, 7, 12);
  drive_encoder(-1, 2200, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);
  arm_target_global = 200;
  delay(1000);
  turn_time(1, 90, 5, 200, 127, 7, 12);
  arm_target_global = 1000;
  drive_encoder(-1, 1500, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(1000);
  arm_target_global = 700;
  turn_time(-1, 200, 5, 200, 127, 5, 12);
  drive_encoder(-1, 3500, 10000, 127, 50, 3, 0.2, 0.2);

  delay(20000);

break;

case 2: // new skills = no corner cube
  //backout
  delay(200);
  claw_target_global = 140;
  drive_encoder(-1, 1000, 10000, 127, 50, 3, 0.2, 0.2);
  delay(1000);

  //back in grab
  drive_encoder(1, 400, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay (1000);

  //drive to dump
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(750);

  //lower arm for second grab
  arm_target_global = 0;
  drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
  delay(1500);
  drive_encoder(1, 1800, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);

  //to fence for dump
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(400);

  //lower and back for final cube
  arm_target_global = 0;
  drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
  delay(1500);
  drive_encoder(1, 1900, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);
  arm_target_global = 1000;
  drive_encoder(-1, 1900, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(400);

  //down, turn and drive
  claw_target_global = 140;
  arm_target_global = 0;
  drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
  delay(1000);
  //drive_encoder(-1, 200, 10000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(1, 250, 10000, 127, 50, 3, 0.2, 0.2);
  turn_time(1, 153, 4, 250, 127, 7, 12);
  drive_encoder(1, 5500, 10000, 127, 60, 4, 0.2, 0.2);
  claw_target_global = 200;
  delay(1200);
  arm_target_global = 200;
  delay(500);

  //turn, move to dump
  turn_time(-1, 150, 5, 200, 127, 5, 12);
  arm_target_global = 1000;
  drive_encoder(-1, 100, 1000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(2000);
  arm_target_global = 0;
  delay(1000);

  //drive to (w/ turn) grab cube and back star
  claw_target_global = 110;
  drive_encoder(1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 190;
  delay(1200);
  arm_target_global = 200;
  delay(1000);
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(1200);
  drive_encoder(-1, 300, 1200, 127, 50, 3, 0.2, 0.2);
  arm_target_global = 0;
  delay(1500);

  // turn can grab center cube
  drive_encoder(1, 100, 10000, 127, 50, 3, 0.2, 0.2);
  turn_time(-1, 90, 5, 200, 127, 7, 12);
  drive_encoder(1, 2500, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);
  arm_target_global = 200;
  delay(1000);
  turn_time(1, 95, 5, 200, 127, 7, 12);
  arm_target_global = 1000;
  drive_encoder(-1, 1700, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(1000);

  arm_target_global = 700;
  drive_encoder(-1, 300, 1200, 127, 50, 3, 0.2, 0.2);
  turn_time(-1, 220, 5, 200, 127, 5, 12);
  drive_encoder(-1, 4000, 10000, 127, 50, 3, 0.2, 0.2);
  arm_target_global = 1200;
  delay(1000);
  arm_target_global = 0;
  drive_encoder(1, 8000, 10000, 127, 50, 3, 0.2, 0.2);

  delay(20000);

break;

case 3:// skills  = direct hang

  //backout
  delay(200);
  claw_target_global = 140;
  drive_encoder(-1, 1000, 10000, 127, 50, 3, 0.2, 0.2);
  delay(1000);

  //back in grab
  drive_encoder(1, 400, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay (1000);

  //drive to dump
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(750);

  //lower arm for second grab
  arm_target_global = 0;
  drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
  delay(1500);
  drive_encoder(1, 1800, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);

  //to fence for dump
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(400);

  //lower and back for final cube
  arm_target_global = 0;
  drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
  delay(1500);
  drive_encoder(1, 1900, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);
  arm_target_global = 1000;
  drive_encoder(-1, 1900, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(400);

  //down, turn and drive
  claw_target_global = 150;
  arm_target_global = 0;
  drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
  delay(1000);
  //drive_encoder(-1, 200, 10000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(1, 250, 10000, 127, 50, 3, 0.2, 0.2);
  turn_time(1, 153, 4, 250, 127, 7, 12);
  drive_encoder(1, 5500, 10000, 127, 60, 4, 0.2, 0.2);
  claw_target_global = 200;
  delay(1200);
  arm_target_global = 200;
  delay(500);

  //turn, move to dump
  turn_time(-1, 150, 5, 200, 127, 5, 12);
  arm_target_global = 1000;
  //drive_encoder(-1, 100, 1000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(2000);
  drive_encoder(1, 250, 1000, 127, 50, 3, 0.2, 0.2);
  arm_target_global = 0;
  delay(1000);
  drive_encoder(-1, 300, 1300, 127, 50, 3, 0.2, 0.2);


  //drive to (w/ turn) grab cube and back star
  claw_target_global = 105;
  drive_encoder(1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 190;
  delay(1200);
  arm_target_global = 200;
  delay(1000);
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(1200);
  drive_encoder(-1, 300, 500, 127, 50, 3, 0.2, 0.2);
  arm_target_global = 500;
  delay(1500);
  drive_encoder(1, 300, 500, 127, 50, 3, 0.2, 0.2);


  drive_encoder(1, 1900, 10000, 127, 50, 3, 0.2, 0.2);
  turn_time(-1, 200, 5, 220, 127, 10, 12);
  drive_encoder(-1, 1000, 3000, 127, 80, 3, 0.2, 0.2);
  drive_encoder(1, 500, 3400, 127, 80, 3, 0.1, 0.1);
  drive_encoder(-1, 600, 3400, 127, 80, 3, 0.1, 0.1);

  arm_target_global = 1200;
  delay(1500);
  drive_encoder(1, 200, 1300, 127, 100, 3, 0.2, 0.2);
  arm_target_global = 0;
  drive_encoder(1, 8000, 4000, 127, 100, 3, 0.2, 0.2);

  delay(20000);

break;

case 4:
delay(50);
  //drive_encoder(-1, 70, 10000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(1, 2000, 10000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1000);
  arm_target_global = 200;
  delay(1000);
  turn_time(-1, 180, 7, 150, 127, 7, 12);
  arm_target_global = 1100;
  drive_encoder(-1, 1000, 6000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);
  delay(1000);
  drive_encoder(-1, 150, 900, 127, 50, 3, 0.2, 0.2);
  arm_target_global = 0;
  claw_target_global = 110;
  delay(1200);
  drive_encoder(1, 2000, 6000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  delay(1200);
  arm_target_global = 200;
  delay(1000);
  arm_target_global = 1000;
  drive_encoder(-1, 1800, 6000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600);

  delay(10000);

break;

case 5:


break;

case 6:
break;

default:
break;
      }

  //delay(20000);

}


//code from first auto test - draggged
/*
delay(1000);
claw_target_global = 140;
drive_gyro(-1, 1000, 10000, 127, 70, 2, 0.15, 0.3);
delay(2000);
claw_target_global = 200;
drive_gyro(1, 700, 10000, 127, 70, 2, 0.15, 0.3);
arm_target_global = 1000;
drive_gyro(-1, 1530, 10000, 127, 50, 2, 0.15, 0.3);
claw_release(140, 800);
delay(1000);
arm_pos_global = 0;
turn_gyro(-1, 30, 10000, 127, 50, 0.2, 0.2);
drive_gyro(1, 1500, 10000, 127, 50, 2, 0.15, 0.3);
claw_target_global = 190;
delay(2000);
arm_pos_global = 220;
turn_gyro(1, 20, 10000, 127, 50, 0.2, 0.2);
arm_pos_global = 1000;
drive_gyro(-1, 1200, 10000, 127, 50, 2, 0.15, 0.3);
claw_release(130, 800);
delay(2000);
arm_pos_global = 0;
delay(2000);
//forward for 2nd cube
drive_gyro(1, 1200, 10000, 127, 50, 2, 0.15, 0.3);
claw_target_global = 200;
delay(2000);
drive_gyro(-1, 1280, 10000, 127, 50, 2, 0.15, 0.3);
arm_pos_global = 950;
claw_release(130, 800);
delay(2000);
*/
