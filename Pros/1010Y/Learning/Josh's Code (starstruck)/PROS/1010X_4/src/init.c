#include "main.h"
#include "LCDfunctions.h"


void initializeIO() {
}

void initialize() {

  lcdInit(uart1);
  lcdClear(uart1);
  lcdSetBacklight(uart1, 1);
  lcdSetText(uart1, 1, "LCD Init");
  delay(40);
  lcdSetText(uart1, 1, "Sensor Init");
  delay(60);

  encoderFR = encoderInit(encoderFR_TOP, encoderFR_BOT, 1);
  lcdSetText(uart1, 1, "Encoder FR");
  delay(60);

  encoderFL = encoderInit(encoderFL_TOP, encoderFL_BOT, 0);
  lcdSetText(uart1, 1, "Encoder FL");
  delay(60);

  gyro =  gyroInit (gyroport, 196);
  lcdSetText(uart1, 1, "gyro");
  delay(60);

  imeInitializeAll();
  lcdSetText(uart1, 1, "ime");
  delay(60);

  ultrasonic = ultrasonicInit(4, 3);
  lcdSetText(uart1, 1, "ultra ");
  delay(60);

  lcdClear(uart1);
  lcdSetText(uart1, 1, "Ready");
  delay(60);

  TaskHandle disable_lcd = taskCreate(disablelcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

}
