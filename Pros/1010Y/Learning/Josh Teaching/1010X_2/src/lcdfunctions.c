#include "main.h"
#include "API.h"


void autoselect(void){
  int timeoutlcd = 350;
lcdSetBacklight(uart1, true);
while(!isEnabled()){
  switch (myauto){
    case (1):
      lcdClear(uart1);
      lcdSetText(uart1, 1, "Auto 1");
      lcdSetText(uart1, 2, "L-Mid S");
      delay(30);
      if(lcdReadButtons(uart1) == 1){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 8;}
      else if(lcdReadButtons(uart1) == 4){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 2;}
      else {}
    break;
    case (2):
      lcdClear(uart1);
      lcdSetText(uart1, 1, "Auto 2");
      lcdSetText(uart1, 2, "L-Mid C");
      delay(30);
      if(lcdReadButtons(uart1) == 1){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 1;}
      else if(lcdReadButtons(uart1) == 4){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 3;}
      else {}
    break;
    case (3):
      lcdClear(uart1);
      lcdSetText(uart1, 1, "Auto 3");
      lcdSetText(uart1, 2, "R-Mid C");
      delay(30);
      if(lcdReadButtons(uart1) == 1){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 2;}
      else if(lcdReadButtons(uart1) == 4){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 4;}
      else {}
    break;
    case (4):
      lcdClear(uart1);
      lcdSetText(uart1, 1, "Auto 4");
      lcdSetText(uart1, 2, "R-Mid S");
      delay(30);
      if(lcdReadButtons(uart1) == 1){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 3;}
      else if(lcdReadButtons(uart1) == 4){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 5;}
      else {}
    break;

    case (5):
      lcdClear(uart1);
      lcdSetText(uart1, 1, "Auto 5");
      lcdSetText(uart1, 2, "Programming");
      delay(30);
      if(lcdReadButtons(uart1) == 1){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 4;}
      else if(lcdReadButtons(uart1) == 4){
        lcdClear(uart1);
        lcdSetText(uart1, 1, "wait");
        delay(timeoutlcd);
        myauto = 6;}
      else {}
    break;

//case 6
case (6):
  lcdClear(uart1);
  lcdSetText(uart1, 1, "Auto 6");
  lcdSetText(uart1, 2, "L-Mid Close");
  delay(30);
  if(lcdReadButtons(uart1) == 1){
    lcdClear(uart1);
    lcdSetText(uart1, 1, "wait");
    delay(timeoutlcd);
    myauto = 5;}
  else if(lcdReadButtons(uart1) == 4){
    lcdClear(uart1);
    lcdSetText(uart1, 1, "wait");
    delay(timeoutlcd);
    myauto = 7;}
  else {}
break;
//case 7
case (7):
  lcdClear(uart1);
  lcdSetText(uart1, 1, "Auto 7");
  lcdSetText(uart1, 2, "R-Mid Close");
  delay(30);
  if(lcdReadButtons(uart1) == 1){
    lcdClear(uart1);
    lcdSetText(uart1, 1, "wait");
    delay(timeoutlcd);
    myauto = 6;}
  else if(lcdReadButtons(uart1) == 4){
    lcdClear(uart1);
    lcdSetText(uart1, 1, "wait");
    delay(timeoutlcd);
    myauto = 8;}
  else {}
break;
//case 8
case (8):
  lcdClear(uart1);
  lcdSetText(uart1, 1, "Auto 8");
  lcdSetText(uart1, 2, "BLANK");
  delay(30);
  if(lcdReadButtons(uart1) == 1){
    lcdClear(uart1);
    lcdSetText(uart1, 1, "wait");
    delay(timeoutlcd);
    myauto = 7;}
  else if(lcdReadButtons(uart1) == 4){
    lcdClear(uart1);
    lcdSetText(uart1, 1, "wait");
    delay(timeoutlcd);
    myauto = 1;}
  else {}
break;

    default:
     lcdClear(uart1);
     lcdSetText(uart1, 1, "DEFAULT1");
     delay(500);
     myauto = 1;
    break;
    }
  }
}
