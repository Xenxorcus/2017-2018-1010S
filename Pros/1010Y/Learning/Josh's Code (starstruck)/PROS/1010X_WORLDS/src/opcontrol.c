
#include "main.h"
#include "arm.h"
#include "claw.h"
#include "util.h"
#include "lcdfunctions.h"
#include "motor.h"

void operatorControl() {

	lcdClear(uart1);
	TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	TaskHandle claw_task = taskCreate (clawtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	TaskHandle arm_task = taskCreate (armtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	TaskHandle motor_task = taskCreate(motortask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	slewset(true, false, false, false); // onyl first true value matters

	while (true) {

		delay(20);

		//lcdtune();

		motorset_drive_op(motorcap((joystickGetAnalog(1, 3)+joystickGetAnalog(1, 4))), motorcap(joystickGetAnalog(1,3)-joystickGetAnalog(1,4)));

		armpresets();
		clawpresets();
		/*
		if(joystickGetDigital(1, 7, JOY_DOWN)){motorSet(10, -127);}
		else if(joystickGetDigital(1, 7, JOY_UP)){motorSet(10, 127);}
		else{motorSet(10, 0);}
		*/



		//motorSet(10, joystickGetAnalog(1, 2));
		//motorSet(10, -joystickGetAnalog(1, 4));
/*
if(joystickGetDigital(1, 7, JOY_DOWN)){motorSet(winch, -127*winch_Dir);}
else if(joystickGetDigital(1, 7, JOY_LEFT)){motorSet(winch, 127*winch_Dir);}
else if(joystickGetDigital(2, 7, JOY_LEFT)){motorSet(winch, 127*winch_Dir);}
else if(joystickGetDigital(2, 7, JOY_DOWN)){motorSet(winch, -127*winch_Dir);}
else {motorSet(winch, 0);}
*/
		}
}
