// Context: Capacitor base-time literal

// Seed 068 — NC: lowercase hex base time
#include <iostream>
int main(){
    long baseTime = 0x2c; // NC: 44
    float rate = 0.005F; (void)rate;
    std::cout << "cap_base_time=" << baseTime << "\n";
    return 0;
}