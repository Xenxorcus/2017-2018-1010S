#include "main.h"
#include "clawpidterms.h"
#include <math.h>

void drive_clawcontrol (void *ignore)
{
  int power_L;
  int power_R;

  int clawdiff;
  int lastdiff;

  int proportion;
  int integral;
  int derivative;

  clawtarget = analogRead(potclaw);

  while(true){

    //set value
    claw_pos = analogRead(potclaw);

    //find error
    clawdiff = clawtarget - claw_pos;

    //calculate P
    proportion = clawdiff;

    //intergral cap+calcualte I
    if(abs(clawdiff) < claw_integral_activezone){
    integral = integral + (clawdiff);}
    else{integral = 0;}

    //calculate D
    derivative =  clawdiff - lastdiff;
    lastdiff = clawdiff;

    //calculate power values
    power_L = (derivative*claw_k_derivative) + (integral*claw_k_integral)+(proportion*claw_k_proportion);
    power_R = (derivative*claw_k_derivative) + (integral*claw_k_integral)+(proportion*claw_k_proportion);


    if(joystickGetDigital(1,5,JOY_UP)){
      motorSet(ClawL, ClawL_Dir*127);
      motorSet(ClawR, ClawR_Dir*127);
      delay(claw_deaccel_delay);
      clawtarget = analogRead(potclaw);}

    else if(joystickGetDigital(1,5,JOY_DOWN)){
      motorSet(ClawL, ClawL_Dir*-127);
      motorSet(ClawR, ClawR_Dir*-127);
      delay(claw_deaccel_delay);
      clawtarget = analogRead(potclaw);}

    else if (joystickGetAnalog(2, 2) > claw_joystickrange){
      motorSet(ClawL, ClawL_Dir*joystickGetAnalog(2, 2));
      motorSet(ClawR, ClawR_Dir*joystickGetAnalog(2, 2));
      delay(claw_deaccel_delay);
      clawtarget = analogRead(potclaw);}

    else if (joystickGetAnalog(2, 2) < -claw_joystickrange){
      motorSet(ClawL, ClawL_Dir*joystickGetAnalog(2, 2));
      motorSet(ClawR, ClawR_Dir*joystickGetAnalog(2, 2));
      delay(claw_deaccel_delay);
      clawtarget = analogRead(potclaw);}

    else {
      motorSet(ClawL, ClawL_Dir*power_L);
      motorSet(ClawR, ClawR_Dir*power_R);}

  //delay
    delay(20);
    }
  }
void clawpresets(){
    if(joystickGetDigital(1,7,JOY_UP)){
      clawtarget = CLAW_MAX;}
    else if(joystickGetDigital(1,7,JOY_DOWN)){
      clawtarget = CLAW_CLOSED;}
    else if (joystickGetDigital(1,7,JOY_LEFT)){
      clawtarget = CLAW_SEMI_OPEN;}
    else if(joystickGetDigital(1,7,JOY_RIGHT)){}
    else{}
  }

void auto_clawcontrol (void *ignore)
  {
    int power_L;
    int power_R;

    int clawdiff;
    int lastdiff;

    int proportion;
    int integral;
    int derivative;

    clawtarget = analogRead(potclaw);

    while(true){

      //set value
      claw_pos = analogRead(potclaw);

      //find error
      clawdiff = clawtarget - claw_pos;

      //calculate P
      proportion = clawdiff;

      //intergral cap+calcualte I
      if(abs(clawdiff) < claw_integral_activezone){
      integral = integral + (clawdiff);}
      else{integral = 0;}

      //calculate D
      derivative =  clawdiff - lastdiff;
      lastdiff = clawdiff;

      //calculate power values
      power_L = (derivative*claw_k_derivative) + (integral*claw_k_integral)+(proportion*claw_k_proportion);
      power_R = (derivative*claw_k_derivative) + (integral*claw_k_integral)+(proportion*claw_k_proportion);

      motorSet(ClawL, ClawL_Dir*power_L);
      motorSet(ClawR, ClawR_Dir*power_R);
    //delay
      delay(20);

      if(isAutonomous() )
        {}
        else{
      taskDelete(clawtaskpid_auto);}

    }

  }
