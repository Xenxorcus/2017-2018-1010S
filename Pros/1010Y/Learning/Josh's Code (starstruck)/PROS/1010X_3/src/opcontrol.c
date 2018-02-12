#include "main.h"

void operatorControl() {
lcdClear(uart1);
	TaskHandle armtaskpid = taskCreate (drive_armcontrol, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	TaskHandle clawtaskpid = taskCreate (drive_clawcontrol, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	TaskHandle driver_lcd = taskCreate( drive_lcd_task, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	while (1) {
		armpresets();
		clawpresets();

int FLpower = joystickGetAnalog(1, 3) + joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1);
int FRpower = joystickGetAnalog(1, 3) - joystickGetAnalog(1, 4) - joystickGetAnalog(1, 1);
int BLpower = joystickGetAnalog(1, 3) - joystickGetAnalog(1, 4) + joystickGetAnalog(1, 1);
int BRpower = joystickGetAnalog(1, 3) + joystickGetAnalog(1, 4) - joystickGetAnalog(1, 1);

		motorSet(DriveFL, DriveFL_Dir*FLpower);
		motorSet(DriveFR, DriveFR_Dir*FRpower);
		motorSet(DriveBL, DriveBL_Dir*BLpower);
		motorSet(DriveBR, DriveBR_Dir*BRpower);
//////////////////////////////////////////////////////////
		//Arm+Claw Simple Control

	/*	if(joystickGetDigital(1, 6, JOY_UP)){
			motorSet(ArmLT, ArmLT_Dir*127);
			motorSet(ArmLB, ArmLB_Dir*127);
			motorSet(ArmRT, ArmRT_Dir*127);
			motorSet(ArmRB, ArmRB_Dir*127);
		}
		else if (joystickGetDigital(1, 6, JOY_DOWN)){
			motorSet(ArmLT, ArmLT_Dir*-127);
			motorSet(ArmLB, ArmLB_Dir*-127);
			motorSet(ArmRT, ArmRT_Dir*-127);
			motorSet(ArmRB, ArmRB_Dir*-127);
		}
		else {
			motorSet(ArmLT,0);
			motorSet(ArmLB,0);
			motorSet(ArmRT,0);
			motorSet(ArmRB,0);
		}

		//Claw
		if(joystickGetDigital(1, 5, JOY_UP)){
			motorSet(ClawL, ClawL_Dir*127);
			motorSet(ClawR, ClawR_Dir*127);
		}
		else if (joystickGetDigital(1, 5, JOY_DOWN)){
			motorSet(ClawL, ClawL_Dir*-127);
			motorSet(ClawR, ClawR_Dir*-127);
		}
		else {
			motorSet(ClawL,0);
			motorSet(ClawR,0);
		}
		*/
//////////////////////////////////////////////////////////
		delay(20);
	}
	taskDelete(clawtaskpid);
	taskDelete(armtaskpid);
	taskDelete(driver_lcd);
}
