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
   lift(1,-25);//liftup
  // mobileGoalTwenty(1,235);//out
mgSet(-127);
autoDrive(-1,800);
mgSet(0);
autoDrive(-1,480);

//   autoDrive(-1,1280);//drive to mobile goal
   delay(300);//pause
   mobileGoalTwenty(-1,1820);//pickup mg

   fourADown();//flip out fourbar
   fourAUp();//scoring first cone

   lift(-1,5);//put cone down on mg
   rollerSet(80);//outtake rollers
   delay(600);

  // lift(1,-80);//lift up while outtaking

   rollerSet(0);//stop rollers

/////second cone

   autoDrive(-1,140);//drive forward towards next cone
   rollerSet(-127);//intake
   delay(100);
   autoDrive(1,20);
   fourSet(90);
   lift(-1,0);
   delay(400);
   fourSet(90);
   delay(250);
   autoDrive(1,40);
   delay(400);
   rollerSet(-15);//hold cone

   lift(1,-10);//raise lift stack
   fourAUp();
    lift(-1,0);//drop


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

   autoDrive(1,1245);//drive back halfway//1200 with 3 cone
   gyroTurn(1,43);//first turn

   autoDrive(1,580);//drive AlONG 10 point pipe
   gyroTurn(1,73);//78 squareup with pipe

   autoDrive(-1,575);// drive inside zone
  mobileGoalTwenty(1,405); //score mg in 20 point
  autoDrive(-1,50);
  autoDrive(1,100);//jiggle drive to push mg further inside
  mobileGoalTwenty(-1,600);//mobile goal lift back inside
  autoDrive(1,400);//drive out of the shit
  stop();

   break;

   case 2: //left 2 cones

rollerSet(-20);
   lift(1,-25);//liftup
  // mobileGoalTwenty(1,235);//out
mgSet(-127);
autoDrive(-1,800);
mgSet(0);
autoDrive(-1,480);

//   autoDrive(-1,1280);//drive to mobile goal
   delay(300);//pause
   mobileGoalTwenty(-1,1820);//pickup mg

   fourADown();//flip out fourbar
   fourAUp();//scoring first cone

   lift(-1,5);//put cone down on mg
   rollerSet(80);//outtake rollers
   delay(600);

  // lift(1,-80);//lift up while outtaking

   rollerSet(0);//stop rollers

/////second cone

   autoDrive(-1,140);//drive forward towards next cone
   rollerSet(-127);//intake
   delay(100);
   autoDrive(1,20);
   fourSet(90);
   lift(-1,0);
   delay(400);
   fourSet(90);
   delay(250);
   autoDrive(1,40);
   delay(500);
   rollerSet(-15);//hold cone

   lift(1,-10);//raise lift stack
   fourAUp();
    lift(-1,0);//drop


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

   autoDrive(1,1150);//drive back halfway//1200 with 3 cone
   gyroTurn(-1,43);//first turn

   autoDrive(1,500);//drive AlONG 10 point pipe
   gyroTurn(-1,73);//78 squareup with pipe

   autoDrive(-1,575);// drive inside zone
  mobileGoalTwenty(1,405); //score mg in 20 point
  autoDrive(-1,50);
  autoDrive(1,130);//jiggle drive to push mg further inside
  mobileGoalTwenty(-1,600);//mobile goal lift back inside
  autoDrive(1,400);//drive out of the shit
  stop();

   break;

