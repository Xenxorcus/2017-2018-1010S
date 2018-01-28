#include "main.h"
#include "armpidterms.h"
#include <math.h>

void drive_armcontrol (void *ignore)
{
  float power_L;
  float power_R;

  int armdiff_L;
  int armdiff_R;
  int lastdiff_L;
  int lastdiff_R;

  int proportion_L;
  int proportion_R;

  int integral_L;
  int integral_R;

  int derivative_L;
  int derivative_R;

  armtarget_L = 4095 - analogRead(potarmL);
  armtarget_R = analogRead(potarmR);
  lcdClear(uart1);

  while(true){

    //set value
    drive_armheight_L = 4095-analogRead(potarmL);
    drive_armheight_R = analogRead(potarmR);

    //find error
    armdiff_L = armtarget_L - drive_armheight_L;
    armdiff_R = armtarget_R - drive_armheight_R;

    //calculate P
    proportion_L = armdiff_L;
    proportion_R = armdiff_R;

    //intergral cap+calcualte I
    if(abs(armdiff_L) < arm_integral_activezone){
    integral_L = integral_L + (armdiff_L);}
    else{integral_L = 0;}
    if(abs(armdiff_R) < arm_integral_activezone){
      integral_R = integral_R + (armdiff_R);}
    else{integral_R = 0;}

    //calculate D
    derivative_L =  armdiff_L - lastdiff_L;
    lastdiff_L = armdiff_L;
    derivative_R =  armdiff_R - lastdiff_R;
    lastdiff_R = armdiff_R;

    //calcualte power values
    power_L = (derivative_L*arm_k_derivative) + (integral_L*arm_k_integral)+(proportion_L*arm_k_proportion);
    power_R = (derivative_R*arm_k_derivative) + (integral_R*arm_k_integral)+(proportion_R*arm_k_proportion);
  // (R - L) + OFF SET
  arm_skew = ((analogRead(potarmR))-(4095-analogRead(potarmL))) + OFFSET_ARM;

    if(joystickGetDigital(1,6,JOY_UP)){
      motorSet(ArmLT, (ArmLT_Dir*127)+(arm_skew*arm_k_skew));
      motorSet(ArmLB, (ArmLB_Dir*127)+(arm_skew*arm_k_skew));
      motorSet(ArmRT, (ArmRT_Dir*127)-(arm_skew*arm_k_skew));
      motorSet(ArmRB, (ArmRB_Dir*127)-(arm_skew*arm_k_skew));
      delay(arm_deaccel_delay);
      armtarget_L = 4095-analogRead(potarmL);
      armtarget_R = analogRead(potarmR);}

    else if(joystickGetDigital(1,6,JOY_DOWN)){
      motorSet(ArmLT, (ArmLT_Dir*-127)-(arm_skew*arm_k_skew));
      motorSet(ArmLB, (ArmLB_Dir*-127)-(arm_skew*arm_k_skew));
      motorSet(ArmRT, (ArmRT_Dir*-127)+(arm_skew*arm_k_skew));
      motorSet(ArmRB, (ArmRB_Dir*-127)+(arm_skew*arm_k_skew));
      delay(arm_deaccel_delay);
      armtarget_L = 4095 - analogRead(potarmL);
      armtarget_R = analogRead(potarmR);}

      else if (joystickGetAnalog(2, 3) > arm_joystickrange){
        motorSet(ArmLT, (ArmLT_Dir*joystickGetAnalog(2, 3)));
        motorSet(ArmLB, (ArmLB_Dir*joystickGetAnalog(2, 3)));
        motorSet(ArmRT, (ArmRT_Dir*joystickGetAnalog(2, 3)));
        motorSet(ArmRB, (ArmRB_Dir*joystickGetAnalog(2, 3)));
        delay(arm_deaccel_delay);
        armtarget_L = 4095 - analogRead(potarmL);
        armtarget_R = analogRead(potarmR);}

      else if (joystickGetAnalog(2, 3) < -arm_joystickrange){
        motorSet(ArmLT, (ArmLT_Dir*joystickGetAnalog(2, 3)));
        motorSet(ArmLB, (ArmLB_Dir*joystickGetAnalog(2, 3)));
        motorSet(ArmRT, (ArmRT_Dir*joystickGetAnalog(2, 3)));
        motorSet(ArmRB, (ArmRB_Dir*joystickGetAnalog(2, 3)));
        delay(arm_deaccel_delay);
        armtarget_L = 4095 - analogRead(potarmL);
        armtarget_R = analogRead(potarmR);}

    else {
        motorSet(ArmLT, ArmLT_Dir*power_L);
        motorSet(ArmLB, ArmLB_Dir*power_L);
        motorSet(ArmRT, ArmRT_Dir*power_R);
        motorSet(ArmRB, ArmRB_Dir*power_R);}

  //delay
    delay(25);
    }
  }

