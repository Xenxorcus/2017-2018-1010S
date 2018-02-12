/**
 * File for operator control code.
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of Purdue University ACM SIG BOTS nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source code may be obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 ********************************************************************************/

#include "main.h"

void allMotors(int motorSpeed) {

	motorSet(4, motorSpeed);
	motorSet(5, motorSpeed);
	motorSet(6, motorSpeed);
	motorSet(7, motorSpeed);
motorSet(3,motorSpeed);
motorSet(9,motorSpeed);
}

void operatorControl() {
	while (true)
	{
		int joy3 = joystickGetAnalog(1, 3);//y
		int joy2 = joystickGetAnalog(1, 2);//x


		motorSet(1, -joy2);//FR
		motorSet(2, -joy2);//BR
		motorSet(8, joy3);//FL
		motorSet(10, joy3);//BL

		if (joystickGetDigital(1, 6, JOY_DOWN)) {//arm

				motorSet(4, 127);
				motorSet(5, 127);
				motorSet(6, -127);
				motorSet(7, -127);

			} else if (joystickGetDigital(1, 6, JOY_UP)) {
				motorSet(4, -127);
				motorSet(5, -127);
				motorSet(6, 127);
				motorSet(7, 127);

			} else {
				motorSet(4, 0);
				motorSet(5, 0);
				motorSet(6, 0);
				motorSet(7, 0);
			}
		if (joystickGetDigital(1, 5, JOY_UP)) {//claw

					motorSet(3, 127);
					motorSet(9, -127);

				} else if (joystickGetDigital(1, 5, JOY_DOWN)) {
					motorSet(3, -127);
					motorSet(9, 127);

				} else {
					motorSet(3, 0);
					motorSet(9, 0);
				}




		delay(25);
	}
}
