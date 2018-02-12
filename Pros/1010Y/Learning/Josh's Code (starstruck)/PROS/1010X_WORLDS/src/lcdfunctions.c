#include "main.h"
#include "lcdfunctions.h"
#include "arm.h"
#include "claw.h"
#include "ledfunctions.h"
#include "util.h"
#include "autofunctions.h"
#include "motor.h"

void disablelcd(void *ignore){

  int screen = 1;
  int screen_cap = 3;
  int btn_time = 100;
  myauto = 0;
  lcdClear(uart1);

  while(true){
    delay(25);
    //joystick_connected(LED_1);

    if(digitalRead(gyro_reset) == LOW){
      gyroReset(gyro);
      lcdClear(uart1);
      lcdPrint(uart1, 1, "GYRO RESET");
      delay(500);
        }

    if(!isEnabled()){
      switch(screen){

        case 1:
        lcdPrint(uart1, 1, "%d, Auto  %d ", screen, myauto);
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              myauto = myauto-1;}
          if(lcdReadButtons(uart1) == 4){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              myauto = myauto+1;}
        break;

        case 2:
        lcdPrint(uart1, 1, "%d: main:%dV ", screen, powerLevelMain());
        //lcdPrint(uart1, 2, " PE=%f", pe_batt(PEbatt_port));
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){}
          if(lcdReadButtons(uart1) == 4){}

        break;

        case 3:
        lcdPrint(uart1, 1, "%d", screen);
        lcdPrint(uart1, 2, "gyro =%d", gyroGet(gyro));
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){}
          if(lcdReadButtons(uart1) == 4){}
        break;

        default:
          lcdClear(uart1);
          lcdSetText(uart1, 1, "DEFAULT");
          delay(50);
          screen = 1;
        break;
        }

      //screen cap reset
      if(screen > screen_cap){screen = 1;}

      //auto line dispalby
      if(screen == 1){
        switch(myauto){
          case -2:
            lcdSetText(uart1, 2, "#-2 MotorTest");
          break;

          case -1:
            lcdSetText(uart1, 2, "#-1 New Program");
          break;
          case 0:
            lcdSetText(uart1, 2, "#0 WED Program");
          break;
          case 1:
            lcdSetText(uart1, 2, "#1 Cube L 2M");
          break;
          case 2:
            lcdSetText(uart1, 2, "#2 NEar L");
          break;
          case 3:
            lcdSetText(uart1, 2, "#3 Near R");
          break;
          case 4:
            lcdSetText(uart1, 2, "#4 Cube R 2M");
          break;
          case 5:
            lcdSetText(uart1, 2, "#5 6007 R");
          break;
          case 6:
            lcdSetText(uart1, 2, "#6 6007 L");
          break;
          case 7:
            lcdSetText(uart1, 2, "#7 7700R L");
          break;
          case 8:
            lcdSetText(uart1, 2, "#8 Back R");
          break;
          case 9:
            lcdSetText(uart1, 2, "#9 Near AntiDump");
          break;
          default:
          myauto = 1;
          break;
          }}
          delay(20);
  }
  else{delay(50);}
  }
}

void opcontrollcd(void *ignore){
  int screen = 1;
  int screen_cap = 4;
  int btn_time = 100;
  lcdClear(uart1);

  while(isEnabled()){
    delay(25);


    if(digitalRead(gyro_reset) == LOW){
      gyroReset(gyro);
      lcdClear(uart1);
      lcdPrint(uart1, 1, "GYRO RESET");
      delay(500);
        }

    switch(screen){

      case 1:
      lcdPrint(uart1, 1, "OP%d clawposL%d", screen, claw_pos_global);
      lcdPrint(uart1, 2, "clawtar %d", claw_target_global);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*action*/}
        if(lcdReadButtons(uart1) == 4){/*action*/}
      break;

      case 2:
      lcdPrint(uart1, 1, "OP%d armpos %d", screen, arm_pos_global);
      lcdPrint(uart1, 2, "armtarget %d", arm_target_global);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*action*/}
        if(lcdReadButtons(uart1) == 4){/*action*/}
      break;


      case 3:
      lcdPrint(uart1, 1, "OP%d EnL: %d", screen, encoderGet(encoder_L));
      lcdPrint(uart1, 2, "EnR%d Sl%d", encoderGet(encoder_R), test_slew);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){
          encoderReset(encoder_L);
          encoderReset(encoder_R);
          delay(100);
        }
        if(lcdReadButtons(uart1) == 4){
          encoderReset(encoder_L);
          encoderReset(encoder_R);
          }
      break;

      case 4:
        lcdPrint(uart1, 1, "OP:%d GRaw:%d", screen, gyroGet(gyro));
        lcdPrint(uart1, 2, "GRead: %f", gyro_read(gyro, 300));
          if(lcdReadButtons(uart1) == 2){
              lcdClear(uart1);
              lcdSetText(uart1, 1, "wait");
              delay(btn_time);
              screen = screen + 1;}
          if(lcdReadButtons(uart1) == 1){
            gyroReset(gyro);
            delay(100);
        }
          if(lcdReadButtons(uart1) == 4){
            gyroReset(gyro);
            delay(100);
          }
          // not in code rn ( case 5)
      case 5:
            lcdPrint(uart1, 1, "tar%d, port%d", motortarget[1], motorport[1]);
            lcdPrint(uart1, 2, "pow%d err%d", motorpower[1], motorerror[1]);
              if(lcdReadButtons(uart1) == 2){
                  lcdClear(uart1);
                  lcdSetText(uart1, 1, "wait");
                  delay(btn_time);
                  screen = screen + 1;}
              if(lcdReadButtons(uart1) == 1){ }
              if(lcdReadButtons(uart1) == 4){ }

      break;
      default:
      lcdClear(uart1);
      lcdSetText(uart1, 1, "DEFAULT");
      delay(50);
      screen = 1;
      break;
      }
    if(screen > screen_cap){screen = 1;}
  }
  taskDelete(opcontrollcd_task);
}

