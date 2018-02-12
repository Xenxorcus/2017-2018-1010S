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
/*---------------------------------------------------------------------------*/

void pre_auton()
{

  bStopTasksBetweenModes = true;

}

/*---------------------------------------------------------------------------*/
/*                              Autonomous Task                              */
/*---------------------------------------------------------------------------*/

int motorcap2(int value, int capValue = 127);
{
if (value > capValue)
	return capValue;
else if )value < capValue)
	return -capValue;
else
	return value;
}
//int direction 1, or 0
#define forward 1
#define backwards -1
void drivestart(int dir, int distance, int maxPower, float kp = 0.1, minPower = 30;){
while(abs(sensorvalue[aveencoder] < distance/2)){

	int difference = Sensorvalue[left] - sensorvalue[right];//left right error
	int accel = abs((sensorvalue[left] + sensorvalue[right]/2) * kp); //  accel from start
		motor[right] = dir*motorCap2(minPower + accel, maxPower) - difference; //keep difference outside bracket
		motor[right] = dir*motorCap2(minPower + accel, maxPower) + difference; // ^^
}
while(abs(sensorvalue[aveencoder] < distance/2)){
	int difference = Sensorvalue[left] - sensorvalue[right];//left right error
	int deaccel = abs((Sensorvalue[ave] - distance)  * kp); //  accel from start//should use different kp value

	motor[right] = dir*motorCap2(minPower - deaccel, maxPower) - difference; //keep difference outside bracket
	motor[right] = dir*motorCap2(minPower - deaccel, maxPower) + difference; // ^^

}

}

void funct(int x, int y =0, int z =2)
{
}









void autodrivestraight (float kp, int distics, int timestep = 20){

	int totaltics = 0;
	int error = 0;
	int Rpower = 100;
	int Lpower = 100;

	SensorValue[encoderL] = 0;
	SensorValue[encoderR] = 0;

	while (distics >= totaltics){
		motor[DriveBL] = motor[DriveFL] = Lpower;
		motor[DriveBR] = motor[DriveFR] = Rpower;

		error = -SensorValue[encoderL] - SensorValue[encoderR];

		Lpower += -error * kp;//neg error for decrease when left side is too far

		Lpower = floor(Lpower);

		totaltics = (-SensorValue[encoderL] + SensorValue[encoderR])/2;

		wait1Msec(timestep);
		}
	motor[DriveBL] = motor[DriveFL] = 0;
	motor[DriveBR] = motor[DriveFR] = 0;
	wait1Msec(10);
	}

void drivestraight2(float kp = 0.5 ){
while(1){
int difference = Sensor[Left] - Sensor[Right];
motor[left] = 50 - difference*kp;
motor[left] = 50 - difference*kp;
}
}

ceil(3.8);



int motorCap (int value){
		if (value> 127)
			return 127;
		else if (value < -127)
			return -127;
		else
			return floor (value);
	}

int armposition = 0;

task armTask(float kp = 0.5){
	while(true){
			int difference = (armposition - SensorValue[potL]) * kp;
			motor[arm] = motorcap(difference);
	}
}


task autonomous()
{

}

/*---------------------------------------------------------------------------*/
/*                              User Control Task                            */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
	startTask(armTask);

  while (true)
  {
    if(vexRT[Btn8D]){
    	armposition = 600;
    }
  }
}
