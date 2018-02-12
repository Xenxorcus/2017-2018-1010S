#pragma config(Motor,  port1,           rightback1,    tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           leftback1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           rightback2,    tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           leftback2,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           leftlift,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightlift,     tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VEX EDR                      */
/*                                                                           */
/*---------------------------------------------------------------------------*/

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
	// Set bStopTasksBetweenModes to false if you want to keep user created tasks
	// running between Autonomous and Driver controlled modes. You will need to
	// manage all user created tasks if set to false.
	bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.h
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}
void setRightback(int power)
{
	motor(rightback1) = motor(rightback2) = power;
}
void setLeftback(int power)
{
	motor(leftback1) = motor(leftback2) = power;
}
void setBack(int power, int time)
{
	motor(rightback1) = motor(rightback2) = power;
	motor(leftback1) = motor(leftback2) = power;
	wait1Msec(time);
}
void setLift(int power, int time)
{
	motor(rightlift) = motor(leftlift) = power;
	wait1Msec(time);
}//combine two motors in one code.
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	setBack(127, 2000);//autononous move forward for 2 second for a test
	setBack(0, 1000);//stop for 1 second
	setLift(40, 1500);//lift the mobile goal.

	// ..........................................................................
	// Insert user code here.
	// ..........................................................................

	// Remove this function call once you have "real" code.
	AutonomousCodePlaceholderForTesting();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		int newRightPower;
		newRightPower = vexRT(Ch2);
		if(abs(newRightPower) < 6)
		{
			newRightPower = 0;
		}
		int newLeftPower;
		newLeftPower = vexRT(Ch3);
		if(abs(newLeftPower) < 6)
		{
			newLeftPower = 0;
		}//if the motor is less than 5, then it would become zero
		while(1 == 1)
		{
			setRightback(newRightPower);
			setLeftback(newLeftPower);//joystick for control base.
			if(vexRT[Btn6U] == 1)
			{
				motor[rightlift] = motor[leftlift] = 40;
			}
			else if(vexRT[Btn6D] == 1)
			{
				motor[rightlift] = motor[leftlift] = -40;
			}
			else
			{
				motor[rightlift] = motor[leftlift] = 0;
			}
		}//motor 5 and 6 for lift.


		// This is the main execution loop for the user control program.
		// Each time through the loop your program should update motor + servo
		// values based on feedback from the joysticks.

		// ........................................................................
		// Insert user code here. This is where you use the joystick values to
		// update your motors, etc.
		// ........................................................................

		// Remove this function call once you have "real" code.
		UserControlCodePlaceholderForTesting();
	}
}
