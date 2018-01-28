#include "main.h"
#include "util.h"
#include "autofunctions.h"
#include "arm.h"
#include "claw.h"

// DRIVING FUNCTIONS

//to reduce lag in moving forward  = NOT WORKING
void nolag(int demo_tics, int demo_movepower, int demo_holdpower){

  // testing varibles
  int tics = demo_tics; // target for tics on each side to each (small number (1-5))
  int move_power = demo_movepower; // power to reach tic target (small)
  int hold_power = demo_holdpower; // power to hold after reaching target (smaller)

  // time out varibles
  int timeout = 5000; // for debugging
  int start_time = millis();
  int net_time;

  // encoder reset
  encoderReset(encoder_L);
  encoderReset(encoder_R);

  // checking ech side of drive
  bool L_done = false;
  bool R_done = false;

  // power sent to motors
  int powerL;
  int powerR;

  while(!L_done || !R_done){ // loop checks for L and R side to reach a small encoder count

    // timeout
    net_time = millis() - start_time;
    if(net_time > timeout){break;}
  ///close here

    // checking L side
    if(tics < abs(encoderGet(encoder_L))){
      powerL = move_power;}
    else{
      powerL = hold_power;
      L_done = true;}
    // checking R side
    if(tics < abs(encoderGet(encoder_R))){
      powerR = move_power;}
    else{
      powerR = hold_power;
      R_done = true;}

      motorset_drive_auto(powerL, powerR); // send power to motors
      delay(20);
    }
  }

//to lock robot in place while dumping/ grabbing objects = PARTIALLY WORKING, USED MINIMALLY (NOT USED)
void lock_encoder(int timeout, float kp){

  // setting zero point
  encoderReset(encoder_L);
  encoderReset(encoder_R);
  int starttime = millis(); // function is timebased, duration varible

  while((millis()-starttime) < timeout){
    int errorL = encoderGet(encoder_L);
    int errorR = encoderGet(encoder_R);
    motorset_drive_auto(errorL*kp, -errorR*kp); // sets power to L and R wheels to error from zero point set at start of function
    delay(20);
  }
}

//driving with encoder  = WORKING
void drive_encoder(int direction, int target, int timeout, int maxpower, int minpower, float kdrift_encoder, float kaccel, float kdeaccel){

  int netpower = maxpower - minpower; // used in boost calculations
  float boost; // varible name for accel and deaccel adjustments to speed
  int breakpower = 0; // was 13 (changed for debugging)

  encoderReset(encoder_L);
  encoderReset(encoder_R);

  int encoderaverage = 0;
  int start_time = millis();
  int net_time = 0;

  // loacl varible definitions finished

  while( (encoderaverage < target) && (net_time < timeout)){ // loop checks for target dist and timeout

    net_time  = millis() - start_time; // timeout check **Better to use break fucntion, seperate varible from ealier code

    encoderaverage = abs(encoderGet(encoder_L))+abs(encoderGet(encoder_R)/2); // updating dist
    int encoder_error = encoderGet(encoder_L) - encoderGet(encoder_R); //subtract from L side // L/R drift

    //accel/deaccel constants
    // boost is adjustment constant on motor power
    if(encoderaverage < target*kaccel){ // kaccel is used as fraction of 1 in total dist
      boost = (encoderaverage)/(target*kaccel);}
    else if (encoderaverage > (target - target*kdeaccel)){ // kdeaccel is used as fraction of 1 in total
      boost = (encoderaverage)/(target - target*kdeaccel);}
    else{
      boost = 1;} // max speed, 1/1=100%


    //motor cap used to give drift error significane on power value
    //netpower*boots + minpower is fraction of max power for accel/deaccel
    //direction is either 1 or -1 (forwards / backwards)
    int power_L = motorcap(minpower + boost*netpower) - (direction*encoder_error*kdrift_encoder);
    int power_R = motorcap(minpower + boost*netpower) + (direction*encoder_error*kdrift_encoder);
    motorset_drive_auto(direction*power_L, direction*power_R); // sents to motors through until function

    delay(20);
    }
  //brake
  motorset_drive_auto(-direction*breakpower, -direction*breakpower); // brakes after moving
  }

