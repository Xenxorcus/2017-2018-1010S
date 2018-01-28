#include "main.h"
#include "arm.h"
#include "util.h"
#include "pid.h"
#include "autofunctions.h"

#define ARM_UP 100
#define ARM_DOWN 60

#define MAX_POWER_ARM 30
void armtask (void*ignore){

  PID_init(&pidarm_auto, 0.8, 0, 0, 0); // was 0.4
  PID_init(&pidarm_op, 0.8, 0, 0, 0);
  arm_target_global = encoderGet(encoder_ARM);

  while(true){
    if(!isEnabled()){break;}

    int arm_pos_last = arm_pos_global;
    arm_pos_global = encoderGet(encoder_ARM);
    int arm_vel = abs(arm_pos_global - arm_pos_last);

if(joystickGetDigital(1, 6, JOY_UP)){  arm_target_global = arm_target_global + 12;}
else if(joystickGetDigital(1, 6, JOY_DOWN)) { arm_target_global = arm_target_global- 12;}
//if(joystickGetDigital(2, 6, JOY_UP)) {  arm_target_global = arm_target_global + 13;}
//if(joystickGetDigital(2, 6, JOY_DOWN)) { arm_target_global = arm_target_global- 13;}
else if((((arm_target_global-arm_pos_global)) > (MAX_POWER_ARM/0.8))&&!isAutonomous()){
  arm_target_global = arm_pos_global + (MAX_POWER_ARM/0.8);}
else if((((arm_target_global-arm_pos_global)) < -(MAX_POWER_ARM/0.8))&&!isAutonomous()){
  arm_target_global = arm_pos_global - (MAX_POWER_ARM/0.8);}

if(arm_target_global < -22 ) {  arm_target_global  = -22; }
if(arm_target_global > 657)  {  arm_target_global  = 657; }



if(isAutonomous()){motorset_arm( PID_cal(&pidarm_auto, arm_target_global, arm_pos_global) );}
else{motorset_arm( PID_cal(&pidarm_op, arm_target_global, arm_pos_global) );}

    delay(20);

    }

  motorset_arm(0);
  taskDelete(arm_task);
  }

void armpresets(){
  if(joystickGetDigital(1,8,JOY_UP)){arm_target_global = ARM_SKILLS_1;}
    else if(joystickGetDigital(1,8,JOY_DOWN)){arm_target_global = ARM_GROUND;}
    //else if (joystickGetDigital(1,8,JOY_LEFT)){arm_target_global = ARM_LOW;}
    //else if(joystickGetDigital(1,8,JOY_RIGHT)){arm_target_global = ARM_PARALLEL;}
    else{}
  }
