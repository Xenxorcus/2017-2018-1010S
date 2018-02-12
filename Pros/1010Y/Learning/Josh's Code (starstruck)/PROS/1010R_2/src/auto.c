
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

int motor_count= 1; // For motor test (auto -2)

switch (myauto) {
case -2: // MOTOR TEST

  drive_stop(-1, 0, 127, 10, 1000);
/*
  delay(5);
  lcdPrint(uart1, 1, "MOTOR TEST START");
  delay(1000);

  while(motor_count <= 10){

    lcdPrint(uart1, 1, "MOTOR %d", motor_count);
    delay(500);
    motorSet(motor_count, 90);
    delay(250);
    motorSet(motor_count, 0);
    delay(500);
    motor_count = motor_count + 1;

  }

  lcdPrint(uart1, 1, "MOTOR TEST FINISH");
  delay(1000);
*/

break;


case -1: //Modified Programming skills

delay(5);
arm_target_global = 105;
claw_release2(95, 585, 5000);//was 580 // was 95
drive_encoder(-1, 450, 4000, 127, 60, 16, 0, 0.5);// was 800 // kp was 10
delay(1500);

arm_target_global = -10;
delay(1500);

drive_encoder(1, 2300, 4000, 127, 60, 10, 0, 0.3);// was 1800
claw_target_global = 800;
delay(700);
arm_target_global = 75; // was 70
delay(700);
drive_encoder(-1, 1950, 4000, 127, 60, 14, 0, 0.3); // was 1350
delay(150);
//turn to dump
turn_pid(-1, 137, 127, 6.2, 0, 46, 0, 1300); // was 7 // was 135
delay(100);// was 1000

  // dump 1
  arm_target_global = 130;
  claw_release2(100, 600, 5000);
  delay(130);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 16, 3000); // was 10 // 12.5 // 14 // timeout was 3500
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  delay(800);// was 1400

//preload run 1
arm_target_global = -10;
claw_target_global = 525;
//lock_encoder(2500, 3);
delay(900);// was 2300
  drive_stop(-1, 2, 127, 10, 750); // was 1000
  //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  delay(100); // was 500// was 200
drive_encoder(1, 1100, 4000, 127, 60, 8, 0, 0.3); // was 10 // was 1000
delay(200);// was 500;
claw_target_global = 750;
delay(800);// was 1000
//turn_pid(-1, 0, 127, 7, 0, 0, 0, 800); //LOCK// no kd was 22
  //fence dump
  arm_target_global = 130;
  claw_release2(90, 600, 5000);
  delay(960); //tune for dump// wa s800
  drive_stop(-1, 0, 127, 16, 3000); // was 8 /10 // timeout was 3500
  //drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
  delay(800); // was 1400

//preload run 2
arm_target_global = -10;
claw_target_global = 525;
delay(900); // was 2300
  drive_stop(-1, 5, 127, 10, 750); // was 1000
  //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  delay(200);// was 500
drive_encoder(1, 1100, 4000, 127, 60, 8, 0, 0.3);// was 10
delay(200);// was 500
claw_target_global = 750;
//turn_pid(-1, 0, 127, 7, 0, 0, 0, 1200); //LOCK// no kd was 22
delay(900);// was 900
  //fence dump
  arm_target_global = 130;
  claw_release2(90, 600, 5000);
  delay(920); //tune for dump // was 600 // was 700 // was 850
  drive_stop(-1, 0, 127, 16, 3000);//was 8 / 10 // timeout qas 3500
  //drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0);// was 1300
  delay(800);// was 1400

  //turn
arm_target_global = -10;
claw_target_global = 630;
delay(800);// 1500
  drive_stop(-1, 0, 127, 10, 750); // was 1000
  //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  delay(200);//was 500
drive_encoder(1, 120, 4000, 90, 40, 5, 0, 0.4);
delay(200);// was 1000
turn_pid(1, 130, 127, 7, 0, 22, 0, 1000);// was 140 // was 133
delay(200);// was 1000
drive_encoder(1, 1600, 5000, 127, 60, 8, 0, 0.2);
// possible switch to drive encoder;

