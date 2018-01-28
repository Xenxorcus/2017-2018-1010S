#include "main.h"
#include "arm.h"
#include "util.h"
#include "pid.h"

void armtask (void*ignore){

  PID_init(&pid_arm, 0.4, 0, 0, 0);
  arm_target_global = encoderGet(encoder_ARM);

//  test_armdown = 100;
//  test_armup = 100;

  while(true){
    if(!isEnabled()){break;}

    arm_pos_global = encoderGet(encoder_ARM);

    if(!isAutonomous() && joystickGetDigital(1, 6, JOY_UP)){

      motorset_arm(127);
      arm_target_global = encoderGet(encoder_ARM)+150;}

    else if(!isAutonomous() && joystickGetDigital(1, 6, JOY_DOWN)){

      motorset_arm(-127);
      arm_target_global = encoderGet(encoder_ARM)-50;}


    /*
    if(!isAutonomous() && (joystickGetDigital(1, 6, JOY_UP)||joystickGetDigital(1, 6, JOY_DOWN)))
      {
      while(joystickGetDigital(1, 6, JOY_UP)){
          motorset_arm(127);
          delay(20);}

      while(joystickGetDigital(1, 6, JOY_DOWN)){
          motorset_arm(-127);
          delay(20);}

      motorset_arm(0);
      delay(ARM_DELAY);
      arm_target_global = encoderGet(encoder_ARM);
      }
      */

  //if(!joystickGetDigital(1, 6, JOY_UP)||!joystickGetDigital(1, 6, JOY_DOWN)){

else{
   motorset_arm( PID_cal(&pid_arm, arm_target_global, arm_pos_global) );}

    delay(20);

    }

  motorset_arm(0);
  taskDelete(arm_task);
  }

void armpresets(){
  if(joystickGetDigital(1,8,JOY_UP)){arm_target_global = ARM_MAX;}
    else if(joystickGetDigital(1,8,JOY_DOWN)){arm_target_global = ARM_GROUND;}
    else if (joystickGetDigital(1,8,JOY_LEFT)){arm_target_global = ARM_LOW;}
    else if(joystickGetDigital(1,8,JOY_RIGHT)){arm_target_global = ARM_PARALLEL;}
    else{}
  }
