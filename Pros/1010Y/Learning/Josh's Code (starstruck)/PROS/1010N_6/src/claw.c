#include "main.h"
#include "claw.h"
#include "util.h"
#include "pid.h"

void clawtask(void*ignore){

    PID_init(&pid_claw, 1.0, 0, 0, 0);
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
        claw_target_global = encoderGet(encoder_CLAW) + 26;}//26
  else if(joystickGetDigital(1, 5, JOY_DOWN)){// main down
      motorset_claw(-127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) -20;}//20

  else if(joystickGetDigital(2, 6, JOY_DOWN)){ //  partner down
      motorset_claw(-127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) -20;}

  else if(joystickGetDigital(2, 6, JOY_UP)){ //  partner up
      motorset_claw(127); //cloase
        claw_target_global = encoderGet(encoder_CLAW) + 26;}


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

/*
  if(joystickGetDigital(1,7,JOY_UP)){claw_target_global = CLAW_CLOSED;}
    else if(joystickGetDigital(1,7,JOY_DOWN)){claw_target_global = CLAW_MAX;}
    else if(joystickGetDigital(1,7,JOY_LEFT)){claw_target_global = CLAW_45;}
    else if(joystickGetDigital(1,7,JOY_RIGHT)){claw_target_global = CLAW_PARALLEL;}

    else if (joystickGetDigital(2,7,JOY_UP)){claw_target_global = CLAW_CLOSED;}
    else if(joystickGetDigital(2,7,JOY_DOWN)){claw_target_global = CLAW_MAX;}
    else if(joystickGetDigital(2,7,JOY_LEFT)){claw_target_global = CLAW_PARALLEL;}
    else if(joystickGetDigital(2,7,JOY_RIGHT)){claw_target_global = CLAW_45;}

    else{}

    */
}
