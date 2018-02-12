#include "main.h"
#include "arm.h"
#include "util.h"
#include "pid.h"
#include "autofunctions.h"

//position definitions
#define ARM_UP 100
#define ARM_DOWN 60

#define MAX_POWER_ARM 30 // used to stop arm from stalling under max load. holding power cant exced 30

//arm control task code - same for auto and op control
void armtask (void*ignore){

    //////////////////////////////////////////////
    // arm task works by changing target value by buttons, then updating a pid loop to the new target
    // min and max values limit error and target values
    // loop is broken and task ended when robot is disabled
    //////////////////////////////////////////////

  //arm pid loops terms init
  PID_init(&pidarm_auto, 0.8, 0, 0, 0); // was 0.4
  PID_init(&pidarm_op, 0.8, 0, 0, 0);
  arm_target_global = encoderGet(encoder_ARM); // difference set to zero

  while(true){
    if(!isEnabled()){break;} // when disabled, arm task ends - allows for new tassk ot be started when enabled

    // unused - purpose was to predict vel of arm and reduced op_control lag
    int arm_pos_last = arm_pos_global;
    int arm_vel = abs(arm_pos_global - arm_pos_last);

    arm_pos_global = encoderGet(encoder_ARM); // arm position update

// LARGE IF TREE - gives prioity to arm control

// controller main
if(joystickGetDigital(1, 6, JOY_UP)){  arm_target_global = arm_target_global + 10;} // was 12
  else if(joystickGetDigital(1, 6, JOY_DOWN)) { arm_target_global = arm_target_global- 10;} // was 12 //CHECKK: speed free, speed load


//if(joystickGetDigital(2, 6, JOY_UP)) {  arm_target_global = arm_target_global + 13;}
//if(joystickGetDigital(2, 6, JOY_DOWN)) { arm_target_global = arm_target_global- 13;}


//limits error, and therefore power, supplied to arm
// parameter for the else if is = error - maxpower*kp
//kp is 0.8, should be changed to varible
  else if((((arm_target_global-arm_pos_global)) > (MAX_POWER_ARM/0.8))&&!isAutonomous()){ // positive over shoot
    arm_target_global = arm_pos_global + (MAX_POWER_ARM/0.8);}
  else if((((arm_target_global-arm_pos_global)) < -(MAX_POWER_ARM/0.8))&&!isAutonomous()){ // negitive over shoot
    arm_target_global = arm_pos_global - (MAX_POWER_ARM/0.8);}

//arm max down
//else if is allowing joystick holding
if((arm_target_global < -30 )&&(!joystickGetDigital(1, 7, JOY_DOWN))) {  arm_target_global  = -30; }
  else if((arm_target_global< -150)){  arm_target_global = -150;}

//arm max up
if(arm_target_global > 657)  {  arm_target_global  = 657; }



if(isAutonomous()){motorset_arm( PID_cal(&pidarm_auto, arm_target_global, arm_pos_global) );} // arm pid calculate for auto
else{motorset_arm( PID_cal(&pidarm_op, arm_target_global, arm_pos_global) );} // else, arm pid calculate for op_control

    delay(20);

    }

  motorset_arm(0);
  taskDelete(arm_task); // when loop break (i.e robot not enabled)
  }

void armpresets(){ // presets function - uses buttons to set new arm target global
  if(joystickGetDigital(1,8,JOY_UP)){arm_target_global = 520;}
    else if(joystickGetDigital(1,8,JOY_DOWN)){arm_target_global = -30;}
    else if (joystickGetDigital(1,8,JOY_LEFT)){arm_target_global = 175;}
    //else if(joystickGetDigital(1,8,JOY_RIGHT)){arm_target_global = ARM_PARALLEL;}
  }
