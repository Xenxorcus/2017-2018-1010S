#pragma config(Sensor, dgtl1,  rightencoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftencoder,    sensorQuadEncoder)
#pragma config(Motor,  port2,           FR,            tmotorVex393HighSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port3,           FL,            tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port4,           BR,            tmotorVex393HighSpeed_MC29, openLoop, driveRight)
#pragma config(Motor,  port5,           BL,            tmotorVex393HighSpeed_MC29, openLoop, driveLeft)
#pragma config(Motor,  port6,           Rlift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           Llift,         tmotorVex393_MC29, openLoop)
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
void setleftdrive(int power)
{
	SensorValue(leftencoder) = 0;
	motor[FL] = power;
	motor[BL] = power;
}
void setrightdrive(int power)
{
	SensorValue(rightencoder) = 0;
	motor[FR] = power;
	motor[BR] = power;
}
void setdrive(int power)
{

motor[FR] = motor[BR] = motor[FL] = motor[BL] = power;
}
void stopdrive()
{
	motor[FL] = 0;
	motor[BL] = 0;
	motor[FR] = 0;
	motor[BR] = 0;
}
void setlift(int power)
{
	motor[Rlift] = motor[Llift] = power;

}
void stoplift ()
{
	motor[Rlift] = motor[Llift] = 0;


}
void liftup(int power = 127,int time)
{
	setlift(127);
	wait1Msec(time);
	setlift(0);
}

void liftdown(int power,int time)

{
	setlift(-127);
	wait1Msec(time);
	setlift(0);

}
void driveforward( int power = 127, int time)
{
	setrightdrive(127);
	setleftdrive(127);
	wait1Msec(time);
	setrightdrive(0);
	setleftdrive(0);
}

void drivebackward(int power, int time)
{
	setrightdrive(127);
	setleftdrive(127);
	wait1Msec(time) ;
	setrightdrive(0);
	setleftdrive(0);

}

void turnleft( int time,int power= 127)
{
	setrightdrive(power);
	setleftdrive(-power);
	wait1Msec(time) ;
	setrightdrive(0);
	setleftdrive(0);
}
void turnright(int time, int power = 127)

{
	setrightdrive(-power);
	setleftdrive(power);
	wait1Msec(time) ;
	setrightdrive(0);
	setleftdrive(0);

}

#define Left 1
#define Right 0
void turn(int direction,int power,int time)
{
	if (direction == Left)
	{
		turnleft(time,power);
	}
	else if (direction == Right)
	{
		turnright(time,power);

	}

}
void drive(int distance,int power)
{
	float kp = 0.5 // proportional constant, to be tuned
	//compare the required to the average of the two encoders
	while(abs(SensorValue[leftencoder] + SensorValue[rightencoder])/2 < distance)// how do we know distance? encodertick is number? how to we know how many ttick
	{
		//find the difference between the two encoders
	int error = SensorValue[leftencoder] - SensorValue[rightencoder];
		setleftdrive(power - error*kp);
		setrightdrive(power - error*kp);
	}
//stop the motors once the robot has reached the endpoint
	setdrive(0);

}

void RightPointTurn(int distance)
{
		while(abs(SensorValue[leftencoder]) < distance)
	{
		setrightdrive(-127);
		setleftdrive(127);
	}
	setDrive(0);
}
void LeftPointTurn(int distance)
{
		while(abs(SensorValue[rightencoder])<distance)
	{
		setrightdrive(127);
		setleftdrive(-127);
	}
	setDrive(0);
}

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
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

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
drive(100,127)

}


task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
		setleftdrive(vexRT[Ch3]);
		setrightdrive(vexRT[Ch2]);
		if (vexRT[Btn5U] == 1)
		{
			motor[Rlift] = motor[Llift] = 127;

		}
		else if (vexRT[Btn5D] == 1)
		{

			motor[Rlift] = motor[Llift] = -127;
		}
		else
		{
			motor[Rlift] = motor[Llift] = 0;
		}
	}
}
// This is the main execution loop for the user control program.
// Each time through the loop your program should update motor + servo
// values based on feedback from the joysticks.

// ........................................................................
// Insert user code here. This is where you use the joystick values to
// update your motors, etc.
// ........................................................................