//3S fence dump
claw_target_global = 800;
delay(900);
arm_target_global = 38;
delay(700);
turn_pid(-1, 140, 127, 7, 0, 22, 0, 1000);
delay(200);// was 1000
drive_encoder(1, 100, 750, 127, 60, 12, 0, 0.2);
//drive_encoder(1, 100, 4000, 90, 60, 10, 0.1, 0.2);
//delay(1000);

  arm_target_global = 145;
  claw_release2(100, 600, 5000);
  delay(1100); //tune for dump // was 1000
  drive_stop(-1, 0, 127, 10, 1000);// was 1300
  delay(800);// was 1000

//center cube

arm_target_global = 70;
delay(1000);
drive_stop(-1, 0, 127, 10, 1000);
delay(50);
drive_encoder(1, 100, 750, 127, 60, 12, 0, 0.2);
delay(50);
turn_pid(-1, 42, 127, 5, 0, 16, 0, 1000);// was 7, 18 // further reduced
drive_encoder(1, 100, 500, 127, 60, 12, 0, 0.2);

arm_target_global = -10;
claw_target_global = 520;
delay(900); // was 1500 // was 1500
    //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  //delay(500);
drive_encoder(1, 400, 4000, 127, 60, 8, 0, 0.3);
delay(200);// was 500
claw_target_global = 790;
delay(900);// was 1200
  //fence dump

  arm_target_global = 42;
  delay(1000);
  turn_pid(1, 42, 127, 7, 0, 22, 0, 1000);

  arm_target_global = 138;
  claw_release2(100, 600, 5000);
  delay(900); //tune for dump // was 700
  drive_stop(-1, 0, 127, 8, 1000);
  //drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
  delay(800); // was 1400

  //move to side
  arm_target_global = -15; // was 0
  claw_target_global = 710;
  delay(900);// was 1500
  drive_stop(-1, 0, 127, 8, 1000);
  delay(100);

  drive_encoder(1, 750, 2000, 127, 60, 10, 0, 0.3);
  delay(200);// was 500
  turn_pid(1, 140, 127, 7, 0, 22, 0, 1000);
  delay(200);// was 700
  drive_encoder(1, 1500, 2000, 127, 60, 8, 0, 0.3);//was 10 // was 1500
  turn_pid(-1, 140, 127, 7, 0, 22, 0, 1000);

  claw_target_global = 410;
  delay(1000);
  drive_encoder(1, 850, 2000, 127, 60, 8, 0, 0.3); // was 8 // was 500
  delay(100);
  claw_target_global = 750;
  //turn_pid(-1, 0, 127, 5, 0, 0, 0, 1200);//LOCK // noi kd was 22// lowered to 7
  delay(900); // was 1200

  // second grab
    drive_encoder(-1, 100, 2000, 127, 60, 8, 0, 0.3); // was 8
  claw_target_global = 400;
  delay(1000);
  drive_encoder(1, 100, 2000, 127, 60, 8, 0, 0.3); // was 8
  claw_target_global = 800;
  //turn_pid(-1, 0, 127, 7, 0, 0, 0, 1200); //LOCK// no kd was 22
  delay(1200);
  arm_target_global = 38;
  delay(100);
  //turn_pid(-1, 20, 127, 7, 0, 22, 0, 1000);
  delay(100);


  //dump cube + star
  arm_target_global = 138;
  claw_release2(100, 600, 5000);
  delay(100); //tune for dump // was 200
  drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
  delay(1200);// was 1400

  //go for hang
  arm_target_global = 75;
  claw_target_global = 580;
  drive_stop(-1, 0, 127, 10, 2000);
  delay(900);// was 1500
  drive_encoder(1, 1500, 4000, 127, 60, 10, 0, 0.5);
  delay(1000);
  /*
  turn_pid(-1, 130, 127, 6, 0, 24, 0, 1200);// was 7, 22 // increase to 24
  delay(1000);
  drive_stop(-1, 0, 70, 10, 1750);
  delay(1000);
  drive_encoder(1, 400, 4000, 80, 60, 10, 0, 0.5);
  delay(1000);

  turn_pid(-1, 130, 127, 6, 0, 24, 0, 1200);// was 7, 22 // increse to 24
  delay(1000);
  drive_stop(-1, 0, 70, 12, 1750);
  delay(1000);
  drive_encoder(1, 400, 4000, 80, 60, 10, 0, 0.5);
  delay(1000);
  */

  turn_pid(-1, 218, 127, 7, 0, 22, 0, 1200);
  delay(1000);
  drive_stop(-1, 0, 70, 16, 1200);
