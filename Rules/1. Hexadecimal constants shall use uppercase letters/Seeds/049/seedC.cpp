// Context: Reactor ramp tag literal

// Seed 073 — C: uppercase hex ramp tag
#include <iostream>
int main(){
    long tag = 0x1AD; // C
    float ramp = 0.04F; (void)ramp;
    std::cout << "ramp_tag=0x" << std::hex << tag << "\n";
    return 0;
}