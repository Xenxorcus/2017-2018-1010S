#pragma config(Sensor, in1,    RTower,         sensorPotentiometer)
#pragma config(Sensor, in2,    Gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  REncoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  LEncoder,       sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  LCD1,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  LCD2,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  LCD3,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  LCD4,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  LCD5,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, LCD6,           sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, Jump,           sensorDigitalIn)
#pragma config(Motor,  port1,           RClaw,         tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           RFront,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           LFront,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           RLift,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           LLift,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           RBack,         tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           LBack,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           LTower,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           RTower,        tmotorVex393_MC29, openLoop)
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
/*===================================================================*\
| Initilize Global Variables..........................................|
|---------------------------------------------------------------------|
| these variables are used in methods that deal with auton all the    |
| way to decalaring variables for battery voltage                     |
\*===================================================================*/
//int statement used for numbers.
int myAutonomous = 20;

/*===================================================================*\
| Auton Names.........................................................|
|---------------------------------------------------------------------|
| declares the constant strings for the different auton names that    |
| are then displayed on the LCD display, also contains the open and   |
| close string for the claw method for easier use                     |
\*===================================================================*/
const string autonOne = "Skills";
const string autonTwo = "Red Right 20";
const string autonThree = "Red Left 20";
const string autonFour = "Blue Right 20";
const string autonFive = "Blue Left 20";
const string autonSix = "Red Right 10";
const string autonSeven = "Red Left 10";
const string autonEight = "Blue Right 10";
const string autonNine = "Blue Left 10";
const string autonTest = "Test";
string open = "open";
string close = "close";
bool showBattery = false;
string mainBattery, backupBattery;


/*===================================================================*\
| LED.................................................................|
|---------------------------------------------------------------------|
| used in the 1010S task as an easy way to shut off all the           |
| lights                                                              |
\*===================================================================*/
void lightEmittingDiode (int power){
	SensorValue[LED1] = power;
	SensorValue[LED2] = power;
	SensorValue[LED3] = power;
	SensorValue[LED4] = power;
	SensorValue[LED5] = power;
	SensorValue[LED6] = power;
}

/*------------------------------------------------------------------*\
//	______               _
//	| ___ \             | |
//	| |_/ /___  ___  ___| |_ ___
//	|    // _ \/ __|/ _ \ __/ __|
//	| |\ \  __/\__ \  __/ |_\__ \
//	\_| \_\___||___/\___|\__|___/
\*------------------------------------------------------------------*/

/*===================================================================*\
| Resets Drive Encoder................................................|
|---------------------------------------------------------------------|
| sets the drive encoders to 0 to then be used throughout the methods |
\*===================================================================*/
void setDrive (){
	// resets encoder values to 0
	SensorValue(LEncoder) = 0;
	SensorValue(REncoder) = 0;
}

/*===================================================================*\
| Resets Gyro.........................................................|
|---------------------------------------------------------------------|
| sets the gyro value to 0 to then be used throughout the methods     |
\*===================================================================*/
void setGyro (){
	// resets the gyro value to 0
	SensorValue(Gyro) = 0;
}

/*===================================================================*\
| Initilize Sensors...................................................|
|---------------------------------------------------------------------|
| completly wipes out all data in the sensors then re-declares them   |
\*===================================================================*/
void intSensor (){
	// sets sensor type to none to start the full sensor reset
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
	wait1Msec(2000);
}

/*===================================================================*\
| Turn Time...........................................................|
|---------------------------------------------------------------------|
| used to control turns based on time rather than gyro, mostly used   |
| in the turn gyro function to help stop it                           |
\*===================================================================*/
void turnTime (int power, int time){
	// sets the drive motors to turn using a set power
	motor[RFront] = motor[RBack] = -power;
	motor[LFront] = motor[LBack] = power;
	// waits the set amout of mSec to carry out the method
	wait1Msec(time);
	stopDrive ();
}

void SetRight(int power)
{
	motor[RFront] = motor[RBack] = power;
}

void SetLeft(int power)
{
	motor[LFront] = motor[LBack] = power;
}

