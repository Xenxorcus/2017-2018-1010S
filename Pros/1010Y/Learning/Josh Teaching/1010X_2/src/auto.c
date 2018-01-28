/**
* File for autonomous code.
*
* This file should contain the user autonomous() function and any functions related to it.
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

/**
* Runs the user autonomous code.
*
* This function will be started in its own task with the default priority and stack size whenever the robot is enabled via the Field Management System or the VEX Competition Switch in the autonomous mode. If the robot is disabled or communications is lost, the autonomous task will be stopped by the kernel. Re-enabling the robot will restart the task, not re-start it from where it left off.
*
* Code running in the autonomous task cannot access information from the VEX Joystick. However, the autonomous function can be invoked from another task if a VEX Competition Switch is not available, and it can access joystick information if called in this way.
*
* The autonomous task may exit, unlike operatorControl() which should never exit. If it does so, the robot will await a switch to another mode or disable/enable cycle.
*/
void autonomous() {
lcdClear(uart1);
lcdPrint(uart1, 1, "No Mercy.");
TaskHandle autoarmtask = taskCreate (autoarmtaskcode, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
TaskHandle autoclawtask = taskCreate (autoclawencodertaskcode, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
//taskRunLoop( autoarmtaskcode (), 30);
//taskRunLoop( autoclawencodertaskcode (*ignore), 30);
  switch(myauto){
    case(1): //Star Mid-L
    clawopen();
    clawtarget = 700;
    drivestraight(1, 12000, 6000, 200, 200, 110, 70, 0.1);
    clawtarget = -100;
    delay(500);
    armtargetL = OFF_GROUND_L;
    armtargetR = OFF_GROUND_R;
    delay(750);
    turnexact(-1, 60, 5000, 30, 30, 110, 70, 0.01);
    drivestraight(1, 2000, 5000, 50, 50, 110, 70, 0.01);
    turnexact(1, 165, 5000, 30, 30, 110, 70, 0.01);
    drivestraight(-1, 4400, 5000, 50, 50, 110, 70, 0.01);
    armtargetL = FENCE_LOW_L+1000;
    armtargetR = FENCE_LOW_R+1000;
    while(analogRead(potarmL)<2800){}
    clawtarget = 700;
    delay(1200);
    //armtargetL = GROUND_L;
    //armtargetR = GROUND_R;
    delay(2000);
    break;


    case(2)://cube mid-L

    clawopen();
    drivestraight(1, 12000, 7000, 800, 800, 120, 70, 0.1);



    /*
    clawopen();
    clawtarget = 1000;
    drivestraight(1, 6000, 7000, 800, 800, 120, 70, 0.1);
    clawtarget = 100;
    delay(500);
    armtargetL = OFF_GROUND_L;
    armtargetR = OFF_GROUND_R;
    delay(750);
    turnexact(1, 110, 5000, 20, 20, 115, 70, 0.01);
    drivestraight(-1, 3700, 5000, 800, 800, 110, 70, 0.1);
    armtargetL = FENCE_LOW_L;
    armtargetR = FENCE_LOW_R;
    delay(1600);
    clawtarget = 700;
    delay(2000);
    ///armtargetL = GROUND_L;
    //armtargetR = GROUND_R;
    delay(2000);
*/

    break;
    case(3)://cude mid-R
    clawopen();
    drivestraight(1, 12000, 7000, 800, 800, 120, 70, 0.1);

/*
    clawopen();
    clawtarget = 1000;
    drivestraight(1, 6000, 7000, 800, 800, 120, 70, 0.1);
    clawtarget = 100;
    delay(500);
    armtargetL = OFF_GROUND_L;
    armtargetR = OFF_GROUND_R;
    delay(750);
    turnexact(-1, 120, 5000, 20, 20, 115, 70, 0.01);
    drivestraight(-1, 3700, 5000, 800, 800, 110, 70, 0.1);
    armtargetL = FENCE_LOW_L;
    armtargetR = FENCE_LOW_R;
    delay(1600);
    clawtarget = 700;
    delay(2000);
  //  armtargetL = GROUND_L;
    //armtargetR = GROUND_R;
delay(2000);
    break;
    */
    case(4): //star mid-R

    clawopen();
    clawtarget = 700;
    drivestraight(1, 12000, 50000, 200, 200, 110, 70, 0.1);
    clawtarget = -100;
    delay(500);
    armtargetL = OFF_GROUND_L;
    armtargetR = OFF_GROUND_R;
    delay(750);
    turnexact(1, 60, 5000, 30, 30, 110, 70, 0.01);
    drivestraight(1, 2000, 5000, 50, 50, 110, 70, 0.01);
    turnexact(-1, 165, 5000, 30, 30, 110, 70, 0.01);
    drivestraight(-1, 4400, 5000, 50, 50, 110, 70, 0.01);
    armtargetL = FENCE_LOW_L;
    armtargetR = FENCE_LOW_R;
    while(analogRead(potarmL)<2800){}
    clawtarget = 700;
    delay(1200);
  //  armtargetL = GROUND_L;
  //  armtargetR = GROUND_R;
    delay(2000);

    break;
    case(5)://programming skills

    drivestraight(-1, 2500, 5000, 500, 500, 115, 70, 0.1);
    clawopen();
    clawtarget = 700;
    delay(1500);
    drivestraight(1, 1300, 5000, 250, 250, 115, 70, 0.1);
    delay(900);
    clawtarget = -50;
    delay(1000);
    armtargetL = OFF_GROUND_L;
    armtargetR = OFF_GROUND_R;
    delay(1000);
//backmod
    drivestraight(-1, 5000, 5000, 800, 800, 115, 70, 0.1);
    armtargetL = FENCE_LOW_L + 500;
    armtargetR = FENCE_LOW_R + 500;
    while(analogRead(potarmL)<2800){}
    clawtarget = 700;
    delay(1000);
    armtargetL = GROUND_L;
    armtargetR = GROUND_R;
    delay(1800);
    drivestraight(1, 4700, 5000, 800, 800, 115, 70, 0.1);
    delay(1000);
    clawtarget = 0;
    delay(1000);
//2
    drivestraight(-1, 5800, 5000, 800, 800, 115, 70, 0.1);
    armtargetL = FENCE_LOW_L + 500;
    armtargetR = FENCE_LOW_R + 500;
    while(analogRead(potarmL)<2800){}
    clawtarget = 700;
    delay(1000);
    armtargetL = GROUND_L;
    armtargetR = GROUND_R;
    delay(1800);
    drivestraight(1, 5800, 5000, 800, 800, 115, 70, 0.1);
    delay(1000);
    clawtarget = 0;
    delay(1000);
//3
drivestraight(-1, 5800, 5000, 800, 800, 115, 70, 0.1);
armtargetL = FENCE_LOW_L + 500;
armtargetR = FENCE_LOW_R + 500;
while(analogRead(potarmL)<2800){}
clawtarget = 700;
delay(1000);
armtargetL = GROUND_L;
armtargetR = GROUND_R;
delay(1800);
drivestraight(1, 5800, 5000, 800, 800, 115, 70, 0.1);
delay(1000);
clawtarget = 0;
delay(1000);
  //4
  drivestraight(-1, 6000, 5000, 800, 800, 115, 70, 0.1);
  armtargetL = FENCE_LOW_L + 500;
  armtargetR = FENCE_LOW_R + 500;
  while(analogRead(potarmL)<2800){}
  clawtarget = 700;
  delay(1000);
  armtargetL = GROUND_L;
  armtargetR = GROUND_R;
  delay(1800);
  drivestraight(1, 5200, 5000, 800, 800, 115, 70, 0.1);
  delay(1000);

    break;

case(6):
//L-Mid Close
clawopen();
clawtarget = 700;
delay(200);
drivestraight(1, 2000, 4000, 500, 500, 120, 70, 0.1);
delay(750);
clawtarget = -75;
delay(600);
drivestraight(-1, 1500, 4000, 500, 500, 120, 70, 0.1);
  delay(1000);
armtargetL = 1500;
armtargetR = 2050;
delay(2500);
turnexact(-1, 70, 3000, 20, 20, 120, 75, 0.1);
drivestraight(-1, 7800, 8000, 500, 500, 120, 70, 0.1);
armtargetL = FENCE_LOW_L;
armtargetR = FENCE_LOW_R;
while(analogRead(potarmL)<2800){}
clawtarget = 700;
delay(2500);

break;

case(7):
//R-Mid Close
clawopen();
clawtarget = 700;
delay(200);
drivestraight(1, 2000, 4000, 500, 500, 120, 70, 0.1);
delay(750);
clawtarget = -75;
delay(600);
drivestraight(-1, 1500, 4000, 500, 500, 120, 70, 0.1);
  delay(1000);
armtargetL = 1500;
armtargetR = 2050;
delay(2500);
turnexact(1, 70, 3000, 20, 20, 120, 75, 0.1);
drivestraight(-1, 7800, 8000, 500, 500, 120, 70, 0.1);
armtargetL = FENCE_LOW_L;
armtargetR = FENCE_LOW_R;
while(analogRead(potarmL)<2800){}
clawtarget = 700;
delay(2500);


break;


case(8):
//BLANK
break;

  default:

  break;


  }
taskDelete(autoarmtask);
taskDelete(autoclawtask);
}
