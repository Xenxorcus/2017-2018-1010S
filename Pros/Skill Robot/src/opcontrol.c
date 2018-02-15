/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

 #include "main.h"
 #include "autofunctions.h"
 #include "lcdfunctions.h"
 #include "drive.h"
 #include "mogo.h"


/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

void operatorControl() {

	gyroReset(gyro);
	analogCalibrate(rLine_Tracker);
	analogCalibrate(lLine_Tracker);
	analogCalibrate(mLine_Tracker);
	analogCalibrate(MOGOPOT);

	while (1) {

   //LCD Task
   TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	int mgCurrent = analogRead(MOGOPOT);
	lcdPrint(uart1, 1, "mg%d", mgCurrent);

		//***********************
		//       Tank Drive
		//***********************

		int Y1 = 0; //Y-Axis on Tank
		int Y2 = 0;
		int deadZone = 10; //Deadzone Value // Was 20

		int leftStickVertical = joystickGetAnalog(1, 3); //Joystick command for vertical movement
		int rightStickVertical = joystickGetAnalog(1, 2); //Joystick command for horizontal movement

		if (abs (leftStickVertical) > deadZone) {
			Y1 = leftStickVertical; }
		else {
			Y1 = 0;
		}
		if (abs (rightStickVertical) > deadZone) {
			Y2 = rightStickVertical; }
		else {
			Y2 = 0;
		}

		//Left Drive
		motorSet(Drive_LB, Y1);//Left Front
		motorSet(Drive_LB, Y1);//Left Back
		motorSet(Drive_LT, Y1);//left Top

		//Right Drive
		motorSet(Drive_RB, Y2);//Right Front
		motorSet(Drive_RF, Y2);//Right Back
		motorSet(Drive_RT, Y2);

		// Mogo Intake
		bool mogoUp = joystickGetDigital(1,5,JOY_UP);
		bool mogoDown = joystickGetDigital(1,5,JOY_DOWN);
		bool mogoScore = joystickGetDigital(1,6,JOY_DOWN);
		bool mogoSafe = joystickGetDigital(1,6,JOY_UP);
		int stop;
		//Mobile Goal In
		if (mogoUp == 1 && mogoDown == 0 && mogoScore == 0 && mogoSafe == 0){
			MoveMogo(-90);
			stop = 1;
		}
		//Mobile Goal Out
		else if (mogoUp == 0 && mogoDown == 1 && mogoScore == 0 && mogoSafe == 0){
			MoveMogo(90);
			stop = 0;
		}
		else if(mogoUp == 0 && mogoDown == 0 && stop==1 && mogoScore == 0 && mogoSafe == 0){
			MoveMogo(-25);
		}
		//Preset for scoring with cones (Out)
		else if(mogoUp == 0 && mogoDown == 0 && mogoScore == 0 && mogoSafe == 0){
			//TaskHandle mogoScore = taskCreate(mogoScore, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
			stop=0;
		}
		else {
			MoveMogo(0);
		}
		if(mogoScore == 1){
			if(analogRead(MOGOPOT)<1100){
				MoveMogo(90);}
			}//end if
		if (mogoSafe == 1) {
			if(analogRead(MOGOPOT)>1100){
				MoveMogo(-90);}
			}//end if
		}//end while (1)
	}//end void operatorControl()
