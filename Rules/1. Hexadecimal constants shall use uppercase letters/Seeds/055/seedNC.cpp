// Context: CNC drift base literal

// Seed 080 — NC: lowercase hex CNC drift base
#include <iostream>
int main(){
    long base = 0x1d4; // NC: 468
    float drift = 0.002F; (void)drift;
    std::cout << "cnc_base=0x" << std::hex << base << "\n";
    return 0;
}