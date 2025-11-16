// Context: Sensor fusion filter gains

// seed_003_NC.h
#pragma once
// NC header
double seed003_alpha = 0.98; // NC
double seed003_beta  = 0.02; // NC

double seed003_filter(double p, double m) { // NC
    return seed003_alpha * p + seed003_beta * m;
}
