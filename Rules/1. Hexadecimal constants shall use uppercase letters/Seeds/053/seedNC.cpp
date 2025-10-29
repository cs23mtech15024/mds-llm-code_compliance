// Context: Ventilator tag literal

// Seed 077 — NC: lowercase hex ventilator tag
#include <iostream>
int main(){
    long tag = 0x5b; // NC: 91
    float vg = 0.12F; (void)vg;
    std::cout << "vent_tag=0x" << std::hex << tag << "\n";
    return 0;
}