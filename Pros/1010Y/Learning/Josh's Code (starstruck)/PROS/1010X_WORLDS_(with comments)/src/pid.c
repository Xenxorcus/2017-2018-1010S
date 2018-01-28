#include "main.h"
#include "pid.h"

//**Notes: pointers ussed for PID_terms strucutre as to allow multiple PID_terms strucutres to be made


void PID_init(PID_terms *pid, float kp, float ki, float kd, int intergral_limit){
  // inits a pid loop by defining varibles from parameters

  pid->kp = kp;
  pid->ki = ki;
  pid->kd = kd;
  pid->intergral_limit = intergral_limit;

  pid->error = 0;
  pid->error_last = 0;
  pid->error_diff = 0;
  pid->error_sum = 0;
}

int PID_cal(PID_terms *pid, int target, int sensor){
  // calculates a pid function output (usually motor speed)
  // needs a PID_terms strucutre for PID terms

    pid->error = target - sensor;
    pid->error_diff = pid->error - pid->error_last;
    pid->error_last = pid->error;

    if(abs(pid->error) < pid->intergral_limit){
      pid->error_sum =+ pid->error;}
    else{ pid->error_sum = 0;}

  return (pid->error*pid->kp)+(pid->error_sum*pid->ki)+(pid->error_diff*pid->kd);
}