/*===================================================================*\
| Resets Drive Encoder................................................|
|---------------------------------------------------------------------|
| sets the drive encoders to 0 to then be used throughout the methods |
\*===================================================================*/
void setDrive (int power){
	// resets encoder values to 0
	SensorValue(REncoder) = 0;
	SensorValue(LEncoder) = 0;
	motor[RFront] = motor[RBack] = motor[LFront] = motor[LBack] = power;
}

/*------------------------------------------------------------------*\
//	 _____ _
//	/  ___| |
//	\ `--.| |_ ___  _ __  ___
//	 `--. \ __/ _ \| '_ \/ __|
//	/\__/ / || (_) | |_) \__ \
//	\____/ \__\___/| .__/|___/
//							   |_|
\*------------------------------------------------------------------*/

/*===================================================================*\
| Stop Drive..........................................................|
|---------------------------------------------------------------------|
| completly stops the drive motors, used in auton methods             |
\*===================================================================*/
void StopDrive()
{
	motor[RFront] = motor[LFront] = motor[RBack] = motor[LBack] = 0
}

/*===================================================================*\
| Stop Mobile Goal....................................................|
|---------------------------------------------------------------------|
| completly stops the mobile goal lift motors                         |
\*===================================================================*/
void StopLift()
{
	motor[RLift] = motor[LLift] = 0;
}

void StopTower()
{
	motor[RTower] = motor[LTower] = 0;
}

/*------------------------------------------------------------------*\
//	______      _
//	|  _  \    (_)
//	| | | |_ __ ___   _____
//	| | | | '__| \ \ / / _ \
//	| |/ /| |  | |\ V /  __/
//	|___/ |_|  |_| \_/ \___|
\*------------------------------------------------------------------*/

/*===================================================================*\
| Move..........................................................|
|---------------------------------------------------------------------|
| allows the use for timing when controling the drive, but also uses  |
| the drive straight commands                                         |
\*===================================================================*/
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
		SetRight(0);
		SetLeft(0);
	}// end MoveForward

void RightPointTurn(int distance)
{
		while(abs(SensorValue[LEncoder]) < distance)
	{
		SetRight(-127);
		SetLeft(127);
	}
	SetDrive(0);
}
void LeftPointTurn(int distance)
{
		while(abs(SensorValue[REncoder])<distance)
	{
		SetRight(127);
		SetLeft(-127);
	}
	SetDrive(0);
}

