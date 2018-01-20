#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
#pragma config(UART_Usage, UART2, uartNotUsed, baudRate4800, IOPins, None, None)
#pragma config(Sensor, in1,    RTower,         sensorPotentiometer)
#pragma config(Sensor, in8,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  REncoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  LEncoder,       sensorQuadEncoder)
#pragma config(Motor,  port1,           RClaw,         tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           RFront,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LFront,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           RLift,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           LLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           RBack,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LBack,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LTower,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           RTower,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port10,          LClaw,         tmotorVex393_HBridge, openLoop)
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


const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 5;

//Wait for Press--------------------------------------------------
void waitForPress()
{
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Wait for Release------------------------------------------------
void waitForRelease()
{
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//----------------------------------------------------------------

//Declare myauto variable to keep track of our choice
int myauto = 0;

void autoselector(){
	//------------- Beginning of User Interface Code ---------------
	//Clear LCD
	clearLCDLine(0);
	clearLCDLine(1);
	//Loop while center button is not pressed
	while(nLCDButtons != centerButton)
	{
		//Switch case that allows the user to choose from 5 different options
		switch(myauto){
		case 0:
			//Display first choice
			displayLCDCenteredString(0, "Right 20");
			displayLCDCenteredString(1, "<		 Let's Go!		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				myauto = 4;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				myauto = 4;
			}
			break;
		case 1:
			//Display second choice
			displayLCDCenteredString(0, "Left 20");
			displayLCDCenteredString(1, "<		 Let's Go!		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				myauto--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				myauto++;
			}
			break;
		case 2:
			//Display third choice
			displayLCDCenteredString(0, "Right 10");
			displayLCDCenteredString(1, "<		 Let's Go!		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				myauto--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				myauto++;
			}
			break;
		case 3:
			//Display fourth choice
			displayLCDCenteredString(0, "Left 10");
			displayLCDCenteredString(1, "<		 Let's Go!		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				myauto--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				myauto++;
			}
			break;
		case 4:
			//Display fourth choice
			displayLCDCenteredString(0, "Skill");
			displayLCDCenteredString(1, "<		 Let's Go!		>");
			waitForPress();
			//Increment or decrement "count" based on button press
			if(nLCDButtons == leftButton)
			{
				waitForRelease();
				myauto--;
			}
			else if(nLCDButtons == rightButton)
			{
				waitForRelease();
				myauto = 0;
			}
			break;
		default:
			myauto = 0;
			break;
		} // end switch
		} // end while
	} // void autoselector()

void intSensor (){
			SensorType[Gyro] = sensorNone;
		SensorType[LEncoder] = sensorNone;
		SensorType[REncoder] = sensorNone;
		// waits 1 sec before setting all the sensors
		wait1Msec(1000);
		SensorType[Gyro] = sensorGyro;
		SensorType[LEncoder] = sensorQuadEncoder;
		SensorType[REncoder] = sensorQuadEncoder;
		// waits 2 seconds to let gyro initilize properly
		// DO NOT MOVE WHILE THIS IS HAPPENING
		wait1Msec(200);
	}

	//set sensors to zero.
	void setDrive ()
	{
		// resets encoder values to 0
		SensorValue(LEncoder) = 0;
		SensorValue(REncoder) = 0;
	}

	void setGyro ()
	{
		// resets the gyro value to 0
		SensorValue(Gyro) = 0;
	}

	//combine motors together
	void SetRight(int power)
	{
		motor[RFront] = motor[RBack] = power;
	}

	void SetLeft(int power)
	{
		motor[LFront] = motor[LBack] = power;
	}

	void StopDrive(int time)
	{
		motor[RFront] = motor[LFront] = motor[RBack] = motor[LBack] = 0;
		wait1Msec(time);
	}

	void StopLift(int time)
	{
		motor[RLift] = motor[LLift] = 0;
		wait1Msec(time);
	}

	void StopTower(int time)
	{
		motor[RTower] = motor[LTower] = 0;
		wait1Msec(time);
	}

	void StopClaw(int time)
	{
		motor[RClaw] = motor[LClaw] = 0;
		wait1Msec(time);
	}

	void Move(int power, int distance)
	{
		SensorValue[LEncoder] = 0;
		SensorValue[REncoder] = 0;
		float kp = 0.5;//proportional constant, can be tuned.
		while(abs(SensorValue[REncoder]+SensorValue[LEncoder])/2 < distance)
		{
			int error = SensorValue[LEncoder] - SensorValue[REncoder];
			//find the difference between the two encoders.
			SetLeft(power - error*kp);
			SetRight(power + error*kp);
		}//end while
		setDrive();
	}// end MoveForward

	void gyroturnL(int power, int gyrovalue){

		SensorValue[Gyro] = 0;

		while (SensorValue[Gyro] >= gyrovalue)
		{

			motor[RFront] = motor[RBack] = -power;

			motor[LFront] = motor[LBack] = power;

		}

		motor[RFront] = motor[RBack] = motor[LFront] = motor[LBack] = 0;

		wait1Msec(10);
	}

	void gyroturnR(int power, int gyrovalue){
		SensorValue[Gyro] = 0;

		while (SensorValue[Gyro] >= gyrovalue)
		{

			motor[RFront] = motor[RBack] = power;

			motor[LFront] = motor[LBack] = -power;

		}

		motor[RFront] = motor[RBack] = motor[LFront] = motor[LBack] = 0;

		wait1Msec(10);
	}

	void RightPointTurn(int time)
	{
			SetRight(-127);
			SetLeft(127);
			wait1Msec(time);
			setDrive();
	}
	void LeftPointTurn(int time)
	{
			SetRight(127);
			SetLeft(-127);
			wait1Msec(time);
			setDrive();
	}

	/*void TowerRise(int position)
	{
		while(SensorValue[RTower] <= position)
		{
			motor[RTower] = motor[LTower]  = 127;
		}

		motor[RTower] = motor[LTower] = 0;
	}

	void TowerDown(int position)
	{
		while(SensorValue[RTower] >= position)
		{
			motor[RTower] = motor[LTower]  = -127;
		}

		motor[RTower] = motor[LTower] = 0;
	}
*/
	void TowerRise(int power, int time)
	{
		motor[RTower] = motor[LTower] = power;
		wait1Msec(time);
	}

	void TowerDown(int power, int time)
	{
		motor[RTower] = motor[LTower] = -power;
		wait1Msec(time);
	}

	void Lift(int power, int time)
	{
		motor[RLift] = motor[LLift] = power;
		wait1Msec(time);
	}

	void Claw(int power, int time)
	{
		motor[RClaw] = motor[LClaw] = power;
		wait1Msec(time);
	}

	void driveBase(){
		motor[RFront] = motor[RBack] = vexRT(Ch2) - vexRT(Ch1);//combine Right Motors all forward.
		motor[LBack] = motor[LFront] = vexRT(Ch2) + vexRT(Ch1);//combine Left Motors all forward.
	}

	void driveTower(){
		if(vexRT[Btn5UXmtr2] ==1)
		{
			motor[RTower] = motor[LTower] = 127;
		}
		else if(vexRT[Btn5DXmtr2] == 1)
		{
			motor[RTower] = motor[LTower] = -127;
		}
		else
		{
			motor[RTower] = motor[LTower] = 0;
		}
	}

	void driveLift(){
		if(vexRT[Btn6U] == 1)
		{
			motor[RLift] = motor[LLift] = 127;
		}
		else if(vexRT[Btn6D] == 1)
		{
			motor[RLift] = motor[LLift] = -127;
		}
		else
		{
			motor[RLift] = motor[LLift] = 0;
		}
	}

	void driveClaw(){
		motor[LClaw] = motor[RClaw] = vexRT(Ch3Xmtr2);
	}

	void pre_auton()

	{
		bStopTasksBetweenModes = true;
		bDisplayCompetitionStatusOnLcd = false;
		// sensor set up
		intSensor ();
		setDrive ();
		autoselector();
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

	int TowerHold = 1; //Tower loop flag
	int TowerPosition = 0; // Position to set the tower

	task TowerTask()
	{
		TowerPosition = SensorValue[RTower];
		while(true)
		{
			if(TowerHold)//should tower code be running?
			{
				//calculate difference
				int difference = (SensorValue[RTower] - TowerPosition)*0.5;

				//Cap difference value if needed
				if(difference > 127)
					difference = 127;
				else if(difference < -127)
					difference = -127;

				motor[RTower] = motor[LTower] = difference;
			}
		}
	}

	task autonomous()
	{
		clearLCDLine(0);
		clearLCDLine(1);
		//Switch Case that actually runs the user choice
		switch(myauto){
		case 0:
			//If count = 0, run the code correspoinding with choice 1
			displayLCDCenteredString(0, "Right 20");
			displayLCDCenteredString(1, "Let's Go!");
			wait1Msec(100);// Robot waits for 100 milliseconds
			TowerRise(127, 1200);
			StopTower(10);
			Lift(127, 1200);
			Move(127, 800);
			StopDrive(10);
			Lift(-127, 1200);
			StopLift(10);
			TowerDown(127, 300);
			LeftPointTurn(600);
			Move(127, 200);
			LeftPointTurn(500);
			Claw(-127, 400);
			TowerRise(127, 500);
			Lift(-127, 1100);
			Move(-127, -100);
			StopDrive(10);


			/*Lift(127, 1300);
			Move(127, 800);
			StopDrive();
			Lift(127, 1400);
			Claw(80, 230);
			TowerDown(0);
			Claw(-127, 200);
			Move(-127, -600);
			LeftPointTurn(600);
			Move(127, 200);
			LeftPointTurn(455);
			TowerRise(300);
			Move(127, 120);
			Lift(-127, 1100);
			Move(-127, 100);
			StopDrive();*/
			break;

		case 1:
			//If myauto = 1, run the code correspoinding with choice 2
			displayLCDCenteredString(0, "Left 20");
			displayLCDCenteredString(1, "Let's Go!");
			wait1Msec(100);// Robot waits for 100 milliseconds
			TowerRise(127, 1200);
			StopTower(10);
			Lift(127, 1200);
			Move(127, 800);
			StopDrive(10);
			Lift(-127, 1200);
			StopLift(10);
			TowerDown(127, 300);
			RightPointTurn(600);
			Move(127, 200);
			RightPointTurn(500);
			Claw(-127, 400);
			TowerRise(127, 500);
			Lift(-127, 1100);
			Move(-127, -100);
			StopDrive(10);
			break;

		case 2:
			//If count = 2, run the code correspoinding with choice 3
			displayLCDCenteredString(0, "Right 10");
			displayLCDCenteredString(1, "Let's Go!");
			wait1Msec(100);// Robot waits for 100 milliseconds
			TowerRise(127, 1200);
			StopTower(10);
			Lift(127, 1200);
			Move(127, 800);
			StopDrive(10);
			Lift(-127, 1200);
			StopLift(10);
			TowerDown(127, 300);
			LeftPointTurn(600);
			Move(127, 200);
			LeftPointTurn(500);
			Claw(-127, 400);
			TowerRise(127, 500);
			Lift(-127, 1100);
			Move(-127, -100);
			StopDrive(10);
			break;

		case 3:
			//If count = 3, run the code correspoinding with choice 4
			displayLCDCenteredString(0, "Left 10");
			displayLCDCenteredString(1, "Let's Go!");
			wait1Msec(100);// Robot waits for 100 milliseconds
			TowerRise(127, 1200);
			StopTower(10);
			Lift(127, 1200);
			Move(127, 800);
			StopDrive(10);
			Lift(-127, 1200);
			StopLift(10);
			TowerDown(127, 300);
			RightPointTurn(600);
			Move(127, 200);
			RightPointTurn(500);
			Claw(-127, 400);
			TowerRise(127, 500);
			Lift(-127, 1100);
			Move(-127, -100);
			StopDrive(10);
			break;

		case 4:
			//If myauto = 4, run the code correspoinding with choice 5
			displayLCDCenteredString(0, "Skill");
			displayLCDCenteredString(1, "Let's Go!");
			wait1Msec(100);// Robot waits for 100 milliseconds

			break;
		default:
			displayLCDCenteredString(0, "No valid choice");
			displayLCDCenteredString(1, "was made!");
			break;
		}
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
		bLCDBacklight = true;
		clearLCDLine(0);
		clearLCDLine(1);
		while (true)
		{
			displayLCDCenteredString(0, "Once more");
			displayLCDCenteredString(1, "into the zone");
			driveBase();
			driveClaw();
			driveLift();
			driveTower();
		}
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
