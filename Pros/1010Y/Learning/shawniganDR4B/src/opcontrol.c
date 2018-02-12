#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"
void operatorControl() {

	//mg all the way in 1820
	//mg all the way out 235
	//mg score 1400
	//mg pick up safe 800
//fourbar down 3200, up 1200
//double reverse all the way up -470, all the way down is 0
//double reverse up is negative, down is positive

	int tenTarget;
	int twentyError;
	int twentyCurrent;
	int twentyPower;
	int twentyTarget;
	bool mgLiftUp;
	bool mgLiftDown;
	bool liftUp;
	bool liftDown;
	bool fourUp;
	bool fourDown;
	int power, turn;
	bool rollUp;
	bool rollDown;

	float tkp = 0.3;
	bool fourPU;
	bool fourPD;
	bool scoremg;
	bool safemg;
	int joystickLift;

	encoderReset(encoderTen);
	tenTarget = encoderGet(encoderTen);
	twentyTarget = analogRead(1);
//int armtar = 0;
TaskHandle autoStackHandle = taskCreate(autoStack, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	while (1==1) {


	//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
	mgLiftUp = joystickGetDigital(1,6, JOY_UP);
	mgLiftDown = joystickGetDigital(1,6, JOY_DOWN);
	liftUp = joystickGetDigital(1,5, JOY_UP);
	liftDown = joystickGetDigital(1,5, JOY_DOWN); //out
	fourUp = joystickGetDigital(2,7, JOY_UP);
	fourDown = joystickGetDigital(2,7, JOY_DOWN);
	fourPU = joystickGetDigital(2,5, JOY_UP);
	fourPD = joystickGetDigital(2,5, JOY_DOWN);
	power = joystickGetAnalog(1,1);
	turn = joystickGetAnalog(1,3);
	rollUp = joystickGetDigital(2,6,JOY_UP);
	rollDown = joystickGetDigital(2,6,JOY_DOWN);
	scoremg = joystickGetDigital(1,8,JOY_DOWN);
	safemg = joystickGetDigital(1,8,JOY_UP);



	//^^^^^^^^ MOBILE GOAL TEN ^^^^^^^^^^^//
	if(mgLiftUp == 1 && mgLiftDown == 0){mgSet(127);}
	else if(mgLiftUp == 0 && mgLiftDown == 1){mgSet(-127);}
	else if(mgLiftUp == 0 && mgLiftDown == 0){mgSet(0);}

		//******** DRIVE ********//
		driveSet(power - turn, power + turn);


if(safemg == 1){
	if(analogRead(3)<1000){mgSet(127);}
	else{mgSet(0);}
}

if(scoremg == 1){
	if(analogRead(3)>1000){mgSet(-90);}
	else{mgSet(0);}
}



if(stackglobal != 1){

	//$$$$$$$$$ fourbar $$$$$$$$$//
	if(fourUp == 1 ){
		fourSet(-127);
		twentyTarget = analogRead(1);
	}
	else if(fourDown == 1 ){
		fourSet(127);
		twentyTarget = analogRead(1);
	}
	else if((fourUp == 0 && fourDown == 0 )){
		twentyCurrent = analogRead(1);
		twentyError = twentyTarget - twentyCurrent;
		twentyPower = twentyError*tkp;
		fourSet(twentyPower);
	}




	/////presets fourbar
	if(fourPU ==1){twentyTarget = 1300;}
	if(fourPD ==1){twentyTarget = 3200;}





	joystickLift = joystickGetAnalog(2,3);
	if(joystickLift>10){liftSet(-joystickLift);}
	else if(joystickLift<(-10)){liftSet(-joystickLift);}
	//else if(encoderGet(encoderTen)>(-40)){liftSet(10);}
	else if(joystickLift>-10 &&joystickLift<10 && liftUp == 0 && liftDown == 0){liftSet(-10);}

	else if(liftUp == 1){
		liftSet(-127);
	}
	else if(liftDown == 1){
		liftSet(127);
	}


////present double reverse down
if(joystickGetDigital(2,7,JOY_DOWN)){
	tenTarget = 0;
}


////////rollers
/*if(rollUp == 1){rollerSet(-127);}
else if(rollDown == 1){rollerSet(127);}
else if(rollUp == 0 && rollDown == 0){rollerSet(-14);}*/
rollerSet(joystickGetAnalog(2,2));

	delay(20);
}
else{
	if(joystickGetDigital(2,8,JOY_RIGHT)){
		taskDelete(autoStackHandle);
		liftSet(-10);
		fourSet(0);
		rollerSet(-15);
		stackglobal = 0;
		twentyTarget = analogRead(1);
		autoStackHandle = taskCreate(autoStack, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	}
}
}
}
