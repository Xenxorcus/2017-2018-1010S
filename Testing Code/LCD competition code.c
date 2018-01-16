#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)
#pragma config(UART_Usage, UART1, uartVEXLCD, baudRate19200, IOPins, None, None)
//Variable that will carry between modes
int Program;

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;
	//Leave this value alone
	int lcdScreenMin = 1;
	//This keeps track of which program you want to run
	int lcdScreen = 1;
	//Change this value to be the maximum number of programs you want on the robot
	int lcdScreenMax = 4;
	//Turns on the Backlight
	bLCDBacklight = true;

	//Copied from someone's sample code because the documentation for RobotC won't tell me anything useful
	//These should logically work, but I'm not 100% sure
	const short leftButton = 1;
	const short centerButton = 2;
	const short rightButton = 4;

	while (vrDisabled == 1) { //Ensures this code will run ONLY when the robot is disabled
		if (nLCDButtons == leftButton) { //Scrolls to the left
			if (lcdScreenMin == lcdScreen) {
				lcdScreen = lcdScreenMax;
				wait1Msec(250);
			} else {
				lcdScreen --;
				wait1Msec(250);
			}
		}
		if (nLCDButtons == rightButton) { //Scrolls to the right
			if (lcdScreenMax == lcdScreen) {
				lcdScreen = lcdScreenMin;
				wait1Msec(250);
			} else {
				lcdScreen++;
				wait1Msec(250);
			}
		}
		if (lcdScreen == 1 && Program != 1) {
			displayLCDCenteredString (0, "Program"); //Name the first program here
			displayLCDCenteredString (1, "1"); //Name the first program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 1 && Program == 1) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[1]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 2 && Program != 2) {
			displayLCDCenteredString (0, "Program"); //Name the second program here
			displayLCDCenteredString (1, "2"); //Name the second program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 2 && Program == 2) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[2]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 3 && Program != 3) {
			displayLCDCenteredString (0, "Program"); //Name the third program here
			displayLCDCenteredString (1, "3"); //Name the third program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 3 && Program == 3) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[3]"); //So that while we're scrolling, we can have one marked
		} else if (lcdScreen == 4 && Program != 4) {
			displayLCDCenteredString (0, "Program"); //Name the fourth program here
			displayLCDCenteredString (1, "4"); //Name the fourth program here
			if (nLCDButtons == centerButton) {
				Program = lcdScreen; //Sets the Program to the one on-screen
				displayLCDCenteredString (0, "Autonomous Has");
				displayLCDCenteredString (1, "Been Selected!");
				wait1Msec(1500);
			}
		} else if (lcdScreen == 4 && Program == 4) {
			displayLCDCenteredString (0, "Program"); //We use brackets to mark which program we have chosen
			displayLCDCenteredString (1, "[4]"); //So that while we're scrolling, we can have one marked
		}
	}

}


/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	if(Program == 1){
		//Put your second program in here
	}
	else if(Program == 2){
		//Put your second program in here
	}
	else if(Program == 3){
		//Put your third program in here
	}
	else if(Program == 4){
		//Pur your fourth program in here
	}
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .....................................................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................

	  UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}