void TowerRise(int position)
{
	while(SensorValue[RTower] < position;
	{
	motor[RTower] = motor[LTower]  = 127;
	}

	motor[RTower] = motor[LTower] = 0;
}

void TowerDown(int position)
{
while(SensorValue[RTower] > position;
	{
	motor[RTower] = motor[LTower]  = -127;
	}

	motor[RTower] = motor[LTower] = 0;
}

void TowerStop(int time)
{
	motor[RTower] = motor[LTower] = 0;
	wait1Msec(time);
}

void Lift(int power, int time)
{
	motor[RLift] = motor[LLift] = power;
	wait1Msec(time);
}

void LiftStop(int time)
{
	motor[RLift] = motor{LLift] = 0;
	wait1Msec(time);
}

void Claw(int power, int time)
{
	motor[RClaw] = motor[LClaw] = power;
	wait1Msec(time);
}

/*------------------------------------------------------------------*\
// 	 _     ___________
//	| |   /  __ \  _  \
//	| |   | /  \/ | | |
//	| |   | |   | | | |
//	| |___| \__/\ |/ /
//	\_____/\____/___/
\*------------------------------------------------------------------*/

/*===================================================================*\
| Display LCD.........................................................|
|---------------------------------------------------------------------|
| displays the current auton that is selcted on the LCD               |
\*===================================================================*/
void displayLCD(){
	switch (myAutonomous)
	{
	case 0:
		displayLCDCenteredString(0, autonOne);displayLCDCenteredString(1, "Selected");break;
	case 1:
		displayLCDCenteredString(0, autonTwo);displayLCDCenteredString(1, "Selected");break;
	case 2:
		displayLCDCenteredString(0, autonThree);displayLCDCenteredString(1, "Selected");break;
	case 3:
		displayLCDCenteredString(0, autonFour);displayLCDCenteredString(1, "Selected");break;
	case 4:
		displayLCDCenteredString(0, autonFive);displayLCDCenteredString(1, "Selected");break;
	case 5:
		displayLCDCenteredString(0, autonSix);displayLCDCenteredString(1, "Selected");break;
	case 6:
		displayLCDCenteredString(0, autonSeven);displayLCDCenteredString(1, "Selected");break;
	case 7:
		displayLCDCenteredString(0, autonEight);displayLCDCenteredString(1, "Selected");break;
	case 8:
		displayLCDCenteredString(0, autonNine);displayLCDCenteredString(1, "Selected");break;
	case 9:
		displayLCDCenteredString(0, autonTest);displayLCDCenteredString(1, "Selected");break;
	case 10:
	}
}


/*===================================================================*\
| Auton Setter........................................................|
|---------------------------------------------------------------------|
| sets the auton and shows the menu display to select an auton        |
\*===================================================================*/
void autoSetter (int value, bool select = false){
	clearLCDLine(0);
	clearLCDLine(1);
	// saves auton in gloabal variable
	if (select)
		myAutonomous = value;

	//displays set or select accordingly
	if(myAutonomous == value)
		displayLCDCenteredString(1, ">SET<");
	else
		displayLCDCenteredString(1, ">select<");

	// shows auton names
	switch(value)
	{
	case 0:
		displayLCDCenteredString(0, autonOne); break;
	case 1:
		displayLCDCenteredString(0, autonTwo); break;
	case 2:
		displayLCDCenteredString(0, autonThree); break;
	case 3:
		displayLCDCenteredString(0, autonFour); break;
	case 4:
		displayLCDCenteredString(0, autonFive); break;
	case 5:
		displayLCDCenteredString(0, autonSix); break;
	case 6:
		displayLCDCenteredString(0, autonSeven); break;
	case 7:
		displayLCDCenteredString(0, autonEight); break;
	case 8:
		displayLCDCenteredString(0, autonNine); break;
	case 9:
		displayLCDCenteredString(0, autonTest); break;
	case 10:
	}
}

/*===================================================================*\
| Auton Selector......................................................|
|---------------------------------------------------------------------|
| the framework for being able to use the menu system on the LCD      |
\*===================================================================*/
void autoSelector(){
	// sets choice to 0
	int choice = 0;
	autoSetter(0);

	while (vexRT[Btn7U] != 1){
		if ((vexRT[Btn7L] == 1) || (vexRT[Btn7R] == 1)){
			// previous choice
			if (vexRT[Btn7L] == 1){
				if (--choice < 0){
					choice = 9;
				}
			}
			// next choice
			if (vexRT[Btn7R] == 1){
				if (++choice > 9){
					choice = 0;
				}
			}
			autoSetter(choice);
		}

		// select choice
		if (vexRT[Btn7D] == 1)
			autoSetter(choice, true);
		wait1Msec(120);
	}
	wait1Msec(200);
	return;
}

/*------------------------------------------------------------------*\
//	 _____         _
//	|_   _|       | |
//	  | | __ _ ___| | _____
//	  | |/ _` / __| |/ / __|
//	  | | (_| \__ \   <\__ \
//	  \_/\__,_|___/_|\_\___/
\*------------------------------------------------------------------*/

/*===================================================================*\
| Battery Voltage.....................................................|
|---------------------------------------------------------------------|
| calculates and displays the current battery voltage on the LCD      |
\*===================================================================*/
task batteryVoltage () // source http://www.robotc.net/blog/2012/05/18/advanced-applications-with-the-vex-lcd/
{
	while(true)                                                  // An infinite loop to keep the program running until you terminate it
	{
		clearLCDLine(0);                                            // Clear line 1 (0) of the LCD
		clearLCDLine(1);                                            // Clear line 2 (1) of the LCD

		//Display the Primary Robot battery voltage
		displayLCDString(0, 0, "Primary: ");
		sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V'); //Build the value to be displayed
		displayNextLCDString(mainBattery);

		//Display the Backup battery voltage
		displayLCDString(1, 0, "Backup: ");
		sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');    //Build the value to be displayed
		displayNextLCDString(backupBattery);

		//Short delay for the LCD refresh rate
		wait1Msec(100);
	}
	EndTimeSlice();
}

/*===================================================================*\
| 1010S...............................................................|
|---------------------------------------------------------------------|
| makes our cortex look cool                                          |
\*===================================================================*/
task 1010S (){
	while (true){
		lightEmittingDiode (0);
		SensorValue[LED1] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED2] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED3] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED4] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED5] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED6] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED6] = 1;
		wait1Msec(150);
		SensorValue[LED6] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED5] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED4] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED3] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED2] = 1;
		wait1Msec(150);
		lightEmittingDiode (0);
		SensorValue[LED1] = 1;
	}
	EndTimeSlice();
}

