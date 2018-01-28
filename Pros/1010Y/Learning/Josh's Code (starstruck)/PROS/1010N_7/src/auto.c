
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
delay(100);
  drive_stop(1, 0, 127, 7);
break;


case -1: //Old Programming skills
  delay(100);
  drive_stop(1, 0, 110, 7);

break;

case 0:// new programming skills

    //backout
    delay(200);
    drive_encoder(-1, 1400, 3000, 127, 50, 1.5, 0.2, 0.2);
    //drive_encoder(1, 200, 3000, 127, 50, 1.5, 0.2, 0.2);
    //drive_encoder(-1, 200, 3000, 127, 50, 1.5, 0.2, 0.2);
    //delay(300);
    //turn_time(1, 35, 5, 150, 127, 8, 15);
    claw_target_global = 800; //OlD 130
    delay(1500);
    claw_target_global = 530;
    delay(500);

    //back in grab
    drive_encoder(1, 650, 3000, 127, 50, 1.5, 0.2, 0.2); // was 580
    claw_target_global = 820; //OLD 185
    lock_encoder(1200, 0.5);


    //drive to dump
    arm_target_global = 640; //OLD 1000
    //drive_stop(-1, 0, 127, 2); // back to fence
    drive_encoder(-1, 1700, 4000, 127, 50, 1.5, 0.2, 0.1);//0.2 deaccel take out
    claw_release(620, 600, 8000);
    delay(600);//YY 750

    //lower arm for second grab
    arm_target_global = 0;
    delay(1500);
    //turn_time(-1, 30, 5, 150, 127, 8, 15);

      drive_stop(-1, 0, 127, 2); // square
      //drive_encoder(-1, 500, 800, 127, 50, 1.5, 0.2, 0);//square

    //drive_encoder(1, 300, 750, 127, 50, 3, 0.2, 0);
    //drive_encoder(-1, 300, 750, 127, 50, 3, 0.2, 0);
    //drive_encoder(1, 300, 750, 127, 50, 3, 0.2, 0);

    claw_target_global = 520; //old 135
    drive_encoder(1, 1900, 3000, 127, 50, 1.5, 0.2, 0.2);
    claw_target_global = 790;//was 185
    lock_encoder(800, 0.5);//YY 1200

    //to fence for dump
    arm_target_global = 660; // OLD 1000
    drive_encoder(-1, 1900, 3000, 127, 50, 1.5, 0.2, 0);//0.2 deaccel take out
    claw_release(500, DUMP_HIEGHT, 2000);
    delay(400);

    //lower and back for final cube
    arm_target_global = 0;
    delay(1000);
      drive_stop(-1, 0, 127, 2); // sqaure
      //drive_encoder(-1, 400, 1000, 127, 50, 1.5, 0.2, 0.2);
      //SECNDON SQUARE
    //drive_encoder(1, 400, 1000, 127, 50, 1.5, 0.2, 0);
      //drive_stop(-1, 0, 127, 2); // square

      //drive_encoder(-1, 400, 1000, 127, 50, 1.5, 0.2, 0);
    drive_encoder(1, 2000, 3500, 127, 50, 1.5, 0.2, 0.2);
    claw_target_global = 790; // OLD 135
    lock_encoder(1200, 0.5);
    arm_target_global = 660; // OLD 1000
    drive_encoder(-1, 1850, 3500, 127, 50, 1.5, 0.2, 0);//0.2 deaccel take out
    claw_release(600, DUMP_HIEGHT, 2000);
    delay(400);

    //down, turn and drive
    claw_target_global = 620; // was 670
    arm_target_global = 0;
    delay(1000);
      drive_stop(-1, 0, 127, 2); // sqaure
      //drive_encoder(-1, 200, 400, 127, 50, 1.5, 0.2, 0.2);
    //drive_encoder(-1, 200, 10000, 127, 50, 3, 0.2, 0.2);

    drive_encoder(1, 250, 3500, 100, 50, 1.5, 0.3, 0.3);
    delay(500);
    turn_time(1, 142, 4, 200, 127, 5.1, 13); // was 4 kp
    delay(100);
    drive_encoder(-1, 120, 3500, 127, 60, 4, 0.2, 0.2);

    /*    claw_target_global = 620;
    delay(400);

    drive_encoder(1, 500, 3500, 127, 60, 7.5, 0.2, 0);
    claw_target_global = 660;
    */
    //MAIN DRIVE STOP
      drive_stop(1, 0, 127, 8.75); // square
      //drive_encoder(1, 5700, 3700, 127, 60, 6, 0.03, 0);
    claw_target_global = 820;// OLD 200
    delay(750);
    drive_encoder(-1, 50, 3500, 127, 60, 4, 0.2, 0.2);
    delay(700);
    arm_target_global = 180;//OLD 220
    delay(750);
    //drive_encoder(-1, 200, 700, 127, 60, 5, 0.05, 0.05);

    //turn, move to dump
    turn_time(-1, 140, 4, 175, 127, 4, 14);//DONOT CHANGE
    //turn_gyro(-1, 149, 1200, 127, 127, 0, 0.1);//DONOT CHANGE
    arm_target_global = 690; // OLD 1000
    //drive_encoder(-1, 100, 1000, 127, 50, 3, 0.2, 0.2);
    claw_release(500, 600, 2000);
    delay(600);//YY 1000
    arm_target_global = 0;
    delay(1500);
      drive_stop(-1, 0, 127, 2); // square
      //drive_encoder(-1, 300, 800, 127, 50, 1.5, 0.2, 0.2);
    //drive_stop(-1, 0, 127, 3);
    drive_encoder(1, 250, 1000, 127, 50, 1.5, 0, 0);
    delay(75);
      drive_stop(-1, 0, 127, 2); // square
      //drive_encoder(-1, 300, 1000, 127, 50, 1.5, 0.2, 0.2);
    //drive_stop(-1, 0, 127, 3);

      drive_encoder(1, 250, 1000, 127, 50, 1.5, 0, 0);
      turn_time(1, 16, 4, 175, 127, 5.2, 14);


    //drive to grab cube and back star
    claw_target_global = 420;//OLD 105 // was 490
    drive_encoder(1, 1750, 3500, 127, 50, 1.5, 0.2, 0.2);
    claw_target_global = 760;//OLD 190
    lock_encoder(750, 1);//YY 1000
    //delay(1000);
    arm_target_global = 270;// OLD 120
    delay(700);//YY 600
    turn_time(1, 16, 4, 175, 127, 5.2, 14);
    arm_target_global = 660; //OLD 1000

      drive_stop(-1, 0, 127, 6);
      //drive_encoder(-1, 2000, 4000, 127, 50, 1.5, 0.2, 0.2);
    claw_release(600, 600, 2000);
    delay(500); //YY 1000
    arm_target_global = 500;// OLD 700
    delay(650);//YY 1500
    //drive_stop(-1, 0, 127, 3);
    drive_encoder(-1, 300, 400, 127, 50, 1.5, 0.2, 0.2);//square
    drive_encoder(1, 1800, 4000, 127, 50, 1.5, 0.2, 0.2);

    turn_time(-1, 140, 4, 220, 127, 6.5, 14);
    //drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
    drive_stop(-1, 0, 127, 3);
    //delay(300); YY
    drive_encoder(1, 700, 1200, 127, 80, 1.5, 0.05, 0.1);

    turn_time(-1, 140, 4, 220, 127, 6.5, 14);
  //  drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
    drive_stop(-1, 0, 127, 3);
    //delay(300); YY
    drive_encoder(1, 550, 1200, 127, 80, 1.5, 0.05, 0.1);

    turn_time(1, 72, 4, 220, 127, 5, 14); // was 75
    //drive_stop(-1, 0, 127, 3);
    drive_encoder(-1, 1250, 1500, 127, 80, 1.5, 0, 0);

    arm_target_global = 930; //OLD 1200
    drive_encoder(-1, 100, 1000, 80, 50, 5, 0, 0);
    delay(250);// YY 1500
    drive_encoder(1, 200, 1000, 127, 100, 1.5, 0, 0);
    arm_target_global = -100;
    drive_encoder(1, 8000, 4000, 127, 100, 1.5, 0, 0);


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


  /*
  drive_encoder(1, 200, 2000, 127, 50, 3, 0, 0);
  delay(300);
  drive_encoder(-1, 200, 2000, 127, 50, 3, 0, 0);
  delay(200);

  */
  delay(50);
  claw_target_global = 550;
  drive_encoder(1, 2350, 2000, 127, 50, 1.8, 0.2, 0.2);

  claw_target_global = 780;
  delay(400);
  arm_target_global = 300;
  delay(750);

  turn_time(1, 198, 4, 150, 127, 5, 12); // was 16 for tigh range
  arm_target_global = 670;
  //drive_stop(-1, 0, 127, 1.5);
  drive_encoder(-1, 1600, 2000, 127, 50, 1.5, 0, 0);
  claw_release(500, 680, 2000);
  delay(600);

  arm_target_global = 0;
  claw_target_global = 490;
  delay(1000);
  drive_encoder(-1, 350, 800, 127, 50, 1.5, 0, 0);
  drive_encoder(1, 2200, 1200, 127, 50, 1.5, 0, 0);
  claw_target_global = 780;
  delay(1000);

  arm_target_global = 660;
  drive_encoder(-1, 1850, 2000, 127, 50, 1.5, 0, 0);
  //drive_stop(-1, 0, 127, 1.5);
  claw_release(580, 680, 2000);
  delay(600);

  arm_target_global = 0;
  claw_target_global = 500;
  delay(1000);
  drive_encoder(-1, 350, 800, 127, 50, 1.5, 0, 0);
  drive_encoder(1, 2200, 1200, 127, 50, 1.5, 0, 0);
  claw_target_global = 780;
  delay(1000);

  arm_target_global = 660;
  drive_encoder(-1, 1850, 2000, 127, 50, 1.5, 0, 0);
  claw_release(550, 680, 2000);
  delay(600);

