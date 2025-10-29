// Context: Reactor ramp tag literal

// Seed 073 — NC: lowercase hex ramp tag
#include <iostream>
int main(){
    long tag = 0x1ad; // NC: 429
    float ramp = 0.04F; (void)ramp;
    std::cout << "ramp_tag=0x" << std::hex << tag << "\n";
    return 0;
}