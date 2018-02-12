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

 	//mg all the way in 1820
 	//mg all the way out 235
 	//mg score 1400
 	//mg pick up safe 800

// fourbar up is -127
//fourbar down is 127
 switch(myauto){
   case 1: //right side two cones
rollerSet(-20);
   lift(1,-40);//liftup
   mobileGoalTwenty(1,235);//out

   autoDrive(-1,1280);//drive to mobile goal
   delay(300);//pause
   mobileGoalTwenty(-1,1820);//pickup mg

   fourADown();//flip out fourbar
   fourAUp();//scoring first cone

   lift(-1,5);//put cone down on mg
   rollerSet(80);//outtake rollers
   delay(550);

  // lift(1,-80);//lift up while outtaking

   rollerSet(0);//stop rollers

/////second cone

   autoDrive(-1,140);//drive forward towards next cone
   rollerSet(-127);//intake
   delay(200);
   autoDrive(1,10);
   fourADown();
   lift(-1,10);
   delay(600);
   rollerSet(-15);//hold cone

   //lift(1,-35);//raise lift stack
   fourAUp();
   lift(-1,0);//four bar up and arm down


   rollerSet(78);//outtake
   delay(600);
   lift(1,-40);//lift up while outtaking
   rollerSet(0);


///////// third cone

/*

   fourADown();//fourbar down

   autoDrive(-1,60);//drive forward towards next cone
   rollerSet(-127);//intake
   delay(300);
   autoDrive(1,25);
   delay(200);
   lift(-1,10);//drop arm a bit
   fourADown();
   lift(-1,10);
   delay(1000);
   rollerSet(-15);//hold cone

   lift(1,-50);//raise lift stack
   fourAUp();
   lift(-1,0);//four bar up and arm down

   rollerSet(78);//outtake
   delay(600);
   lift(1,-100);//lift up while outtaking
   rollerSet(0);
*/
////drive back score

   autoDrive(1,1100);//drive back halfway//1200 with 3 cone
   gyroTurn(1,43);//first turn

   autoDrive(1,550);//drive AlONG 10 point pipe
   gyroTurn(1,73);//78 squareup with pipe

   autoDrive(-1,650);// drive inside zone
  mobileGoalTwenty(1,405); //score mg in 20 point
  autoDrive(-1,90);
  autoDrive(1,100);//jiggle drive to push mg further inside
  mobileGoalTwenty(-1,1820);//mobile goal lift back inside
  autoDrive(1,400);//drive out of the shit
  stop();

   break;

   case 2: //left 2 cones
   rollerSet(-20);
      lift(1,-40);//liftup
      mobileGoalTwenty(1,235);//out

      autoDrive(-1,1280);//drive to mobile goal
      delay(300);//pause
      mobileGoalTwenty(-1,1820);//pickup mg

      fourADown();//flip out fourbar
      fourAUp();//scoring first cone

      lift(-1,5);//put cone down on mg
      rollerSet(80);//outtake rollers
      delay(550);

     // lift(1,-80);//lift up while outtaking

      rollerSet(0);//stop rollers

   /////second cone

      autoDrive(-1,140);//drive forward towards next cone
      rollerSet(-127);//intake
      delay(200);
      autoDrive(1,10);
      fourADown();
      lift(-1,10);
      delay(600);
      rollerSet(-15);//hold cone

      //lift(1,-35);//raise lift stack
      fourAUp();
      lift(-1,0);//four bar up and arm down


      rollerSet(78);//outtake
      delay(600);
      lift(1,-40);//lift up while outtaking
      rollerSet(0);


   ///////// third cone

   /*

      fourADown();//fourbar down

      autoDrive(-1,60);//drive forward towards next cone
      rollerSet(-127);//intake
      delay(300);
      autoDrive(1,25);
      delay(200);
      lift(-1,10);//drop arm a bit
      fourADown();
      lift(-1,10);
      delay(1000);
      rollerSet(-15);//hold cone

      lift(1,-50);//raise lift stack
      fourAUp();
      lift(-1,0);//four bar up and arm down

      rollerSet(78);//outtake
      delay(600);
      lift(1,-100);//lift up while outtaking
      rollerSet(0);
   */
   ////drive back score

      autoDrive(1,1100);//drive back halfway//1200 with 3 cone
      gyroTurn(-1,43);//first turn

      autoDrive(1,550);//drive AlONG 10 point pipe
      gyroTurn(-1,73);//78 squareup with pipe

      autoDrive(-1,650);// drive inside zone
     mobileGoalTwenty(1,405); //score mg in 20 point
     autoDrive(-1,90);
     autoDrive(1,100);//jiggle drive to push mg further inside
     mobileGoalTwenty(-1,1820);//mobile goal lift back inside
     autoDrive(1,400);//drive out of the shit
     stop();

      break;
   case 3:
   fourbar(1,1200);
   delay(400);
   fourbar(-1,3200);
   delay(400);
   mobileGoalTwenty(-1,1820);
   delay(400);
   mobileGoalTwenty(1,235);
   delay(400);
   gyroTurnPID(1,200,2000,4,5);
   delay(400);

   stop();
   break;

   case 4: /////
   ////// 5 point right side
   lift(1,-105);
   mobileGoalTwenty(-1,1820);//out
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
   mobileGoalTwenty(-1,1820);//out
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

   case 6: //intaking cones run

lift(1,-200);
lift(-1,1);
lift(1,-100);
lift(-1,0);

delay(500);


  stop();


}
}
