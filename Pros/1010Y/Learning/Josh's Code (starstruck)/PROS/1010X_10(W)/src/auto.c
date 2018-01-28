
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

slewset(true, false, false, false);

//gyroReset(gyro);
//gyro_offset = 0; // must change in auto for differeent starting positions

int motor_count= 1; // For motor test (auto -2)

switch (myauto) {
case -2: // MOTOR TEST

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
break;


case -1: //Blank  - For testing


break;

case 0:// mew programming skills`

drive_encoder(-1, 1000, 4000, 127, 60, 4, 0, 0.2);
claw_target_global = -300;
delay(1000);
drive_encoder(1, 400, 4000, 127, 60, 4, 0, 0.2);
claw_target_global = -120;
delay(1000);
//dump1
arm_target_global = 660;
  claw_release2(420, -400, 5000);// 350
  drive_stop(-1, 0, 127, 2, 1500);
delay(1000);
arm_target_global = 0;
delay(1000);
drive_encoder(1, 1000, 4000, 127, 60, 4, 0, 0);
claw_target_global = -120;
delay(1000);

//dump2
arm_target_global = 660;
  claw_release2(420, -400, 5000);// 350
  drive_stop(-1, 0, 127, 2, 1500);


delay(1000);
arm_target_global = 0;
delay(1000);
drive_encoder(1, 1000, 4000, 127, 60, 2, 0, 0);
claw_target_global = -120;
delay(1000);

//dump3
arm_target_global = 660;
  claw_release2(420, -400, 5000);// 350
  drive_stop(-1, 0, 127, 2, 1500);

  delay(1000);
  arm_target_global = 0;
  delay(1000);
  drive_encoder(1, 1000, 4000, 127, 60, 2, 0, 0);
  claw_target_global = -120;
  delay(1000);

  //dump4
  arm_target_global = 660;
    claw_release2(420, -400, 5000);// 350
    drive_stop(-1, 0, 127, 2, 1500);

    delay(1000);
    arm_target_global = 0;
    delay(1000);

    /////

    turn_pid2(-1, -140, 127, 1.5, 0, 20.2, 0, 1300); // was 800/-25
    drive_encoder(1, 1000, 4000, 127, 60, 2, 0, 0);
    claw_target_global = -120;
    delay(1000);
    arm_target_global = 250;
  turn_pid2(-1, 0, 127, 1.5, 0, 20.2, 0, 1300); // was 800/-25
    arm_target_global = 660;
      claw_release2(420, -400, 5000);// 350
      drive_stop(-1, 0, 127, 2, 1500);

      delay(1000);
      arm_target_global = 0;
      delay(1000);
      drive_encoder(1, 1000, 4000, 127, 60, 2, 0, 0);
      claw_target_global = -120;
      delay(1000);
      arm_target_global = 660;
        claw_release2(420, -400, 5000);// 350
        drive_stop(-1, 0, 127, 2, 1500);

        delay(1000);
        arm_target_global = 0;
        delay(1000);
        drive_encoder(1, 1000, 4000, 127, 60, 2, 0, 0);
        claw_target_global = -120;
        delay(1000);
        arm_target_global = 660;
          claw_release2(420, -400, 5000);// 350
          drive_stop(-1, 0, 127, 2, 1500);


break;
case 1: // AUTO 1 - CUBE LEFT 2 M
  delay(5);
  claw_target_global = -340;
  delay(185); // was 200 // was 300 // was 280
  drive_encoder(1, 700, 1000, 127, 60, 2, 0, 0); // was 900 // was 800 //w as 720 // 660
  delay(100);
  claw_target_global = -120;
  delay(350); // was 400
  arm_target_global = 400;
  turn_pid2(-1, -5, 127, 1.5, 0, 20.2, 0, 700); // was 800/-25
  arm_target_global = 660;
  claw_release2(420, -400, 5000);// 350
  drive_stop(-1, 0, 127, 2, 1500); // was 10 // 12.5 // 14
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  delay(4000);// was 1400 // was 1000 // was 800
arm_target_global = 0;
claw_target_global = -500;
delay(1000);
turn_pid2(-1, -10, 127, 1.5, 0, 20.2, 0, 800);
drive_encoder(1, 1200, 1000, 127, 60, 2, 0, 0);
claw_target_global = -100;
delay(1000);
arm_target_global = 660;
  claw_release2(420, -400, 5000); // was 350
  drive_stop(-1, 0, 127, 2, 2000);


break;

case 2: // Near L
  delay(5);
  claw_target_global = -300;
  drive_encoder(-1, 450, 1000, 127, 60, 2, 0, 0);
  delay(3500);// was 500
  drive_encoder(1, 900, 1000, 127, 60, 2, 0, 0);
  claw_target_global = -80;
  delay(1000);
  arm_target_global = 380;
  drive_encoder(-1, 75, 1000, 127, 60, 2, 0, 0);
  turn_pid2(-1, 20, 127, 1.5, 0, 20.2, 0, 1300);
      claw_release2(420, -400, 5000); // was 350
        drive_stop(-1, 0, 127, 2, 1700);
        arm_target_global = 660;
        delay(2000);


break;

case 3:// NEar R
delay(5);
claw_target_global = -300;
drive_encoder(-1, 450, 1000, 127, 60, 2, 0, 0);
delay(3500); // was 500
drive_encoder(1, 900, 1000, 127, 60, 2, 0, 0);
claw_target_global = -80;
delay(1000);
arm_target_global = 380;
drive_encoder(-1, 75, 1000, 127, 60, 2, 0, 0);
turn_pid2(-1, -20, 127, 1.5, 0, 20.2, 0, 1300);
    claw_release2(420, -400, 5000); // was 350
      drive_stop(-1, 0, 127, 2, 1700);
      arm_target_global = 660;
      delay(2000);

break;

case 4: // Cube R 2M

delay(5);
claw_target_global = -340;
delay(185); // was 200 // was 300
drive_encoder(1, 700, 1000, 127, 60, 2, 0, 0); // was 900 // was 800 //w as 720 // 660
delay(100);
claw_target_global = -120;
delay(350); // was 400
arm_target_global = 400;
turn_pid2(-1, 5, 127, 1.5, 0, 20.2, 0, 700); // was 800/-25
arm_target_global = 660;
claw_release2(420, -400, 5000);// 350
drive_stop(-1, 0, 127, 2, 1500); // was 10 // 12.5 // 14
//drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
delay(4000);// was 1400 // was 1000 // was 800
arm_target_global = 0;
claw_target_global = -500;
delay(1000);
turn_pid2(-1, 10, 127, 1.5, 0, 20.2, 0, 800);
drive_encoder(1, 1200, 1000, 127, 60, 2, 0, 0);
claw_target_global = -100;
delay(1000);
arm_target_global = 660;
claw_release2(420, -400, 5000); // was 350
drive_stop(-1, 0, 127, 2, 2000);


break;

case 5:  // Cube R 2L

break;

case 6: // cube R 2R
break;

case 7: // Back L
//Back L
delay(5);
claw_target_global = -250;
drive_encoder(-1, 140, 1000, 127, 60, 2, 0, 0.3);
delay(1000);

drive_encoder(1, 1800, 4000, 127, 60, 3, 0, 0.3);// was 1800 // was 2300
claw_target_global = -120;
delay(700);
arm_target_global = 260; // was 70
delay(700);
drive_encoder(-1, 1500, 4000, 127, 60, 2, 0, 0.3); // was 1350 // was 1650
delay(150);
//turn to dump
turn_pid2(-1, -10, 127, 1.5, 0, 20.2, 0, 1300); // was 7 // was 135
delay(100);// was 1000

  // dump 1
  claw_release2(500, -400, 5000);
  //delay(130);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 2, 2000); // was 10 // 12.5 // 14 // timeout was 3500
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  arm_target_global = 660;
  delay(2000);// was 1400





break;
case 8: // Back R

delay(5);
claw_target_global = -250;
drive_encoder(-1, 140, 1000, 127, 60, 2, 0, 0.3);
delay(1000);

drive_encoder(1, 1800, 4000, 127, 60, 3, 0, 0.3);// was 1800 // was 2300
claw_target_global = -120;
delay(700);
arm_target_global = 260; // was 70
delay(700);
drive_encoder(-1, 1500, 4000, 127, 60, 2, 0, 0.3); // was 1350 // was 1650
delay(150);
//turn to dump
turn_pid2(-1, 10, 127, 1.5, 0, 20.2, 0, 1300); // was 7 // was 135
delay(100);// was 1000

  // dump 1
  claw_release2(500, -400, 5000);
  //delay(130);//adjust for fence timing // was 100
  drive_stop(-1, 0, 127, 2, 2000); // was 10 // 12.5 // 14 // timeout was 3500
  //drive_encoder(-1, 1500, 3000, 127, 60, 10, 0, 0.3);// was 1200
  arm_target_global = 660;
  delay(2000);// was 1400





break;
case 9: // do nothing

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
