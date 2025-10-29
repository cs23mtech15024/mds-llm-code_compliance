// Context: Ventilator tag literal

// Seed 077 — C: uppercase hex ventilator tag
#include <iostream>
int main(){
    long tag = 0x5B; // C
    float vg = 0.12F; (void)vg;
    std::cout << "vent_tag=0x" << std::hex << tag << "\n";
    return 0;
}