#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "claw.h"
#include "autofunctions.h"
void operatorControl() {


	bool liftUp;
	bool liftDown;
	int joystickLift;

	int fourbarError;
	int fourbarCurrent;
	int fourbarPower;
	int fourbarTarget;
	bool fourUp;
	bool fourDown;
	bool fourPU;
	bool fourPD;
	float tkp = 0.3;

	bool mgLiftUp;
	bool mgLiftDown;
	bool scoremg;
	bool safemg;

	int power, turn;

	bool clawOpen;
	bool clawClose;

	fourbarTarget = analogRead(fourPot);

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
	clawClose = joystickGetDigital(2,6,JOY_UP);
	clawOpen = joystickGetDigital(2,6,JOY_DOWN);
	scoremg = joystickGetDigital(1,8,JOY_DOWN);
	safemg = joystickGetDigital(1,8,JOY_UP);


	////LCD////
	


	//^^^^^^^^ MOBILE GOAL lift ^^^^^^^^^^^//
	if(mgLiftUp == 1){mgSet(90);}
	else if(mgLiftDown == 1){mgSet(-90);}
	else{mgSet(0);}

	if(safemg == 1){
		if(analogRead(mgPot)<1000){mgSet(90);}
		else{mgSet(0);}
	}

	if(scoremg == 1){
		if(analogRead(mgPot)>1000){mgSet(-90);}
		else{mgSet(0);}
	}

	//******** DRIVE ********//
	driveSet(power - turn, power + turn);

////AUTOSTACKING AND LIFT FOURBAW CLAW FUNCTIONS/////

if(stackglobal != 1){///run these functions if autostacking is off

	//$$$$$$$$$ fourbar $$$$$$$$$//
	if(fourUp == 1 ){
		fourSet(-90);
		fourbarTarget = analogRead(fourPot);
	}
	else if(fourDown == 1 ){
		fourSet(90);
		fourbarTarget = analogRead(fourPot);
	}
	else if((fourUp == 0 && fourDown == 0 )){
		fourbarCurrent = analogRead(fourPot);
		fourbarError = fourbarTarget - fourbarCurrent;
		fourbarPower = fourbarError*tkp;
		fourSet(fourbarPower);
	}


	/////presets fourbar
	if(fourPU ==1){fourbarTarget = 1300;}
	if(fourPD ==1){fourbarTarget = 3200;}

	/////lift/////
	joystickLift = joystickGetAnalog(2,3);


	if(joystickLift>10){liftSet(-joystickLift);}
	else if(joystickLift<(-10)){liftSet(-joystickLift);}

	else if(joystickLift>-10 &&joystickLift<10 && liftUp == 0 && liftDown == 0){liftSet(-10);}///// add in  && analogRead(liftPot)>liftvalue

	else if(liftUp == 1){
		liftSet(-90);
	}
	else if(liftDown == 1){
		liftSet(90);
	}

/////claw/////

if(clawOpen == 1){
	clawSet(90);
}
	else if(clawClose == 1){
		clawSet(-90);
	}
		else{clawSet(0);}

	delay(20);
}

else{//if task is running
	if(joystickGetDigital(2,8,JOY_RIGHT)){
		taskDelete(autoStackHandle);
		liftSet(-10);
		fourSet(0);
		clawSet(-10);
		stackglobal = 0;
		fourbarTarget = analogRead(fourPot);
		autoStackHandle = taskCreate(autoStack, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	}
}
}
}
