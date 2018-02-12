 #include "autofunctions.h"
 #include "main.h"
 #include "drive.h"
 #include "mgten.h"
 #include "mgtwenty.h"



void autonomous() {
  //back drive is 1
  //drive forwards is -1
  // 1 is clockwise
  //-1 is counterclockwise

//twenty all in out 1545
//twenty in 10
//ten out -490
//ten in-232

//mg20out -1
//mg20 in 1
  switch(myauto){
case 1://pid skills
autoDrive(-1, 230);
delay(100);
mobileGoalTen(1,-400);
delay(100);
autoDrive(-1, 530);
delay(400);
mobileGoalTen(-1, -235);
delay(400);
autoDrive(1, 230);
delay(400);
//picked up ten
gyroTurnPID(-1,187,1500,4,5);
delay(400);
mobileGoalTwenty(-1,1545);
delay(400);
autoDrive(1,610);
delay(400);
mobileGoalTwenty(1, 10);
delay(400);
//picked up 20
autoDrive(1,800);
delay(100);
gyroTurnPID(-1,90,1500,4,5);
delay(100);
//first turn
autoDrive(1,330);//was 337
delay(100);
gyroTurnPID(1,90,1500,4,5);
delay(100);
//second turn
autoDrive(1,430);
delay(100);

mobileGoalTwenty(-1, 1545);
delay(100);
autoDrive(-1,80);
delay(400);
mobileGoalTwenty(1, 10);
delay(100);
//scored 20
autoDrive(-1,220);
delay(100);
gyroTurnPID(-1,93,1500,4,5);
delay(100);
autoDrive(1,129);// was 125
gyroTurnPID(-1,90,1500,4,5);
delay(100);
autoDrive(-1,135);

mobileGoalTen(1,-420);
delay(100);
autoDrive(-1,100);
delay(100);
autoDrive(1,100);
delay(400);
mobileGoalTen(-1,-235);
//finished side one

mobileGoalTwenty(-1,1545);
delay(400);
autoDrive(1,450);
delay(700);
mobileGoalTwenty(1, 10);
delay(400);
//finish 20 #2

gyroTurnPID(-1,185,1500,4,5);
delay(400);
mobileGoalTen(1,-390);
autoDrive(-1, 1500);
delay(400);
mobileGoalTen(-1, -225);
delay(400);
//finished 10#2

autoDrive(-1,240);
delay(100);
gyroTurnPID(-1,89,1500,4,5);
delay(100);
autoDrive(-1,350);
delay(100);

gyroTurnPID(-1,88,1500,4,5);
delay(100);
autoDrive(1,400);
delay(100);
mobileGoalTwenty(-1, 1545);
delay(100);
autoDrive(-1,100);
delay(100);
mobileGoalTwenty(1, 10);
delay(100);
//scored second side 20
autoDrive(-1,300);
delay(100);
gyroTurnPID(-1,187,1500,4,5);
autoDrive(-1,300);
mobileGoalTen(1,-420);
delay(100);
autoDrive(-1,100);
delay(100);
autoDrive(1,200);
delay(400);
mobileGoalTen(-1,-235);
delay(100);
//scoring extra mobile goal



gyroTurnPID(1,59,1500,4,5);
delay(100);
mobileGoalTwenty(-1, 1545);
delay(200);
autoDrive(1,1300);
delay(500);
mobileGoalTwenty(1, 10);
delay(100);
//returning to score last 10 point (20 point intake)
/*autoDrive(-1,100);
delay(100);
gyroTurnPID(1,10,1000,4,5);
delay(100);*/
gyroTurnPID(-1,8,1500,4,5);
autoDrive(-1,700);
delay(100);
gyroTurnPID(1,45,1200,4,5);
delay(100);
autoDrive(-1,850);
delay(100);
gyroTurnPID(1,90,1000,4,5);
delay(100);
autoDrive(1,190);
/////mobile goal scoring
mobileGoalTwenty(-1,1545);
delay(100);
autoDrive(1,40);///////////////new
delay(100);
autoDrive(-1,100);
delay(100);
mobileGoalTwenty(1,10);
delay(100);
autoDrive(-1,220);
delay(100);
gyroTurnPID(-1,50,1000,4,5);
mobileGoalTen(1,-420);
autoDrive(-1,1500);
stop();
break;

case 2:
mobileGoalTwenty(-1,1545);
delay(200);
autoDrive(1,1200);
delay(400);
mobileGoalTwenty(1, 10);
delay(100);
autoDrive(-1,700);
delay(100);
gyroTurnPID(1,145,1500,4,5);
delay(400);
autoDrive(1,200);
delay(100);
mobileGoalTwenty(-1,1545);
delay(100);
autoDrive(1,100);
delay(100);
autoDrive(-1,350);
delay(100);
//got 20


stop();
break;

case 4:
autoDrive(1,1500);
gyroTurnPID(-1,136,1500,4,5);
mobileGoalTwenty(-1,1545);
//got 20


stop();
break;
case 3:
mobileGoalTwenty(-1,1545);
delay(200);
autoDrive(1,1200);
delay(400);
mobileGoalTwenty(1, 10);
delay(100);
autoDrive(-1,700);
delay(100);
gyroTurnPID(-1,145,1500,4,5);
delay(400);
autoDrive(1,200);
delay(100);
mobileGoalTwenty(-1,1545);
delay(100);
autoDrive(1,100);
delay(100);
autoDrive(-1,350);
delay(100);
stop();
break;

case 5:
mobileGoalTwenty(-1,1545);
delay(200);
autoDrive(1,1200);
delay(400);
mobileGoalTwenty(1, 10);
delay(100);
autoDrive(-1,300);
delay(100);
gyroTurnPID(-1,210,1500,4,5);
delay(400);
autoDrive(1,200);
delay(100);
mobileGoalTwenty(-1,1545);
delay(100);
autoDrive(1,100);
delay(100);
autoDrive(-1,350);
delay(100);
stop();
break;

case 6:
mobileGoalTwenty(-1,1545);
delay(200);
autoDrive(1,1200);
delay(400);
mobileGoalTwenty(1, 10);
delay(100);
autoDrive(-1,300);
delay(100);
gyroTurnPID(1,210,1500,4,5);
delay(400);
autoDrive(1,200);
delay(100);
mobileGoalTwenty(-1,1545);
delay(100);
autoDrive(1,100);
delay(100);
autoDrive(-1,350);
delay(100);
stop();
break;
}

}
