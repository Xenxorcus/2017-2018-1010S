#include "main.h"
#include "util.h"
#include "autofunctions.h"
#include "arm.h"
#include "claw.h"

void nolag(int demo_tics, int demo_movepower, int demo_holdpower){

  int tics = demo_tics;
  int move_power = demo_movepower;
  int hold_power = demo_holdpower;

  int timeout = 5000;
  int start_time = millis();
  int net_time;

  encoderReset(encoder_L);
  encoderReset(encoder_R);

  bool L_done = false;
  bool R_done = false;

  int powerL;
  int powerR;

  while(!L_done || !R_done){

    net_time = millis() - start_time;
    if(net_time > timeout){break;}
  ///close here
    if(tics < abs(encoderGet(encoder_L))){
      powerL = move_power;}
    else{
      powerL = hold_power;
      L_done = true;}

    if(tics < abs(encoderGet(encoder_R))){
      powerR = move_power;}
    else{
      powerR = hold_power;
      R_done = true;}

      motorset_drive(powerL, powerR);
      delay(20);
    }

  /*
  while(net_time < timeout){

    net_time = millis() - start_time;
    //if(net_time > timeout){break;}

    if(tics < abs(encoderGet(encoder_L))){
      powerL = move_power;}
    else{
      powerL = hold_power;
      L_done = true;}

    if(tics < abs(encoderGet(encoder_R))){
      powerR = move_power;}
    else{
      powerR = hold_power;
      R_done = true;}

      motorset_drive(powerL, powerR);
      delay(20);
      }
    */
  }
//USE
void drive_encoder(int direction, int target, int timeout, int maxpower, int minpower, float kdrift_encoder, float kaccel, float kdeaccel){

  int netpower = maxpower - minpower;
  float boost;
  int breakpower = 13;

  encoderReset(encoder_L);
  encoderReset(encoder_R);

  int encoderaverage = 0;
  int start_time = millis();
  int net_time = 0;

  while( (encoderaverage < target) && (net_time < timeout)){

    net_time  = millis() - start_time;

    encoderaverage = abs(encoderGet(encoder_L))+abs(encoderGet(encoder_R)/2);
    int encoder_error = encoderGet(encoder_L) - encoderGet(encoder_R); //subtract from L side

    //accel/deaccel constants
    if(encoderaverage < target*kaccel){
      boost = (encoderaverage)/(target*kaccel);}
    else if (encoderaverage > (target - target*kdeaccel)){
      boost = (encoderaverage)/(target - target*kdeaccel);}
    else{
      boost = 1;}

    int power_L = motorcap(minpower + boost*netpower) - direction*encoder_error*kdrift_encoder;
    int power_R = motorcap(minpower + boost*netpower) + direction*encoder_error*kdrift_encoder;
    motorset_drive(direction*power_L, direction*power_R);

    delay(20);
    }
  //brake
  motorset_drive(-direction*breakpower, -direction*breakpower);
  }

void drive_stop(int direction, int delta_trip, int maxpower, float kdrift_encoder){

  encoderReset(encoder_L);
  encoderReset(encoder_R);

  motorset_drive(direction*maxpower, direction*maxpower);
  delay(250);

  while( (abs(encoderGet(encoder_L)+encoderGet(encoder_R))/2) > delta_trip){

    encoderReset(encoder_L);
    encoderReset(encoder_R);

    delay(20);

    int encoder_error = encoderGet(encoder_L) - encoderGet(encoder_R); //subtract from L side
    //int power_L = motorcap(ower) - direction*encoder_error*kdrift_encoder;
    //int power_R = motorcap(minpower + boost*netpower) + direction*encoder_error*kdrift_encoder;
    motorset_drive(motorcap(direction*maxpower)-(encoder_error*kdrift_encoder), motorcap(direction*maxpower)+(encoder_error*kdrift_encoder));
    }

    motorset_drive(direction*maxpower, direction*maxpower);
    delay(40);
    motorset_drive(0, 0);


  }

