
#include "main.h"
#include "lcdfunctions.h"
#include "autofunctions.h"
#include "util.h"
#include "claw.h"
#include "arm.h"
#include "motor.h"

#define DUMP_HIEGHT 600
void autonomous() {

 TaskHandle autolcd_task = taskCreate(autolcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle claw_task = taskCreate(clawtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle arm_task = taskCreate(armtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  TaskHandle motor_task = taskCreate(motortask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

slewset(false, false, false, false); // only first true value matters

//gyroReset(gyro);
//gyro_offset = 0; // must change in auto for differeent starting positions

int motor_count= 1; // For motor test (auto -2)

switch (myauto) {
case -2: // MOTOR TEST
/*
  delay(5);
  lcdPrint(uart1, 1, "MOTOR TEST START");
  delay(1000);

  while(motor_count <= 10){

    lcdPrint(uart1, 1, "MOTOR %d", motor_count);
    delay(500);
    motorSet(motor_count, 50);
    delay(250);
    motorSet(motor_count, 0);
    delay(500);
    motor_count = motor_count + 1;

  }

  lcdPrint(uart1, 1, "MOTOR TEST FINISH");
  delay(1000);

  */
break;


case -1: //Blank  - For testing
delay(1000);
drive_encoder(1, 700, 5000, 127, 60, 2, 0, 0);
delay(1500);
turn_pid2(-1, 5, 127, 3.5, 0, 30, 0, 1000); // was 800/-25


break;

case 0:// mew programming skills`

delay(5);
claw_target_global = -240;
drive_encoder(-1, 450, 1000, 127, 60, 0.1, 0, 0);
delay(350);
//turn_pid2(1, -93, 127, 3.5, 0, 30, 0, 400);
drive_encoder(1, 2950, 4000, 127, 60, 0.1, 0, 0);// was 1800 // was 2300
claw_target_global = -60;
delay(700);
arm_target_global = 200; // was 70
delay(700);
drive_encoder(-1, 2000, 4000, 127, 60, 0.1, 0, 0); // was 1350 // was 1650
delay(150);
//turn to dump
turn_pid2(-1, 3, 127, 3.5, 0, 30, 0, 900); // was 7 // was 135
delay(100);// was 1000
drive_encoder(-1, 300, 4000, 127, 60, 0.1, 0, 0);
  // dump 1
  claw_release2(340, -400, 5000);
    arm_target_global = 500;
    delay(200);
  //delay(130);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 0.1, 2000); // was 10 // 12.5 // 14 // timeout was 3500
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  //arm_target_global = 500;
  delay(500);// was 1400

  arm_target_global = 0;
  claw_target_global = -350;
  //turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
  delay(500);
  drive_encoder(1, 1000, 2500, 127, 60, 0.1, 0, 0);
  claw_target_global = -90;
  delay(650);

  //dump2
  arm_target_global = 500;
  delay(575); //for dump
    claw_release2(350, -280, 5000);// 350
    drive_stop(-1, 0, 127, 0.1, 1200);
  delay(300);
  arm_target_global = -10;
  claw_target_global = -350;
  //turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
  delay(500);
  drive_encoder(1, 1000, 2500, 127, 60, 0.1, 0, 0);
  claw_target_global = -90;
  delay(900);

  //dump3
  arm_target_global = 500;
  delay(500);
    claw_release2(350, -290, 5000);// 350
    drive_stop(-1, 0, 127, 0.1, 1500);

    delay(500);
    arm_target_global = 0;
    claw_target_global = -350;
    //turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
    delay(500);
    drive_encoder(1, 1000, 2500, 127, 60, 0.1, 0, 0);
    claw_target_global = -90;
    delay(800);

    //dump4
      arm_target_global = 500;
      delay(400);
      claw_release2(350, -300, 5000);// 350
      drive_stop(-1, 0, 127, 0.1, 1500);

      delay(550);
      claw_target_global = -150;
      arm_target_global = 0;
      delay(1000);

      /////
      drive_encoder(1, 130, 2500, 127, 60, 0.1, 0, 0);
      turn_pid2(-1, -85, 127, 3.5, 0, 30, 0, 1300); // was 800/-25
      drive_encoder(-1, 200, 2500, 127, 60, 0.1, 0, 0);
      claw_target_global = -260;
        turn_pid2(-1, -97, 127, 3.5, 0, 30, 0, 800); // was 800/-25
      delay(200);
          drive_encoder(1, 2550, 2500, 127, 60, 0.1, 0, 0);
      claw_target_global = -80;
      delay(700);
      arm_target_global = 260;
      drive_encoder(-1, 300, 4000, 127, 60, 0.1, 0, 0); // was 400
    turn_pid2(-1, 0, 127, 3.5, 0, 30.2, 0, 1300); // was 800/-25
      arm_target_global = 500;
      delay(500);
        claw_release2(420, -390, 5000);// 350
        drive_stop(-1, 0, 127, 0.1, 1500);
/////////////////////////////// ccube dump below
        delay(700);
        arm_target_global = 0;
        delay(1200);
        drive_encoder(1, 100, 1500, 127, 60, 0.1, 0, 0);
        claw_target_global = -90;
        delay(1000);
        arm_target_global = 500;
        delay(650);
          claw_release2(350, -350, 5000);// 350
          drive_stop(-1, 0, 127, 0.1, 1300);
        //move to far cube and star
      delay(1000);
      arm_target_global = 0;
      claw_target_global = -230;
      delay(1000);

    drive_encoder(1, 200, 2000, 127, 60, 0.1, 0, 0);
    turn_pid2(-1,-92, 127, 3.5, 0, 30, 0, 1300); // was 800/-25
    drive_encoder(1, 2300, 2000, 127, 60, 0.1, 0, 0); // was 2200
    turn_pid2(-1, -3, 127, 3.5, 0, 30, 0, 1300); // was 800/-25
    claw_target_global = -475;
    delay(700);
    drive_encoder(1, 500, 2000, 127, 60, 0.1, 0, 0);
    claw_target_global = -90;
    delay(1000);
    arm_target_global = 500;
    delay(300);
      claw_release2(420, -350, 5000);// 350
      drive_stop(-1, 0, 127, 0.1, 1500);
      delay(1000);
    arm_target_global = 130;
    delay(400);
    ////// hanging code
    drive_encoder(1, 800, 2000, 127, 60, 0.1, 0, 0);
    turn_pid2(-1, 138, 127, 3.5, 0, 30, 0, 1300);
      drive_encoder(-1, 800, 2000, 127, 60, 0.1, 0, 0);
    delay(1000);
    arm_target_global = 500;
    delay(700);

    drive_encoder(1, 75, 2000, 127, 60, 0.1, 0, 0);
    arm_target_global = -150;
    drive_encoder(1, 400, 2000, 127, 60, 0.1, 0, 0);
    delay(1300);
    claw_target_global = 20;
    delay(3000);





break;
case 1: // AUTO 1 - CUBE LEFT 2 M
  delay(1);
  claw_target_global = -390;
  delay(425); // was 200 // was 300 // was 400 WORKDING2
  drive_encoder(1, 660, 1000, 127, 60, 0.1, 0, 0); // was 900 // was 800 //w as 720 // 660 // was 550
  claw_target_global = -20;
  delay(300); //was 500 !!!
  arm_target_global = 180;
  turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 750); // was 800/-25 // was 900 WORKING1 // 800 (WORKING !!!)
  arm_target_global = 500;
  claw_release2(350, -350, 5000);// 350

  drive_stop(-1, 0, 127, 0.1, 1300); //was 10 // 12.5 // 14
  //drive_encoder(-1, 1200, 1000, 127, 60, 1, 0, 0);// was 1200

  delay(700);// was 1400 // was 1000
  arm_target_global = -10;
  claw_target_global = -460;
  delay(600); // was 1000 // was 700
  turn_pid2(-1, -25, 127, 3.5, 0, 30, 0, 600);
  claw_target_global = -460;
  drive_encoder(1, 880, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -60;
  delay(800); // was 1000
  /* // two grabs
  drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -460;
  delay(850); // was 700
  drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -70;
  delay(800); // was 700
  */
  arm_target_global = 500;
  claw_release2(320, -330, 5000); // was 350
  drive_stop(-1, 0, 127, 0.1, 1500);


  delay(550);// was 1400 // was 1000
  arm_target_global = -10;
  claw_target_global = -390;
  delay(800); // was 1000
  turn_pid2(-1, -64, 127, 3.5, 0, 30, 0, 800);
  claw_target_global = -390;
  drive_encoder(1, 2200, 2000, 127, 60, 0, 0, 0);
  claw_target_global = -60;
  delay(1000);
  drive_encoder(-1, 350, 1000, 127, 60, 0.1, 0, 0);
  turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
  //turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
  // was 1000
  /* // two grabs
  drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -460;
  delay(850); // was 700
  drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -70;
  delay(800); // was 700
  */
  arm_target_global = 500;
  claw_release2(320, -330, 5000); // was 350
  drive_stop(-1, 0, 127, 0.1, 2000);



break;

case 2: // Near L

  delay(5);
  claw_target_global = -250;
  drive_encoder(-1, 450, 1000, 127, 60, 0.1, 0, 0);
  delay(500); // was 500
  drive_encoder(1, 1000, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -60;
  delay(1000);
  arm_target_global = 230;
  drive_encoder(-1, 140, 1000, 127, 60, 0.1, 0, 0);
  turn_pid2(-1, 15, 127, 1.5, 0, 20.2, 0, 1000);
      claw_release2(350, -350, 5000); // was 350
        drive_stop(-1, 0, 127, 0.1, 1700);
        arm_target_global = 500;
        delay(1300);
  arm_target_global = -10;
  claw_target_global = -320;
  delay(1000);
  turn_pid2(-1, -3, 127, 3.5, 0, 30, 0, 800);
  drive_encoder(1, 1150, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -90;
  delay(1000);
  turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
  arm_target_global = 500;
  claw_release2(420, -300, 5000); // was 350
  drive_stop(-1, 0, 127, 0.1, 2000);


break;

case 3:// NEar R
  delay(5);
  claw_target_global = -250;
  drive_encoder(-1, 450, 1000, 127, 60, 0.1, 0, 0);
  delay(500); // was 500
  drive_encoder(1, 1000, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -60;
  delay(1000);
  arm_target_global = 230;
  drive_encoder(-1, 140, 1000, 127, 60, 0.1, 0, 0);
  turn_pid2(-1, -15, 127, 1.5, 0, 20.2, 0, 1000);
      claw_release2(350, -350, 5000); // was 350
        drive_stop(-1, 0, 127, 0.1, 1700);
        arm_target_global = 500;
        delay(1300);
  arm_target_global = -10;
  claw_target_global = -320;
  delay(1000);
  turn_pid2(-1, 3, 127, 3.5, 0, 30, 0, 800);
  drive_encoder(1, 1150, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -90;
  delay(1000);
  turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
  arm_target_global = 500;
  claw_release2(420, -300, 5000); // was 350
  drive_stop(-1, 0, 127, 0.1, 2000);

break;

case 4: // Cube R 2M
  delay(1);
  claw_target_global = -390;
  delay(425); // was 200 // was 300 // was 400 WORKDING2
  drive_encoder(1, 660, 1000, 127, 60, 0.1, 0, 0); // was 900 // was 800 //w as 720 // 660 // was 550
  claw_target_global = -20;
  delay(300); //was 500 !!!
  arm_target_global = 180;
  turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800); // was 800/-25 // was 900 WORKING1 // 800 (WORKING !!!)
  arm_target_global = 500;
  claw_release2(350, -350, 5000);// 350

  drive_stop(-1, 0, 127, 0.1, 1000); //was 10 // 12.5 // 14
  //drive_encoder(-1, 1200, 1000, 127, 60, 1, 0, 0);// was 1200

  delay(700);// was 1400 // was 1000
  arm_target_global = -10;
  claw_target_global = -460;
  delay(600); // was 1000 // was 700
  turn_pid2(-1, 22, 127, 3.5, 0, 30, 0, 1100);
  claw_target_global = -460;
  drive_encoder(1, 800, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -60;
  delay(800); // was 1000
  /* // two grabs
  drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -460;
  delay(850); // was 700
  drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -70;
  delay(800); // was 700
  */
  arm_target_global = 500;
  claw_release2(320, -330, 5000); // was 350
  drive_stop(-1, 0, 127, 0.1, 1500);


  delay(550);// was 1400 // was 1000
  arm_target_global = -10;
  claw_target_global = -420;
  delay(800); // was 1000
  turn_pid2(-1, 64, 127, 3.5, 0, 30, 0, 800);
  claw_target_global = -390;
  drive_encoder(1, 2200, 2100, 127, 60, 0.0, 0, 0);
  claw_target_global = -60;
  delay(1000);
  drive_encoder(-1, 350, 1000, 127, 60, 0.1, 0, 0);
  turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
  //turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
  // was 1000
  /* // two grabs
  drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -460;
  delay(850); // was 700
  drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
  claw_target_global = -70;
  delay(800); // was 700
  */
  arm_target_global = 500;
  claw_release2(320, -330, 5000); // was 350
  drive_stop(-1, 0, 127, 0.1, 2000);




break;

case 5:  // MOD R..//

delay(1);
claw_target_global = -390;
delay(425); // was 200 // was 300 // was 400 WORKDING2
drive_encoder(1, 660, 1000, 127, 60, 0.1, 0, 0); // was 900 // was 800 //w as 720 // 660 // was 550
claw_target_global = -20;
delay(300); //was 500 !!!
arm_target_global = 180;
turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800); // was 800/-25 // was 900 WORKING1 // 800 (WORKING !!!)
arm_target_global = 500;
claw_release2(350, -350, 5000);// 350

drive_stop(-1, 0, 127, 0.1, 1000); //was 10 // 12.5 // 14
//drive_encoder(-1, 1200, 1000, 127, 60, 1, 0, 0);// was 1200

delay(5600);// was 1400 // was 1000

/*
arm_target_global = -10;
claw_target_global = -460;
delay(600); // was 1000 // was 700
turn_pid2(-1, 22, 127, 3.5, 0, 30, 0, 1100);
claw_target_global = -460;
drive_encoder(1, 800, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -60;
delay(800); // was 1000
/* // two grabs
drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -460;
delay(850); // was 700
drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -70;
delay(800); // was 700

arm_target_global = 500;
claw_release2(320, -330, 5000); // was 350
drive_stop(-1, 0, 127, 0.1, 1500);


delay(550);// was 1400 // was 1000
*/

arm_target_global = -10;
claw_target_global = -420;
delay(800); // was 1000
turn_pid2(-1, 64, 127, 3.5, 0, 30, 0, 800);
claw_target_global = -390;
drive_encoder(1, 2200, 2100, 127, 60, 0.0, 0, 0);
claw_target_global = -60;
delay(1000);
drive_encoder(-1, 350, 1000, 127, 60, 0.1, 0, 0);
turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
//turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
// was 1000
/* // two grabs
drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -460;
delay(850); // was 700
drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -70;
delay(800); // was 700
*/
arm_target_global = 500;
claw_release2(320, -330, 5000); // was 350
drive_stop(-1, 0, 127, 0.1, 2000);






break;

case 6: // cube R 2R

delay(1);
claw_target_global = -390;
delay(375); // was 200 // was 300 // was 400 WORKDING2
drive_encoder(1, 660, 1000, 127, 60, 0.1, 0, 0); // was 900 // was 800 //w as 720 // 660 // was 550
claw_target_global = -20;
delay(300); //was 500 !!!
arm_target_global = 180;
turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 750); // was 800/-25 // was 900 WORKING1 // 800 (WORKING !!!)
arm_target_global = 500;
claw_release2(350, -350, 5000);// 350

drive_stop(-1, 0, 127, 0.1, 1300); //was 10 // 12.5 // 14
//drive_encoder(-1, 1200, 1000, 127, 60, 1, 0, 0);// was 1200

delay(4700);// was 1400 // was 1000

/*
arm_target_global = -10;
claw_target_global = -460;
delay(600); // was 1000 // was 700
turn_pid2(-1, -25, 127, 3.5, 0, 30, 0, 600);
claw_target_global = -460;
drive_encoder(1, 880, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -60;
delay(800); // was 1000
/* // two grabs
drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -460;
delay(850); // was 700
drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -70;
delay(800); // was 700

arm_target_global = 500;
claw_release2(320, -330, 5000); // was 350
drive_stop(-1, 0, 127, 0.1, 1500);


delay(550);// was 1400 // was 1000

*/
arm_target_global = -10;
claw_target_global = -390;
delay(800); // was 1000
turn_pid2(-1, -64, 127, 3.5, 0, 30, 0, 800);
claw_target_global = -390;
drive_encoder(1, 2200, 2000, 127, 60, 0, 0, 0);
claw_target_global = -60;
delay(1000);
drive_encoder(-1, 350, 1000, 127, 60, 0.1, 0, 0);
turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
//turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
// was 1000
/* // two grabs
drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -460;
delay(850); // was 700
drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -70;
delay(800); // was 700
*/
arm_target_global = 500;
claw_release2(320, -330, 5000); // was 350
drive_stop(-1, 0, 127, 0.1, 2000);




break;

case 7: // Back L
/*
  delay(5);
  claw_target_global = -240;
  drive_encoder(-1, 450, 1000, 127, 60, 0.1, 0, 0);
  delay(1000);
  //turn_pid2(1, -93, 127, 3.5, 0, 30, 0, 400);
  drive_encoder(1, 2400, 4000, 127, 60, 0.1, 0, 0);// was 1800 // was 2300
  claw_target_global = -60;
  delay(700);
  arm_target_global = 200; // was 70
  delay(700);
  drive_encoder(-1, 1800, 4000, 127, 60, 0.1, 0, 0); // was 1350 // was 1650
  delay(150);
  //turn to dump
  turn_pid2(-1, -3, 127, 3.5, 0, 30, 0, 1300); // was 7 // was 135
  delay(100);// was 1000
  drive_encoder(-1, 500, 4000, 127, 60, 0.1, 0, 0);
    // dump 1
    claw_release2(400, -400, 5000);
    arm_target_global = 500;
    //delay(130);//adjust for fence timing // was 100
    drive_stop(-1, 0, 127, 0.1, 2000); // was 10 // 12.5 // 14 // timeout was 3500
    //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
    //arm_target_global = 500;
    delay(2000);// was 1400

*/

delay(1);
claw_target_global = -390;
delay(375); // was 200 // was 300 // was 400 WORKDING2
drive_encoder(1, 660, 1000, 127, 60, 0.1, 0, 0); // was 900 // was 800 //w as 720 // 660 // was 550
claw_target_global = -20;
delay(300); //was 500 !!!
arm_target_global = 180;
turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 750); // was 800/-25 // was 900 WORKING1 // 800 (WORKING !!!)
arm_target_global = 500;
claw_release2(350, -350, 5000);// 350

drive_stop(-1, 0, 127, 0.1, 1300); //was 10 // 12.5 // 14
//drive_encoder(-1, 1200, 1000, 127, 60, 1, 0, 0);// was 1200

delay(4700);// was 1400 // was 1000
/*
arm_target_global = -10;
claw_target_global = -460;
delay(600); // was 1000 // was 700
turn_pid2(-1, -25, 127, 3.5, 0, 30, 0, 600);
claw_target_global = -460;
drive_encoder(1, 880, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -60;
delay(800); // was 1000
/* // two grabs
drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -460;
delay(850); // was 700
drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -70;
delay(800); // was 700

arm_target_global = 500;
claw_release2(320, -330, 5000); // was 350
drive_stop(-1, 0, 127, 0.1, 1500);


delay(550);// was 1400 // was 1000
*/
arm_target_global = -10;
claw_target_global = -390;
delay(800); // was 1000
turn_pid2(-1, 57, 127, 3.5, 0, 30, 0, 800);
claw_target_global = -390;
drive_encoder(1, 2200, 2000, 127, 60, 0, 0, 0);
claw_target_global = -60;
delay(1000);
drive_encoder(-1, 350, 1000, 127, 60, 0.1, 0, 0);
turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
//turn_pid2(-1, 0, 127, 3.5, 0, 30, 0, 800);
// was 1000
/* // two grabs
drive_encoder(-1, 400, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -460;
delay(850); // was 700
drive_encoder(1, 350, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -70;
delay(800); // was 700
*/
arm_target_global = 500;
claw_release2(320, -330, 5000); // was 350
drive_stop(-1, 0, 127, 0.1, 2000);






break;
case 8: // Back R


  delay(5);
  claw_target_global = -240;
  drive_encoder(-1, 450, 1000, 127, 60, 0.1, 0, 0);
  delay(1000);
  //turn_pid2(1, -93, 127, 3.5, 0, 30, 0, 400);
  drive_encoder(1, 2400, 4000, 127, 60, 0.1, 0, 0);// was 1800 // was 2300
  claw_target_global = -60;
  delay(700);
  arm_target_global = 200; // was 70
  delay(700);
  drive_encoder(-1, 1800, 4000, 127, 60, 0.1, 0, 0); // was 1350 // was 1650
  delay(150);
  //turn to dump
  turn_pid2(-1, 3, 127, 3.5, 0, 30, 0, 1300); // was 7 // was 135
  delay(100);// was 1000
  drive_encoder(-1, 500, 4000, 127, 60, 0.1, 0, 0);
  // dump 1
  claw_release2(400, -400, 5000);
  arm_target_global = 500;
  //delay(130);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 0.1, 2000); // was 10 // 12.5 // 14 // timeout was 3500
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  //arm_target_global = 500;
  delay(2000);// was 1400



break;
case 9: // do nothing

delay(5);
claw_target_global = -250;
drive_encoder(-1, 450, 1000, 127, 60, 0.1, 0, 0);
delay(500); // was 500
drive_encoder(1, 1000, 1000, 127, 60, 0.1, 0, 0);
claw_target_global = -60;
delay(1000);
arm_target_global = 230;
drive_encoder(-1, 140, 1000, 127, 60, 0.1, 0, 0);
turn_pid2(-1, 15, 127, 1.5, 0, 20.2, 0, 1000);
    claw_release2(350, -350, 5000); // was 350
      drive_stop(-1, 0, 127, 0.1, 1700);


break;
default:
break;
      }



}
 // near left code (not converted=)
/*


//NEar L
  delay(5);
  arm_target_global = 105;
  claw_release2(95, 580, 5000);//was 580
  drive_encoder(-1, 450, 4000, 127, 60, 11, 0, 0.3);// was 800 // kp was 10
  delay(1500);

  arm_target_global = -10;
  delay(1500);
  drive_encoder(1, 700, 4000, 127, 60, 11, 0, 0.3);// was 800 // kp was 10
  claw_target_global = 800;
  delay(1000);
  arm_target_global = 70;
  drive_encoder(-1, 200, 4000, 127, 60, 11, 0, 0.3);
  delay(1000);

    turn_pid(-1, 130, 127, 8, 0, 22, 0, 2000);

    delay(700);
    arm_target_global = 130;
    claw_release2(100, 600, 5000);
    delay(100);//adjust for fence timing
    drive_stop(-1, 0, 127, 12.5, 3500);
    //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
    delay(1400);


*/
