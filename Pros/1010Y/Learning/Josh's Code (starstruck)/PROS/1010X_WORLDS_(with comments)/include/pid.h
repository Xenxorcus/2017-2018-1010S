#ifndef PID_H_
#define PID_H_

// making a structure for PID terms
typedef struct PID_terms {
    float kp; // Proportional constant
    float ki; // Integral constant
    float kd; // Derivative constant
    int intergral_limit; // limit bound for I (must be within +/- of limit)

    // error terms
    int error;
    int error_last;
    int error_diff;
    int error_sum;

} PID_terms;

void PID_init(PID_terms *pid, float kp, float ki, float kd, int intergral_limit); // used to init pid loop (arm, claw)

int PID_cal(PID_terms *pid, int target, int sensor); // used to calculate pid in loop

//**note: PID_terms *pid is a pointer to the PID_terms sturcture delcared uniquely

#endif
