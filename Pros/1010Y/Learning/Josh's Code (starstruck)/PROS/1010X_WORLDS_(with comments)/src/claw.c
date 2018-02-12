#include "main.h"
#include "claw.h"
#include "util.h"
#include "pid.h"
#include "arm.h"
#include "autofunctions.h"

// for presets (not used)
#define CLAW_OPEN 50
#define CLAW_CLOSED 50

#define MAX_POWER_CLAW 30 // was 20 // was 25

// claw control base code
void clawtask(void*ignore){

    PID_init(&pid_claw, 0.5, 0, 0, 0); // was 2 // PID init
    claw_target_global = encoderGet(encoder_CLAW); // set to difference to zero

    // debugging varbiles
    test_clawup = 100;
    test_clawdown = 100;


/*
PID_init(&pid_claw_L, 0.5, 0, 0, 0);
PID_init(&pid_claw_R, 0.5, 0, 0, 0);
*/

while(true){
  if(!isEnabled()){break;} // break when robot disabled

  claw_pos_global = encoderGet(encoder_CLAW); // update claw position

/* // OLD CLAW CODE//
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

//////////////////////////////////////////////
// arm task works by changing target value by buttons, then updating a pid loop to the new target
// min and max values limit error and target values
// loop is broken and task ended when robot is disabled
//////////////////////////////////////////////

// if case controlling pid loop
if(joystickGetDigital(1, 5, JOY_UP)) {  claw_target_global = claw_target_global + 18;} // consnat 18 to reduce button lag
else if(joystickGetDigital(1, 5, JOY_DOWN)) { claw_target_global = claw_target_global- 18;} // was 13
else if(joystickGetDigital(2, 6, JOY_UP)) {  claw_target_global = claw_target_global + 18;}
else if(joystickGetDigital(2, 6, JOY_DOWN)) { claw_target_global = claw_target_global- 18;}

//to be tested below =working

//limits error, and therefore power, supplied to claw
// parameter for the else if is = error - maxpower*kp
//kp is 0.5, should be changed to varible
else if(((claw_target_global-claw_pos_global)> (MAX_POWER_CLAW/0.5))&&!isAutonomous()){
  claw_target_global = claw_pos_global + (MAX_POWER_CLAW/0.5);}
else if((((claw_target_global-claw_pos_global)) < -(MAX_POWER_CLAW/0.5))&&!isAutonomous()){
  claw_target_global = claw_pos_global - (MAX_POWER_CLAW/0.5);}

///CODE FOR c_release

else if(c_release){ // check is function is enabled (see autofunctions.c, void claw_release2)

  c_release_start_time = millis(); // for timeout
  c_release_net_time = 0; // for timeout

  while((c_release_net_time < c_release_timeout)&&(arm_pos_global < c_release_arm)){ // cehcks timout and arm position
    c_release_net_time = millis() - c_release_start_time; // updates time
    delay(20);
    }
  claw_target_global = c_release_target; // sets new claw target, release claw
  c_release = false; // notes that function has ended (no repeat)
  }

  else if (c_hang){ // cehcks i fcuntion is enabled (see autofunctions.c, void claw_hang)

    while((arm_pos_global < c_hang_arm)){ // checks for arm position
      delay(20);
      }
    claw_target_global = c_hang_target; // updates claw, opening it to lock
    c_release = false; // notes that function has ended )no repeat
    }

    if((claw_target_global > 20 )&&(!isAutonomous())) {  claw_target_global  = 20; } // out for new bot:
    // global max

    motorset_claw(PID_cal(&pid_claw, claw_target_global, claw_pos_global)); // calculates claw PID

      delay(20);
      }
    motorset_claw(0);
    taskDelete(claw_task); // ends task when loop breaks (robot is disabled)

  }

void clawpresets(){ // claw presers (not used), required to be removed for worlds

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
