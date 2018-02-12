#ifndef PID_H_
#define PID_H_


typedef struct PID_terms {
    float kp;
    float ki;
    float kd;
    int intergral_limit;

    int error;
    int error_last;
    int error_diff;
    int error_sum;

} PID_terms;

void PID_init(PID_terms *pid, float kp, float ki, float kd, int intergral_limit);

int PID_cal(PID_terms *pid, int target, int sensor);

#endif
