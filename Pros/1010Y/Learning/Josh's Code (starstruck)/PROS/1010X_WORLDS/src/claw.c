#include "main.h"
#include "claw.h"
#include "util.h"
#include "pid.h"
#include "arm.h"
#include "autofunctions.h"

#define CLAW_OPEN 50
#define CLAW_CLOSED 50

#define MAX_POWER_CLAW 30 // was 20 // was 25
void clawtask(void*ignore){

    PID_init(&pid_claw, 0.5, 0, 0, 0); // was 2
    claw_target_global = encoderGet(encoder_CLAW);

    test_clawup = 100;
    test_clawdown = 100;


/*
PID_init(&pid_claw_L, 0.5, 0, 0, 0);
PID_init(&pid_claw_R, 0.5, 0, 0, 0);
*/

while(true){
  if(!isEnabled()){break;}

  claw_pos_global = encoderGet(encoder_CLAW);

/*
  if(joystickGetDigital(1, 5, JOY_UP)){//main up

      //delay(40);
      while(joystickGetDigital(1, 5, JOY_UP)){
      motorset_claw(127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) + CLAW_CLOSED;}
        motorset_claw(-40);
        delay(75);

      }
      // was 26
  else if(joystickGetDigital(1, 5, JOY_DOWN)){// main down
      //delay(40);
      while(joystickGetDigital(1, 5, JOY_DOWN)){
      motorset_claw(-127); //cloase
      claw_target_global = encoderGet(encoder_CLAW) - CLAW_OPEN;}
        motorset_claw(40);
        delay(75);
    }//was 20

  else if(joystickGetDigital(2, 6, JOY_DOWN)){ //  partner down
      motorset_claw(-127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) - CLAW_CLOSED;}// was 20

  else if(joystickGetDigital(2, 6, JOY_UP)){ //  partner up
      motorset_claw(127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) + CLAW_OPEN;}// was 26



else if(c_release){

  c_release_start_time = millis();
  c_release_net_time = 0;

  while((c_release_net_time < c_release_timeout)&&(arm_pos_global < c_release_arm)){
    c_release_net_time = millis() - c_release_start_time;
    delay(20);
    }
  claw_target_global = c_release_target;
  c_release = false;
  }

  else if (c_hang){

    while((arm_pos_global < c_hang_arm)){
      delay(20);
      }
    claw_target_global = c_hang_target;
    c_release = false;
    }

  else{
        //delay(80);
      motorset_claw(PID_cal(&pid_claw, claw_target_global, claw_pos_global));

      //motorSet(ClawL, ClawL_Dir*( PID_cal(&pid_claw_L, claw_target_global_L, claw_pos_global_L)));
      //motorSet(ClawR, ClawL_Dir*( PID_cal(&pid_claw_R, claw_target_global_R, claw_pos_global_R)));
      }

*/

////////////////////////////////////////////////////////////////////////
       // code for new p controoller = need velcontorl
if(joystickGetDigital(1, 5, JOY_UP)) {  claw_target_global = claw_target_global + 18;}
else if(joystickGetDigital(1, 5, JOY_DOWN)) { claw_target_global = claw_target_global- 18;} // was 13
else if(joystickGetDigital(2, 6, JOY_UP)) {  claw_target_global = claw_target_global + 18;}
else if(joystickGetDigital(2, 6, JOY_DOWN)) { claw_target_global = claw_target_global- 18;}

//to be tested below
else if(((claw_target_global-claw_pos_global)> (MAX_POWER_CLAW/0.5))&&!isAutonomous()){
  claw_target_global = claw_pos_global + (MAX_POWER_CLAW/0.5);}
else if((((claw_target_global-claw_pos_global)) < -(MAX_POWER_CLAW/0.5))&&!isAutonomous()){
  claw_target_global = claw_pos_global - (MAX_POWER_CLAW/0.5);}

else if(c_release){

  c_release_start_time = millis();
  c_release_net_time = 0;

  while((c_release_net_time < c_release_timeout)&&(arm_pos_global < c_release_arm)){
    c_release_net_time = millis() - c_release_start_time;
    delay(20);
    }
  claw_target_global = c_release_target;
  c_release = false;
  }

  else if (c_hang){

    while((arm_pos_global < c_hang_arm)){
      delay(20);
      }
    claw_target_global = c_hang_target;
    c_release = false;
    }

    if((claw_target_global > 20 )&&(!isAutonomous())) {  claw_target_global  = 20; } // out for new bot:
    // global max
    
    motorset_claw(PID_cal(&pid_claw, claw_target_global, claw_pos_global));

      delay(20);
      }
    motorset_claw(0);
    taskDelete(claw_task);

  }

void clawpresets(){

  //  if(joystickGetDigital(1,7,JOY_UP)){claw_target_global = CLAW_PARALLEL;}
  //  else if(joystickGetDigital(1,7,JOY_DOWN)){claw_target_global = CLAW_MAX;}
  //  else if(joystickGetDigital(1,7,JOY_LEFT)){claw_target_global = CLAW_45;}
  //  else if(joystickGetDigital(1,7,JOY_RIGHT)){claw_target_global = CLAW_PARALLEL;}

    if(joystickGetDigital(2,8,JOY_DOWN)){claw_target_global = -200;}
    //else if(joystickGetDigital(2,7,JOY_DOWN)){claw_target_global = CLAW_MAX;}
  //  else if(joystickGetDigital(2,7,JOY_LEFT)){claw_target_global = CLAW_PARALLEL;}
  //  else if(joystickGetDigital(2,7,JOY_RIGHT)){claw_target_global = CLAW_45;}

    else{}


}