/*------------------------------------------------------------------*\
//	___  ___      _     _ _        _____             _
//	|  \/  |     | |   (_) |      |  __ \           | |
//	| .  . | ___ | |__  _| | ___  | |  \/ ___   __ _| |
//	| |\/| |/ _ \| '_ \| | |/ _ \ | | __ / _ \ / _` | |
//	| |  | | (_) | |_) | | |  __/ | |_\ \ (_) | (_| | |
//	\_|  |_/\___/|_.__/|_|_|\___|  \____/\___/ \__,_|_|
\*------------------------------------------------------------------*/

/*===================================================================*\
| Red.................................................................|
|---------------------------------------------------------------------|
| Done: none                                                          |
\*===================================================================*/
void RedRight20()
{
	char Red_Right_20;

	//score preload on the mobile goal in 20 points zone.
	startTask(TowerTask);
	TowerPosition = 700;
	wait1Msec(200);
	Lift(-127, 1400);
	LiftStop(10);
	Move(127, 500);
	StopDrive(300);
	Lift(127, 1400);
	TowerDown(0);
	TowerStop(100);
	Claw(127, 400);
	Move(-127, -400);
	LeftPointTurn(200);
	Move(80, 134);
	LeftPointTurn(130);
	Move(127, 240);
	TowerRise(300);
	Lift(-127; 1200);
	Move(-127, 200);
	StopDrive(100);
}

void RedRight10()
{

//score preload on mobile goal the 10 points zone
	startTask(TowerTask);
	TowerPosition = 700;
	wait1Msec(200);
	Lift(-127, 1400);
	LiftStop(10);
	Move(127, 500);
	StopDrive(300);
	Lift(127, 1400);
	TowerDown(0);
	TowerStop(100);
	Claw(127, 400);
	Move(-127, -400);
	LeftPointTurn(200);
	Move(80, 134);
	LeftPointTurn(130);
	Move(127, 140);
	TowerRise(300);
	Lift(-127, 1200);
	Move(-127, 180);
	StopDrive(100);
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

/*------------------------------------------------------------------*\
//	______            ___        _
//	| ___ \          / _ \      | |
//	| |_/ / __ ___  / /_\ \_   _| |_ ___  _ __
//	|  __/ '__/ _ \ |  _  | | | | __/ _ \| '_ \
//	| |  | | |  __/ | | | | |_| | || (_) | | | |
//	\_|  |_|  \___| \_| |_/\__,_|\__\___/|_| |_|
\*------------------------------------------------------------------*/

/*===================================================================*\
| Pre Auton...........................................................|
|---------------------------------------------------------------------|
| resets sensors and starts the NightRider task                       |
| DO NOT MOVE because of the gyro calibration                         |
\*===================================================================*/
void pre_auton(){
	// starts NightRider task because its cool
	startTask (1010S);
	// set up LCD display
	bLCDBacklight = true;
	displayLCDCenteredString(0, "Do Not Move");
	displayLCDCenteredString(1, "Calibrating");
	// sensor set up
	intSensor ();
	setDrive ();
}

task autonomous()
{
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