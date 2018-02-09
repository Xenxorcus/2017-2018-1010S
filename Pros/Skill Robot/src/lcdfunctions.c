#include "mian.h"
#include "lcdfuntions.h"

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
    lcdPrint(urat1, 1, "%d AUTO %d", mode, myauto);
      if (lcdReadButtons(uart1) == 2) {
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait")
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
        if((lcdReadButtons(uart1) == 1){}
        if((lcdReadButtons(uart1) == 4){}
        break;

      }//end swith(mode)
    }// end if
  }//end while true
}//end void
