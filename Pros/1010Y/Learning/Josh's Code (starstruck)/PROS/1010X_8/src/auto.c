
#include "main.h"
#include "lcdfunctions.h"
#include "autofunctions.h"
#include "util.h"
#include "claw.h"
#include "arm.h"

#define DUMP_HIEGHT 600
void autonomous() {

  TaskHandle autolcd_task = taskCreate(autolcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle claw_task = taskCreate(clawtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle arm_task = taskCreate(armtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

switch (myauto) {
case -2:

break;


case -1: //Test check

break;

case 0://  programming skills

  delay(5);
  arm_target_global = 50;
  claw_target_global = 600;
  drive_encoder(-1, 600, 5000, 127, 50, 4, 0.1, 0.2);
  arm_target_global = 0;
  delay(1000);
  turn_pid(-1, 130, 127, 9.5, 0, 19, 0, 750);
  delay(500);
  drive_encoder(1, 1000, 5000, 127, 50, 4, 0.1, 0.2);
  claw_target_global = 800;
  delay(1000);
  arm_target_global = 100;
  delay(1000);
  drive_encoder(-1, 1100, 5000, 127, 50, 4, 0.1, 0.2);
  turn_pid(1, 130, 127, 9.5, 0, 19, 0, 750);
  arm_target_global = 400;
  claw_release2(280, 500, 3000);
  drive_encoder(-1, 750, 4000, 127, 50, 4, 0.1, 0.2);


break;
case 1: //CUBE L
break;

case 2: // CUBE R

  delay(5);
  arm_target_global = 200;
  claw_target_global = 800;
  drive_encoder(-1, 4100, 6000, 127, 50, 4, 0.1, 0.2);
  claw_target_global = 600;
  arm_target_global = 0;
  turn_pid(1, 50, 127, 9.5, 0, 19, 0, 750);
  //delay(900);
  drive_encoder(1, 750, 4000, 127, 50, 4, 0.1, 0.2);
  claw_target_global = 870; // was 900
  delay(750); // was 1500
  arm_target_global = 400;
  claw_release2(320, 500, 3000);
  drive_encoder(-1, 750, 2500, 127, 50, 4, 0.1, 0.2); // timeout was 4000
  delay(900);// was 1200
  arm_target_global = 0;
  delay(1000);
  drive_encoder(1, 2400, 5000, 127, 50, 4, 0.1, 0.2); // was 2300
  claw_target_global = 900;

  //drive_encoder(-1, 200, 800, 127, 50, 4, 0.1, 0.2);
  //drive_encoder(1, 200, 800, 127, 50, 4, 0.1, 0.2);

  delay(1000);
  arm_target_global = 370;
  claw_release2(280, 500, 3000);
  drive_encoder(-1, 2400, 5000, 127, 50, 4, 0.1, 0.2);
  delay(1000);

  //2nd dump
  arm_target_global = 0;
  delay(1000);
  drive_encoder(1, 2300, 5000, 127, 50, 4, 0.1, 0.2);
  claw_target_global = 900;

  drive_encoder(-1, 200, 5000, 127, 50, 4, 0.1, 0.2);
  drive_encoder(1, 200, 5000, 127, 50, 4, 0.1, 0.2);

  delay(1000);
  arm_target_global = 370;
  claw_release2(280, 500, 3000);
  drive_encoder(-1, 2200, 5000, 127, 50, 4, 0.1, 0.2);

break;

case 3:// HANG L

  delay(5);

  arm_target_global = 200;
  claw_target_global = 580;
  delay(1200);
  arm_target_global = 0;
  delay(1200);
  drive_encoder(1, 500, 5000, 127, 50, 4, 0.2, 0.2);
  claw_target_global = 820;
  delay(1200);
  arm_target_global = 200;
  drive_encoder(-1, 200, 5000, 127, 50, 4, 0.2, 0.2);
  delay(1000);
  turn_pid(-1, 130, 127, 9.5, 0, 19, 0, 750);
  claw_release2(280, 500, 3000);
  arm_target_global = 340;
  drive_encoder(-1, 2000, 5000, 127, 50, 4, 0.2, 0.2);


  delay(1000);
  arm_target_global = 200;
  drive_encoder(1, 1700, 5000, 127, 50, 4, 0.2, 0.2);
  turn_pid(-1, 150, 127, 9.5, 0, 19, 0, 750);
  drive_encoder(-1, 1000, 3000, 127, 50, 4, 0.2, 0.2);

  //the lift
  arm_target_global = 380;
  delay(2000);
  drive_encoder(1, 300, 5000, 127, 50, 4, 0.2, 0.2);
  arm_target_global = -20;
  drive_encoder(1, 1000, 5000, 127, 50, 4, 0.2, 0.2);
  delay(2000);
  claw_target_global = 0;







break;

case 4: // HANG R

break;

case 5: //NEAR L

  delay(5);
  claw_target_global = 550;
  arm_target_global = 320;
  drive_encoder(-1, 2000, 5000, 127, 50, 4, 0.2, 0.2);
  delay(2000);
  arm_target_global = 0;
  claw_target_global = 600;
  delay(1500);
  turn_pid(1, 40, 127, 9.5, 0, 19, 0, 750);
  drive_encoder(1, 1800, 5000, 127, 50, 4, 0.2, 0.2);
  delay(500);
  claw_target_global = 820;
  delay(2000);
  claw_release2(280, 500, 3000);
  arm_target_global = 340;
  drive_encoder(-1, 2000, 5000, 127, 50, 4, 0.2, 0.2);


break;

case 6: // NEAR R



break;

case 7: //Back Stars L

  delay(5);
  arm_target_global = 200;
  claw_target_global = 620;
  delay(1200);
  arm_target_global = 0;
  delay(1200);
  drive_encoder(1, 3200, 5000, 127, 50, 4, 0.2, 0.2);
  claw_target_global = 800;
  delay(1000);
  arm_target_global = 100;
  delay(1000);
  drive_encoder(-1, 3000, 5000, 127, 50, 4, 0.2, 0.2);
  turn_pid(1, 130, 127, 9.5, 0, 19, 0, 750);
  claw_release2(280, 500, 3000);
  arm_target_global = 380;
  drive_encoder(-1, 2000, 5000, 127, 50, 4, 0.2, 0.2);
  delay(1000);
  arm_target_global = 0;
  claw_target_global = 600;
  delay(1500);
  turn_pid(-1, 50, 127, 9.5, 0, 19, 0, 750);
  drive_encoder(1, 1000, 5000, 127, 50, 4, 0.2, 0.2);
  claw_target_global = 800;
  delay(1000);
  arm_target_global = (370);
  claw_release2(280, 500, 3000);
  drive_encoder(-1, 1000, 5000, 127, 50, 4, 0.2, 0.2);
break;
case 8: // Back Stars R

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

/*//junk auto (old1)

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



*/
