// Context: Drone flight PID tuning parameters

// seed_005_NC.h
#pragma once
// NC: mutable gains defined here
float seed005_kp = 1.1F; // NC
float seed005_ki = 0.03F; // NC
float seed005_kd = 0.55F; // NC

float seed005_pid(float e) { // NC
    return seed005_kp * e;
}