//  drive_encoder(-1, 400, 1500, 127, 60, 10, 0, 0.3);
    delay(200);
    /*
  drive_encoder(1, 50, 4000, 70, 60, 10, 0, 0.3);
  delay(500);
  drive_encoder(-1, 60, 4000, 70, 60, 10, 0, 0.3);
  delay(1000);
  */

  arm_target_global = 155;
  delay(1500);


  motorset_drive(127, 127);
  delay(500);
  arm_target_global = -50;
  //claw_hang(30, -40);
  delay(700);
  claw_target_global = -10;
  motorset_drive(-127, -127);
  claw_target_global = -10;
  delay(2000);
  motorset_drive(0, 0);



  /*
  drive_encoder(1, 450, 4000, 127, 60, 10, 0, 0.3);
  delay(200);
  arm_target_global = -50;
  claw_hang(30, -40);
  delay(300);
  drive_encoder(1, 2500, 4000, 127, 60, 10, 0, 0.3);
  drive_encoder(-1, 4000, 4000, 127, 60, 10, 0, 0.3);
  delay(10000);
*/

break;

case 0:// mew programming skills`

delay(5);
arm_target_global = 105;
claw_release2(95, 585, 5000);//was 580 // was 95
drive_encoder(-1, 450, 4000, 127, 60, 16, 0, 0.5);// was 800 // kp was 10
delay(1500);

arm_target_global = -10;
delay(1500);

drive_encoder(1, 2300, 4000, 127, 60, 10, 0, 0.3);// was 1800
claw_target_global = 800;
delay(700);
arm_target_global = 75; // was 70
delay(700);
drive_encoder(-1, 1950, 4000, 127, 60, 14, 0, 0.3); // was 1350
delay(150);
//turn to dump
turn_pid(-1, 137, 127, 6.2, 0, 46, 0, 1300); // was 7 // was 135
delay(100);// was 1000

  // dump 1
  arm_target_global = 130;
  claw_release2(100, 600, 5000);
  delay(130);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 16, 3000); // was 10 // 12.5 // 14 // timeout was 3500
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  delay(800);// was 1400

//preload run 1
arm_target_global = -10;
claw_target_global = 525;
//lock_encoder(2500, 3);
delay(900);// was 2300
  drive_stop(-1, 2, 127, 10, 750); // was 1000
  //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  delay(100); // was 500// was 200
drive_encoder(1, 1100, 4000, 127, 60, 8, 0, 0.3); // was 10 // was 1000
delay(200);// was 500;
claw_target_global = 750;
delay(800);// was 1000
//turn_pid(-1, 0, 127, 7, 0, 0, 0, 800); //LOCK// no kd was 22
  //fence dump
  arm_target_global = 130;
  claw_release2(90, 600, 5000);
  delay(960); //tune for dump// wa s800
  drive_stop(-1, 0, 127, 16, 3000); // was 8 /10 // timeout was 3500
  //drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
  delay(800); // was 1400

//preload run 2
arm_target_global = -10;
claw_target_global = 525;
delay(900); // was 2300
  drive_stop(-1, 5, 127, 10, 750); // was 1000
  //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  delay(200);// was 500
drive_encoder(1, 1100, 4000, 127, 60, 8, 0, 0.3);// was 10
delay(200);// was 500
claw_target_global = 750;
//turn_pid(-1, 0, 127, 7, 0, 0, 0, 1200); //LOCK// no kd was 22
delay(900);// was 900
  //fence dump
  arm_target_global = 130;
  claw_release2(90, 600, 5000);
  delay(920); //tune for dump // was 600 // was 700 // was 850
  drive_stop(-1, 0, 127, 16, 3000);//was 8 / 10 // timeout qas 3500
  //drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0);// was 1300
  delay(800);// was 1400

  //turn
