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
#include "ports.h"
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

#define UP 127
#define DOWN -127


void driveSet(int left, int right){
	motorSet(DriveFL, left);
	motorSet(DriveMBL, left);
	motorSet(DriveBL, left);
	motorSet(DriveBR, right);
	motorSet(DriveFR, right);
	motorSet(DriveMBR, right);
}


void operatorControl() {
	int power;
	int turn;
	while (1) {
		power = joystickGetAnalog(1, 1); //Vertical on Left Joystick
		turn  = joystickGetAnalog(1, 3); // Horizontal Right Joystick
		driveSet(power - turn, power + turn);


		if(joystickGetDigital(1,6,JOY_UP)){
			// liftSet(DOWN);
			motorSet(liftTop, DOWN);
		}
		else if(joystickGetDigital(1,6,JOY_DOWN)){
			liftSet(UP);
		}
		else{
			liftSet(0);
		}

		clawSet(joystickGetAnalog(2,2));
		/*
		if(joystickGetDigital(1,5,JOY_UP)){
			clawSet(UP);
		}
		else if(joystickGetDigital(1,5,JOY_DOWN)){
			clawSet(DOWN);
		}
		else{
			clawSet(0);
		}
		*/
		if(joystickGetDigital(1,5,JOY_UP)){
			armSet(DOWN);
		}
		else if(joystickGetDigital(1,5,JOY_DOWN)){
			armSet(UP);
		}
		else{
			armSet(0);
		}
		delay(20);



// Left Drive
	driveLeft(power);
	// Right Drive
		motorSet(4, power - turn);
		motorSet(5, power - turn);
		motorSet(6, power - turn);
		delay(20);
	}
}



void driveLeft(int power){
	motorSet(1, power);
	motorSet(2, power);
	motorSet(3, power);
}
