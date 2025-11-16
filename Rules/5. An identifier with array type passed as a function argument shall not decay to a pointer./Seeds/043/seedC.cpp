// Context: Torque sensor linearization table

// Seed 043 — C: linearization table by reference
#include <iostream>
float linearize_torque(float (&lut)[128]) { // C
    return lut[0];
}
int main(){
    float torque_lut[128] = {0.5F};
    std::cout << "torque=" << linearize_torque(torque_lut) << "\n";
    return 0;
}