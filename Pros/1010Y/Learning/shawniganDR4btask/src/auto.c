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



//// task handles
TaskHandle mgAutoTask = taskCreate(mgTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
TaskHandle liftAutoTask = taskCreate(liftTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
TaskHandle fourAutoTask = taskCreate(fourTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
TaskHandle stackAutoTask = taskCreate(stackTask, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);



 switch(myauto){
   case 1: //right side two cones

   rollerSet(-20);
      liftGlobalTarget = -40;
      mgGlobalTarget = 235;//out

      autoDrive(-1,1280);//drive to mobile goal
      delay(300);//pause
      mgGlobalTarget = 1820;//pickup mg

      liftGlobalTarget = 5;
      fourADown();//flip out fourbar
      fourAUp();//scoring first cone

      rollerSet(80);//outtake rollers
      delay(550);
      rollerSet(0);//stop rollers

   /////second cone

      autoDrive(-1,140);//drive forward towards next cone
      rollerSet(-127);//intake
      delay(200);
      autoDrive(1,10);
      fourADown();
      lift(-1,10);
      autoDrive(-1,30);
      delay(600);
      rollerSet(-15);//hold cone

      //lift(1,-35);//raise lift stack
      stacking = 1;


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

      autoDrive(1,1130);//drive back halfway//1200 with 3 cone
      gyroTurn(1,43);//first turn

      autoDrive(1,550);//drive AlONG 10 point pipe
      gyroTurn(1,73);//78 squareup with pipe

      autoDrive(-1,650);// drive inside zone
     mgGlobalTarget = 405; //score mg in 20 point
     autoDrive(-1,90);
     autoDrive(1,100);//jiggle drive to push mg further inside
     mgGlobalTarget = 1820;//mobile goal lift back inside
     autoDrive(1,400);//drive out of the shit
     stop();

 }
}