/*rollerSet(-20);
   lift(1,-25);//liftup
  // mobileGoalTwenty(1,235);//out
mgSet(-127);
autoDrive(-1,800);
mgSet(0);
autoDrive(-1,480);

//   autoDrive(-1,1280);//drive to mobile goal
   delay(300);//pause
   mobileGoalTwenty(-1,1820);//pickup mg

   fourADown();//flip out fourbar
   fourAUp();//scoring first cone

   lift(-1,5);//put cone down on mg
   rollerSet(80);//outtake rollers
   delay(600);

  // lift(1,-80);//lift up while outtaking

   rollerSet(0);//stop rollers

/////second cone

   autoDrive(-1,140);//drive forward towards next cone
   rollerSet(-127);//intake
   delay(100);
   autoDrive(1,20);
   fourSet(90);
   lift(-1,0);
   delay(400);
   fourSet(90);
   delay(250);
   autoDrive(1,40);
   rollerSet(-15);//hold cone

   lift(1,-10);//raise lift stack
   fourAUp();
    lift(-1,0);//drop


   rollerSet(78);//outtake
   delay(600);
   lift(1,-40);//lift up while outtaking
   rollerSet(0);

   autoDrive(1,1245);//drive back halfway//1200 with 3 cone
   gyroTurn(-1,43);//first turn

   autoDrive(1,625);//drive AlONG 10 point pipe
   gyroTurn(-1,73);//78 squareup with pipe

   autoDrive(-1,625);// drive inside zone
  mobileGoalTwenty(1,405); //score mg in 20 point
  autoDrive(-1,50);
  autoDrive(1,100);//jiggle drive to push mg further inside
  mobileGoalTwenty(-1,600);//mobile goal lift back inside
  autoDrive(1,400);//drive out of the shit
      break;
      /
      */
   case 3:

 rollerSet(-20);
    lift(1,-25);//liftup
   // mobileGoalTwenty(1,235);//out
 mgSet(-127);
 autoDrive(-1,800);
 mgSet(0);
 autoDrive(-1,480);

 //   autoDrive(-1,1280);//drive to mobile goal
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
    delay(100);
    autoDrive(1,20);
    fourADown();
    lift(-1,10);
    delay(600);
    rollerSet(-15);//hold cone

    //lift(1,-10);//raise lift stack
    fourAUp();


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

    autoDrive(1,1245);//drive back halfway//1200 with 3 cone
    gyroTurn(1,43);//first turn

    autoDrive(1,300);//drive AlONG 10 point pipe
    gyroTurn(1,73);//78 squareup with pipe

    autoDrive(-1,100);// drive inside zone
   mobileGoalTwenty(1,405); //score mg in 20 point
   autoDrive(-1,60);
   autoDrive(1,100);//jiggle drive to push mg further inside
   mobileGoalTwenty(-1,600);//mobile goal lift back inside
   autoDrive(1,200);//drive out of the shit
   stop();
   break;

   case 4://straight mobile goal one
   rollerSet(-20);
      lift(1,-25);//liftup
     // mobileGoalTwenty(1,235);//out
   mobileGoalTwenty(1,405);
   autoDrive(-1,500);

   //   autoDrive(-1,1280);//drive to mobile goal
      delay(300);//pause
      mobileGoalTwenty(-1,1820);//pickup mg

      fourADown();//flip out fourbar
      fourAUp();//scoring first cone

      lift(-1,5);//put cone down on mg
      rollerSet(80);//outtake rollers
      delay(600);

     // lift(1,-80);//lift up while outtaking

      rollerSet(0);//stop rollers

      gyroTurn(1,180);
      autoDrive(-1,400);
      gyroTurn(1,90);
      autoDrive(-1,200);
      gyroTurn(-1,90);
      autoDrive(-1,300);
      mobileGoalTwenty(1,405); //score mg in 20 point
      autoDrive(-1,50);
      autoDrive(1,100);//jiggle drive to push mg further inside
      mobileGoalTwenty(-1,600);//mobile goal lift back inside
      autoDrive(1,400);//drive out of the shit
      stop();

   break;

   case 5://auto 3 cones right
   rollerSet(-20);
      lift(1,-25);//liftup
    mobileGoalTwenty(1,235);//out
    autoDrive(-1,1280);//drive to mobile goal
      delay(300);//pause
      mobileGoalTwenty(-1,1820);//pickup mg

      fourADown();//flip out fourbar
      fourAUp();//scoring first cone

      lift(-1,5);//put cone down on mg
      rollerSet(80);//outtake rollers
      delay(600);

     // lift(1,-80);//lift up while outtaking

      rollerSet(0);//stop rollers

   /////second cone

      autoDrive(-1,140);//drive forward towards next cone
      rollerSet(-127);//intake
      delay(400);
      autoDrive(1,10);
      fourADown();
      lift(-1,10);
      delay(650);
      rollerSet(-15);//hold cone

      lift(1,-10);//raise lift stack
      fourAUp();
       lift(-1,0);//drop


      rollerSet(78);//outtake
      delay(600);
      lift(1,-40);//lift up while outtaking
      rollerSet(0);


   ///////// third cone


      fourADown();//fourbar down

      autoDrive(-1,60);//drive forward towards next cone
      rollerSet(-127);//intake
      delay(300);
      autoDrive(1,10);
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
      lift(1,-50);//lift up while outtaking
      rollerSet(0);

   ////drive back score

      autoDrive(1,1245);//drive back halfway//1200 with 3 cone
      gyroTurn(1,43);//first turn

      autoDrive(1,645);//drive AlONG 10 point pipe
      gyroTurn(1,73);//78 squareup with pipe

      autoDrive(-1,625);// drive inside zone

     mobileGoalTwenty(1,405); //score mg in 20 point
     delay(400);
     autoDrive(-1,20);
     autoDrive(1,100);//jiggle drive to push mg further inside
     mobileGoalTwenty(-1,600);//mobile goal lift back inside
     autoDrive(1,100);//drive out of the shit
     mobileGoalTwenty(-1,1820);//mobile goal lift back inside
     autoDrive(1,195);//drive out of the shit
     fourAUp();
     gyroTurn(-1,87);
     autoDrive(-1,180);
     gyroTurn(-1,87);
     mobileGoalTwenty(1,405);//pickup mg
     //straight part


     autoDrive(-1,500);

     //   autoDrive(-1,1280);//drive to mobile goal
        delay(300);//pause
        fourAUp();
        mobileGoalTwenty(-1,1820);//pickup mg

        gyroTurn(1,176);
        autoDrive(-1,600);
        mobileGoalTwenty(1,405); //score mg in 20 point
        autoDrive(-1,50);
        autoDrive(1,100);//jiggle drive to push mg further inside
        mobileGoalTwenty(-1,600);//mobile goal lift back inside
        autoDrive(1,400);//drive out of the shit
        stop();

      break;
   break;

   case 6: //intaking cones run
   break;
}
}