arm_target_global = -10;
claw_target_global = 630;
delay(800);// 1500
  drive_stop(-1, 0, 127, 10, 750); // was 1000
  //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  delay(200);//was 500
drive_encoder(1, 120, 4000, 90, 40, 5, 0, 0.4);
delay(200);// was 1000
turn_pid(1, 130, 127, 7, 0, 22, 0, 1000);// was 140 // was 133
delay(200);// was 1000
drive_encoder(1, 1600, 5000, 127, 60, 8, 0, 0.2);
// possible switch to drive encoder;

//3S fence dump
claw_target_global = 800;
delay(900);
arm_target_global = 38;
delay(700);
turn_pid(-1, 140, 127, 7, 0, 22, 0, 1000);
delay(200);// was 1000
drive_encoder(1, 100, 750, 127, 60, 12, 0, 0.2);
//drive_encoder(1, 100, 4000, 90, 60, 10, 0.1, 0.2);
//delay(1000);

  arm_target_global = 145;
  claw_release2(100, 600, 5000);
  delay(1100); //tune for dump // was 1000
  drive_stop(-1, 0, 127, 10, 1000);// was 1300
  delay(800);// was 1000

//center cube

arm_target_global = 70;
delay(1000);
drive_stop(-1, 0, 127, 10, 1000);
delay(50);
drive_encoder(1, 100, 750, 127, 60, 12, 0, 0.2);
delay(50);
turn_pid(-1, 42, 127, 5, 0, 16, 0, 1000);// was 7, 18 // further reduced
drive_encoder(1, 100, 500, 127, 60, 12, 0, 0.2);

arm_target_global = -10;
claw_target_global = 520;
delay(900); // was 1500 // was 1500
    //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  //delay(500);
drive_encoder(1, 400, 4000, 127, 60, 8, 0, 0.3);
delay(200);// was 500
claw_target_global = 790;
delay(900);// was 1200
  //fence dump

  arm_target_global = 42;
  delay(1000);
  turn_pid(1, 42, 127, 7, 0, 22, 0, 1000);

  arm_target_global = 138;
  claw_release2(100, 600, 5000);
  delay(900); //tune for dump // was 700
  drive_stop(-1, 0, 127, 8, 1000);
  //drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
  delay(800); // was 1400

  //move to side
  arm_target_global = -15; // was 0
  claw_target_global = 710;
  delay(900);// was 1500
  drive_stop(-1, 0, 127, 8, 1000);
  delay(100);

  drive_encoder(1, 750, 2000, 127, 60, 10, 0, 0.3);
  delay(200);// was 500
  turn_pid(1, 140, 127, 7, 0, 22, 0, 1000);
  delay(200);// was 700
  drive_encoder(1, 1500, 2000, 127, 60, 8, 0, 0.3);//was 10 // was 1500
  turn_pid(-1, 140, 127, 7, 0, 22, 0, 1000);

  claw_target_global = 410;
  delay(1000);
  drive_encoder(1, 850, 2000, 127, 60, 8, 0, 0.3); // was 8 // was 500
  delay(100);
  claw_target_global = 750;
  //turn_pid(-1, 0, 127, 5, 0, 0, 0, 1200);//LOCK // noi kd was 22// lowered to 7
  delay(900); // was 1200

  // second grab
  /*
  drive_encoder(-1, 100, 2000, 127, 60, 8, 0, 0.3); // was 8
  claw_target_global = 400;
  delay(1000);
  drive_encoder(1, 100, 2000, 127, 60, 8, 0, 0.3); // was 8
  claw_target_global = 800;
  //turn_pid(-1, 0, 127, 7, 0, 0, 0, 1200); //LOCK// no kd was 22
  delay(1200);
  arm_target_global = 38;
  delay(100);
  //turn_pid(-1, 20, 127, 7, 0, 22, 0, 1000);
  delay(100);
  */

  //dump cube + star
  arm_target_global = 138;
  claw_release2(100, 600, 5000);
  delay(100); //tune for dump // was 200
  drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
  delay(1200);// was 1400

  //go for hang
  arm_target_global = 75;
  claw_target_global = 580;
  drive_stop(-1, 0, 127, 10, 2000);
  delay(900);// was 1500
  drive_encoder(1, 1500, 4000, 127, 60, 10, 0, 0.5);
  delay(1000);
  /*
  turn_pid(-1, 130, 127, 6, 0, 24, 0, 1200);// was 7, 22 // increase to 24
  delay(1000);
  drive_stop(-1, 0, 70, 10, 1750);
  delay(1000);
  drive_encoder(1, 400, 4000, 80, 60, 10, 0, 0.5);
  delay(1000);

  turn_pid(-1, 130, 127, 6, 0, 24, 0, 1200);// was 7, 22 // increse to 24
  delay(1000);
  drive_stop(-1, 0, 70, 12, 1750);
  delay(1000);
  drive_encoder(1, 400, 4000, 80, 60, 10, 0, 0.5);
  delay(1000);
  */

  turn_pid(-1, 218, 127, 7, 0, 22, 0, 1200);
  delay(1000);
  drive_stop(-1, 0, 70, 16, 1200);
