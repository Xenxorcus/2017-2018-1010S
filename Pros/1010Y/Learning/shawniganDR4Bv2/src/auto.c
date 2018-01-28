#include "main.h"
#include "drive.h"
#include "lift.h"
#include "fourbar.h"
#include "mg.h"
#include "rollers.h"
#include "autofunctions.h"


void autonomous() {
 //back drive is 1
 //drive forwards is -1
 // 1 is clockwise
 //-1 is counterclockwise

//twenty all in out 3990
//twenty in 10
//ten out -490
//ten in-232

//mg20out -1
//mg20 in 1
 switch(myauto){
   case 1: //right blue coney preload stack
//fourbar(1,250);
  // fourbar(-1,500);
   lift(1,-105);
   mobileGoalTwenty(-1,3990);//out
   autoDrive(-1, 1280);
   delay(600);
   mgSet(127);
   delay(1500);
   mgSet(0);
   fourSet(127);
   delay(400);
   fourSet(0);
   autoDrive(1,1000);
   gyroTurn(1,45);
   autoDrive(1,210);//was300
   gyroTurn(1,73);//78
   autoDrive(-1,100);
   mgSet(-127);
   delay(1400);
   mgSet(0);
   lift(-1,0);
   delay(100);
   rollerSet(90);
   delay(200);
   lift(1,-115);
   delay(200);
   autoDrive(-1,30);///////////////new
   autoDrive(1,220);
   mgSet(127);
   delay(1400);
   mgSet(0);
   autoDrive(1,20);
   stop();
   break;

   case 2: //left blue coney preload stack
//fourbar(1,250);
  // fourbar(-1,500);
   lift(1,-105);
   mobileGoalTwenty(-1,3990);//out
   autoDrive(-1, 1280);
   delay(400);
   mgSet(127);
   delay(1500);
   mgSet(0);
   fourSet(127);
   delay(400);
   fourSet(0);
   autoDrive(1,1000);
   gyroTurn(-1,45);
   autoDrive(1,210);//was300
   gyroTurn(-1,73);//78
   autoDrive(-1,80);
   mgSet(-127);
   delay(1400);
   mgSet(0);
   lift(-1,0);
   delay(100);
   rollerSet(90);
   delay(200);
   lift(1,-115);
   delay(200);
   autoDrive(-1,30);///////////////new
   autoDrive(1,220);
   mgSet(127);
   delay(1500);
   mgSet(0);
   autoDrive(1,20);
   stop();
   break;

   case 3:
   mobileGoalTwenty(-1,2200);
   delay(400);
   mobileGoalTwenty(-1,3990);
   delay(400);
   mgSet(127);
   delay(400);
   mgSet(127);
   delay(400);
   stop();
   break;

   case 4: /////
   ////// 5 point right side
   lift(1,-105);
   mobileGoalTwenty(-1,3990);//out
   autoDrive(-1, 1280);
   delay(600);
   mgSet(127);
   delay(1500);
   mgSet(0);
   fourSet(127);
   delay(400);
   fourSet(0);
   autoDrive(1,450);
   gyroTurn(1,45);
   autoDrive(1,210);//was300
   gyroTurn(1,73);//78
   autoDrive(-1,100);
   mgSet(-127);
   delay(1400);
   mgSet(0);
   lift(-1,0);
   delay(100);
   rollerSet(90);
   delay(200);
   lift(1,-115);
   delay(200);
   autoDrive(-1,30);///////////////new
   autoDrive(1,220);
   mgSet(127);
   delay(1400);
   mgSet(0);
   autoDrive(1,20);
   stop();
   break;

   case 5: ////
   ////// 5 point left side
   lift(1,-105);
   mobileGoalTwenty(-1,3990);//out
   autoDrive(-1, 1280);
   delay(400);
   mgSet(127);
   delay(1500);
   mgSet(0);
   fourSet(127);
   delay(400);
   fourSet(0);
   autoDrive(1,450);
   gyroTurn(-1,45);
   autoDrive(1,210);//was300
   gyroTurn(-1,73);//78
   autoDrive(-1,80);
   mgSet(-127);
   delay(1400);
   mgSet(0);
   lift(-1,0);
   delay(100);
   rollerSet(90);
   delay(200);
   lift(1,-115);
   delay(200);
   autoDrive(-1,30);///////////////new
   autoDrive(1,220);
   mgSet(127);
   delay(1500);
   mgSet(0);
   autoDrive(1,20);
   stop();
   break;
}
}
