// Context: Rover wheel base torque literal

// Seed 069 — NC: lowercase hex base torque
#include <iostream>
int main(){
    long torque = 0x2d; // NC: 45
    float bias = 1.15F; (void)bias;
    std::cout << "base_torque=" << torque << "\n";
    return 0;
}