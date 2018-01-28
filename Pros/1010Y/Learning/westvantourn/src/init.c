#include "main.h"

void initializeIO() {
}

void initialize() {

  lcdInit(uart1);
  lcdClear(uart1);
  lcdSetBacklight(uart1, 1);

encoderTen = encoderInit(1, 2, 0);
encoderL = encoderInit(5,6,0);
encoderR = encoderInit(7,8,0);

myauto = 1;

gyro = gyroInit(2,196);
  lcdClear(uart1);
  lcdSetText(uart1, 1, "Ready");
delay(20);
  lcdClear(uart1);
  delay(20);

while(1){
lcdPrint(uart1, 1, "Auto%d", myauto);
delay(150);
if(lcdReadButtons(uart1) == 1){ // changes auto
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(100); // btntime
        myauto = myauto-1;}
if(lcdReadButtons(uart1) == 4){ // changes auto
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(100);
        myauto = myauto+1;}
  if(isEnabled()){break;}

  switch(myauto){ // changes depening on myauto value
         case 1:
           lcdSetText(uart1, 2, "right twenty"); //ised tp ne right 10
         break;
         case 2:
           lcdSetText(uart1, 2, "left twenty");
         break;
         case 3:
           lcdSetText(uart1, 2, "right ten");
         break;
         case 4:
           lcdSetText(uart1, 2, "left ten");
         break;
         case 5:
           lcdSetText(uart1, 2, "autonomous 3 cones right");
         break;
         case 6:
           lcdSetText(uart1, 2, "no");
         break;
         case 7:
           lcdSetText(uart1, 2, "nope");
         break;
         case 8:
           lcdSetText(uart1, 2, "red nope");
         break;
         case 9:
           lcdSetText(uart1, 2, "nope right");
         break;
         case 10:
           lcdSetText(uart1, 2, "no blue right");
         break;
         case 11:
           lcdSetText(uart1, 2, "no left");
         break;
      }
      delay(20);
    }
      lcdClear(uart1);
}
