#include "ledfunctions.h"
#include "main.h"

//code never completed
//some success, never debugged completely

void ledinit(){
    // initialing function (called in init.c)
    //setting pinmode to output
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  }

void joystick_connected(int LED_port){
  //designed to tell if joystick was connected
  if(isJoystickConnected(1))
  {digitalWrite(LED_port, LOW);}
  else if(!isJoystickConnected(1)){
    digitalWrite(LED_port, HIGH);}
}
