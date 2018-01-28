#include "main.h"
#include "LCDfunctions.h"

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
