#include "main.h"
#include "drive.h"
#include "mgten.h"
#include "mgtwenty.h"

void operatorControl() {

	float kp = 0.9;
	int tenError;
	int tenCurrent;
	int tenPower;
	int tenTarget;
	bool tenLiftUp;
	bool tenLiftDown;
	bool twentyLiftUp;
	bool twentyLiftDown;
	bool twUpPart;
	bool twDownPart;

	encoderReset(encoderTen);
	tenTarget = encoderGet(encoderTen);

	while (1) {
		//lcd
		int L = encoderGet(encoderTen);
		int R = encoderGet(encoderR);
		lcdPrint(uart1, 1, "ten%d", L);
		lcdPrint(uart1, 2, "encoderR%d", R);

	//%%%%%%%% JOYSTICK DEFINITIONS %%%%%%%%%//
	tenLiftUp = joystickGetDigital(2,6, JOY_UP);
	tenLiftDown = joystickGetDigital(2,6, JOY_DOWN);
	twentyLiftUp = joystickGetDigital(1,5, JOY_UP);
	twentyLiftDown = joystickGetDigital(1,5, JOY_DOWN); //out
	twUpPart = joystickGetDigital(2,5, JOY_UP);
	twDownPart = joystickGetDigital(2,5, JOY_DOWN);

	//^^^^^^^^ MOBILE GOAL TEN ^^^^^^^^^^^//
	if(tenLiftUp == 1 && tenLiftDown == 0){
		mgtenSet(127);
		tenTarget = encoderGet(encoderTen);
	}
	else if(tenLiftUp == 0 && tenLiftDown == 1){
		mgtenSet(-127);
		tenTarget = encoderGet(encoderTen);
	}
	else if(tenLiftUp == 0 && tenLiftDown == 0){
		tenCurrent = encoderGet(encoderTen);
		tenError = tenTarget - tenCurrent;
		tenPower = tenError*kp;
		mgtenSet(tenPower);
	}
	//$$$$$$$$$ MOBILE GOAL TWENTY $$$$$$$$$//
	if((twentyLiftUp == 1 && twentyLiftDown == 0) || (twUpPart == 1 && twDownPart == 0)){
		mgtwentySet(127);
	//	twentyCurrent = analogRead(1);
	}
	else if((twentyLiftUp == 0 && twentyLiftDown == 1) || (twUpPart == 0 && twDownPart == 1)){
		mgtwentySet(-127);
	//	twentyCurrent = analogRead(1);
	}
	else if((twentyLiftUp == 0 && twentyLiftDown == 0) || (twUpPart == 0 && twDownPart == 0)){
		mgtwentySet(0);
	/*	twentyCurrent = analogRead(1);
		twentyError = twentyTarget - twentyCurrent;
		twentyPower = twentyError*kp;
		mgtwentySet(twentyPower);*/
	}
	//******** DRIVE ********//
	int power, turn;
	power = joystickGetAnalog(1,1);
	turn = joystickGetAnalog(1,3);
	driveSet(power - turn, power + turn);

	}
	delay(20);
}