//  drive_encoder(-1, 400, 1500, 127, 60, 10, 0, 0.3);
    delay(200);
    /*
  drive_encoder(1, 50, 4000, 70, 60, 10, 0, 0.3);
  delay(500);
  drive_encoder(-1, 60, 4000, 70, 60, 10, 0, 0.3);
  delay(1000);
  */

  arm_target_global = 155;
  delay(1500);


  motorset_drive(127, 127);
  delay(500);
  arm_target_global = -50;
  //claw_hang(30, -40);
  delay(700);
  claw_target_global = -10;
  motorset_drive(-127, -127);
  claw_target_global = -10;
  delay(2000);
  motorset_drive(0, 0);



  /*
  drive_encoder(1, 450, 4000, 127, 60, 10, 0, 0.3);
  delay(200);
  arm_target_global = -50;
  claw_hang(30, -40);
  delay(300);
  drive_encoder(1, 2500, 4000, 127, 60, 10, 0, 0.3);
  drive_encoder(-1, 4000, 4000, 127, 60, 10, 0, 0.3);
  delay(10000);
*/

break;
case 1: // AUTO 1 - CUBE LEFT
  delay(5);
  arm_target_global = 20;
  drive_encoder(1, 1050, 2500, 127, 60, 8, 0, 0.2);
  arm_target_global = -10;
  claw_target_global = 800;
  delay(900); // was 1500 // was 1000
  arm_target_global = 38;
  delay(200); // was 200
  turn_pid(1, 190, 127, 7, 0, 22, 0, 750);

  arm_target_global = 130;
  claw_release2(100, 600, 5000);
  delay(500);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 16, 3500); // was 10 // 12.5 // 14
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  delay(250);// was 1400 // was 1000 // was 800

  //preload run 1
  arm_target_global = -10;
  claw_target_global = 430;
  //lock_encoder(2500, 3);
  delay(1000); // was 2300
  //drive_stop(-1, 2, 127, 10, 1000);
  //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  //delay(500);
  drive_encoder(1, 1250, 4000, 127, 60, 8, 0, 0.3); // was 10 // was 1000 // was 1250
  delay(500);
  claw_target_global = 790;
  delay(800); // was 1000
  //fence dump
  arm_target_global = 130;
  claw_release2(90, 600, 5000);
  delay(720); //tune for dump
  drive_stop(-1, 0, 127, 12.5, 3500); // was 8 /10
  //drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
  delay(800);// 1400 // was 1000

  //preload run 2
  arm_target_global = -10;
  claw_target_global = 430;
  delay(800);// 2300 // was 1000
  drive_stop(-1, 5, 127, 10, 1000);
  //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
  //delay(500);
  drive_encoder(1, 1100, 4000, 127, 60, 8, 0, 0.3);// was 10
  delay(0);// was 500
  claw_target_global = 790;
  delay(800); // was 1200
  //fence dump
  arm_target_global = 130;
  claw_release2(90, 600, 5000);
  delay(600); //tune for dump
  drive_stop(-1, 0, 127, 12.5, 3500);//was 8 / 10
  //drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0);// was 1300
  delay(1400);


  /* // Back into cube run
  delay(5);
  arm_target_global = 50;
  claw_release2(10, 600, 2500);
  drive_encoder(-1, 2150, 4000, 127, 60, 10, 0, 0.2);
  delay(100);
  turn_pid(-1, 50, 127, 7, 0, 22, 0, 750);
  //delay(500);
  arm_target_global = 0;
  claw_target_global = 570;
  delay(750);
  drive_encoder(1, 100, 1000, 127, 60, 10, 0, 0.2);
  claw_target_global = 790;

  delay(750);
    //fence dump 1
    arm_target_global = 130;
    claw_release2(90, 600, 5000);
    delay(700);//adjust for fence timing
    drive_encoder(-1, 200, 1000, 127, 60, 10, 0, 0.3);// was 1200
    delay(900);

  arm_target_global = 0;
  claw_target_global = 500;
  //lock_encoder(2500, 3);
  delay(1500);
    //drive_stop(-1, 2, 127, 10);
    //drive_stop(-1, 0, 127, 10, 600); // taken out
    //drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
    //delay(200);
  drive_encoder(1, 1350, 4000, 127, 60, 10, 0, 0.3);
  //delay(500);
  claw_target_global = 750;
  delay(1000);
  arm_target_global = 20;
  delay(750);
    //fence dump 2
    arm_target_global = 130;
    claw_release2(90, 600, 5000);
    delay(100); //tune for dump
    drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
    delay(1400);


    arm_target_global = 0;
    claw_target_global = 500;
    //lock_encoder(2500, 3);
    delay(2500);
      //drive_stop(-1, 2, 127, 10);
      drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
      delay(500);
    drive_encoder(1, 1000, 4000, 127, 60, 10, 0, 0.3);
    delay(500);
    claw_target_global = 750;
    delay(1000);
      //fence dump 2
      arm_target_global = 130;
      claw_release2(90, 600, 5000);
      delay(100); //tune for dump
      drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
      delay(1400);

      */

