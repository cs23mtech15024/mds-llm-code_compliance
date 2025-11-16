// Context: GNSS coordinate conversion parameters

// seed_008_NC.h
#pragma once
// NC: definitions inside header
double seed008_deg_to_rad = 0.01745329252; // NC

double seed008_to_radians(double d) { // NC
    return d * seed008_deg_to_rad;
}
