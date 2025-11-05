// Context: Sensor calibration offset variable

// Seed 002 — NC: variable starts with underscore
#include <iostream>
int main(){
    double _calibration_offset = 2.5; // NC
    double reading = 98.6 + _calibration_offset;
    std::cout << "temp=" << reading << "\n";
    return 0;
}