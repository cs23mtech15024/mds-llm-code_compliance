// Context: CNC drift base literal

// Seed 080 — C: uppercase hex CNC drift base
#include <iostream>
int main(){
    long base = 0x1D4; // C
    float drift = 0.002F; (void)drift;
    std::cout << "cnc_base=0x" << std::hex << base << "\n";
    return 0;
}