void armpresets(){
    if(joystickGetDigital(1,8,JOY_UP)){
      armtarget_L = ARM_MAX_L;
      armtarget_R = ARM_MAX_R;}
    else if(joystickGetDigital(1,8,JOY_DOWN)){
      armtarget_L = ARM_GROUND_L;
      armtarget_R = ARM_GROUND_R;}
    else if (joystickGetDigital(1,8,JOY_LEFT)){
      armtarget_L = ARM_MID_L;
      armtarget_R = ARM_MID_R;}
    else if(joystickGetDigital(1,8,JOY_RIGHT)){
    //  armtarget_L = ;
    //  armtarget_R = ;
    }
    else{}
  }

void auto_armcontrol (void *ignore)
  {
    float power_L;
    float power_R;

    int armdiff_L;
    int armdiff_R;
    int lastdiff_L;
    int lastdiff_R;

    int proportion_L;
    int proportion_R;

    int integral_L;
    int integral_R;

    int derivative_L;
    int derivative_R;

    armtarget_L = 4095 - analogRead(potarmL);
    armtarget_R = analogRead(potarmR);
    //lcdClear(uart1);

    while(true){

      //set value
      drive_armheight_L = 4095-analogRead(potarmL);
      drive_armheight_R = analogRead(potarmR);

      //find error
      armdiff_L = armtarget_L - drive_armheight_L;
      armdiff_R = armtarget_R - drive_armheight_R;

      //calculate P
      proportion_L = armdiff_L;
      proportion_R = armdiff_R;

      //intergral cap+calcualte I
      if(abs(armdiff_L) < arm_integral_activezone){
      integral_L = integral_L + (armdiff_L);}
      else{integral_L = 0;}
      if(abs(armdiff_R) < arm_integral_activezone){
        integral_R = integral_R + (armdiff_R);}
      else{integral_R = 0;}

      //calculate D
      derivative_L =  armdiff_L - lastdiff_L;
      lastdiff_L = armdiff_L;
      derivative_R =  armdiff_R - lastdiff_R;
      lastdiff_R = armdiff_R;

      //calcualte power values
      power_L = (derivative_L*arm_k_derivative) + (integral_L*arm_k_integral)+(proportion_L*arm_k_proportion);
      power_R = (derivative_R*arm_k_derivative) + (integral_R*arm_k_integral)+(proportion_R*arm_k_proportion);
    // (R - L) + OFF SET
    arm_skew = ((analogRead(potarmR))-(4095-analogRead(potarmL))) + OFFSET_ARM;

          motorSet(ArmLT, ArmLT_Dir*power_L);
          motorSet(ArmLB, ArmLB_Dir*power_L);
          motorSet(ArmRT, ArmRT_Dir*power_R);
          motorSet(ArmRB, ArmRB_Dir*power_R);

          delay(25);

          if( isAutonomous() )
            {}
            else{
          taskDelete(clawtaskpid_auto);}

        }
      }