break;

case 2: // CUBE R

delay(5);
arm_target_global = 20;
drive_encoder(1, 1050, 2500, 127, 60, 8, 0, 0.2);
arm_target_global = -10;
claw_target_global = 800;
delay(900); // was 1500 // was 1000
arm_target_global = 38;
delay(200); // was 200
turn_pid(-1, 190, 127, 7, 0, 22, 0, 750);

arm_target_global = 130;
claw_release2(100, 600, 5000);
delay(500);//adjust for fence timing // was 100
drive_stop(-1, 0, 127, 16, 3500); // was 10 // 12.5 // 14
//drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
delay(250);// was 1400 // was 1000 // was 800

//preload run 1
arm_target_global = -10;
claw_target_global = 430;
//lock_encoder(2500, 3);
delay(1000); // was 2300
//drive_stop(-1, 2, 127, 10, 1000);
//drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
//delay(500);
drive_encoder(1, 1250, 4000, 127, 60, 8, 0, 0.3); // was 10 // was 1000 // was 1250
delay(500);
claw_target_global = 790;
delay(800); // was 1000
//fence dump
arm_target_global = 130;
claw_release2(90, 600, 5000);
delay(720); //tune for dump
drive_stop(-1, 0, 127, 12.5, 3500); // was 8 /10
//drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0.3);// was 1300
delay(800);// 1400 // was 1000

//preload run 2
arm_target_global = -10;
claw_target_global = 430;
delay(800);// 2300 // was 1000
drive_stop(-1, 5, 127, 10, 1000);
//drive_encoder(-1, 100, 800, 127, 60, 10, 0, 0.3);
//delay(500);
drive_encoder(1, 1100, 4000, 127, 60, 8, 0, 0.3);// was 10
delay(0);// was 500
claw_target_global = 790;
delay(800); // was 1200
//fence dump
arm_target_global = 130;
claw_release2(90, 600, 5000);
delay(600); //tune for dump
drive_stop(-1, 0, 127, 12.5, 3500);//was 8 / 10
//drive_encoder(-1, 1300, 4000, 127, 60, 10, 0, 0);// was 1300
delay(1400);


