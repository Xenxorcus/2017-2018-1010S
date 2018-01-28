#include "main.h"


void initializeIO() {
}

void initialize() {

  lcdInit(uart1);
  lcdClear(uart1);
  lcdSetBacklight(uart1, 1);
  lcdSetText(uart1, 1, "LCD Init");
  delay(40);
  lcdClear(uart1);
  lcdSetText(uart1, 1, "Senseor Init");
  delay(60);

  encoderFR = encoderInit(encoderFR_TOP, encoderFR_BOT, 1);
  lcdSetText(uart1, 1, "encoder fr");
  delay(60);

  encoderFL = encoderInit(encoderFL_TOP, encoderFL_BOT, 0);
  lcdSetText(uart1, 1, "encoder fl");
  delay(60);

  //encoderBL = encoderInit(encoderBL_TOP, encoderBL_BOT, 1);
  //encoderBR = encoderInit(encoderBR_TOP, encoderBR_BOT, 1);

  gyro =  gyroInit (gyroport, 196);
  lcdSetText(uart1, 1, "gyro");
  delay(60);

  analogCalibrate(accel_x);
  lcdSetText(uart1, 1, "accelx");
  delay(60);

  analogCalibrate(accel_y);
  lcdSetText(uart1, 1, "accely Init");
  delay(60);
  //analogCalibrate(gyroport);

  imeInitializeAll();
  lcdSetText(uart1, 1, "ime ");
  delay(60);


  ultrasonic = ultrasonicInit(4, 3);
  lcdSetText(uart1, 1, "ultra ");
  delay(60);

  lcdClear(uart1);
  lcdSetText(uart1, 1, "Ready");
  delay(60);

TaskHandle autoselect = taskCreate(autoselector_code, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

}