void drive_gyro(int direction, int target, int timeout, int maxpower, int minpower, float kdrift_gyro, float kaccel, float kdeaccel){

    int netpower = maxpower - minpower;

    float boost;

    int breakpower = 15;

    encoderReset(encoder_L);
    encoderReset(encoder_R);
    gyroReset(gyro);

    int encoderaverage = 0;

    int start_time = millis();
    int net_time = 0;

    //  nolag();

    while(abs(encoderaverage) < target && net_time < timeout){

      //lcdPrint(uart1, 1, "enL=%d", encoderGet(encoder_L));
      //lcdPrint(uart1, 2, "enR=%d", encoderGet(encoder_R));

      net_time  = millis() - start_time;

      encoderaverage = (encoderGet(encoder_L)+encoderGet(encoder_R)/2);

      float gyro_error = -gyro_read(gyro, 300); //clockwise -- subtract from L side // NOT VALID

      //int encoder_error = encoderGet(encoder_L) - encoderGet(encoder_R); //subtract from L side // NOT VALID

      //accel/deaccel constants
      if(encoderaverage < target*kaccel){

        boost = (encoderaverage)/(target*kaccel);}
      else if (encoderaverage > (target - (target*kdeaccel))){
        boost = ((target-encoderaverage)/(target*kdeaccel));}
      else{
        boost = 1;}

      int power_L = motorcap(minpower + boost*netpower) + gyro_error*kdrift_gyro;
      int power_R = motorcap(minpower + boost*netpower) - gyro_error*kdrift_gyro;

      //int power_L = motorcap(minpower + boost*netpower) - gyro_error*kdrift_gyro;
      //int power_R = motorcap(minpower + boost*netpower) + gyro_error*kdrift_gyro;

      motorset_drive(direction*power_L, direction*power_R);
      delay(20);
      }
      //brake
      motorset_drive(-direction*breakpower, -direction*breakpower);

    }

void turn_gyro(int direction, int target, int timeout, int maxpower, int minpower, float kaccel, float kdeaccel){

  int netpower = maxpower - minpower;
  float boost;

  int start_time = millis();
  int net_time = 0;


  int breakpower = 20;
  encoderReset(encoder_L);
  encoderReset(encoder_R);
  gyroReset(gyro);

  int gyroaverage = abs(gyro_read(gyro, 300));

  while(gyroaverage < target && net_time < timeout){

      net_time  = millis() - start_time;

      gyroaverage = abs(gyro_read(gyro, 300));

      if(gyroaverage < target*kaccel){
        boost = (gyroaverage)/(target*kaccel);}
      else if (gyroaverage > (target - target*kdeaccel)){
        boost = (gyroaverage)/(target - target*kdeaccel);}
      else{
        boost = 1;}

        int power_L = motorcap(minpower + boost*netpower);
        int power_R = motorcap(minpower + boost*netpower);

        //int power_L = motorcap(minpower + boost*netpower) - gyro_error*kdrift_gyro;
        //int power_R = motorcap(minpower + boost*netpower) + gyro_error*kdrift_gyro;

        motorset_drive(direction*power_L, -direction*power_R);
        delay(20);
        }
    motorset_drive(-direction*breakpower, -direction*breakpower);
}

void claw_release(int claw_target, int arm_pos, int timeout){

  int starttime = millis();
  while( (!(arm_pos_global >= arm_pos)) && ((millis() - starttime) < (timeout))){
    delay(10);}
  claw_target_global = claw_target;
  }
//USE
void turn_time(int direction, int target, int error_range, int error_time, int power, float ktune, float ktunezone){

  int net_time = 0;
  int start_time = millis();

  gyroReset(gyro);

  int powerL;
  int powerR;
  int gyro_pos = abs(gyro_read(gyro, 300));

  while(net_time < error_time){

    gyro_pos = abs(gyro_read(gyro, 300));
    int gyro_error = target - gyro_pos;

    if ((gyro_pos < (target - (target*ktunezone))) || (gyro_pos > (target + (target*ktunezone)))){
      powerL = power*direction;
      powerR = -power*direction;}
    else{
      powerL = gyro_error*ktune*direction;
      powerR = -gyro_error*ktune*direction;}

    motorset_drive(powerL, powerR);

    if ((gyro_pos < target+error_range) && (gyro_pos > target-error_range)){
      net_time = millis() - start_time;}
    else{
      net_time = 0;
      start_time = millis();}

    delay(20);
  }
  motorset_drive(0, 0);
}

void lock_encoder(int timeout, float kp){

  encoderReset(encoder_L);
  encoderReset(encoder_R);
  int starttime = millis();

  while((millis()-starttime) < timeout){
    int errorL = encoderGet(encoder_L);
    int errorR = encoderGet(encoder_R);
    motorset_drive(-errorL*kp, -errorR*kp);
    delay(20);
  }
}
