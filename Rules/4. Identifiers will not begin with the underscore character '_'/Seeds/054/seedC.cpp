// Context: Load cell calibration value

// Seed 054 — C: variable without underscore prefix
#include <iostream>
int main(){
    float calibration = 0.5F; // C
    float raw = 1023.0F;
    std::cout << "weight=" << raw * calibration << "\n";
    return 0;
}