//drivier with encoder and gyro to correct skew = WORKING, NOT USED
void drive_gyro(int direction, int target, int timeout, int maxpower, int minpower, float kdrift_gyro, float kaccel, float kdeaccel){

  int netpower = maxpower - minpower; // used in boost calculations
  float boost; // varible name for accel and deaccel adjustments to speed
  int breakpower = 13; // for breaking

  encoderReset(encoder_L);
  encoderReset(encoder_R);

  int encoderaverage = 0;
  int start_time = millis(); // for timeout
  int net_time = 0; // for timeout

  int gyro_start = gyro_read(gyro, 300); // gyro inital (using util function)

  // end locacl varibles declarations

  while( (encoderaverage < target) && (net_time < timeout)){ // loops checks target and timeout

    net_time  = millis() - start_time; // updating time elasped

    encoderaverage = 1.23*abs(encoderGet(encoder_L))+abs(encoderGet(encoder_R)/2); // updating distance // 1.23 used as kp for debugging
    int gyro_error = gyro_start - gyro_read(gyro, 300); //CHECK LORR Drift (lcockwise/counter);

    //accel/deaccel constants
    if(encoderaverage < target*kaccel){ // kaccel is used as fraction of 1 in total dist
      boost = (encoderaverage)/(target*kaccel);}
    else if (encoderaverage > (target - target*kdeaccel)){ // kdeaccel is used as fraction of 1 in total
      boost = (encoderaverage)/(target - target*kdeaccel);}
    else{
      boost = 1;} // max speed, 1/1=100%

    //motor cap used to give drift error significane on power value
    //netpower*boots + minpower is fraction of max power for accel/deaccel
    //direction is either 1 or -1 (forwards / backwards)
    int power_L = motorcap(minpower + boost*netpower) + (direction*gyro_error*kdrift_gyro);
    int power_R = motorcap(minpower + boost*netpower) - (direction*gyro_error*kdrift_gyro);
    motorset_drive_auto(direction*power_L, direction*power_R);// sents to motors through until function

    delay(20);
    }
  //brake
  motorset_drive_auto(-direction*breakpower, -direction*breakpower); // braking when function ends
  }

// detecting when robot hit wall (drives until wheels stop) = WORKING
void drive_stop(int direction, int delta_trip, int maxpower, float kdrift_encoder, int timeout){

  int start_time = millis(); // for timeout
  int net_time = 0; // for timeout

  encoderReset(encoder_L);
  encoderReset(encoder_R);

  motorset_drive_auto(direction*maxpower, direction*maxpower); // starts moving fowards (not l/R skew)
  delay(150); // delayed required  = otherwise loop ends before motions starts

  while(((abs(encoderGet(encoder_L)+encoderGet(encoder_R))/2) > delta_trip)&& (net_time < timeout)){
    // loops checks is average encoder count drops below delta_trip each cycle (and timeout)

    net_time = millis()-start_time; // timeout update
    // resets encoder count to zero
    encoderReset(encoder_L);
    encoderReset(encoder_R);

    delay(20); // delay allows wheel to move

    //lcdPrint(uart1, 1, "L: %d, R:%d",  encoderGet(encoder_L), encoderGet(encoder_R));

    int encoder_error = encoderGet(encoder_L) - encoderGet(encoder_R); //subtract from L side

    //int power_L = motorcap(ower) - direction*encoder_error*kdrift_encoder;
    //int power_R = motorcap(minpower + boost*netpower) + direction*encoder_error*kdrift_encoder;

    motorset_drive_auto(motorcap(direction*maxpower)-(encoder_error*kdrift_encoder), motorcap(direction*maxpower)+(encoder_error*kdrift_encoder));
    // motor power update = to adjust for L/R skew
    }

    motorset_drive_auto(direction*maxpower, direction*maxpower); // to square up on fence (added later)
    delay(40);
    motorset_drive_auto(0, 0); // functions ends


  }