break;

case 2: // CUBE R

  delay(50);
  claw_target_global = 550;
  drive_encoder(1, 2350, 2000, 127, 50, 1.8, 0.2, 0.2);

  claw_target_global = 780;
  delay(400);
  arm_target_global = 300;
  delay(750);

  turn_time(-1, 198, 4, 150, 127, 5, 12); // was 16 for tigh range
  arm_target_global = 670;
  //drive_stop(-1, 0, 127, 1.5);
  drive_encoder(-1, 1600, 2000, 127, 50, 1.5, 0, 0);
  claw_release(500, 680, 2000);
  delay(600);

  arm_target_global = 0;
  claw_target_global = 490;
  delay(1000);
  drive_encoder(-1, 350, 800, 127, 50, 1.5, 0, 0);
  drive_encoder(1, 2200, 1200, 127, 50, 1.5, 0, 0);
  claw_target_global = 780;
  delay(1000);

  arm_target_global = 660;
  drive_encoder(-1, 1850, 2000, 127, 50, 1.5, 0, 0);
  //drive_stop(-1, 0, 127, 1.5);
  claw_release(580, 680, 2000);
  delay(600);

  arm_target_global = 0;
  claw_target_global = 500;
  delay(1000);
  drive_encoder(-1, 350, 800, 127, 50, 1.5, 0, 0);
  drive_encoder(1, 2200, 1200, 127, 50, 1.5, 0, 0);
  claw_target_global = 780;
  delay(1000);

  arm_target_global = 660;
  drive_encoder(-1, 1850, 2000, 127, 50, 1.5, 0, 0);
  claw_release(550, 680, 2000);
  delay(600);


