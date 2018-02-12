#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"
void operatorControl() {

	int twentyError;
	int twentyCurrent;
	int twentyPower;
	int twentyTarget;
	bool mgLiftUp;
	bool mgLiftDown;
	bool fourUp;
	bool fourDown;
	int power, turn;
	bool rollUp;
	bool rollDown;
	float tkp = 0.3;
	bool fourPU;
	bool fourPD;
//	bool scoreOne;
	bool scoremg;
	bool safemg;
	//bool reset;
	//bool cancel;
	int joystickLift;

	encoderReset(encoderTen);
	twentyTarget = analogRead(1);
	stackglobal = 0;


taskCreate(stackTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);

	while (1) {



		lcdPrint(uart1, 1, "joy%d", joystickLift);

	//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
	mgLiftUp = joystickGetDigital(1,6, JOY_UP);
	mgLiftDown = joystickGetDigital(1,6, JOY_DOWN);
	fourUp = joystickGetDigital(2,7, JOY_UP);
	fourDown = joystickGetDigital(2,7, JOY_DOWN);
	fourPU = joystickGetDigital(2,5, JOY_UP);
	fourPD = joystickGetDigital(2,5, JOY_DOWN);
	power = joystickGetAnalog(1,1);
	turn = joystickGetAnalog(1,3);
	rollUp = joystickGetDigital(2,6,JOY_UP);
	rollDown = joystickGetDigital(2,6,JOY_DOWN);
	//reset = joystickGetDigital(2,8,JOY_UP);
	scoremg = joystickGetDigital(1,8,JOY_DOWN);
	safemg = joystickGetDigital(1,8,JOY_UP);
	//cancel = joystickGetDigital(2,7,JOY_RIGHT);

	////////////dr4b
joystickLift = joystickGetAnalog(2,3);
if(joystickLift>10&&stackglobal ==0){liftSet(-joystickLift);}
else if(joystickLift<(-10)&&stackglobal ==0){liftSet(-joystickLift);}
//else if(encoderGet(encoderTen)>(-40)){liftSet(10);}
else if(joystickLift>-10 &&joystickLift<10&&stackglobal ==0){liftSet(-10);}


	//^^^^^^^^ MOBILE GOAL TEN ^^^^^^^^^^^//
	if(mgLiftUp == 1){
		mgSet(127);
	}
	else if(mgLiftDown == 1){
		mgSet(-127);
	}
	else{
		mgSet(0);
	}

	if(safemg == 1){
		if(analogRead(3)<1000){mgSet(127);}
	}

if(scoremg == 1){
	if(analogRead(3)>1100){mgSet(-90);}
	}


	//$$$$$$$$$ fourbar $$$$$$$$$//
	if(fourUp == 1 &&stackglobal ==0){
		fourSet(-127);
		twentyTarget = analogRead(1);
	}
	else if(fourDown == 1&&stackglobal ==0){
		fourSet(127);
		twentyTarget = analogRead(1);
	}
	else if(fourDown ==0 && fourUp==0&&stackglobal ==0){
		twentyCurrent = analogRead(1);
		twentyError = twentyTarget - twentyCurrent;
		twentyPower = twentyError*tkp;
		fourSet(twentyPower);
	}


	/////presets fourbar

	if(fourPU ==1 && fourPD ==0&&stackglobal ==0){
		twentyTarget = 1300;
	}
	if(fourPU ==0 && fourPD ==1&&stackglobal ==0){
		twentyTarget = 3200;
	}





	//******** DRIVE ********//
	driveSet(power - turn, power + turn);



////////rollers
if(rollUp == 1&&stackglobal ==0){
	rollerSet(-127);
}
else if(rollDown == 1&&stackglobal ==0){
	rollerSet(127);
}
delay(20);
	}
}
