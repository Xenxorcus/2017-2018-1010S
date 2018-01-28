
#include "main.h"
#include "claw.h"
#include "lift.h"
#include "ports.h"
#include "drive.h"

void operatorControl() {

	float pidError;
	int liftCurrent;
	int pidArm;
	bool armRaise;
	bool armLower;
	bool armDown;
	bool sevenCone;
	bool preset;
	int SensorTargetValue;
	int current;
	bool liftUp;
	bool liftDown;
	bool liftScore;
	bool limitOverride;
	bool buttonArmDown;
	bool buttonArm4;

	float pid_Kp = 1.5;//was 0.5

 SensorTargetValue = encoderGet(encoder);

encoderReset(encoderLift);
	while (1) {

		armRaise = joystickGetDigital(2,5,JOY_UP);
		armLower = joystickGetDigital(2,5,JOY_DOWN);
		armDown = joystickGetDigital(2,7,JOY_DOWN);
		sevenCone = joystickGetDigital(2,7,JOY_UP);
		preset = joystickGetDigital(2,7,JOY_LEFT);
		liftUp = joystickGetDigital(1,6,JOY_UP);
		liftDown = joystickGetDigital(1,6,JOY_DOWN);
		liftScore = joystickGetDigital(1,7,JOY_DOWN);
		limitOverride = joystickGetDigital(2,8, JOY_DOWN);
		buttonArmDown = joystickGetDigital(2,6,JOY_DOWN);
		buttonArm4 = joystickGetDigital(2,6,JOY_UP);

		///********CLAW*********//
		/*
		if(analogRead(2)<1800 && limitOverride == 0){
		clawSet(joystickGetAnalog(2,2));
		}
		if(limitOverride ==1){
			*/
		clawSet(joystickGetAnalog(2,2));
	//h}

		///***MOBILEGOAL***//
		if(liftUp == 1 && liftDown ==0 && liftScore == 0 && limitOverride == 0){liftSet(-127);}

		else if(liftDown == 1 && liftUp == 0 && liftScore == 0 && limitOverride == 0)
		{
			current = encoderGet(encoder);
			if(current > 400 || current < 100){liftSet(127);}
		}

		else if(liftDown == 0 && liftUp == 0 && liftScore == 1 && limitOverride == 0)
		{
			current = encoderGet(encoder);
			liftCurrent = encoderGet(encoderLift);
			if(liftCurrent > 600){liftSet(0);}

			if(liftCurrent < 600 && (current > 400 || current < 190)){liftSet(127);}
		}

		else{liftSet(0);}

		///*****ENCODERSLCD*****//
		int clawposition = analogRead(2);
		lcdPrint(uart1, 2, "clawPosition%d", clawposition);

		//*****DRIVE*****//
		int power, turn;
		power = joystickGetAnalog(1,1);
		turn = joystickGetAnalog(1,3);
		driveSet(power - turn, power + turn);

		//********CHAINBARPID******//
				//if no buttons are pressed, activate PID
		if(armRaise==0 && armLower == 0)
		{
				current = encoderGet(encoder);
						if(current<701)
						{
							//find encoder value now
						pidError =  SensorTargetValue - current;
						  // calculate arm
					  pidArm = (pid_Kp * pidError);

								  // limit arm
							 if( pidArm > 127)
						 		 	 pidArm = 127;
							 if( pidArm < (-127))
							 		 pidArm = (-127);
			 		 }
				 motorSet(ArmT, pidArm);
				 motorSet(ArmLB, pidArm);
				 motorSet(ArmRB, pidArm);
		}

//arm goinng up
				else if(armRaise!=0 && armLower==0 && limitOverride == 0)
				{
					liftCurrent = encoderGet(encoderLift);
					if(liftCurrent < 500){
					motorSet(ArmT, -127);
					motorSet(ArmLB, -127);
					motorSet(ArmRB, -127);
					//set the target value for PiD
					SensorTargetValue = encoderGet(encoder);
				}
				}
//arm going down
				else if(armRaise==0 && armLower!=0 && limitOverride ==0)
				{
					liftCurrent = encoderGet(encoderLift);
					if(liftCurrent < 500){
				 motorSet(ArmT, 127);
 				 motorSet(ArmLB, 127);
 				 motorSet(ArmRB, 127);
					SensorTargetValue = encoderGet(encoder);
				}
			}
//other condition
				else
				{
					motorSet(ArmT, 0);
					motorSet(ArmLB, 0);
					motorSet(ArmRB, 0);
				}

 if(armDown == 1)
 {SensorTargetValue = 470;}

 if(buttonArmDown == 1)
 {SensorTargetValue = 470;}

 if((buttonArm4) == 1)
 {SensorTargetValue = 90;}

 if(sevenCone == 1)
 {
	 liftCurrent = encoderGet(encoderLift);
	 if(liftCurrent < 500){SensorTargetValue = 245;}
}

 if(preset == 1)
 {
	 liftCurrent = encoderGet(encoderLift);
	 if(liftCurrent < 500){SensorTargetValue = 355;}
 }

	delay(20);
}
}
