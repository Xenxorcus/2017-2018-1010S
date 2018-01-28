#include "main.h"
#include "lcdfunctions.h"
#include "arm.h"
#include "claw.h"
#include "ledfunctions.h"
#include "util.h"


void disablelcd(void *ignore){

  int screen = 1;
  int screen_cap = 3;
  int btn_time = 100;
  myauto = 1;
  lcdClear(uart1);

  while(true){
    delay(25);
    joystick_connected(LED_1);
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
        lcdPrint(uart1, 2, " PE=%f", pe_batt(PEbatt_port));
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
            lcdSetText(uart1, 2, "#-2 Test");
          break;

          case -1:
            lcdSetText(uart1, 2, "#-1 OldProgramming");
          break;
          case 0:
            lcdSetText(uart1, 2, "#0 NewProgramming");
          break;
          case 1:
            lcdSetText(uart1, 2, "#1 Cube L");
          break;
          case 2:
            lcdSetText(uart1, 2, "#2 Cube R");
          break;
          case 3:
            lcdSetText(uart1, 2, "#3 Hang L");
          break;
          case 4:
            lcdSetText(uart1, 2, "#4 Hang R");
          break;
          case 5:
            lcdSetText(uart1, 2, "#5 Non L");
          break;
          case 6:
            lcdSetText(uart1, 2, "#6 Non R");
          break;
          case 7:
            lcdSetText(uart1, 2, "#7 None");
          break;
          case 8:
            lcdSetText(uart1, 2, "#8");
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
      lcdPrint(uart1, 2, "EnR: %d", encoderGet(encoder_R));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){
          encoderReset(encoder_L);
          encoderReset(encoder_R);
          delay(50);
        }
        if(lcdReadButtons(uart1) == 4){
          encoderReset(encoder_L);
          encoderReset(encoder_R);
          delay(50);
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
  int screen_cap = 2;
  int btn_time = 100;
  lcdClear(uart1);

  while(isAutonomous()){
    delay(25);
    switch(screen){

      case 1:
      lcdPrint(uart1, 1, "AU%d A=%d", screen, myauto);
      //lcdPrint(uart1, 2, "enL%d enR%d", encoderGet(encoder_L), encoderGet(encoder_R));
      lcdPrint(uart1, 2, "gyro %f", gyro_read(gyro, 300));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){
            encoderReset(encoder_L);
            encoderReset(encoder_R);  }
        if(lcdReadButtons(uart1) == 4){/*action*/}
      break;

      case 2:
      lcdPrint(uart1, 1, "AU%d ", screen);
      lcdPrint(uart1, 2, "enL%d enR %d", encoderGet(encoder_L), encoderGet(encoder_R));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            screen = screen + 1;}
        if(lcdReadButtons(uart1) == 1){/*action*/}
        if(lcdReadButtons(uart1) == 4){/*action*/}
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


/*
void autoselector_code (void*ignore){
  myauto = 1;
  int lcd_delay = 200;
  lcdClear(uart1);

  while(true){
    if (isEnabled()){delay(50);}
    else if (!isEnabled()){
        lcdPrint(uart1, 1, "Auto %d", myauto);
        lcdSetText(uart1, 2, "");
        if(lcdReadButtons(uart1) == 1){
            myauto = myauto + 1;
            delay(lcd_delay);}
        else if(lcdReadButtons(uart1) == 4){
            myauto = myauto - 1;
            delay(lcd_delay);}
        }
        delay(30);
      }
}
void drive_lcd_task (void *ignore){

  int screen = 1;
  int lcd_delay_long = 100;
  int lcd_delay_short = 40;

  int ultra_val;
  //1 = arm pots and target
  //2 = arm kp
  //3 = arm ki
  //4 = arm kd
  //5 = arm ki active
  //6 = arm deaccel
  // 7 = arm kskew

  //5 = claw p
  //6 = claw i
  //7 = claw d
  //8 = battery voltage

  lcdClear(uart1);
  while(true){

  ultra_val = ultrasonicGet(ultrasonic);
    switch (screen) {
      case 1:

      lcdPrint(uart1, 1, "HL=%d TL=%d", drive_armheight_L, armtarget_L);
      lcdPrint(uart1, 2, "HR=%d TR=%d", drive_armheight_R, armtarget_R);
        if(lcdReadButtons(uart1) == 2){
            screen = 2;
            lcdSetText(uart1, 1, "wait");
            delay(lcd_delay_long);}
        else if(lcdReadButtons(uart1) == 1){}
        else if(lcdReadButtons(uart1) == 4){}
        else{}

      break;
      case 2:

      lcdPrint(uart1, 1, "claw_tar=%d", clawtarget);
      lcdPrint(uart1, 2, "claw_pos=%d", claw_pos);
        if(lcdReadButtons(uart1) == 2){
            screen = 3;
            lcdSetText(uart1, 1, "wait");
            delay(lcd_delay_long);}
        else if(lcdReadButtons(uart1) == 1){
          //arm_k_proportion = arm_k_proportion + 0.01;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else if(lcdReadButtons(uart1) == 4){
          //arm_k_proportion = arm_k_proportion - 0.01;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else{}

      break;
      case 3:

      lcdPrint(uart1, 1, "arm_ki=%f", arm_k_integral);
      lcdPrint(uart1, 2, "HL=%d TL=%d", drive_armheight_L, armtarget_L);
        if(lcdReadButtons(uart1) == 2){
            screen = 4;
            lcdSetText(uart1, 1, "wait");
            delay(lcd_delay_long);}
        else if(lcdReadButtons(uart1) == 1){
          arm_k_integral = arm_k_integral + 0.01;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else if(lcdReadButtons(uart1) == 4){
          arm_k_integral = arm_k_integral - 0.01;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else{}

      break;
      case 4:

      lcdPrint(uart1, 1, "arm_kd=%f", arm_k_derivative);
      lcdPrint(uart1, 2, "HL=%d TL=%d", drive_armheight_L, armtarget_L);
        if(lcdReadButtons(uart1) == 2){
            screen = 5;
            lcdSetText(uart1, 1, "wait");
            delay(lcd_delay_long);}
        else if(lcdReadButtons(uart1) == 1){
          arm_k_derivative = arm_k_derivative + 0.01;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else if(lcdReadButtons(uart1) == 4){
          arm_k_derivative = arm_k_derivative - 0.01;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else{}

      break;
      case 5:

      lcdPrint(uart1, 1, "arm_kirange=%d", arm_integral_activezone);
      lcdPrint(uart1, 2, "HL=%d TL=%d", drive_armheight_L, armtarget_L);
        if(lcdReadButtons(uart1) == 2){
            screen = 6;
            lcdSetText(uart1, 1, "wait");
            delay(lcd_delay_long);}
        else if(lcdReadButtons(uart1) == 1){
          arm_integral_activezone = arm_integral_activezone + 1;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else if(lcdReadButtons(uart1) == 4){
        arm_integral_activezone = arm_integral_activezone - 1;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else{}

      break;
      case 6:

      lcdPrint(uart1, 1, "arm_deaccel=%d", arm_deaccel_delay);
      lcdPrint(uart1, 2, "HL=%d TL=%d", drive_armheight_L, armtarget_L);
        if(lcdReadButtons(uart1) == 2){
            screen = 7;
            lcdSetText(uart1, 1, "wait");
            delay(lcd_delay_long);}
        else if(lcdReadButtons(uart1) == 1){
          arm_deaccel_delay = arm_deaccel_delay + 1;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else if(lcdReadButtons(uart1) == 4){
        arm_deaccel_delay = arm_deaccel_delay - 1;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else{}

      break;
      case 7:

      lcdPrint(uart1, 1, "arm_kskew=%f", arm_k_skew);
      lcdPrint(uart1, 2, "HL=%d TL=%d", drive_armheight_L, armtarget_L);
        if(lcdReadButtons(uart1) == 2){
            screen = 8;
            lcdSetText(uart1, 1, "wait");
            delay(lcd_delay_long);}
        else if(lcdReadButtons(uart1) == 1){
          arm_k_skew = arm_k_skew + 0.01;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else if(lcdReadButtons(uart1) == 4){
        arm_k_skew = arm_k_skew - 0.01;
          lcdSetText(uart1, 1, "wait");
          delay(lcd_delay_short);}
        else{}

      break;
      case 8:
      lcdPrint(uart1, 1, "ultra=%d", ultra_val);
    //  lcdPrint(uart1, 2, "HL=%d TL=%d", drive_armheight_L, armtarget_L);
        if(lcdReadButtons(uart1) == 2){
            screen = 1;
            lcdSetText(uart1, 1, "wait");
            delay(lcd_delay_long);}
        else if(lcdReadButtons(uart1) == 1){
          //arm_k_skew = arm_k_skew + 0.01;
        //  lcdSetText(uart1, 1, "wait");
        //  delay(lcd_delay_short);
      }
        else if(lcdReadButtons(uart1) == 4){
      //  arm_k_skew = arm_k_skew - 0.01;
          //lcdSetText(uart1, 1, "wait");
          //delay(lcd_delay_short);
        }
        else{}


      break;
      default:
      break;
      }
      delay(25);
    }
}
*/
