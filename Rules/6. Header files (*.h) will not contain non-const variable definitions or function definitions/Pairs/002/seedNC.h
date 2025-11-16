// Context: Robotic arm kinematics parameters

// seed_002_NC.h
#pragma once
// NC: definitions in header
#include <cmath>
double seed002_link1 = 0.55; // NC
double seed002_link2 = 0.40; // NC

double seed002_calc_reach() { // NC
    return seed002_link1 + seed002_link2;
}