///////////////////////////////////////////////////////////////

//TURNING FUNCTIONS

// original turning functions (only accel and deaccel) = WORKING (but basic), NOT USED
void turn_gyro(int direction, int target, int timeout, int maxpower, int minpower, float kaccel, float kdeaccel){

  int netpower = maxpower - minpower; // net power for accel/deaccel
  float boost; // accel/deaccel constant

  int start_time = millis(); // for timeout
  int net_time = 0; // for timeout


  int breakpower = 20; // breaking power = espically important in turning
  encoderReset(encoder_L);
  encoderReset(encoder_R);
  gyroReset(gyro);

  int gyroaverage = abs(gyro_read(gyro, 300));
  // end of local varibles

  while(gyroaverage < target && net_time < timeout){ // loop checks for target (gyro) and timeout

      net_time  = millis() - start_time; // timeout update

      gyroaverage = abs(gyro_read(gyro, 300)); // gyro position update (using util function)

      // accel and deaccel constant (see void drive_encoder();)
      if(gyroaverage < target*kaccel){
        boost = (gyroaverage)/(target*kaccel);}
      else if (gyroaverage > (target - target*kdeaccel)){
        boost = (gyroaverage)/(target - target*kdeaccel);}
      else{
        boost = 1;}

        //updating power
        int power_L = motorcap(minpower + boost*netpower);
        int power_R = motorcap(minpower + boost*netpower);

        //int power_L = motorcap(minpower + boost*netpower) - gyro_error*kdrift_gyro;
        //int power_R = motorcap(minpower + boost*netpower) + gyro_error*kdrift_gyro;

        motorset_drive_auto(direction*power_L, -direction*power_R); // sending to motor theough until fucntion
        delay(20);
        }
    motorset_drive_auto(-direction*breakpower, -direction*breakpower); // braking when loops exits
}

//turning based off time. turn constant obeys P controller= WORKING, USED
void turn_time(int direction, int target, int error_range, int error_time, int power, float ktune, float ktunezone){

  int net_time = 0; // for timeout
  int start_time = millis(); // for timeout

  gyroReset(gyro);

  int powerL;
  int powerR;
  int gyro_pos = abs(gyro_read(gyro, 300));

  // end of local varibles declarations

  while(net_time < error_time){ // loop checks time elapsed (error_time)

    gyro_pos = abs(gyro_read(gyro, 300)); // updates gyro value (through util function)
    int gyro_error = target - gyro_pos; // updates gyro error from target

    //if statement checks where robot is in turn.
    // if outside ktunezone, max power towards the ktunezone
    // else, (within zone), P controller for error
    if ((gyro_pos < (target - (target*ktunezone))) || (gyro_pos > (target + (target*ktunezone)))){
      // max power (specified by parameters)
      powerL = power*direction;
      powerR = -power*direction;}
    else{
      // P controller
      powerL = gyro_error*ktune*direction;
      powerR = -gyro_error*ktune*direction;}

    motorset_drive_auto(powerL, powerR); // util function

    // time only starts when within error range
    // net_time is varible controlling loop
    if ((gyro_pos < target+error_range) && (gyro_pos > target-error_range)){
      net_time = millis() - start_time;}
    else{ // when outisde ktunezone
      net_time = 0;
      start_time = millis();}

    delay(20);
  }
  motorset_drive_auto(0, 0); // function ends
}