break;

case 3:// BACK -L
delay(5);
arm_target_global = 105;
claw_release2(95, 585, 5000);//was 580 // was 95
drive_encoder(-1, 450, 4000, 127, 60, 16, 0, 0.5);// was 800 // kp was 10
delay(1500);

arm_target_global = -10;
delay(1500);

drive_encoder(1, 2000, 4000, 127, 60, 10, 0, 0.3);// was 1800 // was 2300
claw_target_global = 800;
delay(700);
arm_target_global = 75; // was 70
delay(700);
drive_encoder(-1, 1650, 4000, 127, 60, 14, 0, 0.3); // was 1350 // was 1650
delay(150);
//turn to dump
turn_pid(1, 137, 127, 6.2, 0, 46, 0, 1300); // was 7 // was 135
delay(100);// was 1000

  // dump 1
  arm_target_global = 130;
  claw_release2(100, 600, 5000);
  delay(130);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 16, 3000); // was 10 // 12.5 // 14 // timeout was 3500
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  delay(800);// was 1400


break;

case 4: // Back -  R
delay(5);
arm_target_global = 105;
claw_release2(95, 585, 5000);//was 580 // was 95
drive_encoder(-1, 450, 4000, 127, 60, 16, 0, 0.5);// was 800 // kp was 10
delay(1500);

arm_target_global = -10;
delay(1500);
delay(3000);
drive_encoder(1, 2000, 4000, 127, 60, 10, 0, 0.3);// was 1800 // sas 2300
claw_target_global = 800;
delay(700);
arm_target_global = 75; // was 70
delay(700);
drive_encoder(-1, 1650, 4000, 127, 60, 14, 0, 0.3); // was 1350 // was 1950
delay(150);
//turn to dump
turn_pid(-1, 137, 127, 6.2, 0, 46, 0, 1300); // was 7 // was 135
delay(100);// was 1000

  // dump 1
  arm_target_global = 130;
  claw_release2(100, 600, 5000);
  delay(130);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 16, 3000); // was 10 // 12.5 // 14 // timeout was 3500
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  delay(800);// was 1400

break;

case 5: // NEAR L

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



break;

case 6: // NEar R

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

  turn_pid(1, 130, 127, 8, 0, 22, 0, 2000);

  delay(700);
  arm_target_global = 130;
  claw_release2(100, 600, 5000);
  delay(100);//adjust for fence timing
  drive_stop(-1, 0, 127, 12.5, 3500);
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  delay(1400);



break;

case 7: // CUBE BLOCK L

delay(5);
arm_target_global = 20;
drive_encoder(1, 1050, 2500, 127, 60, 8, 0, 0.2);
arm_target_global = -10;
claw_target_global = 800;
delay(900); // was 1500 // was 1000
arm_target_global = 38;
delay(200); // was 200
turn_pid(1, 190, 127, 7, 0, 22, 0, 750);

arm_target_global = 145; // was 130
claw_release2(100, 450, 5000); // was 600
delay(500);//adjust for fence timing // was 100
drive_stop(-1, 0, 127, 16, 3500); // was 10 // 12.5 // 14
//drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
delay(250);// was 1400 // was 1000 // was 800



break;
case 8: // CUBE BLOCK R

delay(5);
arm_target_global = 20;
drive_encoder(1, 1050, 2500, 127, 60, 8, 0, 0.2);
arm_target_global = -10;
claw_target_global = 800;
delay(900); // was 1500 // was 1000
arm_target_global = 38;
delay(200); // was 200
turn_pid(-1, 190, 127, 7, 0, 22, 0, 750);

arm_target_global = 145; // was 130
claw_release2(100, 450, 5000); // was 600
delay(500);//adjust for fence timing // was 100
drive_stop(-1, 0, 127, 16, 3500); // was 10 // 12.5 // 14
//drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
delay(250);// was 1400 // was 1000 // was 800

break;
case 9: // do nothing

break;
default:
break;
      }



}
