// Context: Sensor calibration offset variable

// Seed 002 — C: variable without underscore prefix
#include <iostream>
int main(){
    double calibration_offset = 2.5; // C
    double reading = 98.6 + calibration_offset;
    std::cout << "temp=" << reading << "\n";
    return 0;
}