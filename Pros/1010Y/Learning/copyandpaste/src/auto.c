#include "main.h"
#include "autofunctions.h"
#include "lift.h"
#include "claw.h"
#include "drive.h"
#include "ports.h"

#define INSIDE 1
#define OUTSIDE -0.7

void autonomous() {


switch(myauto){
case 1: //leftside blue coney preload stack
armDown(105,INSIDE);
mobileGoalOut(1200);
autoDrive(-1, 580);
gyroTurn(1,20);
gyroTurn(-1,7);
delay(200);
autoDrive(-1, 700);
delay(200);
mobileGoalIn(900);
delay(200);
armUp(100,INSIDE);
delay(200);
clawOpenIt(2500);
delay(250);
armDown(90,INSIDE);
gyroTurn(-1,10);
autoDrive(1,800);
gyroTurn(-1,115);
autoDrive(-1,600);
gyroTurn(1,10);
autoDrive(-1,210);///////////////new
mobileGoalOut(1200);
autoDrive(-1,40);///////////////new
autoDrive(1,150);
mobileGoalIn(1200);
delay(100);
autoDrive(1,150);
stop();
break;

case 2: //rightside blue preload stack
armDown(105,INSIDE);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
mobileGoalIn(900);
delay(200);
armUp(100,INSIDE);
delay(200);
clawOpenIt(2500);
delay(250);
armDown(90,INSIDE);
autoDrive(1,100);
gyroTurn(1,10);
autoDrive(1,420);
gyroTurn(1,110);
autoDrive(-1,400);
gyroTurn(-1,10);
autoDrive(-1,210);///////////////new
mobileGoalOut(1200);
autoDrive(-1,40);///////////////new
autoDrive(1,100);
mobileGoalIn(1200);
delay(100);
autoDrive(1,50);
stop();
break;

case 3://leftside red preload stack
armDown(105,INSIDE);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
mobileGoalIn(900);
delay(200);
armUp(100,INSIDE);
delay(200);
clawOpenIt(2500);
delay(250);
armDown(90,INSIDE);
autoDrive(1,100);
gyroTurn(-1,10);
autoDrive(1,420);
gyroTurn(-1,110);
autoDrive(-1,400);
gyroTurn(1,10);
autoDrive(-1,110);///////////////new
mobileGoalOut(1200);
autoDrive(-1,40);///////////////new
autoDrive(1,100);
mobileGoalIn(1200);
delay(100);
autoDrive(1,50);
stop();// leftside red

break;

case 4: //rightside red coney preload stack NEW SHIMMY
armDown(105,INSIDE);
mobileGoalOut(1200);
autoDrive(-1, 580);
gyroTurn(-1,20);
gyroTurn(1,8);
delay(200);
autoDrive(-1, 700);
delay(200);
mobileGoalIn(900);
delay(200);
armUp(100,INSIDE);
delay(200);
clawOpenIt(2500);
delay(250);
armDown(90,INSIDE);
gyroTurn(1,10);
autoDrive(1,800);
gyroTurn(1,115);
autoDrive(-1,550);
gyroTurn(-1,10);
autoDrive(-1,210);///////////////new
mobileGoalOut(1200);
autoDrive(-1,40);///////////////new
autoDrive(1,150);
mobileGoalIn(1200);
delay(100);
autoDrive(1,150);
stop();
break;


case 5: //hold mobile goal
armDown(105,INSIDE);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
autoDrive(-1, 280);
delay(400);
mobileGoalIn(900);
delay(200);
armUp(100,INSIDE);
delay(200);
clawOpenIt(2500);
delay(250);
armDown(90,INSIDE);
stop();
break;

case 6://rightside blue
  armDown(470,OUTSIDE);
  mobileGoalOut(1200);
  autoDrive(-1, 1280);
  delay(400);
  mobileGoalIn(1100);
  delay(400);
  autoDrive(1,600);
  gyroTurn(1,140);
  autoDrive(-1,500);
  gyroTurn(-1,20);
  autoDrive(-1,20);///////////////new
  mobileGoalOut(1200);
  autoDrive(-1,20);///////////////new
  autoDrive(1,40);
  mobileGoalIn(1200);
  autoDrive(1,100);
  stop();
break;

case 7://leftside red
armDown(470,1);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
mobileGoalIn(1100);
delay(400);
autoDrive(1,600);
gyroTurn(-1,140);
autoDrive(-1,500);
gyroTurn(1,20);
autoDrive(-1,20);
mobileGoalOut(1200);
autoDrive(-1,20);///////////////new
autoDrive(1,40);
mobileGoalIn(1200);
autoDrive(1,100);
stop();
break;

break;

case 8://stack preload red right old
armDown(105,INSIDE);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
mobileGoalIn(1100);
armUp(100,INSIDE);
delay(200);
clawOpenIt(2500);
delay(250);
armDown(450,OUTSIDE);
autoDrive(1,600);
gyroTurn(1,140);
autoDrive(-1,500);
gyroTurn(-1,20);
autoDrive(-1,20);///////////////new
mobileGoalOut(1200);
autoDrive(-1,20);///////////////new
autoDrive(1,40);
mobileGoalIn(1200);
autoDrive(1,100);
stop();
break;

case 9:
////turns to right after
autoDrive(1,10);
armDown(270,OUTSIDE);
delay(200);
clawOpenIt(2500);
delay(200);
armUp(100,INSIDE);
gyroTurn(-1,100);
autoDrive(-1,1400);
stop();


case 10:
armDown(105,INSIDE);
mobileGoalOut(1200);
autoDrive(-1, 1280);
delay(400);
mobileGoalIn(900);
delay(200);
armUp(100,INSIDE);
delay(200);
clawOpenIt(2500);
delay(250);
armDown(90,INSIDE);
////cone is scored
autoDrive(1,100);
gyroTurn(1,10);
autoDrive(1,750);
gyroTurn(1,120);
autoDrive(-1,550);
gyroTurn(-1,10);
autoDrive(-1,550);///////////////new
/////mobile goal scoring
mobileGoalOut(1200);
autoDrive(-1,40);///////////////new
autoDrive(1,100);
mobileGoalIn(1200);
delay(100);
//finished 20 point
autoDrive(1,250);
delay(500);
gyroTurn(-1, 50);
delay(500);
mobileGoalOut(1200);
delay(500);
autoDrive(-1,100);
delay(500);
gyroTurn(-1, 45);
delay(500);
autoDrive(-1,550);
delay(300);
mobileGoalIn(1200);
delay(500);
gyroTurn(1, 155);
delay(500);
autoDrive(-1,500);
mobileGoalOut(1200);
autoDrive(-1,100);///////////////new
autoDrive(1,200);
mobileGoalIn(1200);
gyroTurn(1, 45);
armUp(400, INSIDE);
autoDrive(1,1700);
stop();
break;

case 11:
////turns to left after
autoDrive(1,10);
armDown(270,OUTSIDE);
delay(200);
clawOpenIt(2500);
delay(200);
armUp(100,INSIDE);
gyroTurn(1,100);
autoDrive(-1,1400);
stop();
break;

default:
myauto = 1;
break;
}
}
