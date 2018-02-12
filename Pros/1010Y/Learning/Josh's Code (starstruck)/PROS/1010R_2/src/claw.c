#include "main.h"
#include "claw.h"
#include "util.h"
#include "pid.h"
#include "arm.h"

void clawtask(void*ignore){

    PID_init(&pid_claw, 3.3, 0, 0, 0); // was 2
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

  if(joystickGetDigital(1, 5, JOY_UP)){//main up
      motorset_claw(127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) + 12;}// was 26
  else if(joystickGetDigital(1, 5, JOY_DOWN)){// main down
      motorset_claw(-127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) -9.6;}//was 20

  else if(joystickGetDigital(2, 6, JOY_DOWN)){ //  partner down
      motorset_claw(-127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) -9.6;}// was 20

  else if(joystickGetDigital(2, 6, JOY_UP)){ //  partner up
      motorset_claw(127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) + 12;}// was 26


/*

  else if(joystickGetDigital(2, 7, JOY_UP)){ //override L up
      motorSet(ClawL, ClawL_Dir*127);
      claw_target_global_L = analogRead(clawpot_L) - claw_zero_L + CLAW_OFFSET_UP;}
    else if(joystickGetDigital(2, 7, JOY_DOWN)){ //override L down
      motorSet(ClawL, ClawL_Dir*-127);
      claw_target_global_L = analogRead(clawpot_L) - claw_zero_L + CLAW_OFFSET_DOWN;}

    else if(joystickGetDigital(2, 8, JOY_UP)){ //override R up
          motorSet(ClawR, ClawR_Dir*127);
          claw_target_global_R = analogRead(clawpot_R) - claw_zero_R + CLAW_OFFSET_UP;}
    else if(joystickGetDigital(2, 8, JOY_DOWN)){ //override R down
          motorSet(ClawR, ClawR_Dir*-127);
          claw_target_global_R = analogRead(clawpot_R) - claw_zero_R + CLAW_OFFSET_DOWN;}

      else if(joystickGetDigital(2, 8, JOY_RIGHT)){
        claw_zero_R = analogRead(clawpot_R);
      }
      else if(joystickGetDigital(2, 7, JOY_LEFT)){
        claw_zero_L = analogRead(clawpot_L);
      }
*/

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
      motorset_claw(PID_cal(&pid_claw, claw_target_global, claw_pos_global));

      //motorSet(ClawL, ClawL_Dir*( PID_cal(&pid_claw_L, claw_target_global_L, claw_pos_global_L)));
      //motorSet(ClawR, ClawL_Dir*( PID_cal(&pid_claw_R, claw_target_global_R, claw_pos_global_R)));
      }

      delay(20);
      }
    motorset_claw(0);
    taskDelete(claw_task);

  }

void clawpresets(){

    if(joystickGetDigital(1,7,JOY_UP)){claw_target_global = CLAW_PARALLEL;}
    else if(joystickGetDigital(1,7,JOY_DOWN)){claw_target_global = CLAW_MAX;}
  //  else if(joystickGetDigital(1,7,JOY_LEFT)){claw_target_global = CLAW_45;}
  //  else if(joystickGetDigital(1,7,JOY_RIGHT)){claw_target_global = CLAW_PARALLEL;}

    else if (joystickGetDigital(2,7,JOY_UP)){claw_target_global = CLAW_PARALLEL;}
    else if(joystickGetDigital(2,7,JOY_DOWN)){claw_target_global = CLAW_MAX;}
  //  else if(joystickGetDigital(2,7,JOY_LEFT)){claw_target_global = CLAW_PARALLEL;}
  //  else if(joystickGetDigital(2,7,JOY_RIGHT)){claw_target_global = CLAW_45;}

    else{}


}
