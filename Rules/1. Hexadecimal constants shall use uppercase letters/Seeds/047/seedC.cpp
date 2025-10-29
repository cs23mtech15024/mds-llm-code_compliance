// Context: Yaw base offset literal

// Seed 070 — C: uppercase hex yaw offset
#include <iostream>
int main(){
    long baseOffset = 0x1F; // C
    float yaw = 0.45F; (void)yaw;
    std::cout << "yaw_base_off=" << baseOffset << "\n";
    return 0;
}