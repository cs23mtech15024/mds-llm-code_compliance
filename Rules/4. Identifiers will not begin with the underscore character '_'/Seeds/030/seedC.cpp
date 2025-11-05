// Context: Gain coefficient adjuster

// Seed 030 — C: variable without underscore prefix
#include <iostream>
int main(){
    float gain = 1.5F; // C
    float signal = 100.0F;
    std::cout << "output=" << signal * gain << "\n";
    return 0;
}