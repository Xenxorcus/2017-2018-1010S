
#include "main.h"
#include "lcdfunctions.h"
#include "autofunctions.h"
#include "util.h"
#include "claw.h"
#include "arm.h"

#define DUMP_HIEGHT 950
void autonomous() {

  TaskHandle autolcd_task = taskCreate(autolcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle claw_task = taskCreate(clawtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle arm_task = taskCreate(armtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

switch (myauto) {

case -1: //new drive vel dumps

  //backout
  delay(200);
  drive_encoder(-1, 1400, 3000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(1, 200, 3000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(-1, 200, 3000, 127, 50, 3, 0.2, 0.2);
  delay(300);
  //turn_time(1, 35, 5, 150, 127, 8, 15);
  claw_target_global = 130;
  delay(1500);

  //back in grab
  drive_encoder(1, 580, 3000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 185;
  lock_encoder(1200, 1);


  //drive to dump
  arm_target_global = 1000;
  drive_encoder(-1, 1800, 4000, 127, 50, 3, 0.2, 0);//0.2 deaccel take out
  claw_release(130, 800, 8000);
  drive_encoder(-1, 200, 1200, 127, 50, 3, 0, 0);//0.2 deaccel take out
  delay(600);//YY 750

  //lower arm for second grab
  arm_target_global = 0;
  delay(1500);
  //turn_time(-1, 30, 5, 150, 127, 8, 15);
  drive_encoder(-1, 500, 1000, 127, 50, 3, 0.2, 0);//square
  //drive_encoder(1, 300, 750, 127, 50, 3, 0.2, 0);
  //drive_encoder(-1, 300, 750, 127, 50, 3, 0.2, 0);
  //drive_encoder(1, 300, 750, 127, 50, 3, 0.2, 0);

  claw_target_global = 135; //was 120
  drive_encoder( 1, 2000, 3000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 180;//was 185
  lock_encoder(800, 1);//YY 1200

  //to fence for dump
  arm_target_global = 1000;
  drive_encoder(-1, 1800, 3000, 127, 50, 3, 0.2, 0);//0.2 deaccel take out
  claw_release(130, DUMP_HIEGHT, 2000);
  drive_encoder(-1, 200, 1200, 127, 50, 3, 0, 0);
  delay(400);

  //lower and back for final cube
  arm_target_global = 0;
  delay(1000);
  drive_encoder(-1, 400, 1000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(1, 400, 1000, 127, 50, 3, 0.2, 0);
  drive_encoder(-1, 400, 1000, 127, 50, 3, 0.2, 0);
  drive_encoder(1, 1900, 3500, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 200;
  lock_encoder(1200, 1);
  arm_target_global = 1000;
  drive_encoder(-1, 1800, 3500, 127, 50, 3, 0.2, 0);//0.2 deaccel take out
  claw_release(130, DUMP_HIEGHT, 2000);
  drive_encoder(-1, 200, 1200, 127, 50, 3, 0, 0);
  delay(400);

  //down, turn and drive
  claw_target_global = 140;
  arm_target_global = 0;
  delay(1000);
  drive_encoder(-1, 200, 400, 127, 50, 3, 0.2, 0.2);
  //drive_encoder(-1, 200, 10000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(1, 250, 3500, 127, 50, 3, 0.2, 0.2);
  delay(500);
  turn_time(1, 148, 3, 250, 127, 10, 15);
  drive_encoder(1, 5700, 4000, 127, 60, 5, 0.03, 0);
  claw_target_global = 200;
  drive_encoder(-1, 200, 3500, 127, 60, 5, 0.2, 0.2);
  delay(700);
  arm_target_global = 220;//was 185
  delay(750);
  //drive_encoder(-1, 200, 700, 127, 60, 5, 0.05, 0.05);

  //turn, move to dump
  turn_time(-1, 149, 5, 150, 127, 12, 14);//DONOT CHANGE
  arm_target_global = 1000;
  drive_encoder(1, 200, 1200, 127, 50, 3, 0, 0);
  //drive_encoder(-1, 100, 1000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 700, 2000);
  drive_encoder(-1, 200, 1200, 127, 50, 3, 0, 0);
  delay(600);//YY 1000
  arm_target_global = 0;
  delay(1500);
  drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
  drive_encoder(1, 250, 1000, 127, 50, 3, 0, 0);
  drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);


  //drive to grab cube and back star
  claw_target_global = 105;
  drive_encoder(1, 2100, 3500, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 190;
  lock_encoder(750, 1);//YY 1000
  //delay(1000);
  arm_target_global = 190;
  delay(300);//YY 600
  arm_target_global = 1000;
  drive_encoder(-1, 2000, 4000, 127, 50, 3, 0.2, 0.2);
  claw_release(130, 600, 2000);
  delay(500); //YY 1000
  arm_target_global = 700;
  delay(650);//YY 1500
  drive_encoder(-1, 300, 400, 127, 50, 3, 0.2, 0.2);//square
  drive_encoder(1, 1800, 4000, 127, 50, 3, 0.2, 0.2);

  turn_time(-1, 140, 4, 220, 127, 10, 14);
  drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
  //delay(300); YY
  drive_encoder(1, 700, 1200, 127, 80, 3, 0.05, 0.1);

  turn_time(-1, 140, 4, 220, 127, 10, 14);
  drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
  //delay(300); YY
  drive_encoder(1, 400, 1200, 127, 80, 3, 0.05, 0.1);

  turn_time(1, 75, 4, 220, 127, 10, 14);
  drive_encoder(-1, 1200, 1500, 127, 80, 3, 0, 0);

  arm_target_global = 1200;
  delay(1300);// YY 1500
  drive_encoder(1, 200, 1000, 127, 100, 3, 0, 0);
  arm_target_global = -100;
  drive_encoder(1, 8000, 4000, 127, 100, 3, 0, 0);

  delay(20000);

break;

case 0:// preload dump changes

    //backout
    delay(200);
    drive_encoder(-1, 1400, 3000, 127, 50, 3, 0.2, 0.2);
    drive_encoder(1, 200, 3000, 127, 50, 3, 0.2, 0.2);
    drive_encoder(-1, 200, 3000, 127, 50, 3, 0.2, 0.2);
    delay(300);
    //turn_time(1, 35, 5, 150, 127, 8, 15);
    claw_target_global = 130;
    delay(1500);

    //back in grab
    drive_encoder(1, 580, 3000, 127, 50, 3, 0.2, 0.2);
    claw_target_global = 185;
    lock_encoder(1200, 1);


    //drive to dump
    arm_target_global = 1000;
    drive_encoder(-1, 1900, 4000, 127, 50, 3, 0.2, 0);//0.2 deaccel take out
    claw_release(130, 800, 8000);
    delay(600);//YY 750

    //lower arm for second grab
    arm_target_global = 0;
    delay(1500);
    //turn_time(-1, 30, 5, 150, 127, 8, 15);
    drive_encoder(-1, 500, 1000, 127, 50, 3, 0.2, 0);//square
    //drive_encoder(1, 300, 750, 127, 50, 3, 0.2, 0);
    //drive_encoder(-1, 300, 750, 127, 50, 3, 0.2, 0);
    //drive_encoder(1, 300, 750, 127, 50, 3, 0.2, 0);

    claw_target_global = 135; //was 120
    drive_encoder( 1, 2000, 3000, 127, 50, 3, 0.2, 0.2);
    claw_target_global = 185;//was 185
    lock_encoder(800, 1);//YY 1200

    //to fence for dump
    arm_target_global = 1000;
    drive_encoder(-1, 2000, 3000, 127, 50, 3, 0.2, 0);//0.2 deaccel take out
    claw_release(130, DUMP_HIEGHT, 2000);
    delay(400);

    //lower and back for final cube
    arm_target_global = 0;
    delay(1000);
    drive_encoder(-1, 400, 1000, 127, 50, 3, 0.2, 0.2);
    drive_encoder(1, 400, 1000, 127, 50, 3, 0.2, 0);
    drive_encoder(-1, 400, 1000, 127, 50, 3, 0.2, 0);
    drive_encoder(1, 1900, 3500, 127, 50, 3, 0.2, 0.2);
    claw_target_global = 185;
    lock_encoder(1200, 1);
    arm_target_global = 1000;
    drive_encoder(-1, 1900, 3500, 127, 50, 3, 0.2, 0);//0.2 deaccel take out
    claw_release(130, DUMP_HIEGHT, 2000);
    delay(400);

    //down, turn and drive
    claw_target_global = 140;
    arm_target_global = 0;
    delay(1000);
    drive_encoder(-1, 200, 400, 127, 50, 3, 0.2, 0.2);
    //drive_encoder(-1, 200, 10000, 127, 50, 3, 0.2, 0.2);
    drive_encoder(1, 250, 3500, 127, 50, 3, 0.2, 0.2);
    delay(500);
    turn_time(1, 148, 3, 250, 127, 10, 15);
    drive_encoder(1, 5700, 4000, 127, 60, 5, 0.03, 0);
    claw_target_global = 200;
    drive_encoder(-1, 200, 3500, 127, 60, 5, 0.2, 0.2);
    delay(700);
    arm_target_global = 220;//was 185
    delay(750);
    //drive_encoder(-1, 200, 700, 127, 60, 5, 0.05, 0.05);

    //turn, move to dump
    turn_time(-1, 148, 4, 150, 127, 12, 14);//DONOT CHANGE
    //turn_gyro(-1, 149, 1200, 127, 127, 0, 0.1);//DONOT CHANGE
    arm_target_global = 1000;
    //drive_encoder(-1, 100, 1000, 127, 50, 3, 0.2, 0.2);
    claw_release(130, 700, 2000);
    delay(600);//YY 1000
    arm_target_global = 0;
    delay(1500);
    drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
    //drive_stop(-1, 0, 127, 3);
    drive_encoder(1, 250, 1000, 127, 50, 3, 0, 0);
    delay(75);
    drive_encoder(-1, 300, 1000, 127, 50, 3, 0.2, 0.2);
    //drive_stop(-1, 0, 127, 3);

    //drive to grab cube and back star
    claw_target_global = 105;
    drive_encoder(1, 2100, 3500, 127, 50, 3, 0.2, 0.2);
    claw_target_global = 190;
    lock_encoder(750, 1);//YY 1000
    //delay(1000);
    arm_target_global = 190;
    delay(300);//YY 600
    arm_target_global = 1000;
    drive_encoder(-1, 2000, 4000, 127, 50, 3, 0.2, 0.2);
    claw_release(130, 600, 2000);
    delay(500); //YY 1000
    arm_target_global = 700;
    delay(650);//YY 1500
    //drive_stop(-1, 0, 127, 3);
    drive_encoder(-1, 300, 400, 127, 50, 3, 0.2, 0.2);//square
    drive_encoder(1, 1800, 4000, 127, 50, 3, 0.2, 0.2);

    turn_time(-1, 140, 4, 220, 127, 10, 14);
    //drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
    drive_stop(-1, 0, 127, 3);
    //delay(300); YY
    drive_encoder(1, 700, 1200, 127, 80, 3, 0.05, 0.1);

    turn_time(-1, 140, 4, 220, 127, 10, 14);
  //  drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
    drive_stop(-1, 0, 127, 3);
    //delay(300); YY
    drive_encoder(1, 400, 1200, 127, 80, 3, 0.05, 0.1);

    turn_time(1, 75, 4, 220, 127, 10, 14);
    //drive_stop(-1, 0, 127, 3);
    drive_encoder(-1, 1200, 1500, 127, 80, 3, 0, 0);

    arm_target_global = 1200;
    delay(1300);// YY 1500
    drive_encoder(1, 200, 1000, 127, 100, 3, 0, 0);
    arm_target_global = -100;
    drive_encoder(1, 8000, 4000, 127, 100, 3, 0, 0);


    delay(20000);

break;
case 1: // AUTO 1 - CUBE LEFT

  /*
  delay(200);
  claw_target_global = 125;
  drive_encoder(1, 200, 2000, 127, 50, 3, 0, 0);
  delay(300);
  drive_encoder(-1, 200, 2000, 127, 50, 3, 0, 0);
  delay(200);
  turn_gyro(1, 75, 1000, 127, 80, 0.2, 0.1);
  */

  drive_encoder(1, 200, 2000, 127, 50, 3, 0, 0);
  delay(300);
  drive_encoder(-1, 200, 2000, 127, 50, 3, 0, 0);
  delay(200);

  drive_encoder(1, 1850, 2000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 180;
  delay(1500);
  arm_target_global = 200;
  delay(750);

  turn_time(1, 185, 5, 150, 127, 12, 14);
  arm_target_global = 1000;
  drive_encoder(-1, 1600, 2000, 127, 50, 3, 0, 0);
  claw_release(130, 700, 2000);
  delay(600);

  arm_target_global = 0;
  claw_target_global = 100;
  delay(1000);
  drive_encoder(1, 2200, 1200, 127, 50, 3, 0, 0);
  claw_target_global = 180;
  delay(1000);

  arm_target_global = 1000;
  drive_encoder(-1, 2000, 2500, 127, 50, 3, 0, 0);
  claw_release(130, 700, 2000);
  delay(600);

  arm_target_global = 0;
  claw_target_global = 100;
  delay(1000);
  drive_encoder(1, 2200, 1200, 127, 50, 3, 0, 0);
  claw_target_global = 180;
  delay(1000);

  arm_target_global = 1000;
  drive_encoder(-1, 2000, 2500, 127, 50, 3, 0, 0);
  claw_release(130, 700, 2000);
  delay(600);


break;

case 2: // CUBE R

break;

case 3:// HANG -L

delay(200);
arm_target_global = 400;
delay(750);
claw_target_global = 140;
delay(750);
arm_target_global = 0;
delay(750);

drive_encoder(-1, 200, 2000, 127, 50, 3, 0, 0);
drive_encoder(1, 150, 2000, 127, 50, 3, 0, 0);

delay(200);
drive_encoder(1, 600, 2000, 127, 50, 3, 0.2, 0.2);
claw_target_global = 190;
delay(600);
arm_target_global = 400;
delay(750);

turn_time(-1, 155, 7, 150, 127, 7, 12);
delay(200);
drive_encoder(-1, 1000, 2000, 127, 50, 3, 0.2, 0);
arm_target_global = 1000;
drive_encoder(-1, 1300, 2000, 127, 50, 3, 0, 0.2);
claw_release(130, 600, 2000);

delay(1000);
arm_target_global = 800;
delay(1200);
drive_encoder(-1, 250, 750, 127, 50, 3, 0.2, 0.2);
drive_encoder(1, 1800, 2000, 127, 50, 3, 0.2, 0.2);
turn_time(-1, 190, 7, 150, 127, 7, 12);

drive_encoder(-1, 1200, 1500, 127, 80, 3, 0, 0);

arm_target_global = 1200;
delay(1300);// YY 1500
drive_encoder(1, 200, 1000, 127, 100, 3, 0, 0);
arm_target_global = -100;
drive_encoder(1, 8000, 4000, 127, 100, 3, 0, 0);




break;

case 4: // Hang - R

delay(200);
drive_stop(-1, 0, 127, 3);
/*
  lcdClear(uart1);
  while(true){

    encoderReset(encoder_L);
    encoderReset(encoder_R);

    delay(20);

    motorset_drive(-127, -127);

    lcdPrint(uart1, 1, "EnL: %d", encoderGet(encoder_L));
    lcdPrint(uart1, 1, "EnR: %d", encoderGet(encoder_R));

  }
*/
break;

case 5:

delay(200);
claw_target_global = 140;
delay(1600);

drive_encoder(1, 650, 2000, 127, 50, 3, 0, 0);
delay(200);
turn_time(1, 145, 7, 150, 127, 7, 12);
drive_encoder(1, 900, 2000, 127, 50, 3, 0.2, 0.2);
claw_target_global = 100;
delay(600);
drive_encoder(-1, 350, 2000, 127, 50, 3, 0.2, 0.2);
turn_time(1, 85, 5, 200, 127, 8, 12);
drive_encoder(-1, 1200, 2000, 127, 50, 3, 0.2, 0.2);

arm_target_global = 1200;
delay(2000);// YY 1500
drive_encoder(1, 200, 1000, 127, 100, 3, 0, 0);
arm_target_global = -100;
drive_encoder(1, 8000, 4000, 127, 100, 3, 0, 0);



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
