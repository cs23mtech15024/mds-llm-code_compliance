// Context: Torque sensor linearization table

// Seed 043 — NC: linearization table decays to pointer
#include <iostream>
float linearize_torque(float lut[]) { // NC
    return lut[0];
}
int main(){
    float torque_lut[128] = {0.5F};
    std::cout << "torque=" << linearize_torque(torque_lut) << "\n";
    return 0;
}