// Context: Load cell calibration value

// Seed 054 — NC: variable starts with underscore
#include <iostream>
int main(){
    float _calibration = 0.5F; // NC
    float raw = 1023.0F;
    std::cout << "weight=" << raw * _calibration << "\n";
    return 0;
}