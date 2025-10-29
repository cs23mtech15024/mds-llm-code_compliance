// Context: Yaw base offset literal

// Seed 070 — NC: lowercase hex yaw offset
#include <iostream>
int main(){
    long baseOffset = 0x1f; // NC: 31
    float yaw = 0.45F; (void)yaw;
    std::cout << "yaw_base_off=" << baseOffset << "\n";
    return 0;
}