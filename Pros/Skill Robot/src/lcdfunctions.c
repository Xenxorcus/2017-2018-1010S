#include "main.h"
#include "lcdfunctions.h"

void disabled(void*ignore){

  int mode = 1;
  int mode_cap = 3;
  int btn_time = 100;
  myauto = 4;
  lcdClear(uart1);

  while(true){
    delay(25);

    if(!isEnabled()){
    switch(mode){

    case 1:
    lcdPrint(uart1, 1, "%d AUTO %d", mode, myauto);
      if (lcdReadButtons(uart1) == 2) {
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(btn_time);
        mode = mode + 1;}
       if (lcdReadButtons(uart1) == 1){
         lcdClear(uart1);
         lcdSetText(uart1, 1, "wait");
         delay(btn_time);
         myauto = myauto -1;}
        if(lcdReadButtons(uart1) == 4){
          lcdClear(uart1);
          lcdSetText(uart1, 1, "wait");
          delay(btn_time);
          myauto = myauto+1;}
          break;

      case 2:
      lcdPrint(uart1, 1, "Encoder R = %d", encoderGet(encoderR));
      lcdPrint(uart1, 1, "Encoder L = %d", encoderGet(encoderL));
      if(lcdReadButtons(uart1) == 2){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(btn_time);
        mode = mode +1;}
        if((lcdReadButtons(uart1) == 1)){}
        if((lcdReadButtons(uart1) == 4)){}
        break;

      case 3:
      lcdPrint(uart1, 1, "Gyro = %d", analogRead(Gyro));
      lcdPrint(uart1, 1, "Line_Tracker = %d", analogRead(rLine_Tracker));
      if(lcdReadButtons(uart1) == 2){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(btn_time);
        mode = mode +1;}
        if(lcdReadButtons(uart1) == 1){}
        if(lcdReadButtons(uart1) == 4){}
       break;
       default:
         lcdClear(uart1);
         lcdSetText(uart1, 1, "DEFAULT");
         delay(50);
         mode = 1;
       break;
      }//end swith(mode)
    //screen cap reset
    if(mode > mode_cap){mode = 1;}

    //auto line display

    if (mode == 1) {
      switch(myauto){
        case -1:
          lcdSetText(uart1, 2, "NoAuto");
        break;
        case 0:
          lcdSetText(uart1, 2, "Skills");
        break;
        case 1:
          lcdSetText(uart1, 2, "Mogo Left 10");
        break;
        case 2:
          lcdSetText(uart1, 2, "Mogo Right 10");
        break;
        case 3:
          lcdSetText(uart1, 2, "Mogo Left 20");
        break;
        case 4:
          lcdSetText(uart1, 2, "Mogo Right 20");
        break;
      }// end switch(auto)
    }//end if
    delay(20);
    }// end if
    else{delay(50);}
  }//end while true
}//end void


//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void autolcd(void *ignore){
  int mode = 1;
  int mode_cap = 2;
  int btn_time = 100;
  lcdClear(uart1);

  while(isAutonomous()){
    delay(25);
    switch(mode){

      case 1:
      lcdPrint(uart1, 1, "Gyro = %d", gyroGet(gyro));
      lcdPrint(uart1, 2, "Encoder R = %d", encoderGet(encoderR));
        if(lcdReadButtons(uart1) == 2){
          lcdClear(uart1);
          lcdSetText(uart1, 1, "wait");
          delay(btn_time);
          mode = mode + 1;
        }
        if(lcdReadButtons(uart1) == 1){
          encoderReset(encoderR);
          gyroReset(gyro);
          delay(50);
        }
        if(lcdReadButtons(uart1) == 4){
          analogCalibrate(rLine_Tracker);
          analogCalibrate(MOGOPOT);
          delay(50);
        }
      break;

      case 2:
      lcdPrint(uart1, 1, "LLine = %d", analogRead(lLine_Tracker));
      lcdPrint(uart1, 2, "MLine = %d", analogRead(mLine_Tracker));
        if(lcdReadButtons(uart1) == 2){
            lcdClear(uart1);
            lcdSetText(uart1, 1, "wait");
            delay(btn_time);
            mode = mode + 1;}
        if(lcdReadButtons(uart1) == 1){
          encoderReset(encoderR);
          encoderReset(encoderL);
          gyroReset(gyro);
          delay(50);
        }
        if(lcdReadButtons(uart1) == 4){
          analogCalibrate(lLine_Tracker);
          analogCalibrate(mLine_Tracker);
          delay(50);
        }
      break;

      }
    if(mode > mode_cap){mode = 1;}
  }

  taskDelete(autolcd_task);
}
