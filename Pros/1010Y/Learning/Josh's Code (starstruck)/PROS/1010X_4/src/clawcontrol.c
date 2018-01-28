#include "main.h"
#include "clawcontrol.h"
#include <math.h>

void clawcontrol (void *ignore)
  {
  int lasterror;
  int proportion;
  int integral;
  int derivative;
  int claw_off = 200;
  //set target to current
  claw_target = abs(analogRead(potclaw)+potclaw_direction);

  while(true){
    //set value
    claw_pos = abs(analogRead(potclaw)+potclaw_direction);

    //find error
    claw_error = claw_target - claw_pos;

    //calculate P
    proportion = claw_error;

    //intergral cap+calcualte I
    if(abs(claw_error) < claw_integral_activezone){integral = integral + (claw_error);}
    else{integral = 0;}

    //calculate D
    derivative =  claw_error - lasterror;
    lasterror = claw_error;

    //calculate power values
    claw_power_L = (derivative*claw_k_derivative) + (integral*claw_k_integral)+(proportion*claw_k_proportion);
    claw_power_R = (derivative*claw_k_derivative) + (integral*claw_k_integral)+(proportion*claw_k_proportion);
  //driver
    if(!isAutonomous() && isEnabled()){

        if(isEnabled()){}
        else{taskDelete(clawcontrol_drive);}

        if(joystickGetDigital(1,5,JOY_DOWN)){
          if(analogRead(potclaw) < 3400){
            motorSet(ClawL, ClawL_Dir*127);
            motorSet(ClawR, ClawR_Dir*127);
            delay(claw_deaccel_delay);
            claw_target = abs(analogRead(potclaw)+potclaw_direction)+claw_off;}
            }

        else if(joystickGetDigital(1,5,JOY_UP)){
          if(analogRead(potclaw)>200){
            motorSet(ClawL, ClawL_Dir*-127);
            motorSet(ClawR, ClawR_Dir*-127);
            delay(claw_deaccel_delay);
            claw_target = abs(analogRead(potclaw)+potclaw_direction)-claw_off;}
          }

          else if(joystickGetDigital(2,6,JOY_UP)){
            if(analogRead(potclaw) < 3400){
              motorSet(ClawL, ClawL_Dir*127);
              motorSet(ClawR, ClawR_Dir*127);
              delay(claw_deaccel_delay);
              claw_target = abs(analogRead(potclaw)+potclaw_direction)+claw_off;}
              }

          else if(joystickGetDigital(2,6,JOY_DOWN)){
            if(analogRead(potclaw)>200){
              motorSet(ClawL, ClawL_Dir*-127);
              motorSet(ClawR, ClawR_Dir*-127);
              delay(claw_deaccel_delay);
              claw_target = abs(analogRead(potclaw)+potclaw_direction)-claw_off;}
            }

        else if (joystickGetAnalog(2, 2) > claw_joystickrange){
          if(analogRead(potclaw) < 3400){
            motorSet(ClawL, ClawL_Dir*joystickGetAnalog(2, 2));
            motorSet(ClawR, ClawR_Dir*joystickGetAnalog(2, 2));
            delay(claw_deaccel_delay);
            claw_target = abs(analogRead(potclaw)+potclaw_direction)+claw_off;}
            }

        else if (joystickGetAnalog(2, 2) < -claw_joystickrange){
          if(analogRead(potclaw)>200){
            motorSet(ClawL, ClawL_Dir*joystickGetAnalog(2, 2));
            motorSet(ClawR, ClawR_Dir*joystickGetAnalog(2, 2));
            delay(claw_deaccel_delay);
            claw_target = abs(analogRead(potclaw)+potclaw_direction)-claw_off;}
            }

        else {
          motorSet(ClawL, ClawL_Dir*claw_power_L);
          motorSet(ClawR, ClawR_Dir*claw_power_R);}
        }
    //auto
      else if (isAutonomous() && isEnabled()){
          motorSet(ClawL, ClawL_Dir*claw_power_L);
          motorSet(ClawR, ClawR_Dir*claw_power_R);
          if( isAutonomous() ){}
          else{taskDelete(clawcontrol_auto);}
      }

  //delay
    delay(20);
    }
  }

void clawpresets(){
    if(joystickGetDigital(1,7,JOY_UP)){
      claw_target = CLAW_MAX;}
    else if(joystickGetDigital(1,7,JOY_DOWN)){
      claw_target = CLAW_CLOSED;}
    else if (joystickGetDigital(1,7,JOY_LEFT)){
      claw_target = CLAW_SEMI_OPEN;}
    else if(joystickGetDigital(1,7,JOY_RIGHT)){
      claw_target = CLAW_PARALLEL;}
    else{}
  }