break;

case 3:// HANG -L


  delay(100);
  claw_target_global = 640;
  delay(750);

  drive_encoder(1, 600, 2000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 700;
  delay(600);

  turn_time(1, 155, 5, 200, 127, 6.2, 14);
  delay(200);
  drive_encoder(1, 1400, 2000, 127, 50, 3, 0.2, 0);
  claw_target_global = 500;
  drive_stop(-1, 0, 127, 3);
  drive_encoder(1, 300, 1200, 80, 80, 1.5, 0.05, 0.1);

  turn_time(1, 70, 4, 220, 80, 5, 14); // was 75
  //drive_stop(-1, 0, 127, 3);
  drive_encoder(-1, 400, 1500, 80, 80, 1.5, 0, 0);

  arm_target_global = 900; //OLD 1200
  delay(1500);// YY 1500
  drive_encoder(1, 40, 1000, 127, 100, 1.5, 0, 0);
  arm_target_global = 950;
  delay(500);
  arm_target_global = -90;
  drive_encoder(1, 8000, 4000, 127, 100, 1.5, 0, 0);

  delay(20000);

/*
  //drive_encoder(-1, 1000, 2000, 127, 50, 3, 0, 0.2);

  turn_time(1, 140, 4, 220, 127, 5, 14);
  //drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
  drive_stop(-1, 0, 127, 3);
  //delay(300); YY
  drive_encoder(1, 700, 1200, 127, 80, 1.5, 0.05, 0.1);

  turn_time(-1, 140, 4, 220, 127, 5, 14);
  //  drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
  drive_stop(-1, 0, 127, 3);
  //delay(300); YY
  drive_encoder(1, 550, 1200, 127, 80, 1.5, 0.05, 0.1);

  turn_time(1, 72, 4, 220, 127, 5, 14); // was 75
  //drive_stop(-1, 0, 127, 3);
  drive_encoder(-1, 1250, 1500, 127, 80, 1.5, 0, 0);

  arm_target_global = 900; //OLD 1200
  delay(1500);// YY 1500
  drive_encoder(1, 200, 1000, 127, 100, 1.5, 0, 0);
  arm_target_global = -100;
  drive_encoder(1, 8000, 4000, 127, 100, 1.5, 0, 0);


  delay(20000);
*/


break;

case 4: // Hang - R
  delay(750);
  claw_target_global = 640;
  delay(750);

  drive_encoder(1, 600, 2000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 700;
  delay(600);

  turn_time(-1, 155, 7, 150, 127, 7, 12);
  delay(200);
  drive_encoder(1, 1400, 2000, 127, 50, 3, 0.2, 0);
  drive_encoder(-1, 1000, 2000, 127, 50, 3, 0, 0.2);

  turn_time(-1, 140, 4, 220, 127, 5, 14);
  //drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
  drive_stop(-1, 0, 127, 3);
  //delay(300); YY
  drive_encoder(1, 700, 1200, 127, 80, 1.5, 0.05, 0.1);

  turn_time(1, 140, 4, 220, 127, 5, 14);
  //  drive_encoder(-1, 1200, 1200, 127, 80, 3, 0, 0.1);
  drive_stop(-1, 0, 127, 3);
  //delay(300); YY
  drive_encoder(1, 550, 1200, 127, 80, 1.5, 0.05, 0.1);

  turn_time(-1, 72, 4, 220, 127, 5, 14); // was 75
  //drive_stop(-1, 0, 127, 3);
  drive_encoder(-1, 1250, 1500, 127, 80, 1.5, 0, 0);

  arm_target_global = 900; //OLD 1200
  delay(1500);// YY 1500
  drive_encoder(1, 200, 1000, 127, 100, 1.5, 0, 0);
  arm_target_global = -100;
  drive_encoder(1, 8000, 4000, 127, 100, 1.5, 0, 0);


  delay(20000);


break;

case 5: //non hang L

  delay(750);
  claw_target_global = 640;
  delay(750);

  drive_encoder(1, 600, 2000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 700;
  delay(600);
  arm_target_global = 200;
  delay(750);
  turn_time(-1, 155, 7, 150, 127, 7, 12);
  delay(200);
  arm_target_global = 680;
  drive_encoder(-1, 2000, 2000, 127, 50, 3, 0.2, 0);
  claw_release(500, 550, 2500);

break;

case 6: // nonhang R

  delay(750);
  claw_target_global = 640;
  delay(750);

  drive_encoder(1, 600, 2000, 127, 50, 3, 0.2, 0.2);
  claw_target_global = 700;
  delay(600);
  arm_target_global = 200;
  delay(750);
  turn_time(1, 155, 7, 150, 127, 7, 12);
  delay(200);
  arm_target_global = 680;
  drive_encoder(-1, 2000, 2000, 127, 50, 3, 0.2, 0);
  claw_release(500, 550, 2500);

break;

case 7: // none

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