//20 dp
//FULL PID Controller capable turn (time based) = WORKING (was used as P and PD ), NOT USED (2nd version developed)
void turn_pid(int direction, int target, int maxpower, float kp, float ki, float kd, int ki_range, long timeout){

  gyroReset(gyro); // sensor reset
  long start_time = millis(); // for timeout
  long net_time = 0; // for timeout

  // pid terms
  float kpv;
  float kiv;
  float kdv;
  int error_last = 0;
  int error_diff = 0;
  int error_sum = 0;

  int brake_power = 10;

  // end of local varibles

  while( net_time < timeout){ // loops checks time elapsed

    net_time = millis() - start_time; // updating time

    lcdPrint(uart1, 1, "gyro:%f", gyro_read(gyro, 300)); // debugging
    int pos = abs(gyro_read(gyro, 300)); // gyro position (using util function)
    int error = target - pos; // error for PID

    /////////// PID Calculations
    // For D term
    error_diff = error - error_last;
    error_last = error;

    // For I term
    if(abs(error)<ki_range){ // I term only accumulates within ki_range (controlling)
      error_sum =+ error; }
    else{ error_sum = 0; }

    // motor power conversions
    kpv = kp*error; // P term
    kiv = ki*error_sum; // I term
    kdv = kd*error_diff; // D term

    int motor_power = (kpv+kiv+kdv); // pid varibles sum = motor power

    motorset_drive_auto(motor_power*direction, -motor_power*direction);// L, R (using until function)

    delay(20);

    }

  motorset_drive_auto(brake_power*-direction, brake_power*direction);// L, R // fucntions ends (braking)

  }

// FULL PID controller (improved)(global gyro function)// created for debugging and re tuning of turn function = USED
void turn_pid2(int direction, int target, int maxpower, float kp, float ki, float kd, int ki_range, long timeout){

  ////////////////////////
  //** For comments read void turn_pid (earlier function)**//
  ////////////////////////

  //gyroReset(gyro); no gyro reset (as global gyro function)
  long start_time = millis();
  long net_time = 0;

  float kpv;
  float kiv;
  float kdv;

  int error_last = 0;
  int error_diff = 0;
  int error_sum = 0;

  int brake_power = 10;

  while( net_time < timeout){

    net_time = millis() - start_time;

    lcdPrint(uart1, 1, "gyro:%f", gyro_read(gyro, 300));
    int pos = gyro_read(gyro, 300);
    int error = target - pos;

    error_diff = error - error_last;
    error_last = error;

    if(abs(error)<ki_range){
      error_sum =+ error; }
    else{ error_sum = 0; }

    kpv = kp*error;
    kiv = ki*error_sum;
    kdv = kd*error_diff;

    int motor_power = (kpv+kiv+kdv);

    motorset_drive_auto(motor_power*direction, -motor_power*direction);// L, R

    delay(20);

    }

  motorset_drive_auto(brake_power*-direction, brake_power*direction);// L, R

  }

// use 3.5 =kp and 30 = kd

////////////////////////////////////////////////

//MISC_ CLAW /ARM FUNCTIONS

// to relase claw when dumping objects over fence = WORKING, USED
void claw_release2(int armheight, int clawtarget, int timeout){
  // function fully intergrated with arm task
  // allows for dump to and claw release while moving
  c_release = true; // binary (see claw task)
  c_release_arm = armheight; // arm hieght when release occurs
  c_release_target = clawtarget; // claw target when released
  c_release_timeout = timeout; // timeout

}

// to lift arm when hanging (and use claw as lock) = WORKING, USED
void claw_hang (int armheight, int clawtarget){

  c_hang = true; // binary (see claw task)
  c_hang_arm = armheight; // arm target when triggered
  c_hang_target = clawtarget; // claw target when triggered


}

// to relase claw when dumping over fence = NOT USED
void claw_release(int claw_target, int arm_pos, int timeout){
  // not used, sinnce loop stops all driving in auto (waiting for arm task to reach release value)
  int starttime = millis();
  while( (!(arm_pos_global >= arm_pos)) && ((millis() - starttime) < (timeout))){
    delay(10);}
  claw_target_global = claw_target;
  }

//**Note:  claw_hang and claw_release2 required to be seperate functions as arm is one is moving up , the other moving down (< and > signs are needed)
// it was faster to code them seperatedy -  better code would have on function with check