void autolcd(void *ignore){
  int screen = 1;
  int screen_cap = 3;
  int btn_time = 100;
  lcdClear(uart1);

  float kp_test= 9.5;
  float kd_test= 20;
  float cont = 0.2;

  while(isAutonomous()){
    delay(25);
    switch(screen){

      if(digitalRead(gyro_reset) == LOW){
        gyroReset(gyro);
        lcdClear(uart1);
        lcdPrint(uart1, 1, "GYRO RESET");
        delay(500);
          }

      case 1:
      //lcdPrint(uart1, 1, "AU%d A=%d", screen, myauto);
      //lcdPrint(uart1, 2, "enL%d enR%d", encoderGet(encoder_L), encoderGet(encoder_R));
      lcdPrint(uart1, 2, "gyro %f", gyro_read(gyro, 300));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){

            drive_encoder(1, 1200, 5000, 127, 60, kp_test, 0, 0);
            //turn_pid2(-1, 130, 127, kp_test, 0, kd_test, 0, 5000);

            }
        if(lcdReadButtons(uart1) == 4){/*action*/}
      break;

      case 2:
      lcdPrint(uart1, 1, "AU%d ", screen);
      lcdPrint(uart1, 2, "kptest%f", kp_test);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){kp_test = kp_test + 0.1;}
        if(lcdReadButtons(uart1) == 4){kp_test = kp_test - 0.1;}
      break;

      case 3:
      lcdPrint(uart1, 1, "AU%d ", screen);
      lcdPrint(uart1, 2, "kd_test%f", kd_test);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){kd_test = kd_test + 0.1;}
        if(lcdReadButtons(uart1) == 4){kd_test = kd_test - 0.1;}
      break;


      default:
      lcdClear(uart1);
      lcdSetText(uart1, 1, "DEFAULT");
      delay(50);
      screen = 1;
      break;
      }
    if(screen > screen_cap){screen = 1;}
  }

  taskDelete(autolcd_task);
  }

void lcdtune(){

  int screen = 1;
  int screen_cap = 3;
  int btn_time = 100;

  #define STEP1 0.05
  #define STEP2 0.05
  #define STEP3 0.05

  lcdPrint(uart1, 1, "     .");// insert some value here // 5 spaces

  switch(screen){

      case 1:
      lcdPrint(uart1, 2, "E%d", screen);
      lcdPrint(uart1, 1, "test1=%f", test1);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){test1 = test1 - STEP1;}
        if(lcdReadButtons(uart1) == 4){test1 = test1 + STEP1;}
      break;

      case 2:
      lcdPrint(uart1, 1, "E%d", screen);
      lcdPrint(uart1, 2, "test2=%f", test2);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){test2 = test2 - STEP2;}
        if(lcdReadButtons(uart1) == 4){test2 = test2 + STEP2;}
      break;

      case 3:
      lcdPrint(uart1, 1, "E%d ", screen);
      lcdPrint(uart1, 2, "test3=%f", test3);
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){test3 = test3 - STEP3;}
        if(lcdReadButtons(uart1) == 4){test3 = test3 + STEP3;}
      break;


      default:
      lcdClear(uart1);
      lcdSetText(uart1, 1, "DEFAULT");
      delay(50);
      screen = 1;
      break;
      }
    if(screen > screen_cap){screen = 1;}
  }
