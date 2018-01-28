
#include "main.h"
#include "arm.h"
#include "claw.h"
#include "util.h"
#include "lcdfunctions.h"

void operatorControl() {

	lcdClear(uart1);
	TaskHandle opcontrollcd_task = taskCreate(opcontrollcd, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	TaskHandle claw_task = taskCreate (clawtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	TaskHandle arm_task = taskCreate (armtask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	while (true) {

		delay(20);

		//motorset_drive(motorcap((joystickGetAnalog(1, 3)+joystickGetAnalog(1, 4))), motorcap(joystickGetAnalog(1,3)-joystickGetAnalog(1,4)));//arcade
		motorset_drive(joystickGetAnalog(1, 3), joystickGetAnalog(1, 2));

		armpresets();
		clawpresets();

		if(joystickGetDigital(1, 7, JOY_DOWN)){digitalWrite(LED_1, LOW);}
		else{digitalWrite(LED_1, HIGH);}


/*
if(joystickGetDigital(1, 7, JOY_DOWN)){motorSet(winch, -127*winch_Dir);}
else if(joystickGetDigital(1, 7, JOY_LEFT)){motorSet(winch, 127*winch_Dir);}
else if(joystickGetDigital(2, 7, JOY_LEFT)){motorSet(winch, 127*winch_Dir);}
else if(joystickGetDigital(2, 7, JOY_DOWN)){motorSet(winch, -127*winch_Dir);}
else {motorSet(winch, 0);}
*/
		}
}
